
#include <iostream>

#include <NeuralNetwork.h>

using namespace std;

int main(void) {
	vector<double> inputs;
	inputs.push_back(1.0);
	inputs.push_back(0.0);

	NeuralNetwork testNet("../examples/data/model_OR.lnn");

	vector<double> result = testNet.evaluate(inputs);

	cout << "Output of network is: [" << result[0];
	for(size_t i=1; i<result.size(); i++) {
		cout << "," << result[i];
	}
	cout << "]" << endl;
	
	return 0;
}