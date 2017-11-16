#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(string modelPath) {
	isLoaded = false;
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
				number_inputs = n_neurons;
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
				number_outputs = n_neurons;
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
				0,
				&ActivationFunctions::no_activation,//&ActivationFunctions::fast_sigmoid,
				&ActivationFunctions::no_activation,//&ActivationFunctions::reverse_fast_sigmoid,
				NeuronInitializer::ConstantInitializer(layer["Bias"])));
			cout << "Added a Bias neuron" << endl;
		}

		neurons.push_back(layer_neurons);
	}

	cout << endl;
	cout << "=======================" << endl;
	cout << "NeuralNetwork Loaded" << endl;
	isLoaded = true;

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

vector<double> NeuralNetwork::evaluate(vector<double>& inputs) {
	assert(inputs.size() == number_inputs);

	vector<double> output;

	///////////////////////////////////////////////////////////////////////////
	/*cout << "Network has " << neurons.size() << " layers" << endl;
	cout << "Inputs are: " << endl;

	for(size_t i=0; i<number_inputs; i++) {
		cout << ": " << inputs[i] << endl;
	}
	for(size_t i_layer=0; i_layer<neurons.size(); i_layer++) {
		cout << "layer " << i_layer << " has " << neurons[i_layer].size() << " neurons" << endl;
	}*/
	///////////////////////////////////////////////////////////////////////////

	// initialize input values for input layer:
	double* vals_in  = (double*)malloc(inputs.size()*sizeof(double));
	// initialize output values for input layer:
	double* vals_out = (double*)malloc(neurons[0].size()*sizeof(double));
	// pass input values to input array:
	for(unsigned int i=0; i<inputs.size(); i++) {
		vals_in[i] = inputs[i];
	}

	// iterate for input layer:
	vector<Neuron*>& layer = neurons[0];
	for(unsigned int i_neuron=0; i_neuron<layer.size(); i_neuron++) {
		vals_out[i_neuron] = layer[i_neuron]->evaluate(&vals_in[i_neuron]);
		//cout << "Output: " << vals_out[i_neuron] << endl;
	}

	// iterate for the rest of layers:
	for(unsigned int i_layer=1; i_layer<neurons.size(); i_layer++) {
		//cout << "--" << endl;
		vector<Neuron*>& layer = neurons[i_layer];
		double* temp = vals_in;
		vals_in  = vals_out;
		vals_out = temp;

		vals_out = (double*)realloc(vals_out, layer.size()*sizeof(double));

		for(unsigned int i_neuron=0; i_neuron<layer.size(); i_neuron++) {
			vals_out[i_neuron] = layer[i_neuron]->evaluate(vals_in);
			//cout << "Output: " << vals_out[i_neuron] << endl;
		}
	}

	unsigned int n_outputs = neurons.back().size();

	for(unsigned int i=0; i<n_outputs; i++) {
		output.push_back(vals_out[i]);
	}

	free(vals_in);
	free(vals_out);

	return output;

}

