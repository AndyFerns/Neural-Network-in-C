#include <stdio.h>
#include <stdlib.h>
#include "../headers/neuralNetwork.h"

int main() {
    srand(42);

    int hidden[] = {2};
    Network net = createNetwork(2, hidden, 1, 1);

    // training on XOR function (LESGOOOO)
    double inputs[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    double outputs[4][1] = {{0}, {1}, {1}, {0}};

    for (int epoch = 0; epoch < 10000; epoch++) {
        double loss = 0;
        for (int i = 0; i < 4; i++) {
            forward(&net, inputs[i]);
            loss += meanSquaredError(net.layers[net.num_layers - 1].outputs, outputs[i], 1);
            backward(&net, inputs[i], outputs[i], 0.5);
        }
        if (epoch % 1000 == 0)
            printf("Epoch %d, Loss = %f\n", epoch, loss);
    }

    printf("Testing:\n");
    for (int i = 0; i < 4; i++) {
        forward(&net, inputs[i]);
        printf("%d XOR %d = %f\n", (int)inputs[i][0], (int)inputs[i][1], net.layers[net.num_layers - 1].outputs[0]);
    }

    freeNetwork(&net);
    return 0;
}