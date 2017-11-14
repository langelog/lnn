#ifndef LNN_NEURAL_NETWORK_H
#define LNN_NEURAL_NETWORK_H

#include <iostream>
#include <json.hpp>
#include <string>
#include <fstream>

#include "Neuron.h"

using json = nlohmann::json;
using namespace std;

class NeuralNetwork {
public:
	NeuralNetwork(string modelPath);

private:
	json model;
	Neuron* ns;

};

#endif