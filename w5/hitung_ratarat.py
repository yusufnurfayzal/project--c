# ======================================================
# PROGRAM HITUNG RATA-RATA NILAI
# Bahasa : Python
# Fungsi : Menghitung total dan rata-rata nilai
# ======================================================

# Tampilan Judul Program
print("=" * 55)
print("           PROGRAM HITUNG RATA-RATA")
print("=" * 55)

# Input jumlah data
jumlah_data = int(input("Masukkan jumlah nilai yang ingin dihitung : "))

# Variabel untuk menyimpan total nilai
total_nilai = 0

print("-" * 55)

# Perulangan input nilai
for i in range(1, jumlah_data + 1):
    nilai = float(input(f"Masukkan nilai ke-{i} : "))
    
    # Menambahkan nilai ke total
    total_nilai += nilai

print("-" * 55)

# Menghitung rata-rata
rata_rata = total_nilai / jumlah_data

# Menampilkan hasil
print("                 HASIL PERHITUNGAN")
print("-" * 55)
print(f"Jumlah Data Nilai : {jumlah_data}")
print(f"Total Semua Nilai : {total_nilai}")
print(f"Rata-rata Nilai   : {rata_rata:.2f}")

print("-" * 55)

# Menentukan kategori nilai
if rata_rata >= 90:
    print("Kategori Nilai    : Sangat Baik")
elif rata_rata >= 75:
    print("Kategori Nilai    : Baik")
elif rata_rata >= 60:
    print("Kategori Nilai    : Cukup")
else:
    print("Kategori Nilai    : Kurang")

print("=" * 55)
print("         PROGRAM SELESAI DIJALANKAN")
print("=" * 55)