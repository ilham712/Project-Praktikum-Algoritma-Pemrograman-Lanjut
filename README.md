# 🎬 BIOSKOP XXI - Sistem Booking Tiket Film (C++)

## 📌 Deskripsi Project

Project ini merupakan program simulasi sistem booking tiket bioskop berbasis **C++** menggunakan konsep dasar hingga menengah pemrograman.

Program ini memungkinkan pengguna untuk:

* Melihat daftar film
* Booking tiket bioskop
* Memilih kursi
* Melakukan searching film
* Melakukan sorting film
* Menyimpan riwayat tiket
* Menyimpan data kursi menggunakan file handling

---

# ✨ Fitur Utama

✅ Menampilkan daftar film
✅ Booking tiket bioskop
✅ Pemilihan kursi bioskop
✅ Validasi kursi terisi
✅ Searching film berdasarkan:

* Judul Film (Sequential Search)
* Kode Film (Binary Search)

✅ Sorting film berdasarkan:

* Judul Film (Bubble Sort)
* Rating Film (Selection Sort)

✅ Penyimpanan data menggunakan file `.txt`
✅ Riwayat tiket bioskop
✅ Tampilan tabel terminal yang rapi

---

# 🧠 Konsep Pemrograman yang Digunakan

Project ini menerapkan berbagai konsep penting dalam bahasa C++:

| Konsep             | Implementasi                      |
| ------------------ | --------------------------------- |
| Struct             | Data Film & Tiket                 |
| Nested Struct      | Struct Film di dalam Struct Tiket |
| Array Multidimensi | Sistem kursi bioskop              |
| Function           | Modular program                   |
| Rekursi            | Menu utama                        |
| Sequential Search  | Cari judul film                   |
| Binary Search      | Cari kode film                    |
| Bubble Sort        | Sorting judul                     |
| Selection Sort     | Sorting rating & kode             |
| File Handling      | Penyimpanan kursi & riwayat       |
| Pointer            | Penyimpanan data tiket            |

---

# 🏗️ Struktur Program

```bash
📂 Project Bioskop
 ┣ 📜 main.cpp
 ┣ 📜 kursi.txt
 ┣ 📜 riwayat_tiket.txt
 ┗ 📜 README.md
```

---

# 🎞️ Daftar Film

| Judul Film        | Genre          | Rating |
| ----------------- | -------------- | ------ |
| Avengers          | Action         | 9.0    |
| Interstellar      | Sci-Fi         | 9.5    |
| Conjuring         | Horror         | 8.0    |
| Agak Laen         | Horror, Comedy | 7.2    |
| Pabrik Gula       | Horror         | 9.0    |
| Dilan 1990        | Romance        | 7.0    |
| Project Hail Mary | Sci-Fi         | 8.6    |
| Kuncen            | Horror         | 10.0   |
| Minions           | Komedi         | 9.2    |
| Aquaman           | Action         | 9.8    |

---

# 🖥️ Tampilan Program

## 📋 Menu Utama

```cpp
===== BIOSKOP XXI =====
1. Lihat Film
2. Booking Tiket Film
3. Cari Film
4. Sorting Film
5. Riwayat Tiket Film
6. Keluar
```

---

# 💾 File Handling

Program menggunakan file:

* `kursi.txt` → menyimpan data kursi yang sudah terisi
* `riwayat_tiket.txt` → menyimpan riwayat pembelian tiket

---

# 🚀 Cara Menjalankan Program

## Menggunakan Dev-C++

1. Buka file `.cpp`
2. Compile program
3. Jalankan program

## Menggunakan Terminal

```bash
g++ main.cpp -o bioskop
./bioskop
```

---

# 📚 Algoritma yang Digunakan

## 🔎 Searching

* Sequential Search
* Binary Search

## 🔃 Sorting

* Bubble Sort
* Selection Sort

---

# 👨‍💻 Author

**Ilham Cahyo Saputro (123250097)**

**Sekar Putri Santyaningrum (123250110)**

**Kelas Praktikum: IF-E**

Project dibuat untuk memenuhi project praktikum algoritma pemrograman lanjut.

---

# ⭐ Penutup

Project ini dibuat sebagai simulasi sederhana sistem booking tiket bioskop dengan penerapan berbagai algoritma dan konsep fundamental dalam C++.

Terima kasih telah mengunjungi repository ini 🙌
