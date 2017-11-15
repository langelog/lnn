#ifndef LNN_NEURAL_NETWORK_H
#define LNN_NEURAL_NETWORK_H

#include <iostream>
#include <json.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "Neuron.h"

using json = nlohmann::json;
using namespace std;

class NeuralNetwork {
public:
	NeuralNetwork(string modelPath);

private:
	json model;
	//Neuron* ns;
	vector<vector<Neuron*> > neurons;

private:
	void add_constant_weight_neuron(vector<Neuron*>& layer_neurons, unsigned int n_inputs, double value);
	void add_normal_weight_neuron(vector<Neuron*>& layer_neurons, unsigned int n_inputs, double mean, double deviation, default_random_engine& randEngine);
};

#endif