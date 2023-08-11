#include "neuron.h"

double frand(){
    return 2*(double)rand()/RAND_MAX - 1.0;
}

Perceptron::Perceptron(int inputs, double bias){
    this->bias = bias;
    weights.resize(inputs+1);
    generate(weights.begin(),weights.end(),frand);

}

double Perceptron::run(vector<double>x){
    x.push_back(bias);
    double sum = inner_product(x.begin(),x.end(),weights.begin(),(double)0.0);
    return sigmoid(sum);
}

void Perceptron::set_weights(vector<double> w_init){
    weights = w_init;
}

double Perceptron::sigmoid(double sum){
    return 1.0/(exp(-sum)+1.0);
}


MultiLayerPerceptron::MultiLayerPerceptron(vector<int> layers, double bias, double eta){
    this->bias = bias;
    this->layers = layers;
    this->eta = eta;
    for (size_t i = 0; i < layers.size(); i++)
    {
        values.push_back(vector<double>(layers[i],0.0));
        network.push_back(vector<Perceptron>());

        //first layer is empty as it has no neurons

        if (i > 0){
            for (size_t j = 0; j < layers[i]; j++)
            {
                network[i].push_back(Perceptron(layers[i-1],bias));
            }
            
        }

    }

}

void MultiLayerPerceptron::print_weights(){

for (size_t i = 0; i < layers.size(); i++)
{
    for (size_t j = 0;j < layers[i]; j++)
    {
        cout << "Layer: ";
    }
    
}


}