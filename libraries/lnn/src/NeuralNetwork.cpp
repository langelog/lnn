#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(string modelPath) {
	cout << "Parsing from " << modelPath << endl;
	ifstream i(modelPath);
	i >> model;
	i.close();
	assert(model["Name"].is_string());
	cout << "Loading network " << model["Name"];
	assert(model["Layers"].is_array());

	unsigned int n_layers = model["Layers"].size();

	for(unsigned int i_layer=0; i_layer<n_layers; i_layer++) {
		cout << ".";
		assert(model["Layers"][i].is_object());
	}

	cout << endl;

	/*double inputs[] = {1.2, 3.2, 1.3, 4.2, 2.3, 2.5, 1.0, 3.2, 1.9, 0.2};
	std::default_random_engine randEngine;

	ns = new Neuron(
		10,
		&ActivationFunctions::fast_sigmoid,
		&ActivationFunctions::reverse_fast_sigmoid,
		//NeuronInitializer::NormalInitializer(randEngine, 0.0, 1.0));
		NeuronInitializer::ConstantInitializer(1.0));

	cout << ns->evaluate(inputs) << endl;*/


}