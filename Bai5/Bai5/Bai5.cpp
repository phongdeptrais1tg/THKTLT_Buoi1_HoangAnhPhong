#include <stdio.h>

int main() {
    int a, b, c;
    printf("Nhap 3 so nguyen a, b, c: ");
    scanf_s("%d %d %d", &a, &b, &c);

   
        double result = (double)c / (a - b);
        printf("Ket qua cua c/(a-b) la: %lf\n", result);
    

    return 0;
}
