#include "dynamic_m.h"
#include <malloc.h>

void Create(int ***x, int n, int m) {
    *x = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(m * sizeof(int));
    }
    return;
}

void Vvod(FILE *in, int **x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(in, "%i", &x[i][j]);
        }
    }
    return;
}

void Vivod(FILE *out, int **x, int n, int m) {
    fprintf(out, "==================================\n");
    fprintf(out, "Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%4i ", x[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

int est_otr(int *str, int m) {
    int j = 0;
    int fl = 1;
    while (j < m && fl) {
        if (str[j] < 0) {
            fl = 0;
        } else {
            j += 1;
        }
    }
    return !fl;
}

int poisk_str(int **x, int n, int m) {
    int i = 0;
    int fl = 1;
    while (i < n && fl) {
        if (est_otr(x[i], m) == 1) {
            fl = 0;
        } else {
            i += 1;
        }
    }
    return i;
}

void Ochistka(int ***x, int n) {
    for (int i = 0; i < n; i++) {
        free((*x)[i]);
    }
    free((*x));
    return;
}
