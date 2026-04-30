#include <stdio.h>

// Fungsi untuk sorting (Bubble Sort sederhana)
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // tukar
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Masukkan jumlah data (N): ");
    scanf("%d", &n);

    int arr[n];

    // Input data
    printf("Masukkan %d bilangan:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // =====================
    // HITUNG MEAN
    // =====================
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float mean = sum / n;

    // =====================
    // SORTING UNTUK MEDIAN
    // =====================
    bubbleSort(arr, n);

    // =====================
    // HITUNG MEDIAN
    // =====================
    float median;
    if (n % 2 == 0) {
        median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        median = arr[n/2];
    }

    // =====================
    // HITUNG MODE
    // =====================
    int mode = arr[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    // =====================
    // OUTPUT
    // =====================
    printf("\nHasil:\n");
    printf("Mean   = %.2f\n", mean);
    printf("Median = %.2f\n", median);
    printf("Mode   = %d (muncul %d kali)\n", mode, maxCount);

    return 0;
}