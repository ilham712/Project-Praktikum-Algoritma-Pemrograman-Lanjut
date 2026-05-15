#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// ================= STRUCT =================
struct Film {
    string judul;
    string genre;
    int durasi;
    float rating;
};

struct Tiket {
    string nama;
    string film;
    int baris;
    int kolom;
    Tiket* next;
};

// ================= GLOBAL =================
Film daftarFilm[100];
int jumlahFilm = 0;

char kursi[5][5];

Tiket* head = NULL;

// ================= FUNCTION =================

// Inisialisasi kursi
void initKursi() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            kursi[i][j] = 'O';
        }
    }
}

// Tambah film default
void tambahFilmDefault() {
    daftarFilm[0] = {"Avengers", "Action", 180, 9.0};
    daftarFilm[1] = {"Interstellar", "Sci-Fi", 169, 9.5};
    daftarFilm[2] = {"Conjuring", "Horror", 120, 8.0};

    jumlahFilm = 3;
}

// Tampilkan film
void tampilFilm() {
    cout << "\n===== DAFTAR FILM =====\n";

    for(int i = 0; i < jumlahFilm; i++) {
        cout << i + 1 << ". "
             << daftarFilm[i].judul
             << " | Genre: " << daftarFilm[i].genre
             << " | Durasi: " << daftarFilm[i].durasi
             << " menit"
             << " | Rating: " << daftarFilm[i].rating
             << endl;
    }
}

// Tampilkan kursi
void tampilKursi() {
    cout << "\n===== KURSI BIOSKOP =====\n";

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << kursi[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nO = Kosong\n";
    cout << "X = Terisi\n";
}

// Booking tiket
void bookingTiket() {
    tampilFilm();

    int pilihFilm;
    cout << "\nPilih film: ";
    cin >> pilihFilm;

    if(pilihFilm < 1 || pilihFilm > jumlahFilm) {
        cout << "Film tidak valid!\n";
        return;
    }

    tampilKursi();

    int baris, kolom;

    cout << "\nMasukkan baris kursi (1-5): ";
    cin >> baris;

    cout << "Masukkan kolom kursi (1-5): ";
    cin >> kolom;

    baris--;
    kolom--;

    if(kursi[baris][kolom] == 'X') {
        cout << "Kursi sudah terisi!\n";
        return;
    }

    string nama;
    cout << "Masukkan nama pembeli: ";
    cin.ignore();
    getline(cin, nama);

    // Update kursi
    kursi[baris][kolom] = 'X';

    // Linked List Tiket
    Tiket* baru = new Tiket;

    baru->nama = nama;
    baru->film = daftarFilm[pilihFilm - 1].judul;
    baru->baris = baris + 1;
    baru->kolom = kolom + 1;
    baru->next = NULL;

    if(head == NULL) {
        head = baru;
    } else {
        Tiket* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = baru;
    }

    cout << "\n===== TIKET BERHASIL =====\n";
    cout << "Nama  : " << nama << endl;
    cout << "Film  : " << baru->film << endl;
    cout << "Kursi : " << baru->baris
         << "-" << baru->kolom << endl;
}

// Searching film
void cariFilm() {
    string keyword;

    cout << "\nMasukkan judul film: ";
    cin.ignore();
    getline(cin, keyword);

    bool ditemukan = false;

    for(int i = 0; i < jumlahFilm; i++) {
        if(daftarFilm[i].judul == keyword) {
            cout << "\nFilm ditemukan!\n";

            cout << daftarFilm[i].judul
                 << " | " << daftarFilm[i].genre
                 << " | Rating: "
                 << daftarFilm[i].rating << endl;

            ditemukan = true;
        }
    }

    if(!ditemukan) {
        cout << "Film tidak ditemukan!\n";
    }
}

// Sorting film berdasarkan rating
void sortingFilm() {
    for(int i = 0; i < jumlahFilm - 1; i++) {
        for(int j = 0; j < jumlahFilm - i - 1; j++) {

            if(daftarFilm[j].rating <
               daftarFilm[j + 1].rating) {

                swap(daftarFilm[j],
                     daftarFilm[j + 1]);
            }
        }
    }

    cout << "\nFilm berhasil diurutkan!\n";
}

// Tampilkan tiket
void tampilTiket() {
    cout << "\n===== RIWAYAT TIKET =====\n";

    if(head == NULL) {
        cout << "Belum ada tiket!\n";
        return;
    }

    Tiket* temp = head;

    while(temp != NULL) {
        cout << "Nama  : " << temp->nama << endl;
        cout << "Film  : " << temp->film << endl;
        cout << "Kursi : "
             << temp->baris
             << "-" << temp->kolom << endl;

        cout << "-------------------\n";

        temp = temp->next;
    }
}

// Simpan tiket ke file
void simpanFile() {
    ofstream file("tiket.txt");

    Tiket* temp = head;

    while(temp != NULL) {
        file << temp->nama << "|"
             << temp->film << "|"
             << temp->baris << "|"
             << temp->kolom << endl;

        temp = temp->next;
    }

    file.close();
}

// Rekursi menu
void menu() {
    int pilih;

    cout << "\n===== BIOSKOP XXI =====\n";
    cout << "1. Lihat Film\n";
    cout << "2. Booking Tiket\n";
    cout << "3. Cari Film\n";
    cout << "4. Sorting Film\n";
    cout << "5. Riwayat Tiket\n";
    cout << "0. Keluar\n";

    cout << "Pilih menu: ";
    cin >> pilih;

    switch(pilih) {
        case 1:
            tampilFilm();
            break;

        case 2:
            bookingTiket();
            break;

        case 3:
            cariFilm();
            break;

        case 4:
            sortingFilm();
            break;

        case 5:
            tampilTiket();
            break;

        case 0:
            simpanFile();
            cout << "Program selesai!\n";
            return;

        default:
            cout << "Menu tidak valid!\n";
    }

    menu(); // REKURSI
}

// ================= MAIN =================
int main() {
    initKursi();

    tambahFilmDefault();

    menu();

    return 0;
}
