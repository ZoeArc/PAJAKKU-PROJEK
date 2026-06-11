# 🚗 PAJAKKU — Sistem Pembayaran Pajak Kendaraan

![C](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue?style=flat-square&logo=c)
![Platform](https://img.shields.io/badge/Platform-CLI%20%2F%20Terminal-black?style=flat-square&logo=gnometerminal)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow?style=flat-square)

**PAJAKKU** adalah sistem informasi yang dirancang untuk memudahkan pengelolaan dan pembayaran pajak kendaraan bermotor.

---

## 📋 Daftar Isi

- [Fitur Utama](#-fitur-utama)
- [Struktur Program](#-struktur-program)
- [Persyaratan Sistem](#-persyaratan-sistem)
- [Instalasi & Menjalankan Program](#-instalasi--menjalankan-program)
- [Cara Penggunaan](#-cara-penggunaan)
- [Tim Pengembang](#-tim-pengembang)

---

## ✨ Fitur Utama

### 🔐 Autentikasi
- Registrasi akun dengan validasi username dan password
- Login untuk Admin dan Pengguna
- Opsi keluar dari program

### 🛠️ Admin
| Fitur | Keterangan |
|---|---|
| Dashboard | Statistik total kendaraan, pemilik, transaksi, dan pendapatan pajak |
| Manajemen Kendaraan | Tambah, edit, hapus, dan lihat data kendaraan |
| Manajemen Pembayaran | Validasi, lihat, dan riwayat pembayaran |
| Laporan Pajak | Laporan kendaraan aktif, pajak dibayar, dan kendaraan menunggak |

### 👤 Pengguna
| Fitur | Keterangan |
|---|---|
| Beranda | Lihat, cari, dan urutkan daftar kendaraan |
| Data Kendaraan | Kelola data kendaraan milik pengguna |
| Pembayaran Pajak | Hitung total, denda, dan konfirmasi bayar |
| Perhitungan Denda | Hitung denda berdasarkan lama keterlambatan |
| Riwayat Pembayaran | Lihat riwayat transaksi dan detail pembayaran |
| Pencarian Data | Cari kendaraan berdasarkan nomor plat atau nama pemilik |

---

## 📂 Struktur Program

```
LOGIN
├── DAFTAR         → Registrasi akun baru
├── MASUK          → Login ke sistem
└── EXIT           → Keluar program

ADMIN
├── Dashboard Admin
├── Manajemen Kendaraan
├── Manajemen Pembayaran
├── Laporan Pajak
└── Logout

PENGGUNA
├── Beranda
├── Data Kendaraan
├── Pembayaran Pajak
├── Perhitungan Denda
├── Riwayat Pembayaran
├── Pencarian Data
└── Logout
```

---

## 💻 Persyaratan Sistem

- Sistem operasi: Windows / Linux / macOS
- Compiler: `g++` (GCC versi 7.0 ke atas) atau `MinGW` untuk Windows
- Terminal / Command Prompt

---

## 🚀 Instalasi & Menjalankan Program

### 1. Clone Repository

```bash
git clone https://github.com/ZoeArc/PAJAKKU-PROJEK.git
cd PAJAKKU-PROJEK
```

### 2. Kompilasi Program

```bash
g++ main.cpp -o Pajakku.exe
```

### 3. Jalankan Program

```bash
Pajakku.exe
```

---

## 📖 Cara Penggunaan

### Akun Default Admin
```
Username : admin
Password : 12345678
```

### Alur Penggunaan Pengguna Baru
1. Jalankan program
2. Pilih **`[2] Daftar`** untuk membuat akun
3. Masukkan username dan password
4. Konfirmasi password
5. Login menggunakan akun yang baru dibuat
6. Navigasi menu sesuai kebutuhan

### Alur Pembayaran Pajak
1. Login sebagai **Pengguna**
2. Masuk ke menu **Pembayaran Pajak**
3. Pilih kendaraan yang ingin dibayarkan pajaknya
4. Sistem menampilkan pajak pokok dan denda keterlambatan (jika ada)
5. Konfirmasi pembayaran
6. Cek riwayat di menu **Riwayat Pembayaran**

---

## 👥 Tim Pengembang

| No | Nama | NIM | Peran |
|---|---|---|---|
| 1 | Muhamad Alfian Maulana | F1D02510077 | Ketua |
| 2 | Asmaul Husna | F1D02510106 | Anggota |
| 3 | Wildan Afandika | F1D02510141 | Anggota |
| 4 | Lalu Helmi Firdaus | F1D02510119 | Anggota |
| 5 | Tiha Karyati | F1D02510028 | Anggota |
| 6 | Heni Patun Pidani | F1D02510009 | Anggota |
| 7 | Edgar Dave Aipassa | F1D02510111 | Anggota |

---
