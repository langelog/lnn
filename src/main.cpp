
#include <iostream>

#include <NeuralNetwork.h>

using namespace std;

int main(void) {
	vector<double> inputs;
	inputs.push_back(1.0);
	inputs.push_back(0.0);

	NeuralNetwork testNet("/Users/langelog/Git/lnn/examples/data/model_OR.lnn");

	vector<double> result = testNet.evaluate(inputs);
	
	return 0;
}