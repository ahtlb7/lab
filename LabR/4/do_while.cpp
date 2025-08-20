#include <stdio.h>
#include <math.h>

int main() {
    int F = 17, n = 5, x = -F;
    do {
        double y = pow(x, n);
        printf("x = %d\t y = %.0f\n", x, y);
        x++;
    } while (x <= F);
    return 0;
}
