const biodata = {
  nama: "YUSUF NUR FAYZAL",
  nim: "2025806061",
  kelas: "SHIFT",
  jurusan: "Teknik Informatika",
  universitas: "Universitas Insan Pembangunan Indonesia",
  email: "yusufnurfayzal9@gmail.com",
  hobi: ["Coding", "Membaca", "Olahraga"],
};

console.log("=========================================");
console.log("           BIODATA MAHASISWA              ");
console.log("=========================================");
console.log(`Nama        : ${biodata.nama}`);
console.log(`NIM         : ${biodata.nim}`);
console.log(`Kelas       : ${biodata.kelas}`);
console.log(`Jurusan     : ${biodata.jurusan}`);
console.log(`Universitas : ${biodata.universitas}`);
console.log(`Email       : ${biodata.email}`);
console.log(`Hobi        : ${biodata.hobi.join(", ")}`);
console.log("=========================================");