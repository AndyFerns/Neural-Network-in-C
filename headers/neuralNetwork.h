#ifndef neuralNetwork_H
#define neuralNetwork_H

typedef struct Layer{
    int input_size;
    int output_size;
    double **weights;
    double *biases;
    double *outputs;
    double *deltas;
} Layer; 

#endif