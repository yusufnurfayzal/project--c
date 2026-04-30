#include <stdio.h>

int main() {
    int angka[10];
    int terbesar;

    // Input data
    for(int i = 0; i < 10; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    // Inisialisasi nilai terbesar
    terbesar = angka[0];

    // Cari nilai terbesar
    for(int i = 1; i < 10; i++) {
        if(angka[i] > terbesar) {
            terbesar = angka[i];
        }
    }

    // Output hasil
    printf("\nNilai terbesar adalah: %d\n", terbesar);

    return 0;
}