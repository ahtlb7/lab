#include <stdio.h>
#include <math.h>

int main() {
    int F = 17, n = 5;
    for (int x = -F; x <= F; x++) {
        double y = pow(x, n);
        printf("x = %d\t y = %.0f\n", x, y);
    }
    return 0;
}
