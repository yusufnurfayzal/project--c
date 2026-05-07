# ======================================================
# PROGRAM KONVERSI SUHU
# Bahasa : Python
# Fungsi : Mengubah satuan suhu
# ======================================================

# Fungsi konversi suhu
def celcius_ke_fahrenheit(c):
    return (c * 9/5) + 32

def celcius_ke_kelvin(c):
    return c + 273.15

def fahrenheit_ke_celcius(f):
    return (f - 32) * 5/9

def kelvin_ke_celcius(k):
    return k - 273.15


# Tampilan awal program
print("=" * 50)
print("         PROGRAM KONVERSI SUHU PYTHON")
print("=" * 50)

print("\nDaftar Menu Konversi Suhu")
print("1. Celcius → Fahrenheit")
print("2. Celcius → Kelvin")
print("3. Fahrenheit → Celcius")
print("4. Kelvin → Celcius")
print("5. Keluar")

print("-" * 50)

# Input pilihan user
pilihan = input("Masukkan pilihan menu (1/2/3/4/5): ")

print("-" * 50)

# Proses sesuai pilihan
if pilihan == "1":
    print("Konversi Celcius ke Fahrenheit")
    
    c = float(input("Masukkan suhu dalam Celcius : "))
    
    hasil = celcius_ke_fahrenheit(c)
    
    print(f"\nHasil Konversi :")
    print(f"{c}°C = {hasil:.2f}°F")

elif pilihan == "2":
    print("Konversi Celcius ke Kelvin")
    
    c = float(input("Masukkan suhu dalam Celcius : "))
    
    hasil = celcius_ke_kelvin(c)
    
    print(f"\nHasil Konversi :")
    print(f"{c}°C = {hasil:.2f} K")

elif pilihan == "3":
    print("Konversi Fahrenheit ke Celcius")
    
    f = float(input("Masukkan suhu dalam Fahrenheit : "))
    
    hasil = fahrenheit_ke_celcius(f)
    
    print(f"\nHasil Konversi :")
    print(f"{f}°F = {hasil:.2f}°C")

elif pilihan == "4":
    print("Konversi Kelvin ke Celcius")
    
    k = float(input("Masukkan suhu dalam Kelvin : "))
    
    hasil = kelvin_ke_celcius(k)
    
    print(f"\nHasil Konversi :")
    print(f"{k} K = {hasil:.2f}°C")

elif pilihan == "5":
    print("Program selesai. Terima kasih telah menggunakan program ini.")

else:
    print("ERROR : Pilihan menu tidak tersedia!")

print("=" * 50)
print("            PROGRAM TELAH SELESAI")
print("=" * 50)