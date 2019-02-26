# UlarTangga01
Project grafkom-ibnu, berupa program ular tangga 3D

> Code berikut digunakan untuk memenuhi projek Mata kuliah Grafika Komputer kelas C, yang diampu oleh Bapak [YONATHAN FERRY HENDRAWAN](https://forlap.ristekdikti.go.id/dosen/detail/NUJEMEU5MDItODgyNi00MUIzLUJCOEEtMTQyMjcwODE1MjRE)

## Environment

* C++
* OpenGL

## Fitur-Fitur yang tersedia
*Juga merupakan kriteria penilaian*

### Demo ke 2

1. Petak dan pagar ular tangga, yang berupa obyek 2 dimensi di demo 2, dibuat menjadi 3 dimensi. Ukuran ular tangga (berapa petak x petak) tetap mengikuti sistem demo 2. 
2. Angka NRP diubah menjadi obyek 3 dimensi. Angka yang ditampilkan tetap mengikuti sistem demo 2. 
3. Ular dan tangga diubah menjadi obyek 3 dimensi. 
4. Ular harus memiliki minimal 1 sisi miring. 
5. Bentuk ujung tangga dan ular terserah: boleh siku, boleh sejajar sumbu koordinat. Ujung anak tangga harus menyentuh ibu tangga. Anak tangga siku dengan ibu tangga. 
6. Ular tidak boleh hasil transformasi. Hanya tangga yang boleh transformasi. 
7. Buat 2 mode view: orthogonal dan isometric. 
8. Pada mode isometric saja, papan ular tangga dapat dirotasi pada sumbunya menggunakan tombol j, k, l, i atau J, K, L, I. Sudut perputaran tetap tersimpan ketika terjadi perpindahan mode tampilan. 
9. Pada mode isometric, petak/kotak/cell dibuat menjadi transparan. Pada mode orthogonal, tidak transparan. 
10. Buat sebuah obyek observer yang dapat digerakkan ke kanan-kiri, atas-bawah menggunakan tombol: a, s, d, w atau A, S, D, W. 
11. Posisi awal objek observer ada di sebelah kiri 2 obyek player. 
12. Obyek observer dibuat sedemikian rupa sehingga tidak dapat keluar dari area papan ular tangga. 

### Demo ke 3

**Animasi:**
1. Pada mode view kedua, obyek observer berotasi pada sumbu x, y, z sesuai penekanan tombol mouse kiri, tengah, dan kanan. (10)
2. Animasi mulai di mode 2, dan berhenti di mode 1 dan 3 (3)
3. Klik tombol mouse meneruskan rotasi dari sudut terakhir (5)

**Shading:**
1. Buat sumber cahaya Ambient, Diffuse, Specular. 1 ambience, 1 light untuk diffuse, 1 light untuk specular. (5)
2. Semua bidang diberi vektor normalnya:

    Hanya balok yang sejajar sumbu koordinat atau menggunakan glRotate (10)
    Semua balok ular termasuk yang tidak sejajar sumbu koordinat: dihitung secara manual (15)

**Material Obyek:**

1. Menggunakan glColorMaterial (5)
2. Setiap obyek diatur materialnya satu per satu (7)
3. Penekanan tombol 1 akan men-On/Off Ambient light. Penekanan tombol 2 akan men-On/Off Diffuse light. Penekanan tombol 3 akan men-On/Off Specular light. (5)
4. Harus menggunakan GL_FRONT (--pada semua glMaterialfv(GL_FRONT, tipe, array) bagi yang menggunakan material; atau glColorMaterial(GL_FRONT, mode) bagi yang menggunakan glColorMaterial()--) dan shading semua obyek berjalan dengan benar (10)

**Viewing:**
1. Ada mode view ketiga ketika tombol v ditekan: dari sudut pandang kamera. Proyeksi mode 3 harus perspective, mode 1 dan 2 harus ortho  (15)
2. Pada mode view ketiga, semua obyek NRP dirotasi 90 derajat sehingga tampak berdiri tegak lurus terhadap dasar papan ular tangga. (10)
3. Pada mode view ketiga, obyek player harus dirotasi juga supaya tampak tegak lurus terhadap dasar papan ular tangga. (5)
4. Berjalan di dalam lingkungan maze. Navigasi menggunakan tombol panah: atas, bawah, kiri, kanan (10)
