# UlarTangga01
Project grafkom-ibnu, berupa program ular tangga 3D

> Code berikut digunakan untuk memenuhi projek Mata kuliah Grafika Komputer kelas C, yang diampu oleh Bapak [YONATHAN FERRY HENDRAWAN](https://forlap.ristekdikti.go.id/dosen/detail/NUJEMEU5MDItODgyNi00MUIzLUJCOEEtMTQyMjcwODE1MjRE)

## Environment

* C++
* OpenGL

## Fitur-Fitur yang tersedia
*Juga merupakan kriteria penilaian*

### Demo ke 2

1. Ukuran kotak ular tangga bergantung pada digit terakhir NRP: 
– Untuk NRP yang berakhiran 0: ukuran kotak 5 kolom x 17 baris. Total 85 kotak. 
– Untuk NRP yang berakhiran 1: ukuran kotak 17 kolom x 5 baris. Total 85 kotak. 
– Untuk NRP yang berakhiran 2: ukuran kotak 4 kolom x 21 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 3: ukuran kotak 21 kolom x 4 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 4: ukuran kotak 6 kolom x 14 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 5: ukuran kotak 14 kolom x 6 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 6: ukuran kotak 7 kolom x 12 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 7: ukuran kotak 12 kolom x 7 baris. Total 84 kotak. 
– Untuk NRP yang berakhiran 8: ukuran kotak 9 kolom x 9 baris. Total 81 kotak. 
– Untuk NRP yang berakhiran 9: ukuran kotak 8 kolom x 10 baris. Total 80 kotak.
2. Kotak diberi nomor sesuai kaidah permainan ular tangga. Tidak perlu membuat semua kotak bernomor. Hanya gunakan 3 digit terakhir NRP. 
3. Petak-petak harus dibuat keduanya dengan polygon/glRecti, bukan hanya satu warna petak saja. 
4. Pagar harus dibuat dengan polygon/glRecti. 
5. Terdapat minimal 3 tangga dan 3 ular. 
6. Panjang minimum tangga adalah 4 kotak dan terdiri dari tangga horisontal, vertikal, dan diagonal. 
7. Panjang minimum ular adalah 3 x 2 kotak dengan 3 bagian/segmen. 
8. Posisi tangga dan ular bebas. 
9. Anak tangga dibuat proporsional dan berjarak sama satu sama lainnya. 
10. Permainan dijalankan dengan menekan tombol spasi. Nilai dadu dirandom bergantian untuk player 1 dan player 2. Bidak dijalankan sesuai kaidah ular tangga. Bila bertemu tangga, player naik posisinya, bila bertemu ular, player turun posisinya. 
11. Bila posisi player sudah mencapai lebih dari sama dengan nilai maksimum kotak (misal >=84), player tersebut menang. 
12. Semua obyek dibuat menggunakan polygon. Tidak boleh ada yang menggunakan line.

### Demo ke 3

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

### Demo ke 4

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

## Note
> Untuk melihat versi Demo ke-n, silakan lihat history perubahan Code 
> Demo ke 1 merupakan projek berbeda, jadi tidak ditulis di sini
