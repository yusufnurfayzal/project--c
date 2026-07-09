const http = require("http");

const PORT = 3000;

function layout(title, content) {
  return `
  <!DOCTYPE html>
  <html lang="id">
  <head>
    <meta charset="UTF-8" />
    <title>${title} - Informasi Kampus</title>
    <style>
      body {
        font-family: Arial, sans-serif;
        max-width: 700px;
        margin: 40px auto;
        padding: 0 20px;
        color: #222;
        background: #f7f7fb;
      }
      header {
        background: #1e3a8a;
        color: #fff;
        padding: 16px 24px;
        border-radius: 8px;
        margin-bottom: 24px;
      }
      nav a {
        color: #fff;
        margin-right: 14px;
        text-decoration: none;
        font-size: 14px;
      }
      nav a:hover { text-decoration: underline; }
      h1 { color: #1e3a8a; }
      .card {
        background: #fff;
        padding: 20px 24px;
        border-radius: 8px;
        box-shadow: 0 1px 4px rgba(0,0,0,0.08);
      }
      footer {
        margin-top: 24px;
        font-size: 12px;
        color: #777;
        text-align: center;
      }
    </style>
  </head>
  <body>
    <header>
      <nav>
        <a href="/">Beranda</a>
        <a href="/profil">Profil</a>
        <a href="/jurusan">Jurusan</a>
        <a href="/fasilitas">Fasilitas</a>
        <a href="/kontak">Kontak</a>
      </nav>
    </header>
    <div class="card">
      ${content}
    </div>
    <footer>&copy; 2026 Server Informasi Kampus - Praktikum Node.js</footer>
  </body>
  </html>
  `;
}

const routes = {
  "/": {
    title: "Beranda",
    status: 200,
    content: `
      <h1>Selamat Datang di Sistem Informasi Kampus</h1>
      <p>Website ini dibangun menggunakan <strong>Node.js</strong> (modul <code>http</code> bawaan)
      sebagai contoh implementasi backend sederhana.</p>
      <p>Gunakan menu di atas untuk menjelajahi halaman: Profil, Jurusan, Fasilitas, dan Kontak.</p>
    `,
  },
  "/profil": {
    title: "Profil Kampus",
    status: 200,
    content: `
      <h1>Profil Kampus</h1>
      <p><strong>Nama Kampus:</strong> Universitas Contoh</p>
      <p><strong>Berdiri sejak:</strong> 1999</p>
      <p><strong>Alamat:</strong> Jl. Pendidikan No. 10, Tangerang, Banten</p>
      <p><strong>Visi:</strong> Menjadi universitas unggul berbasis teknologi.</p>
    `,
  },
  "/jurusan": {
    title: "Daftar Jurusan",
    status: 200,
    content: `
      <h1>Daftar Jurusan</h1>
      <ul>
        <li>Teknik Informatika</li>
        <li>Sistem Informasi</li>
        <li>Manajemen Bisnis</li>
        <li>Desain Komunikasi Visual</li>
      </ul>
    `,
  },
  "/fasilitas": {
    title: "Fasilitas",
    status: 200,
    content: `
      <h1>Fasilitas Kampus</h1>
      <ul>
        <li>Laboratorium Komputer</li>
        <li>Perpustakaan Digital</li>
        <li>Ruang Seminar</li>
        <li>Wi-Fi Kampus 24 Jam</li>
        <li>Lapangan Olahraga</li>
      </ul>
    `,
  },
  "/kontak": {
    title: "Kontak",
    status: 200,
    content: `
      <h1>Kontak Kami</h1>
      <p><strong>Email:</strong> info@universitascontoh.ac.id</p>
      <p><strong>Telepon:</strong> (021) 1234-5678</p>
      <p><strong>Alamat:</strong> Jl. Pendidikan No. 10, Tangerang, Banten</p>
    `,
  },
};

const server = http.createServer((req, res) => {
  const { method, url } = req;

  res.setHeader("Content-Type", "text/html; charset=utf-8");

  if (method !== "GET") {
    res.statusCode = 405;
    res.end(layout("Method Tidak Diizinkan", `
      <h1>405 - Method Tidak Diizinkan</h1>
      <p>Server ini hanya mendukung method GET.</p>
      <a href="/">← Kembali ke Beranda</a>
    `));
    return;
  }

  const route = routes[url];

  if (route) {
    res.statusCode = route.status; 
    res.end(layout(route.title, route.content));
  } else {
    res.statusCode = 404; 
    res.end(layout("404 Tidak Ditemukan", `
      <h1>404 - Halaman Tidak Ditemukan</h1>
      <p>Maaf, halaman "${url}" tidak tersedia di server ini.</p>
      <a href="/">← Kembali ke Beranda</a>
    `));
  }
});

server.listen(PORT, () => {
  console.log(`Server Informasi Kampus berjalan di http://localhost:${PORT}`);
});
