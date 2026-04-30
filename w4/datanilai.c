#include <stdio.h>
#include <stdlib.h>

// Struct mahasiswa
struct Mahasiswa {
    char nama[50];
    int nilai;
    char grade;
};

// Fungsi menentukan grade
char hitungGrade(int nilai) {
    if(nilai >= 85) return 'A';
    else if(nilai >= 70) return 'B';
    else if(nilai >= 60) return 'C';
    else if(nilai >= 50) return 'D';
    else return 'E';
}

int main() {
    int n;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Validasi
    if(n <= 0) {
        printf("Jumlah tidak valid!\n");
        return 0;
    }

    // Alokasi memori
    struct Mahasiswa *mhs;
    mhs = (struct Mahasiswa*) malloc(n * sizeof(struct Mahasiswa));

    // Input data
    for(int i = 0; i < n; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama  : ");
        scanf(" %[^\n]", mhs[i].nama);
        printf("Nilai : ");
        scanf("%d", &mhs[i].nilai);

        // Hitung grade
        mhs[i].grade = hitungGrade(mhs[i].nilai);
    }

    // Hitung statistik
    int total = 0;
    int max = mhs[0].nilai;
    int min = mhs[0].nilai;
    int idxMax = 0, idxMin = 0;

    for(int i = 0; i < n; i++) {
        total += mhs[i].nilai;

        if(mhs[i].nilai > max) {
            max = mhs[i].nilai;
            idxMax = i;
        }

        if(mhs[i].nilai < min) {
            min = mhs[i].nilai;
            idxMin = i;
        }
    }

    float rata = total / (float)n;

    // Output data
    printf("\n=== Data Mahasiswa ===\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s - %d (Grade %c)\n",
               i + 1,
               mhs[i].nama,
               mhs[i].nilai,
               mhs[i].grade);
    }

    // Statistik
    printf("\nRata-rata nilai : %.2f\n", rata);
    printf("Nilai tertinggi : %d (%s)\n", max, mhs[idxMax].nama);
    printf("Nilai terendah  : %d (%s)\n", min, mhs[idxMin].nama);

    // Free memory
    free(mhs);

    return 0;
}