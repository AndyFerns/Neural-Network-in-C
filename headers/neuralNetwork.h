#ifndef neuralNetwork_H
#define neuralNetwork_H

// Layer struct
typedef struct Layer{
    int input_size;
    int output_size;
    double **weights;
    double *biases;
    double *outputs;
    double *deltas;
} Layer; 

// Neural network struct
typedef struct Network {
    Layer *layers;
    int num_layers; 
} Network;

// Network constructor
Network createNetwork(int input_size, int *hidden_sizes, int num_hidden, int output_sizes);
// Network Mem Free
void freeNetwork(Network *net); 
// FW chaining
void forward(Network* net, double *input); 
// Backward chaining
void backward(Network *net, double *input, double *target, double learning_rate); 
double meanSquaredError(double *output, double *target, int size);
Layer createLayer(int input_size, int output_size);

#endif