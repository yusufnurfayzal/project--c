#include <stdio.h>
#include <stdlib.h>

// Struct karyawan
struct Karyawan {
    char nama[50];
    int umur;
    float gaji;
};

// Fungsi kategori gaji
char* kategoriGaji(float gaji) {
    if(gaji >= 10000000) return "Tinggi";
    else if(gaji >= 5000000) return "Sedang";
    else return "Rendah";
}

int main() {
    int n;

    printf("Masukkan jumlah karyawan: ");
    scanf("%d", &n);

    // Validasi
    if(n <= 0) {
        printf("Jumlah tidak valid!\n");
        return 0;
    }

    // Alokasi memori
    struct Karyawan *kar;
    kar = (struct Karyawan*) malloc(n * sizeof(struct Karyawan));

    // Input data
    for(int i = 0; i < n; i++) {
        printf("\nKaryawan ke-%d\n", i + 1);
        printf("Nama  : ");
        scanf(" %[^\n]", kar[i].nama);
        printf("Umur  : ");
        scanf("%d", &kar[i].umur);
        printf("Gaji  : ");
        scanf("%f", &kar[i].gaji);
    }

    // Inisialisasi statistik
    float totalGaji = 0;
    float maxGaji = kar[0].gaji;
    float minGaji = kar[0].gaji;
    int idxMax = 0, idxMin = 0;

    // Hitung statistik
    for(int i = 0; i < n; i++) {
        totalGaji += kar[i].gaji;

        if(kar[i].gaji > maxGaji) {
            maxGaji = kar[i].gaji;
            idxMax = i;
        }

        if(kar[i].gaji < minGaji) {
            minGaji = kar[i].gaji;
            idxMin = i;
        }
    }

    float rataGaji = totalGaji / n;

    // Tampilkan data
    printf("\n=== Data Karyawan ===\n");
    for(int i = 0; i < n; i++) {
        printf("%d. Nama : %s\n", i + 1, kar[i].nama);
        printf("   Umur : %d\n", kar[i].umur);
        printf("   Gaji : %.2f (%s)\n", kar[i].gaji, kategoriGaji(kar[i].gaji));
    }

    // Tampilkan statistik
    printf("\n=== Statistik ===\n");
    printf("Total gaji     : %.2f\n", totalGaji);
    printf("Rata-rata gaji : %.2f\n", rataGaji);
    printf("Gaji tertinggi : %.2f (%s)\n", maxGaji, kar[idxMax].nama);
    printf("Gaji terendah  : %.2f (%s)\n", minGaji, kar[idxMin].nama);

    // Free memory
    free(kar);

    return 0;
}