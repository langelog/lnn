#ifndef LNN_NEURON_INITIALIZER_H
#define LNN_NEURON_INITIALIZER_H

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

namespace Initializators {
    typedef enum{
        Constant,
        Gauss
    } InitializatorType;

    void   ConstantInitializer(double* weigths, unsigned int n_values, double value);
    void** ConstantParamsGen(double value);

    void   NormalDistributionInitializer(double* weights, unsigned int n_values, std::default_random_engine& randEngine, double mean, double dev);
    void** GaussParamsGen(std::default_random_engine& randEngine, double mean=0.0, double dev=1.0);

}

typedef struct {
	Initializators::InitializatorType   init;
    void                               *initializatorFunction;
    void                              **vals;
} Initializer;

class NeuronInitializer {
public:
	static Initializer ConstantInitializer(double value);
	static Initializer NormalInitializer(default_random_engine& randEngine, double mean=0.0, double deviation=1.0);
};


#endif