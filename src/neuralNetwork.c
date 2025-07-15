#include <headers/neuralNetwork.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.c"

Layer createLayer(int input_size, int output_size) {
    Layer layer;
    layer.input_size = input_size;
    layer.output_size = output_size;

    layer.weights = malloc(output_size * sizeof(double*));
    for (int i = 0; i < output_size; i++) {
        layer.weights[i] = malloc(input_size * sizeof(double*));
        
        for (int j = 0; j < input_size; j++) {
            layer.weights[i][j] = randWeight();
        }
    }
    layer.biases = malloc(output_size * sizeof(double*));
    layer.outputs = malloc(output_size * sizeof(double*));
    layer.deltas = malloc(output_size * sizeof(double*));

    for (int i = 0; i < output_size; i++) {
        layer.biases[i] = randWeight(); 
    }
    return layer;
}

