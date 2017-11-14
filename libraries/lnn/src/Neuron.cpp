#include "Neuron.h"

double ActivationFunctions::fast_sigmoid(double x) {
    return x/(1+abs(x));
}
double ActivationFunctions::reverse_fast_sigmoid(double x) {
    return (x>0)? (x/(x+1)) : (x/(1-x));
}

Neuron::Neuron(
	unsigned int   n_inputs,
	double       (*activationFn)(double),
	double       (*reverseFn)(double),
	Initializer    neuronIniter) {

	this->n_inputs     = n_inputs;
	this->activationFn = activationFn;
	this->reverseFn    = reverseFn;

	initialize(neuronIniter);
}

Neuron::~Neuron() {

}

double Neuron::evaluate(double* inputs) {
	double result = 0.0;
	for(unsigned int i=0; i<n_inputs; i++) {
		result += inputs[i]*weights[i];
	}
	return result;//activationFn(result);
}

void Neuron::initialize(Initializer neuronIniter) {
	weights = new double[n_inputs];
	switch(neuronIniter.init) {
	case Initializators::InitializatorType::Constant:
		cout << "inicializando constante" << endl;
		((void (*)(double*,unsigned int,double))neuronIniter.initializatorFunction)(weights, n_inputs, *((double*)neuronIniter.vals[0]));
		break;
	case Initializators::InitializatorType::Gauss:
		cout << "inicializando gauss... not yet implemented" << endl;
		((void (*)(double*,unsigned int,std::default_random_engine&,double,double))neuronIniter.initializatorFunction)(weights, n_inputs, *((std::default_random_engine*)neuronIniter.vals[0]), *((double*)neuronIniter.vals[1]), *((double*)neuronIniter.vals[2]));
		break;
	}
}
