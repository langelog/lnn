#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(string modelPath) {
	cout << "Parsing from " << modelPath << endl;
	ifstream i(modelPath);
	i >> model;
	i.close();

	default_random_engine randEngine;

	assert(model["Name"].is_string());
	cout << "Loading network " << model["Name"] << endl;
	assert(model["Layers"].is_array());

	unsigned int n_layers = model["Layers"].size();

	for(unsigned int i_layer=0; i_layer<n_layers; i_layer++) {
		cout << ".";
		json layer = model["Layers"][i_layer];
		assert(layer.is_object());
		assert(layer["LayerType"].is_string());
		assert(layer["Neurons"].is_number());

		string       layer_type  = layer["LayerType"];
		unsigned int n_neurons   = layer["Neurons"];
		json         initializer = layer["Initializer"];

		assert(initializer.is_object());
		assert(initializer["Type"].is_string());

		string initer_type = initializer["Type"];
		
		cout << layer_type << endl;
		cout << "Neurons: " << n_neurons << endl;

		vector<Neuron*> layer_neurons;

		double value;
		double mean;
		double deviation;
		unsigned int n_inputs;

		for(unsigned int i_neuron=0; i_neuron<n_neurons; i_neuron++) {
			if(layer_type == "Input") {
				n_inputs = 1; // number of inputs per neuron
				//cout << "Neuron with " << n_inputs << " inputs" << endl;
				if(initer_type == "Constant") {
					assert(initializer["Value"].is_number());
					value = initializer["Value"];
					add_constant_weight_neuron(layer_neurons, 1, value);
				} else if(initer_type == "Normal") {
					assert(initializer["Mean"].is_number());
					assert(initializer["Deviation"].is_number());
					mean = initializer["Mean"];
					deviation = initializer["Deviation"];
					add_normal_weight_neuron(layer_neurons, 1, mean, deviation, randEngine);
				} else {
					cout << "Initializator not supported" << endl;
				}
				cout << "Added Input Neuron" << endl;
			} else if(layer_type == "Hidden") {
				n_inputs = neurons.back().size(); // number of inputs per neuron
				//cout << "Neuron with " << n_inputs << " inputs" << endl;
				if(initer_type == "Constant") {
					assert(initializer["Value"].is_number());
					value = initializer["Value"];
					add_constant_weight_neuron(layer_neurons, n_inputs, value);
				} else if(initer_type == "Normal") {
					assert(initializer["Mean"].is_number());
					assert(initializer["Deviation"].is_number());
					mean = initializer["Mean"];
					deviation = initializer["Deviation"];
					add_normal_weight_neuron(layer_neurons, n_inputs, mean, deviation, randEngine);
				} else {
					cout << "Initializator not supported" << endl;
				}
				cout << "Added Hidden Neuron" << endl;
			} else if(layer_type == "Output") {
				n_inputs = neurons.back().size(); // number of inputs per neuron
				if(initer_type == "Constant") {
					assert(initializer["Value"].is_number());
					value = initializer["Value"];
					add_constant_weight_neuron(layer_neurons, n_inputs, value);
				} else if(initer_type == "Normal") {
					assert(initializer["Mean"].is_number());
					assert(initializer["Deviation"].is_number());
					mean = initializer["Mean"];
					deviation = initializer["Deviation"];
					add_normal_weight_neuron(layer_neurons, n_inputs, mean, deviation, randEngine);
				} else {
					cout << "Initializator not supported" << endl;
				}
				cout << "Added Output Neuron" << endl;
			} else {
				cout << "Layer type not supported yet" << endl;
			}
		}

		if(layer["Bias"].is_number()) {
			// there is a bias neuron to implement:
			layer_neurons.push_back(new Neuron(
				1,
				&ActivationFunctions::fast_sigmoid,
				&ActivationFunctions::reverse_fast_sigmoid,
				NeuronInitializer::ConstantInitializer(layer["Bias"])));
			cout << "Added a Bias neuron" << endl;
		}

		neurons.push_back(layer_neurons);
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

void NeuralNetwork::add_constant_weight_neuron(vector<Neuron*>& layer_neurons, unsigned int n_inputs, double value) {
	layer_neurons.push_back(new Neuron(
		n_inputs,
		&ActivationFunctions::fast_sigmoid,
		&ActivationFunctions::reverse_fast_sigmoid,
		NeuronInitializer::ConstantInitializer(value)));
}

void NeuralNetwork::add_normal_weight_neuron(vector<Neuron*>& layer_neurons, unsigned int n_inputs, double mean, double deviation, default_random_engine& randEngine) {
	layer_neurons.push_back(new Neuron(
		n_inputs,
		&ActivationFunctions::fast_sigmoid,
		&ActivationFunctions::reverse_fast_sigmoid,
		NeuronInitializer::NormalInitializer(randEngine, mean, deviation)));
}

