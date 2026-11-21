#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *in = fopen("test2.txt", "r");
    if (in == NULL) {
        printf("Ошибка открытия входного файла!\n");
        return 1;
    }

    int n, m;
    do {
        printf("Введите количество строк N: ");
        scanf("%i", &n);
        if (n <= 1 || n > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (n <= 1 || n > 100);

    do {
        printf("Введите количество столбцов M: ");
        scanf("%i", &m);
        if (m <= 1 || m > 100) {
            printf("Ошибка! M должно быть больше 1 и не больше 100.\n");
        }
    } while (m <= 1 || m > 100);

    int **A = NULL;
    Create(&A, n, m);
    Vvod(in, A, n, m);

    int i = 0;
    int fl = 1;
    while (i < n && fl) {
        if (est_otr(A[i], m) == 1) {
            fl = 0;
        } else {
            i += 1;
        }
    }

    FILE *out = fopen("output.txt", "w");
    Vivod(out, A, n, m);

    if (fl == 0) {
        fprintf(out, "В массиве есть строка, содержащая отрицательный элемент.\n");
        fprintf(out, "Номер строки: %i (индекс в массиве: %i)\n", i + 1, i);
    } else {
        fprintf(out, "В массиве нет строк, содержащих отрицательный элемент.\n");
    }

    fclose(in);
    fclose(out);

    printf("Результат успешно записан в output.txt!\n");
    Ochistka(&A, n);

    return 0;
}
