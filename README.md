# Doubly Linked List Mini Lab

Tugas Struktur Data: memahami perubahan Doubly Linked List saat node
di-insert, di-delete, dan di-traverse dua arah (forward dan backward).

## Tim

| Nama | GitHub | Role |
|------|--------|------|
| [Nayla Novtiera Anjani] | [@SHADE-commit] | Builder, Tester, Reviewer, Documenter |

Tim ini beranggotakan satu orang, sehingga semua peran dipegang sendiri.

## Cara Menjalankan

```bash
g++ src/main.cpp -o dll
./dll
```

Di Windows jalankan `dll.exe`.

## Konsep Singkat

```
NULL <- [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] -> NULL
```

- `next` dipakai untuk bergerak maju (forward traversal).
- `prev` dipakai untuk bergerak mundur (backward traversal).
- Saat insert/delete, pointer `prev` dan `next` node di sekitarnya
  harus diperbarui keduanya agar list tetap konsisten di dua arah.

## Isi Program (`src/main.cpp`)

| Task | Deskripsi |
|------|-----------|
| 1 | Struktur node: data, prev, next |
| 2 | Membuat list minimal 5 node (Song A - Song E) |
| 3 | Forward traversal |
| 4 | Backward traversal |
| 5 | Insert Song X di antara Song B dan Song C |
| 6 | Delete Song C |
| 7 | Contoh dunia nyata: [isi, mis. browser history] |
| 8 | Prediksi sebelum menjalankan program |
| 9 | Break and fix: sengaja membuat kesalahan pointer lalu memperbaikinya |

## Alur Eksperimen

Predict -> Run -> Observe -> Change -> Explain

Catatan eksperimen ada di folder `experiments/`.

## Dokumentasi Lain

- [AI-NOTES.md](AI-NOTES.md)
- [REFLECTION.md](REFLECTION.md)
