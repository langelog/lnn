#include "NeuronInitializer.h"

void Initializators::ConstantInitializer(double *weigths, unsigned int n_values, double value) {
    for(unsigned int i=0; i<n_values; i++) {
        weigths[i] = value;
    }
}

void Initializators::NormalDistributionInitializer(double *weights, unsigned int n_values, std::__1::default_random_engine &randEngine, double mean, double dev) {

    std::normal_distribution<double> dist(mean,dev);
    for(unsigned int i=0; i<n_values; i++) {
        double val = dist(randEngine);
        std::cout << "Value: " << val << std::endl;
        weights[i] = val;
    }
}

void** Initializators::ConstantParamsGen(double value) {
    void **vals;
    double* val = new double;
    *val = value;
    vals = new void*[1];
    vals[0] = (void*)val;
    return vals;
}

void** Initializators::GaussParamsGen(std::__1::default_random_engine &randEngine, double mean, double dev) {
    void **vals;
    double* val_mean = new double;
    double* val_dev  = new double;
    *val_mean = mean;
    *val_dev  = dev;
    vals = new void*[3];
    vals[0] = (void*)&randEngine;
    vals[1] = (void*)val_mean;
    vals[2] = (void*)val_dev;
    return vals;
}

Initializer NeuronInitializer::ConstantInitializer(double value) {
	Initializer initer;
	initer.init                  = Initializators::Constant;
	initer.initializatorFunction = (void*)&Initializators::ConstantInitializer;
	initer.vals                  = Initializators::ConstantParamsGen(value);
	return initer;
}

Initializer NeuronInitializer::NormalInitializer(default_random_engine& randEngine, double mean, double deviation) {
	Initializer initer;
	initer.init                  = Initializators::Gauss;
	initer.initializatorFunction = (void*)&Initializators::NormalDistributionInitializer;
	initer.vals                  = Initializators::GaussParamsGen(randEngine, mean, deviation);
	return initer;
}

