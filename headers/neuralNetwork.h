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

// Network constructors
Network createNetwork(int input_size, int *hidden_sizes, int num_hidden, int output_sizes);
void freeNetwork(Network *net); // Network Mem Free
void forward(Network* net, double *input); // FW chaining
void backward(Network *net, double *input, double *target, double learning_rate); // Backward chaining
double meanSquaredError(double *output, double *target, int size);

#endif