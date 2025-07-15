#include <headers/neuralNetwork.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.c"

//Layer Constructor
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

// Network constructor
Network createNetwork(int input_size, int *hidden_sizes, int num_hidden, int output_size) {
    Network net;
    net.num_layers = num_hidden + 1;
    net.layers = malloc(net.num_layers * sizeof(Layer));

    int previous = input_size;
    for (int i = 0; i < num_hidden; i++) {
        net.layers[i] = createLayer(previous, hidden_sizes[i]);
        previous = hidden_sizes[i];
    }

    net.layers[num_hidden] = createLayer(previous, output_size);
    return net;
}

// neural network memory freeing 
void freeNetwork(Network *net) {
    for (int l = 0; l < net->num_layers; l++) {
        Layer layer = net->layers[l];
        for (int i = 0; i < layer.output_size; i++)
            free(layer.weights[i]);
        free(layer.weights);
        free(layer.biases);
        free(layer.outputs);
        free(layer.deltas);
    }
    free(net->layers);
}

// forward chaining for data-driven inference
void forward(Network *net, double *input) {
    double *in = input;

    for (int l = 0; l < net->num_layers; l++) {
        Layer *layer = &net->layers[l];
        for (int i = 0; i < layer->output_size; i++) {
            double sum = layer->biases[i];
            for (int j = 0; j < layer->input_size; j++)
                sum += layer->weights[i][j] * in[j];
            layer->outputs[i] = sigmoid(sum);
        }
        in = layer->outputs;
    }
}


// backward chaining for rule-based inference
void backward(Network *net, double *input, double *target, double lr) {
    // Output layer
    Layer *out = &net->layers[net->num_layers - 1];
    for (int i = 0; i < out->output_size; i++) {
        double o = out->outputs[i];
        out->deltas[i] = (o - target[i]) * o * (1 - o);
    }

    // Hidden layers
    for (int l = net->num_layers - 2; l >= 0; l--) {
        Layer *layer = &net->layers[l];
        Layer *next = &net->layers[l + 1];

        for (int i = 0; i < layer->output_size; i++) {
            double error = 0.0;
            for (int j = 0; j < next->output_size; j++)
                error += next->weights[j][i] * next->deltas[j];
            layer->deltas[i] = layer->outputs[i] * (1 - layer->outputs[i]) * error;
        }
    }
}