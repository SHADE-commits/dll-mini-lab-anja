Contoh yang dipilih:* Browser history

*Data yang dipakai:* Home <-> Search <-> Article <-> Video

*Predict:* Traversal forward akan menampilkan Home, Search, Article, Video. Traversal backward akan menampilkan Video, Article, Search, Home.

*Run / Observe:* Output program sesuai prediksi. Forward dimulai dari Home dan backward dimulai dari Video.

*Change:* Menghapus halaman Article dari history.

*Explain:* Setelah Article dihapus, next dari Search menunjuk ke Video dan prev dari Video menunjuk ke Search. Traversal forward menjadi Home, Search, Video, dan backward menjadi Video, Search, Home.

*Kenapa Doubly Linked List cocok untuk contoh ini?*
Tombol Back memakai pointer prev dan tombol Forward memakai pointer next, sehingga pengguna bisa bergerak dua arah dari halaman mana pun tanpa mengulang dari awal. Menghapus satu halaman dari history juga cukup dengan memperbarui pointer di node sekitarnya.
