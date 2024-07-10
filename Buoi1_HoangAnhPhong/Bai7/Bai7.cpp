#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int root = (int)sqrt(num);
    return root * root == num;
}

void inputArray(int* arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf_s("%d", &arr[i]);
    }
}

void outputArray(int* arr, int size) {
    printf("Mang hien tai: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findMaxElement(int* arr, int size) {
    int* max = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }
    printf("Phan tu lon nhat la %d tai dia chi %p\n", *max, max);
}

void findEvenOddElements(int* arr, int size) {
    int* maxEven = NULL;
    int* minOdd = NULL;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            if (maxEven == NULL || arr[i] > *maxEven) {
                maxEven = &arr[i];
            }
        }
        else {
            if (minOdd == NULL || arr[i] < *minOdd) {
                minOdd = &arr[i];
            }
        }
    }

    if (maxEven != NULL) {
        printf("Phan tu chan lon nhat tai dia chi %p\n", maxEven);
    }
    else {
        printf("Khong co phan tu chan trong mang\n");
    }

    if (minOdd != NULL) {
        printf("Phan tu le nho nhat tai dia chi %p\n", minOdd);
    }
    else {
        printf("Khong co phan tu le trong mang\n");
    }
}

int removeZeros(int* arr, int size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

int addElementAfterFirst(int* arr, int size, int x) {
    if (size == 0) {
        arr[0] = x;
        return 1;
    }

    for (int i = size; i > 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[1] = x;
    return size + 1;
}

int sumPerfectSquares(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (isPerfectSquare(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

void findLocalMaxima(int* arr, int size) {
    printf("Cac so cuc dai trong mang: ");
    for (int i = 0; i < size; i++) {
        if ((i == 0 && arr[i] > arr[i + 1]) ||
            (i == size - 1 && arr[i] > arr[i - 1]) ||
            (i > 0 && i < size - 1 && arr[i] > arr[i - 1] && arr[i] > arr[i + 1])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, x;
    printf("Nhap kich thuoc cua mang: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    inputArray(arr, n);
    outputArray(arr, n);

    findMaxElement(arr, n);

    findEvenOddElements(arr, n);

    n = removeZeros(arr, n);
    printf("Mang sau khi xoa cac phan tu co gia tri 0: ");
    outputArray(arr, n);

    printf("Nhap gia tri can them vao sau phan tu dau tien: ");
    scanf_s("%d", &x);
    n = addElementAfterFirst(arr, n, x);
    outputArray(arr, n);

    int sum = sumPerfectSquares(arr, n);
    printf("Tong cac phan tu la so chinh phuong: %d\n", sum);

    findLocalMaxima(arr, n);

    free(arr);
    return 0;
}
