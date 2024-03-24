#include <stdio.h>

// Definisikan struktur untuk menyimpan tanggal
struct Date {
    int day;
    int month;
    int year;
};

// Fungsi untuk mengecek apakah suatu tahun adlaah tahun kabisat
int kabisat(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1; // Tahun kabisat
    else
        return 0; // Bukan tahun kabisat
}
 
// Fungsi untuk menentukan jumlah hari dalam suatu bulan pada suatu tahun
int cekhari(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31; // Bulan dengan 31 hari
        case 4: case 6: case 9: case 11:
            return 30; // Bulan dengan 30 hari
        case 2:
            if (kabisat(year))
                return 29; // Februari dalam tahun kabisat
            else
                return 28; // Februari bukan dalam tahun kabisat
        default:
            return -1; // Bulan tidak valid
    }
}

// Fungsi untuk menghitung tanggal besok dari tanggal yang diberikan
struct Date besok1(struct Date today) {
    struct Date besok1;
    besok1.day = today.day;
    besok1.month = today.month;
    besok1.year = today.year;
    
    // Logika untuk menentukan tanggal besoknya
    if (besok1.day == 28 && besok1.month == 2 && kabisat(besok1.year)) {
        besok1.day = 29;
    } else if (besok1.day == 29 && besok1.month == 2 && !kabisat(besok1.year)) {
        besok1.day = 1;
        besok1.month = 3;
    } else if (besok1.day == 31 && besok1.month == 12) {
        besok1.day = 1;
        besok1.month = 1;
        besok1.year++;
    } else if (besok1.day == cekhari(besok1.month, besok1.year)) {
        besok1.day = 1;
        besok1.month++;
    } else {
        besok1.day++;
    }
    
    return besok1;
}

// Fungsi utama
int main() {
    struct Date today, besok;
    // Meminta pengguna untuk memasukkan tanggal 
    printf("Masukkan tanggal (format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &today.day, &today.month, &today.year);
    // Validsi input tanggal
    if (today.day < 1 || today.day > 31 || today.month < 1 || today.month > 12 || today.year < 1) {
        printf("Input tidak valid!\n");
        return 1;
    }
    // Validasi apakah tanggal valis sesuai dengan bulan tahunnya
    if (today.day > cekhari(today.month, today.year)) {
        printf("Input tanggal tidak valid!\n");
        return 1;
    }
    // Menghitung tanggal besokknya
    besok = besok1(today);
    
    // Menampilkan tanggal besoknya
    printf("Tanggal besoknya adalah: %d/%d/%d\n", besok.day, besok.month, besok.year);
    
    return 0;
}