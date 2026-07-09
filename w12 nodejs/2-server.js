const http = require("http");

const PORT = 3000;

const server = http.createServer((req, res) => {
  const { method, url } = req;

  res.setHeader("Content-Type", "text/html; charset=utf-8");

  if (method === "GET" && url === "/") {
    res.statusCode = 200; // OK
    res.end(`
      <h1>Selamat Datang di Praktikum Pemrograman Dasar</h1>
      <p>Silakan coba routing berikut:</p>
      <ul>
        <li><a href="/profil">/profil</a></li>
        <li><a href="/mata-kuliah">/mata-kuliah</a></li>
        <li><a href="/kontak">/kontak</a></li>
        <li><a href="/halaman-tidak-ada">/halaman-tidak-ada (contoh 404)</a></li>
      </ul>
    `);
  } else if (method === "GET" && url === "/profil") {
    res.statusCode = 200; // OK
    res.end(`
      <h1>Halaman Profil</h1>
      <p>Nama    : YUSUF NUR FAYZAL</p>
      <p>NIM     : 2025806061</p>
      <p>Jurusan : Teknik Informatika</p>
      <a href="/">← Kembali ke Beranda</a>
    `);
  } else if (method === "GET" && url === "/mata-kuliah") {
    res.statusCode = 200; 
    res.end(`
      <h1>Daftar Mata Kuliah</h1>
      <ul>
        <li>Pemrograman Dasar</li>
        <li>Struktur Data</li>
        <li>Basis Data</li>
        <li>Jaringan Komputer</li>
      </ul>
      <a href="/">← Kembali ke Beranda</a>
    `);
  } else if (method === "GET" && url === "/kontak") {
    res.statusCode = 200; // OK
    res.end(`
      <h1>Kontak</h1>
      <p>Email    : mahasiswa@example.com</p>
      <p>Telepon  : 0812-xxxx-xxxx</p>
      <a href="/">← Kembali ke Beranda</a>
    `);
  } else {
    res.statusCode = 404; 
    res.end(`
      <h1>404 - Halaman Tidak Ditemukan</h1>
      <p>Maaf, halaman "${url}" tidak tersedia di server ini.</p>
      <a href="/">← Kembali ke Beranda</a>
    `);
  }
});

server.listen(PORT, () => {
  console.log(`Server berjalan di http://localhost:${PORT}`);
});
