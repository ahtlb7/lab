/* Лабораторная работа №5. Массивы и указатели.
   Вариант: дата рождения D = 17 (нечётная) → массив 4x5, ищем max, исключаем 3 и 7.
   (Замечание: в условии "5 столбцов и 4 строки" — воспринимаю как ROWS=4, COLS=5.) */

#include <stdio.h>

int main(void) {
    int D = 17;

    int rows, cols;
    int find_min = 0; /* 0 = ищем max, 1 = ищем min */

    if (D % 2 == 0) {
        rows = 5;  /* 5 строк */
        cols = 4;  /* 4 столбца */
        find_min = 1; /* ищем минимальный */
        /* запрещены 2 и 8 */
    } else {
        rows = 4;  /* 4 строки */
        cols = 5;  /* 5 столбцов */
        find_min = 0; /* ищем максимальный */
        /* запрещены 3 и 7 */
    }

    /* Для отчёта: зафиксируем массив вручную. Без чисел 3 и 7. */
    int a[4][5] = {
        {  1,  5,  9, 11,  2 },
        {  4,  6, 10, 12, 14 },
        { 15, 16, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    /* Если D чётное, массив размера 5x4 — в таком случае нужно изменить объявление.
       Для краткости здесь приведён нечётный вариант (4x5). */

    /* Поиск max или min */
    int best_val = a[0][0];
    int best_i = 0, best_j = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            /* Пропустить запрещённые (на всякий случай, если генерация) */
            if (D % 2 == 0) {
                if (a[i][j] == 2 || a[i][j] == 8) continue;
                if (find_min) {
                    if (a[i][j] < best_val) {
                        best_val = a[i][j];
                        best_i = i; best_j = j;
                    }
                } else {
                    if (a[i][j] > best_val) {
                        best_val = a[i][j];
                        best_i = i; best_j = j;
                    }
                }
            } else {
                if (a[i][j] == 3 || a[i][j] == 7) continue;
                if (find_min) {
                    if (a[i][j] < best_val) {
                        best_val = a[i][j];
                        best_i = i; best_j = j;
                    }
                } else {
                    if (a[i][j] > best_val) {
                        best_val = a[i][j];
                        best_i = i; best_j = j;
                    }
                }
            }
        }
    }

    /* Вывод массива */
    printf("Массив (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    if (find_min)
        printf("\nМинимальный допустимый элемент = %d (i=%d, j=%d)\n", best_val, best_i, best_j);
    else
        printf("\nМаксимальный допустимый элемент = %d (i=%d, j=%d)\n", best_val, best_i, best_j);

    return 0;
}
