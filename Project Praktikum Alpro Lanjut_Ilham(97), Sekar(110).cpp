#include <iostream>
#include <iomanip>
using namespace std;

// ===== STRUCT =====
struct Film {
	string judul;
	int kode;
	string genre;
	int durasi;
	float rating;
};

struct Tiket {
	
};

// ===== INISIALISASI GLOBAL =====
Film daftarFilm[100];
int jumlahFilm = 0;

char kursi[10][10];

// ===== FUNCTION =====

// Inisialisasi awal kursi bioskop
void jumlahKursi() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			kursi[i][j] = 'O';
		}
	}
}

// Menampilkan Kursi Bioskop
void tampilKursi() {
    cout << "\n===== KURSI BIOSKOP =====\n";

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << kursi[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nO = Kosong\n";
    cout << "X = Terisi\n";
}

// Daftar Film 
void katalogFilm() {
	daftarFilm[0] = {"Avengers", 10, "Action", 180, 9.0};
    daftarFilm[1] = {"Interstellar", 20, "Sci-Fi", 169, 9.5};
    daftarFilm[2] = {"Conjuring", 30, "Horror", 120, 8.0};

    jumlahFilm = 3;
}

// Menampilkan Daftar Film
void tampilFilm() {
	cout << "\n===== DAFTAR FILM =====\n\n";
	
	
	cout << left
		 << setw(5) << "No"
         << setw(15) << "Judul"
         << setw(10) << "Kode"
         << setw(12) << "Genre"
         << setw(10) << "Durasi"
         << setw(10) << "Rating" << endl;
         
    cout << "-----------------------------------------------------\n";

    for(int i = 0; i < jumlahFilm; i++) {
        cout << left
			 << setw(5) << i + 1
             << setw(15) << daftarFilm[i].judul
             << setw(10) << daftarFilm[i].kode
             << setw(12) << daftarFilm[i].genre
             << setw(10) << daftarFilm[i].durasi
             << setw(10) << daftarFilm[i].rating
             << endl;
    }
	cout << endl;
	system("pause");
}

//Menu untuk memesan Tiket Film
void bookingTiket() {
	tampilFilm();

    int pilihFilm;
    cout << "\nPilih film (Masukkan No Film): ";
    cin >> pilihFilm;

    if(pilihFilm < 1 || pilihFilm > jumlahFilm) {
        cout << "Film tidak valid!\n";
        return;
    }

    tampilKursi();

    int baris, kolom;

    cout << "\nMasukkan baris kursi (1-10): ";
    cin >> baris;

    cout << "Masukkan kolom kursi (1-10): ";
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
}

//Menu untuk Mencari Film
void cariFilm() {
	int opsiCari;
	int cariKode;
	string keyword;
	bool ditemukan;
	char again;
	
	cout << "\n===== Menu Cari Film =====\n";
	cout << "1. Cari Berdasarkan Judul\n";
	cout << "2. Cari Berdasarkan Kode Film\n";
	cout << "Pilih Menu : ";
	cin >> opsiCari;
	
	switch(opsiCari) {
		case 1: 
			ditemukan = false;
			cout << "\nMasukkan judul film: ";
			cin.ignore();
			getline(cin, keyword);

			

			for(int i = 0; i < jumlahFilm; i++) {
				if(daftarFilm[i].judul == keyword) {
				cout << "\nFilm ditemukan!\n\n";
				cout << left
					 << setw(15) << "Judul"
					 << setw(10) << "Kode"
					 << setw(12) << "Genre"
					 << setw(10) << "Durasi"
					 << setw(10) << "Rating" << endl;
				cout << "-----------------------------------------------------\n";
				cout << left
					 << setw(15) << daftarFilm[i].judul
					 << setw(10) << daftarFilm[i].kode
					 << setw(12) << daftarFilm[i].genre
					 << setw(10) << daftarFilm[i].durasi
					 << setw(10) << daftarFilm[i].rating
					 << endl;

				ditemukan = true;
				}
			}

			if(!ditemukan) {
				cout << "Film tidak ditemukan!\n";
			}
			
			cout << "\nCari lagi? (y/n):"; 
			cin >> again;
			
			if(again == 'y' || again == 'Y') {
				system("cls");
				cariFilm();
			} else if(again == 'n'|| again == 'N'){
				system("cls");
			}
			break;
		case 2: {
			// Sequential Search Non-Sentinel
			cout << "\nMasukkan kode film: ";
			cin >> cariKode;
			ditemukan = false;
			int i = 0;
			
			while(i < jumlahFilm && !ditemukan) {
				if(daftarFilm[i].kode == cariKode) {
					cout << "\nFilm ditemukan!\n\n";
					cout << left
						 << setw(15) << "Judul"
						 << setw(10) << "Kode"
						 << setw(12) << "Genre"
						 << setw(10) << "Durasi"
						 << setw(10) << "Rating" << endl;
					cout << "-----------------------------------------------------\n";
					cout << left
						 << setw(15) << daftarFilm[i].judul
						 << setw(10) << daftarFilm[i].kode
						 << setw(12) << daftarFilm[i].genre
						 << setw(10) << daftarFilm[i].durasi
						 << setw(10) << daftarFilm[i].rating
						 << endl;
					 
					ditemukan = true;
				}  
				i++; 
			} 
			if(!ditemukan) {
				cout << "Film dengan kode tersebut tidak ditemukan!\n";
			}      
			
			cout << "\nCari lagi? (y/n):"; 
			cin >> again;
			
			if(again == 'y' || again == 'Y') {
				system("cls");
				cariFilm();
			} else if(again == 'n'|| again == 'N'){
				system("cls");
			}
			break;
		}
		default:
			system("cls");
			cout << "Menu tidak valid!\n";
			cariFilm();
	}
	
}

void shortingFilm() {}
void riwayatFilm() {}
void simpanFile() {}



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
	
	switch(pilih) {
		case 1: 
			system("cls");
			tampilFilm();
			break;
		case 2: 
			bookingTiket();
			break;
		case 3: 
			system("cls");
			cariFilm();
			break;
		case 4: 
			shortingFilm();
			break;
		case 5: 
			riwayatFilm();
			break;
		case 6: 
			simpanFile();
			break;
			cout << "Program selesai!\n";
            return;
		default: 
			system("cls");
			cout << "Menu tidak valid!\n";
	}
	
	menu(); // --> REKURSI
}

int main() {
	jumlahKursi();
	
	katalogFilm();
	
	menu();
	
	return 0;
}
