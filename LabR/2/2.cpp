/* Моя первая программа на Си */
#include <stdio.h>
int main() {
    int x;
    float y, z;
    printf("Введите значение переменной x: ");
    scanf("%d", &x);
    printf("Введите значение переменной y: ");
    scanf("%f", &y);
    z = x + y;
    printf("Сумма введенных переменных = %7.3f\n", z);
    z = x * y;
    printf("Произведение введенных переменных = %7.3f\n", z);
    return 0;
}
