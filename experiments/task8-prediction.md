Given:** A <-> B <-> C <-> D, lalu node C dihapus.

**Prediction (ditulis sebelum menjalankan program):** A <-> B <-> D

**Actual result:** A <-> B <-> D (forward), dan D <-> B <-> A (backward).

**Cocok dengan prediksi?** Ya

**Explain:** Setelah C dihapus, next dari B menunjuk ke D dan prev dari D menunjuk ke B. Karena kedua pointer itu diperbarui, traversal di dua arah sama-sama tidak lagi melewati C.
