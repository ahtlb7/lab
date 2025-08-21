#include <stdio.h>

/* Функция для вычисления результата */
int calculate(int day, int month) {
    if (day % 2 == 0) {
        return day / month; // Если день чётный — деление
    } else {
        return day * month; // Если день нечётный — умножение
    }
}

int main() {
    int day = 17;  // Дата рождения
    int month = 5; // Месяц рождения

    int result = calculate(day, month);

    printf("День: %d, Месяц: %d\n", day, month);
    printf("Результат: %d\n", result);

    return 0;
}
