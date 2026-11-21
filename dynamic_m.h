#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void Create(int ***x, int n, int m);
void Vvod(FILE *in, int **x, int n, int m);
void Vivod(FILE *out, int **x, int n, int m);
int est_otr(int *str, int m);
void Ochistka(int ***x, int n);

#endif
