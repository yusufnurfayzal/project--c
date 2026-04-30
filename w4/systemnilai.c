#include <stdio.h>

int main() {

    int nilai[5];
    int total = 0;
    float rata;
    int jumlah = 5;

    // Input nilai
    for(int i = 0; i < jumlah; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
        total += nilai[i];
    }

    // Hitung rata-rata
    rata = total / (float)jumlah;

    // Output hasil
    printf("\nTotal nilai: %d\n", total);
    printf("Rata-rata: %.2f\n", rata);

    return 0;
}
