#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int tu;
    int mau;
} PhanSo;


void nhapMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap tu va mau so cua phan so thu %d: ", i + 1);
        scanf_s("%d/%d", &arr[i].tu, &arr[i].mau);
        while (arr[i].mau == 0) {
            printf("Mau so khong duoc bang 0. Nhap lai mau so: ");
            scanf_s("%d", &arr[i].mau);
        }
    }
}


void xuatMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");
}


void xuatPhanSoMauLonHonTu(PhanSo* arr, int size) {
    printf("Cac phan so co mau > tu: ");
    for (int i = 0; i < size; i++) {
        if (arr[i].mau > arr[i].tu) {
            printf("%d/%d ", arr[i].tu, arr[i].mau);
        }
    }
    printf("\n");
}


int demPhanSoChan(PhanSo* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}


int uscln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void rutGonPhanSo(PhanSo* ps) {
    int gcd = uscln(abs(ps->tu), abs(ps->mau));
    ps->tu /= gcd;
    ps->mau /= gcd;
}


void rutGonMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        rutGonPhanSo(&arr[i]);
    }
}


PhanSo tichMangPhanSo(PhanSo* arr, int size) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < size; i++) {
        tich.tu *= arr[i].tu;
        tich.mau *= arr[i].mau;
    }
    rutGonPhanSo(&tich);
    return tich;
}


int soSanhPhanSo(PhanSo a, PhanSo b) {
    return a.tu * b.mau - b.tu * a.mau;
}


PhanSo timPhanSoLonNhat(PhanSo* arr, int size) {
    PhanSo max = arr[0];
    for (int i = 1; i < size; i++) {
        if (soSanhPhanSo(arr[i], max) > 0) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &n);

    PhanSo* arr = (PhanSo*)malloc(n * sizeof(PhanSo));

    
    nhapMangPhanSo(arr, n);
    printf("Mang phan so vua nhap: ");
    xuatMangPhanSo(arr, n);

    
    xuatPhanSoMauLonHonTu(arr, n);

    
    int soPhanSoChan = demPhanSoChan(arr, n);
    printf("So phan so co mau va tu deu chan: %d\n", soPhanSoChan);

    
    rutGonMangPhanSo(arr, n);
    printf("Mang phan so sau khi rut gon: ");
    xuatMangPhanSo(arr, n);

    
    PhanSo tich = tichMangPhanSo(arr, n);
    printf("Tich cua cac phan so trong mang: %d/%d\n", tich.tu, tich.mau);

    
    PhanSo max = timPhanSoLonNhat(arr, n);
    printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

    free(arr);
    return 0;
}
