#include "Neuron.h"

double ActivationFunctions::fast_sigmoid(double x) {
    return x/(1+abs(x));
}
double ActivationFunctions::reverse_fast_sigmoid(double x) {
    return (x>0)? (x/(x+1)) : (x/(1-x));
}
double ActivationFunctions::no_activation(double x) {
	return x;
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
	if(n_inputs == 0) // in case this is a bias neuron:
		return activationFn(weights[0]);
	for(unsigned int i=0; i<n_inputs; i++) {
		result += inputs[i]*weights[i];
	}
	return activationFn(result);
}

void Neuron::initialize(Initializer neuronIniter) {
	unsigned int n_in = (n_inputs==0)? 1 : n_inputs;
	weights = new double[n_in];
	switch(neuronIniter.init) {
	case Initializators::InitializatorType::Constant:
		//cout << "inicializando constante" << endl;
		((void (*)(double*,unsigned int,double))neuronIniter.initializatorFunction)(weights, n_in, *((double*)neuronIniter.vals[0]));
		break;
	case Initializators::InitializatorType::Gauss:
		//cout << "inicializando gauss" << endl;
		((void (*)(double*,unsigned int,std::default_random_engine&,double,double))neuronIniter.initializatorFunction)(weights, n_in, *((std::default_random_engine*)neuronIniter.vals[0]), *((double*)neuronIniter.vals[1]), *((double*)neuronIniter.vals[2]));
		break;
	}
}
