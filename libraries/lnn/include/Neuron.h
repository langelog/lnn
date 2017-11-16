#ifndef LNN_NEURON_H
#define LNN_NEURON_H

#include <iostream>

#include <json.hpp>

#include "NeuronInitializer.h"

using namespace std;

namespace ActivationFunctions {
    double fast_sigmoid(double x);
    double reverse_fast_sigmoid(double x);

    double no_activation(double x);
}

class Neuron {
public:
	Neuron(
		unsigned int   n_inputs,
		double       (*activationFn)(double),
		double       (*reverseFn)(double),
		Initializer    neuronIniter);

	~Neuron();

	double evaluate(double* inputs);

private:
	unsigned int  n_inputs;
	double*       weights;

private:
	void          initialize(Initializer neuronIniter);
	double       (*activationFn)(double);
	double       (*reverseFn)(double);
};

#endif
