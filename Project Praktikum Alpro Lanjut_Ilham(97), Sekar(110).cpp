#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// ===== STRUCT =====
struct Film {
	string judul;
	int kode;
	string genre;
	int durasi;
	float rating;
	int studio;
};

struct Tiket {
	string nama;
	int baris;
	int kolom;
	Film film;
	int harga;
};

// ===== INISIALISASI GLOBAL =====
Film daftarFilm[100];
int jumlahFilm = 0;

char kursi[100][10][10];

Tiket daftarTiket[100];
int jumlahTiket = 0;

// ===== INISIALISASI FUNCTION =====

// === MENU UTAMA===
void menu();

// === KURSI ===
void jumlahKursi();
void tampilKursi(int studio);
void simpanKursi();
void loadKursi();

// === DAFTAR FILM ===
void katalogFilm();

// === ISI MENU ===
void tampilFilm();
void bookingTiket();
void cariFilm();
void sortingFilm();

// === SORTING ===
void sortingKode();
void sortingJudul();
void sortingRating();

// === RIWAYAT ===
void simpanData(Tiket *t);
void riwayatFilm();


// ===== MAIN =====
int main() {
	jumlahKursi();
	
	katalogFilm();
	
	loadKursi();
	
	menu();
	
	return 0;
}

// ===== MENU UTAMA =====
void menu() {
	int pilih;
	
	cout << "\n===== BIOSKOP XXI =====\n";
	cout << "1. Lihat Film\n";
	cout << "2. Booking Tiket Film\n";
	cout << "3. Cari Film\n";
	cout << "4. Sorting Film\n";
	cout << "5. Riwayat Tiket Film\n";
	cout << "6. Keluar\n";
	
	cout << "Pilih Menu : ";
	cin >> pilih;
	
	// ===== BASE CASE =====
    if(pilih == 6) {
        system("cls");
        cout << "Program selesai!\n";
        return;
    }
	
	// ===== PROSES MENU =====
	switch(pilih) {
		case 1: 
			system("cls");
			sortingKode();
			tampilFilm();
			system("pause");
			system("cls");
			break;
		case 2: 
			system("cls");
			bookingTiket();
			break;
		case 3: 
			system("cls");
			cariFilm();
			break;
		case 4: 
			system("cls");
			sortingFilm();
			break;
		case 5: 
			system("cls");
			riwayatFilm();
			break;
		default: 
			system("cls");
			cout << "Menu tidak valid!\n";
	}
	
	menu(); // --> REKURSI
}

// ===== KURSI =====

// Inisialisasi awal kursi bioskop
void jumlahKursi() {
    for(int f = 0; f < 100; f++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                kursi[f][i][j] = 'O';
            }
        }
    }
}

// Load kursi untuk pengecekan kursi mana yang udah keisi dan mana yang belum
void loadKursi() {
    ifstream file("kursi.txt");
    
    if(!file.is_open()) {
		return;
    }

    string line;

    while(getline(file, line)) {

        stringstream ss(line);

        string studio;
        string baris;
        string kolom;

        getline(ss, studio, '|');
        getline(ss, baris, '|');
        getline(ss, kolom);

        int s = stoi(studio);
        int b = stoi(baris);
        int k = stoi(kolom);

        kursi[s][b][k] = 'X';
    }
    file.close();
}

// Menampilkan Kursi Bioskop
void tampilKursi(int studio) {
    cout << "\n===== KURSI BIOSKOP =====\n\n";

    // Nomor kolom atas
    cout << "    ";
    for(int i = 1; i <= 10; i++) {
        cout << setw(3) << i << " ";
    }
    cout << endl;
    cout << "   " << string(40,'-');
    cout << endl;

    for(int i = 0; i < 10; i++) {
        // Nomor baris kiri
        cout << setw(3) << i + 1 << "|";

        for(int j = 0; j < 10; j++) {
            cout << setw(3) << kursi[studio][i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nO = Kosong\n";
    cout << "X = Terisi\n";
}

// Untuk menyimpan kursi yang sudah terisi
void simpanKursi() {
    ofstream file("kursi.txt");

    for(int f = 0; f < jumlahFilm; f++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(kursi[f][i][j] == 'X') {
                    file << daftarFilm[f].studio - 1 << "|"
                         << i << "|"
                         << j << endl;
                }
            }
        }
    }
    file.close();
}

// ===== DAFTAR FILM ===== 
void katalogFilm() {
	daftarFilm[0] = {"Avengers", 10, "Action", 180, 9.0, 1};
    daftarFilm[1] = {"Interstellar", 20, "Sci-Fi", 169, 9.5, 2};
    daftarFilm[2] = {"Conjuring", 30, "Horror", 120, 8.0, 3};
    daftarFilm[3] = {"Agak Laen", 40, "Horror, Comedi", 119, 7.2, 4};
    daftarFilm[4] = {"Pabrik Gula", 50, "Horror", 105, 9, 5};
    daftarFilm[5] = {"Dilan 1990", 60, "Romance", 110, 7, 6};
    daftarFilm[6] = {"Project Hail Mary", 70, "Sci-Fi", 157, 8.6, 7};
    daftarFilm[7] = {"Kuncen", 80, "Horror", 108, 10, 8};
    daftarFilm[8] = {"Minions", 90, "Komedi", 91, 9.2, 9};
    daftarFilm[9] = {"Aquaman", 100, "Action", 143, 9.8, 10};

    jumlahFilm = 10;
}

// ===== ISI MENU =====

// Menampilkan Daftar Film
void tampilFilm() {
	cout << "\n===== DAFTAR FILM =====\n\n";
	
	cout << left
		 << setw(5) << "No"
         << setw(25) << "Judul"
         << setw(10) << "Kode"
         << setw(20) << "Genre"
         << setw(10) << "Durasi"
         << setw(10) << "Rating" 
         << setw(10) << "Studio" << endl;
         
    cout << string(87, '-');
    cout << endl;

    for(int i = 0; i < jumlahFilm; i++) {
        cout << left
			 << setw(5) << i + 1
             << setw(25) << daftarFilm[i].judul
             << setw(10) << daftarFilm[i].kode
             << setw(20) << daftarFilm[i].genre
             << setw(10) << daftarFilm[i].durasi
             << setw(10) << daftarFilm[i].rating
             << setw(10) << daftarFilm[i].studio
             << endl;
    }
	cout << endl;
}

//Menu untuk memesan Tiket Film
void bookingTiket() {
	sortingKode();
	tampilFilm();

    int pilihFilm;
    cout << "\nPilih film (Masukkan No Film): ";
    cin >> pilihFilm;

    if(pilihFilm < 1 || pilihFilm > jumlahFilm) {
        cout << "Film tidak valid!\n";
        system("pause");
		system("cls");
        return;
    }
    
    cout << "Studio : "
     << daftarFilm[pilihFilm - 1].studio
     << endl;

	int studio = daftarFilm[pilihFilm - 1].studio - 1;
    tampilKursi(studio);

    int baris, kolom;

    cout << "\nMasukkan baris kursi (1-10): ";
    cin >> baris;

    cout << "Masukkan kolom kursi (1-10): ";
    cin >> kolom;

    baris--;
    kolom--;
    
    if(baris < 0 || baris >= 10 ||
	   kolom < 0 || kolom >= 10) {

		cout << "Posisi kursi tidak valid!\n";
		system("pause");
		system("cls");
		return;
	}
    
    if(kursi[studio][baris][kolom] == 'X') {
        cout << "Kursi sudah terisi!\n";
        system("pause");
		system("cls");
        return;
    }

    string nama;
    cout << "Masukkan nama pembeli: ";
    cin.ignore();
    getline(cin, nama);

    // Update kursi
    kursi[studio][baris][kolom] = 'X';
    simpanKursi();
    
    daftarTiket[jumlahTiket].nama = nama;
	daftarTiket[jumlahTiket].baris = baris + 1;
	daftarTiket[jumlahTiket].kolom = kolom + 1;

	daftarTiket[jumlahTiket].film = daftarFilm[pilihFilm - 1];
	daftarTiket[jumlahTiket].harga = 35000;
	
	simpanData(&daftarTiket[jumlahTiket]);
	
	cout << "\nBooking berhasil!\n";

	cout << "Nama   : "
		 << daftarTiket[jumlahTiket].nama
		 << endl;

	cout << "Film   : "
		 << daftarTiket[jumlahTiket].film.judul
		 << endl;
	cout << "Studio : "
		 << daftarTiket[jumlahTiket].film.studio
		 << endl;
	cout << "Kursi  : "
		 << daftarTiket[jumlahTiket].baris
		 << "-"
		 << daftarTiket[jumlahTiket].kolom
		 << endl;
	cout << "Harga  : "
		 << daftarTiket[jumlahTiket].harga
		 << endl << endl << endl;
		 
	jumlahTiket++;
	
	system("pause");
	system("cls");
}

//Menu untuk Mencari Film (Searching)
void cariFilm() {

    char again;

    do {
        sortingKode();

        int opsiCari;
        int cariKode;
        string keyword;
        bool ditemukan;

        cout << "\n===== Menu Cari Film =====\n";
        cout << "1. Cari Berdasarkan Judul Film\n";
        cout << "2. Cari Berdasarkan Kode Film\n";
        cout << "3. Kembali\n";
        cout << "Pilih Menu : ";
        cin >> opsiCari;

        switch(opsiCari) {
            case 1:
				// Sequential Search Non-Sentinel
                ditemukan = false;
                cout << "\nMasukkan judul film: ";
                cin.ignore();
                getline(cin, keyword);

                for(int i = 0; i < jumlahFilm; i++) {
                    if(daftarFilm[i].judul == keyword) {
                        cout << "\nFilm ditemukan!\n\n";

                        cout << left
                             << setw(25) << "Judul"
                             << setw(10) << "Kode"
                             << setw(20) << "Genre"
                             << setw(10) << "Durasi"
                             << setw(10) << "Rating"
                             << setw(10) << "Studio" << endl;

                        cout << string(82, '-');
                        cout << endl;

                        cout << left
                             << setw(25) << daftarFilm[i].judul
                             << setw(10) << daftarFilm[i].kode
                             << setw(20) << daftarFilm[i].genre
                             << setw(10) << daftarFilm[i].durasi
                             << setw(10) << daftarFilm[i].rating
                             << setw(10) << daftarFilm[i].studio
                             << endl;

                        ditemukan = true;
                    }
                }
                if(!ditemukan) {
                    cout << "\nFilm tidak ditemukan!\n";
                }
                break;
            case 2:
            //Binary Search
            {
                cout << "\nMasukkan kode film : ";
                cin >> cariKode;

                int awal = 0;
                int akhir = jumlahFilm - 1;

                ditemukan = false;

                while(awal <= akhir && !ditemukan) {

                    int tengah = (awal + akhir) / 2;

                    if(daftarFilm[tengah].kode == cariKode) {

                        cout << "\nFilm ditemukan!\n\n";

                        cout << left
                             << setw(25) << "Judul"
                             << setw(10) << "Kode"
                             << setw(20) << "Genre"
                             << setw(10) << "Durasi"
                             << setw(10) << "Rating"
                             << setw(10) << "Studio" << endl;

                        cout << string(82, '-');
                        cout << endl;

                        cout << left
                             << setw(25) << daftarFilm[tengah].judul
                             << setw(10) << daftarFilm[tengah].kode
                             << setw(20) << daftarFilm[tengah].genre
                             << setw(10) << daftarFilm[tengah].durasi
                             << setw(10) << daftarFilm[tengah].rating
                             << setw(10) << daftarFilm[tengah].studio
                             << endl;

                        ditemukan = true;

                    } else if(cariKode < daftarFilm[tengah].kode) {
                        akhir = tengah - 1;
                    } else {
                        awal = tengah + 1;
                    }
                }

                if(!ditemukan) {
                    cout << "\nFilm tidak ditemukan!\n";
                }
                break;
            }
			case 3:
                system("cls");
                return;
            default:
				system("cls");
                cout << "\nMenu tidak valid!\n";
                return cariFilm();
        }

        cout << "\nCari lagi? (y/n): ";
        cin >> again;

        system("cls");

    } while(again == 'y' || again == 'Y');
}

//Menu untuk Sorting Film
void sortingFilm() {
    int opsiCari;

    do {
        cout << "\n===== Menu Sorting Film =====\n";
        cout << "1. Sorting Berdasarkan Judul Film\n";
        cout << "2. Sorting Berdasarkan Rating Film\n";
        cout << "3. Kembali\n";
        cout << "Pilih Menu : ";
        cin >> opsiCari;

        switch(opsiCari) {
            case 1:
                system("cls");
                sortingJudul();
                break;
            case 2:
                system("cls");
                sortingRating();
                break;
            case 3:
                system("cls");
                return;
            default:
				system("cls");
                cout << "Menu tidak valid!\n";
        }
    } while(true);
}

// ===== SORTING =====

//Sorting accending berdasarkan kode untuk syarat binary search di menu cari berdasarkan kode film
void sortingKode() {
	//Selection Sort
    for(int i = 0; i < jumlahFilm - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < jumlahFilm; j++) {

            if(daftarFilm[j].kode <
               daftarFilm[minIndex].kode) {

                minIndex = j;
            }
        }

        Film temp;

        temp = daftarFilm[i];
        daftarFilm[i] = daftarFilm[minIndex];
        daftarFilm[minIndex] = temp;
    }
}

// Sorting judul menggunakan Bubble Sort
void sortingJudul() {
    char again;

    do {
        int pilihan;

        cout << "\n===== SORTING JUDUL =====\n";
        cout << "1. Ascending\n";
        cout << "2. Descending\n";
        cout << "3. Kembali\n";
        cout << "Pilih : ";
        cin >> pilihan;

        if(pilihan != 1 && pilihan != 2 && pilihan != 3) {
			system("cls");
            cout << "Menu tidak valid!\n";
            continue;
        }
        for(int i = 0; i < jumlahFilm - 1; i++) {
            for(int j = 0; j < jumlahFilm - i - 1; j++) {
                bool kondisi = false;
				// ASC
                if(pilihan == 1) {
                    kondisi =
                    daftarFilm[j].judul >
                    daftarFilm[j + 1].judul;
				// DESC
                } else if (pilihan == 2){
                    kondisi =
                    daftarFilm[j].judul <
                    daftarFilm[j + 1].judul;
                } else {
					system("cls");
					return;
				}
                if(kondisi) {
                    Film temp;

                    temp = daftarFilm[j];
                    daftarFilm[j] = daftarFilm[j + 1];
                    daftarFilm[j + 1] = temp;
                }
            }
        }
        cout << "\nSorting judul berhasil!\n\n";

        tampilFilm();

        cout << "\nSorting lagi? (y/n): ";
        cin >> again;
        
        if(again == 'n' || again == 'N') {
			system("cls");
			return menu();
		}

        system("cls");

    } while(again == 'y' || again == 'Y');
}

// Sorting judul menggunakan Selection Sort
void sortingRating() {
    char again;

    do {
        int pilihan;

        cout << "\n===== SORTING RATING =====\n";
        cout << "1. Ascending\n";
        cout << "2. Descending\n";
        cout << "3. Kembali\n"; 
        cout << "Pilih : ";
        cin >> pilihan;

        if(pilihan != 1 && pilihan != 2 && pilihan != 3) {
			system("cls");
            cout << "Menu tidak valid!\n";
            continue;
        }
        for(int i = 0; i < jumlahFilm - 1; i++) {
            int index = i;
            for(int j = i + 1; j < jumlahFilm; j++) {
                bool kondisi = false;
                if(pilihan == 1) {
                    kondisi =
                    daftarFilm[j].rating <
                    daftarFilm[index].rating;
                } else if(pilihan == 2){
                    kondisi =
                    daftarFilm[j].rating >
                    daftarFilm[index].rating;
                } else {
					system("cls");
					return;
				}
                if(kondisi) {
                    index = j;
                }
            }
            Film temp;

            temp = daftarFilm[i];
            daftarFilm[i] = daftarFilm[index];
            daftarFilm[index] = temp;
        }
        cout << "\nSorting rating berhasil!\n\n";

        tampilFilm();

        cout << "\nSorting lagi? (y/n): ";
        cin >> again;
        
        if(again == 'n' || again == 'N') {
			system("cls");
			return menu();
		}

        system("cls");

    } while(again == 'y' || again == 'Y');
}


// ===== RIWAYAT =====

// Untuk menyimpan riwayat tiket
void simpanData(Tiket *t) {
	ofstream file("riwayat_tiket.txt", ios::app);

    if(!file.is_open()) {
        cout << "File gagal dibuka!\n";
        return;
    }

    stringstream ss;

    ss << t->nama << "|"
       << t->film.judul << "|"
       << t->film.kode << "|"
       << t->film.studio << "|"
       << t->baris << "|"
       << t->kolom << "|"
       << t->harga;

    file << ss.str() << endl;

    file.close();

}

// Untuk menampilkan riwayat tiket
void riwayatFilm() {
    ifstream file("riwayat_tiket.txt");

    if(!file.is_open()) {
        cout << "File tidak ditemukan!\n";
        system("pause");
		system("cls");
        return;
    }
    
    if(file.peek() == EOF) {
		cout << "Belum ada riwayat tiket!\n";
		system("pause");
		system("cls");
		return;
	}

    string line;

    cout << "\n===== RIWAYAT TIKET =====\n\n";
    cout << left
         << setw(20) << "Nama"
         << setw(25) << "Film"
         << setw(10) << "Kode"
         << setw(10) << "Studio"
         << setw(10) << "Baris"
         << setw(10) << "Kolom"
         << setw(10) << "Harga"
         << endl;

    cout << string(90, '-');
    cout << endl;

    while(getline(file, line)) {

        stringstream ss(line);

        string nama;
        string judul;
        string kode;
        string studio;
        string baris;
        string kolom;
        string harga;

        getline(ss, nama, '|');
        getline(ss, judul, '|');
        getline(ss, kode, '|');
        getline(ss, studio, '|');
        getline(ss, baris, '|');
        getline(ss, kolom, '|');
        getline(ss, harga);

        cout << left
             << setw(20) << nama
             << setw(25) << judul
             << setw(10) << kode
             << setw(10) << studio
             << setw(10) << baris
             << setw(10) << kolom
             << setw(10) << harga
             << endl;
    }
    cout << endl;
    
    system("pause");
	system("cls");

    file.close();
}


 
