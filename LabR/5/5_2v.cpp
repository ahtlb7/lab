/* 5. Вариант с динамическим заполнением + указателями (C)
 Если хочешь показать навыки работы с указателями и генерацией массива:*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int D = 17; // дата рождения
    int rows = (D % 2 == 0) ? 5 : 4;
    int cols = (D % 2 == 0) ? 4 : 5;
    int find_min = (D % 2 == 0); // 1 если чётное → ищем min, иначе max

    int banned1 = (D % 2 == 0) ? 2 : 3;
    int banned2 = (D % 2 == 0) ? 8 : 7;

    int size = rows * cols;
    int *arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    /* Заполнение натуральными числами 1..99, пропуская запрещённые */
    for (int k = 0; k < size; k++) {
        int val;
        do {
            val = 1 + rand() % 99;
        } while (val == banned1 || val == banned2);
        arr[k] = val;
    }

    /* Поиск */
    int best_val = arr[0];
    int best_index = 0;
    for (int k = 1; k < size; k++) {
        int val = arr[k];
        if (val == banned1 || val == banned2) continue; // перестраховка
        if (find_min) {
            if (val < best_val) {
                best_val = val;
                best_index = k;
            }
        } else {
            if (val > best_val) {
                best_val = val;
                best_index = k;
            }
        }
    }

    /* Преобразование индекса в координаты */
    int best_i = best_index / cols;
    int best_j = best_index % cols;

    /* Вывод таблицы */
    printf("Массив (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", arr[i * cols + j]);
        printf("\n");
    }

    if (find_min)
        printf("\nМинимальный элемент = %d (i=%d, j=%d)\n", best_val, best_i, best_j);
    else
        printf("\nМаксимальный элемент = %d (i=%d, j=%d)\n", best_val, best_i, best_j);

    free(arr);
    return 0;
}
