#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double *data; // Stored row-major
} Matrix;

// Allocation
Matrix matCreate(int rows, int cols);
void matFree(Matrix *m);

// Access
double matGet(Matrix *m, int row, int col);
void matSet(Matrix *m, int row, int col, double value);

// Operations
Matrix matDot(Matrix *a, Matrix *b);             // Matrix multiplication
void matAdd(Matrix *a, Matrix *b);               // Element-wise addition
void matApply(Matrix *m, double (*func)(double)); // Apply function to each element
void matFill(Matrix *m, double value);
void matPrint(Matrix *m);                         // For debugging

#endif
