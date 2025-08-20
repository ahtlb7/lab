#include <stdio.h>

int main() {
    int A = 2003, B = 4, C = 17;
    int M, mode;
    float X, K, Y;

    printf("Выберите режим (1 - целочисленная функция M, 2 - вещественная функция Y): ");
    scanf("%d", &mode);

    switch(mode) {
        case 1:
            M = A + B + C;
            printf("Результат M = %d\n", M);
            break;
        case 2:
            X = (float)C / B;
            K = (float)B / A;
            if (X != K) {
                Y = (X * K) / (X - K);
                printf("Результат Y = %.5f\n", Y);
            } else {
                printf("Ошибка: знаменатель выражения равен нулю.\n");
            }
            break;
        default:
            printf("Ошибка: выбран неверный режим.\n");
    }

    return 0;
}
