#include <math.h>
#include <stdlib.h>
#include "../headers/matrix.h"
#include <stdio.h>

// Matrix Allocation
Matrix matCreate(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(sizeof(double) * rows * cols);
    return m;
}
// matrix deallocation
void matFree(Matrix *m) {
    free(m->data);
    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
}

// matrix retrieval
double matGet(Matrix *m, int row, int col) {
    return m->data[row * m->cols + col];
}

// matrix value setter
void matSet(Matrix *m, int row, int col, double value) {
    m->data[row * m->cols + col] = value;
}

/* Matrix Arithmetics */

// addition
void matAdd(Matrix *a, Matrix *b) {
    for (int i = 0; i < a->rows * a->cols; i++)
        a->data[i] += b->data[i];
}

// dot product (scalar product)
Matrix matDot(Matrix *a, Matrix *b) {
    Matrix result = matCreate(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; k++) {
                sum += matGet(a, i, k) * matGet(b, k, j);
            }
            matSet(&result, i, j, sum);
        }
    }
    return result;
}

// apply function to each element
void matApply(Matrix *m, double (*func)(double)) {
    for (int i = 0; i < m->rows * m->cols; i++)
        m->data[i] = func(m->data[i]);
}


void matFill(Matrix *m, double value) {
    for (int i = 0; i < m->rows * m->cols; i++)
        m->data[i] = value;
}

// matrix display
void matPrint(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%6.2f ", matGet(m, i, j));
        }
        printf("\n");
    }
}
