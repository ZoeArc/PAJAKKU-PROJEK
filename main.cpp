#include <iostream>
#include <conio.h>
using namespace std;

const string RED    = "\033[31m";
const string BLACK   = "\033[30m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string WHITE  = "\033[37m";
const string PURPLE = "\033[95m";
const string ITALIC    = "\033[3m";
const string DIM       = "\033[2m";
const string BOLD      = "\033[1m";
const string RESET  = "\033[0m";

void align(){
    cout << "                                        ";
}
void hapusLayar() {
    cout << "\033[2J\033[3J\033[H";
}
void pauseLayar() {
    align(); cout  << "Tekan ENTER untuk melanjutkan...";
    cin.ignore(10000, '\n');
}

void kreator() {
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "---------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                             [ KREATOR PROGRAM ]                            " << endl;
	align(); cout << PURPLE  << "---------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    align(); cout << BOLD << DIM << "                  [1] Heni Patun Pidani        (F1D02510009)" << endl;
    align(); cout << "                  [2] Tiha Karyati             (F1D02510028)" << endl; 
    align(); cout << "                  [3] Muhamad Alfian Maulana   (F1D02510077)" << endl; 
    align(); cout << "                  [4] Asmaul Husnah            (F1D02510106)" << endl; 
    align(); cout << "                  [5] Edgar Dave Aipassa       (F1D02510111)" << endl;
    align(); cout << "                  [6] Lalu Helmi Firdaus       (F1D02510119)" << endl;
    align(); cout << "                  [7] Wildan Afandika          (F1D02510141)" << endl << RESET;
}

void bannerUtama() {
    cout << "\n\n";
    align(); cout << CYAN   << "XXXXXXX    XXXXXX       XXXXX   XXXXXX   XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n";
    align(); cout << CYAN   << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n";  
    align(); cout << CYAN   << "XXX  XXX  XXX  XXX      XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n";  
    align(); cout << PURPLE  << "XXX  XXXX XXX XXXX      XXXXX  XXX  XXXX XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"; 
    align(); cout << PURPLE  << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n";  
    align(); cout << PURPLE  << "XXXXXXX   XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"; 
    align(); cout << CYAN   << "XXX       XXX  XXX  XX  XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n";  
    align(); cout << CYAN   << "XXX       XXX  XXX  XXXXXXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXXXXXXXX \n";  
    align(); cout << CYAN   << "XXX       XXX  XXX   XXXXXXX   XXX  XXX  XXXX  XXXX  XXXX  XXXX   XXXXXXXX  \n";  
    align(); cout << PURPLE  << "___________________________________________________________________________\n";
    align(); cout << PURPLE  << "|__________________________________________________________________________|\n";
    align(); cout << PURPLE  << "|                                                                          |\n";
    align(); cout << PURPLE  << "|" << ITALIC << YELLOW << "                      SISTEM PEMBAYARAN PAJAK KENDARAAN                   " << RESET; cout << PURPLE << "|\n";
    align(); cout << PURPLE  << "|__________________________________________________________________________|\n";
    align(); cout << PURPLE  << "|__________________________________________________________________________|\n";
    cout << RESET << endl;
}

const int maxKendaraan = 100; 
string platNomor[maxKendaraan];
string namaPemilik[maxKendaraan];
string usernamePemilik[maxKendaraan];
string jenisKendaraan[maxKendaraan];
int besarPajak[maxKendaraan];
int jumlahKendaraan = 0;
bool statusBayar[maxKendaraan] = {false};
int denda[maxKendaraan] = {0};
const int maksPengguna = 100;
struct Pengguna {
    string namaLengkap;
    string username;
    string password;
    string admin;
};
int totalPengguna = 1;
Pengguna dataPengguna[maksPengguna];
void tambahKendaraan() {
	hapusLayar();
    bannerUtama();
	if (jumlahKendaraan >= maxKendaraan) {
        cout << RED << "[ERROR] Memori penuh! Tidak dapat menambah kendaraan lagi.\n" << RESET;
        return;
    }
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                          [ TAMBAH DATA KENDARAAN ]                         " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    
    while (true) {
        align(); cout << "Masukkan Nomor Plat (contoh: DR 1234 AB) : ";
        getline(cin, platNomor[jumlahKendaraan]);
        if (!platNomor[jumlahKendaraan].empty()) {
            break; 
        }
        align(); cout << RED << "[ERROR] Plat nomor tidak boleh kosong!\n" << RESET;
    }
    
    while (true) {
        align(); cout << "Masukkan Nama Pemilik                    : ";
        getline(cin, namaPemilik[jumlahKendaraan]);
        if (!namaPemilik[jumlahKendaraan].empty()) {
            break;
        }
        align(); cout << RED << "[ERROR] Nama pemilik tidak boleh kosong!\n" << RESET;
    }

    while(true)
{
    align(); cout << "Masukkan Username Pemilik                : ";
    getline(cin, usernamePemilik[jumlahKendaraan]);

    bool ditemukan = false;

    for(int i = 0; i < totalPengguna; i++)
    {
        if(dataPengguna[i].username ==
           usernamePemilik[jumlahKendaraan])
        {
            ditemukan = true;
            break;
        }
    }

    if(ditemukan)
    {
        break;
    }
    align();cout << RED
             << "[ERROR] Username tidak terdaftar!\n"
             << RESET;
}
    while (true) {
        align(); cout << "Masukkan Jenis Kendaraan (Mobil/Motor)   : ";
        getline(cin, jenisKendaraan[jumlahKendaraan]);
        if (jenisKendaraan[jumlahKendaraan] == "Mobil" || jenisKendaraan[jumlahKendaraan] == "Motor" || 
            jenisKendaraan[jumlahKendaraan] == "mobil" || jenisKendaraan[jumlahKendaraan] == "motor") {
            break;
        }
        align(); cout << RED << "[ERROR] Jenis kendaraan harus berupa 'Mobil' atau 'Motor'!\n" << RESET;
    }
   
    while (true) {
        align(); cout << "Masukkan Besar Pajak Tahunan (Rp)        : "; cin >> besarPajak[jumlahKendaraan];
  
        if (cin.fail() || besarPajak[jumlahKendaraan] < 0) {
            cin.clear();            
            cin.ignore(1000, '\n'); 
            align(); cout << RED << "[ERROR] Input tidak valid! Masukkan nominal angka yang benar.\n" << RESET;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    
    align(); cout << GREEN << "[SISTEM] Data kendaraan berhasil ditambahkan!\n" << RESET;
    align(); cout << "----------------------------------------------------------------------------" << endl;
    align(); cout << "Plat Nomor      : " << platNomor[jumlahKendaraan] << endl;
    align(); cout << "Pemilik         : " << namaPemilik[jumlahKendaraan] << endl;
    align(); cout << "Jenis           : " << jenisKendaraan[jumlahKendaraan] << endl;
    align(); cout << "Pajak Tahunan   : Rp " << besarPajak[jumlahKendaraan] << endl;
    align(); cout << "----------------------------------------------------------------------------" << endl;
    jumlahKendaraan++;
    pauseLayar();
}

void editDataKendaraan() {
    hapusLayar();
    bannerUtama();
    align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                     [ PILIH DATA YANG INGIN DI EDIT ]                      " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;
    }
    hapusLayar();
    bannerUtama();
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                     [ PILIH DATA YANG INGIN DI EDIT ]                      " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        align(); cout << " [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    align(); cout << "----------------------------------------------------------------------------" << endl;
    
    int nomorData;
    while (true) {
        align(); cout << "Masukkan nomor data kendaraan yang mau diedit: ";
        cin >> nomorData;
        if (cin.fail() || nomorData < 1 || nomorData > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            align(); cout << RED << "[ERROR] Nomor tidak valid!\n" << RESET;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    int idx = nomorData - 1; 
    int pilihanEdit = 0;
    bool isSelesai = false;
    
    do {
        hapusLayar();
        bannerUtama();
        align(); cout << GREEN  << "============================================================================" << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << CYAN   << "                            [ EDIT DATA KENDARAAN ]                         " << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << GREEN  << "============================================================================" << RESET << endl;

        align(); cout << "Data Saat Ini:\n";
        
        if (pilihanEdit == 0) {
            align(); cout << GREEN << "[1] Plat Nomor         : " << platNomor[idx] << " <\n" << RESET;
        } else {
            align(); cout << "[1] Plat Nomor         : " << platNomor[idx] << "\n";
        }
        if (pilihanEdit == 1) {
            align(); cout << GREEN << "[2] Nama Pemilik       : " << namaPemilik[idx] << " <\n" << RESET;
        } else {
            align(); cout << "[2] Nama Pemilik       : " << namaPemilik[idx] << "\n";
        }
        if (pilihanEdit == 2) {
            align(); cout << GREEN << "[3] Username Pemilik   : " << usernamePemilik[idx] << " <\n" << RESET;
        } else {
            align(); cout << "[3] Username Pemilik   : " << usernamePemilik[idx] << "\n";
        }
        if (pilihanEdit == 3) {
            align(); cout << GREEN << "[4] Jenis Kendaraan    : " << jenisKendaraan[idx] << " <\n" << RESET;
        } else {
            align(); cout << "[4] Jenis Kendaraan    : " << jenisKendaraan[idx] << "\n";
        }
        if (pilihanEdit == 4) {
            align(); cout << GREEN << "[5] Pajak Tahunan      : Rp " << besarPajak[idx] << " <\n" << RESET;
        } else {
            align(); cout << "[5] Pajak Tahunan      : Rp " << besarPajak[idx] << "\n";
        }
        if (pilihanEdit == 5) {
            align(); cout << GREEN << "[0] Selesai Mengedit <\n" << RESET;
        } else {
            align(); cout << "[0] Selesai Mengedit\n";
        }
        align(); cout << "----------------------------------------------------------------------------" << endl;

        int keyEdit = getch();
        if (keyEdit == 224 || keyEdit == 0) {
            keyEdit = getch();
            if (keyEdit == 72) { // atas
                pilihanEdit--;
                if (pilihanEdit < 0) pilihanEdit = 5;
            } else if (keyEdit == 80) { // bawah
                pilihanEdit++;
                if (pilihanEdit > 5) pilihanEdit = 0;
            }
        } else if (keyEdit == '\r') {

            if (pilihanEdit == 0){
                string platBaru;
                while(true){
                    align(); cout << "Masukkan Nomor Plat Baru (misal: DK 1234 AB): ";
                    getline(cin, platBaru);
                    if(!platBaru.empty()) break;
                    align(); cout << RED << "[ERROR] Plat nomor tidak boleh kosong!\n" << RESET;
                }
                platNomor[idx] = platBaru;
                align(); cout << GREEN << "[SISTEM] Plat nomor berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 1){
                string namaBaru;
                while(true){
                    align(); cout << "Masukkan Nama Pemilik Baru: ";
                    getline(cin, namaBaru);
                    if(!namaBaru.empty()) break;
                    align(); cout << RED << "[ERROR] Nama pemilik tidak boleh kosong!\n" << RESET;
                }
                namaPemilik[idx] = namaBaru;
                align(); cout << GREEN << "[SISTEM] Nama pemilik berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 2){
                while(true){
                    string userBaru;
                    align(); cout << "Masukkan Username Baru : ";
                    getline(cin, userBaru);
                    bool ditemukan = false;
                    for(int i = 0; i < totalPengguna; i++){
                        if(dataPengguna[i].username == userBaru){
                            ditemukan = true;
                            break;
                        }
                    }
                    if(!ditemukan){
                        align(); cout << RED<< "[ERROR] Username tidak terdaftar!\n"<< RESET;
                    }
                    else{
                        usernamePemilik[idx] = userBaru;
                        align(); cout << GREEN << "[SISTEM] Username berhasil diperbarui!\n" << RESET;
                        break;
                    }
                }
                pauseLayar();
                }
            else if (pilihanEdit == 3){
                while(true){
                    align(); cout << "Masukkan Jenis Kendaraan Baru (Mobil/Motor): ";
                    getline(cin, jenisKendaraan[idx]);
                    if(jenisKendaraan[idx] == "Mobil" || jenisKendaraan[idx] == "Motor" || jenisKendaraan[idx] == "mobil" || jenisKendaraan[idx] == "motor")
                    {
                        break;
                    }
                    align(); cout << RED << "[ERROR] Hanya boleh Mobil atau Motor!\n" << RESET;
                }
                align(); cout << GREEN << "[SISTEM] Jenis kendaraan berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 4) {
                while (true) {
                align(); cout << "Masukkan Besar Pajak Tahunan Baru (Rp): ";
                cin >> besarPajak[idx];
                if (cin.fail() || besarPajak[idx] < 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                align(); cout << RED << "[ERROR] Pajak harus berupa angka positif!\n" << RESET;
                } else {
                cin.ignore(10000, '\n');
                align(); cout << GREEN << "[SISTEM] Besar pajak berhasil diperbarui!\n" << RESET;
                break;
                }
                }
                pauseLayar();
            }
            else if (pilihanEdit == 5) {
                align(); cout << GREEN << "[SISTEM] Keluar dari menu edit. Perubahan disimpan!\n" << RESET;
                isSelesai = true;
            }
        }
    } while (!isSelesai);
}

void lihatKendaraan() {
    hapusLayar();
    bannerUtama();
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                        [ DAFTAR KENDARAAN TERDAFTAR ]                      " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;     
    }

    for (int i = 0; i < jumlahKendaraan; i++) {
        align(); cout << YELLOW << "Detail Informasi Kendaraan ke-" << i + 1 << ":" << RESET << endl;
        align(); cout << "1. Nomor Plat        : " << platNomor[i] << endl;
        align(); cout << "2. Nama Pemilik      : " << namaPemilik[i] << endl;
        align(); cout << "3. Username Pemilik  : " << usernamePemilik[i] << endl;
        align(); cout << "4. Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
        align(); cout << "5. Pajak Tahunan     : Rp " << besarPajak[i] << endl;
        align(); cout << YELLOW << "----------------------------------------------------------------------------" << RESET << endl;
    }
    pauseLayar();
}

void hapusKendaraan() {
    hapusLayar();
    bannerUtama();
    align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                           [ HAPUS DATA KENDARAAN ]                         " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;  
    }

    for (int i = 0; i < jumlahKendaraan; i++) {
        align(); cout << "  [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    align(); cout << "--------------------------------------------------------------\n";

    int nomorHapus;
    while (true) {
        align(); cout << "Masukkan nomor kendaraan yang ingin dihapus : "; cin >> nomorHapus;

        if (cin.fail() || nomorHapus < 1 || nomorHapus > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            align(); cout << RED << "[ERROR] Nomor tidak valid! Masukkan angka sesuai daftar di atas.\n" << RESET;
        } else {
            break; 
        }
    }

    int indeksHapus = nomorHapus - 1;

    char konfirmasi;
    while (true) {
        align(); cout << RED << "Yakin ingin menghapus data milik " << namaPemilik[indeksHapus] << "? (Y/N) : " << RESET;
        cin >> konfirmasi;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            align(); cout << RED << "[ERROR] Input salah! Masukkan Y atau N.\n" << RESET;
            continue;
        }

        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            for (int i = indeksHapus; i < jumlahKendaraan - 1; i++) {
            platNomor[i]       = platNomor[i + 1];
            namaPemilik[i]     = namaPemilik[i + 1];
            usernamePemilik[i] = usernamePemilik[i + 1];
            jenisKendaraan[i]  = jenisKendaraan[i + 1];
            besarPajak[i]      = besarPajak[i + 1];
            statusBayar[i]     = statusBayar[i + 1];
            denda[i]           = denda[i + 1];
            }

            jumlahKendaraan--; 
            align(); cout << GREEN << "[SISTEM] Data kendaraan berhasil dihapus secara permanen!\n" << RESET;
            cin.get();
            pauseLayar();
            break;
        } 
        else if (konfirmasi == 'N' || konfirmasi == 'n') {
            align(); cout << YELLOW << "[SISTEM] Penghapusan dibatalkan. Data tetap aman.\n" << RESET;
            cin.get();
            pauseLayar();
            break;
        } 
        else {
            align(); cout << RED << "[ERROR] Masukkan 'Y' untuk setuju atau 'N' untuk batal.\n" << RESET;
        }
    }
}

void manajemenKendaraanAdmin(){
    int pilihan = 0;
    bool isKembali = false;
    do {
        hapusLayar();
        bannerUtama();
        
        if (pilihan == 0) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [1] Tambah Kendaraan                                <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [1] Tambah Kendaraan                                 |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 1) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [2] Edit Data Kendaraan                             <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [2] Edit Data Kendaraan                              |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [3] Lihat Kendaraan                                 <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [3] Lihat Kendaraan                                  |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 3) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [4] Hapus Kendaraan                                 <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [4] Hapus Kendaraan                                  |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 4) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [0] Kembali                                         <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [0] Kembali                                          |\n";
            align(); cout <<"============================================================================\n";
        }

        int keyAdmin = getch();
        if (keyAdmin == 224 || keyAdmin == 0) {
            keyAdmin = getch();
            if (keyAdmin == 72) {
                pilihan--;
                if (pilihan < 0) pilihan = 4;
            } else if (keyAdmin == 80) {
                pilihan++;
                if (pilihan > 4) pilihan = 0;
            }
        } else if (keyAdmin == '\r') {
            if (pilihan == 0) {
                tambahKendaraan();
            } 
            else if (pilihan == 1) {
                editDataKendaraan();
            } 
            else if (pilihan == 2) {
                lihatKendaraan();
            } 
            else if (pilihan == 3) {
                hapusKendaraan();
            } 
            else if (pilihan == 4) {
                align(); cout << "[LOADING] Kembali ke menu utama...\n";
                isKembali = true;
            }
        }
    } while (!isKembali); 
}

void laporanPajakAdmin(){
    int pilihan = 0;
    bool isKembali = false;
    do{
        hapusLayar();
        bannerUtama();
        align(); cout << GREEN  << "============================================================================" << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << CYAN   << "                           [ LAPORAN PAJAK ADMIN ]                          " << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << GREEN  << "============================================================================" << RESET << endl;
        
        if (pilihan == 0) {
            align(); cout << GREEN << "============================================================================\n";
            align(); cout << GREEN <<"|                     [1] Pembayaran Pajak                                <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [1] Pembayaran Pajak                                 |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 1) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [2] Hitung Denda Keterlambatan                      <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [2] Hitung Denda Keterlambatan                       |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [3] Riwayat Pembayaran                              <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [3] Riwayat Pembayaran                               |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 3) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [0] Kembali                                         <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [0] Kembali                                          |\n";
            align(); cout <<"============================================================================\n";
        }

        int keyLap = getch();
        if (keyLap == 224 || keyLap == 0) {
            keyLap = getch();
            if (keyLap == 72) {
                pilihan--;
                if (pilihan < 0) pilihan = 3;
            } else if (keyLap == 80) {
                pilihan++;
                if (pilihan > 3) pilihan = 0;
            }
        } else if (keyLap == '\r') {
            if (pilihan == 0){
                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                             [ PEMBAYARAN PAJAK ]                           " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0){
                    align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                for (int i = 0; i < jumlahKendaraan; i++){
                    align(); cout << i + 1 << ". " << platNomor[i] << " | " << namaPemilik[i];
                    if (statusBayar[i]){
                        align(); cout << " ("<<GREEN<<"LUNAS"<<RESET<<")"<< endl;
                    }
                    else {
                        align(); cout << endl;
                    }
                }
                int pilih;
                align(); cout << "Pilih kendaraan : ";
                cin >> pilih;
                if (cin.fail() || pilih < 1 || pilih > jumlahKendaraan){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    align(); cout << RED << "[ERROR] Pilihan kendaraan tidak valid!\n" << RESET;
                    pauseLayar();
                    continue;
                }
                int idx = pilih - 1;
                if (statusBayar[idx]){
                    align(); cout << GREEN << "[SISTEM] Pajak kendaraan ini sudah lunas!\n" << RESET;
                    cin.get();
                    pauseLayar();
                    continue;
                }
                int totalTagihan = besarPajak[idx] + denda[idx];
                align(); cout << "Plat Nomor      : " << platNomor[idx] << endl;
                align(); cout << "Pemilik         : " << namaPemilik[idx] << endl;
                align(); cout << "Pajak Pokok     : Rp " << besarPajak[idx] << endl;
                align(); cout << "Denda           : Rp " << denda[idx] << endl;
                align(); cout << "Total Bayar     : Rp " << totalTagihan << endl;

                int uangDibayar;
                align(); cout << "Masukkan uang pembayaran : Rp ";
                cin >> uangDibayar;

                if(cin.fail() || uangDibayar < 0){
                cin.clear();
                cin.ignore(10000, '\n');
                align(); cout << RED << "[ERROR] Nominal pembayaran tidak valid!\n" << RESET;
                pauseLayar();
                continue;
                }
                if (uangDibayar < totalTagihan){
                    align(); cout << RED << "Pembayaran gagal!\n" << RESET;
                    align(); cout << "Uang kurang Rp " << totalTagihan - uangDibayar << endl;
                }
                else{
                    int kembalian = uangDibayar - totalTagihan;
                    statusBayar[idx] = true;
                    align(); cout << GREEN << "Pembayaran berhasil!\n" << RESET;
                    align(); cout << "Uang Dibayar    : Rp " << uangDibayar << endl;
                    align(); cout << "Kembalian       : Rp " << kembalian << endl;
                    align(); cout << "Status Pajak    : LUNAS\n";
                }
                cin.get();
                pauseLayar();
            }
            else if (pilihan == 1){
                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                      [ HITUNG DENDA KETERLAMBATAN ]                        " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0){
                    align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                for (int i = 0; i < jumlahKendaraan; i++){
                    align(); cout << i + 1 << ". "<< platNomor[i]<< " | "<< namaPemilik[i]<< endl;
                }

                int pilih;
                align(); cout << "Pilih kendaraan : ";
                cin >> pilih;

                if (cin.fail() || pilih < 1 || pilih > jumlahKendaraan){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    align(); cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
                }
                else{
                    int bulan;
                    align(); cout << "Masukkan jumlah bulan keterlambatan : ";
                    cin >> bulan;
                    if(cin.fail() || bulan < 0){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    } else {
                        int idx = pilih - 1;
                        denda[idx] = besarPajak[idx] * 2 * bulan / 100;
                        align(); cout << "Pajak Pokok     : Rp "<< besarPajak[idx] << endl;
                        align(); cout << "Denda           : Rp "<< denda[idx] << endl;
                        align(); cout << "Total Tagihan   : Rp "<< besarPajak[idx] + denda[idx]<< endl;
                    }
                }
                cin.get();
                pauseLayar();
            }
            else if (pilihan == 2){
                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                            [ RIWAYAT PEMBAYARAN ]                          " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                bool ada = false;
                for (int i = 0; i < jumlahKendaraan; i++){
                    if (statusBayar[i]){
                        ada = true;
                        align(); cout << "============================================================================\n";
                        align(); cout << "Plat Nomor      : " << platNomor[i] << endl;
                        align(); cout << "Nama Pemilik    : "<< namaPemilik[i] << endl;
                        align(); cout << "Jenis Kendaraan : " << jenisKendaraan[i] << endl;
                        align(); cout << "Pajak Pokok     : Rp " << besarPajak[i] << endl;
                        align(); cout << "Denda           : Rp "<< denda[i] << endl;
                        align(); cout << "Total Bayar     : Rp "<< besarPajak[i] + denda[i]<< endl;
                        align(); cout << "Status          : LUNAS\n";
                        align(); cout << "============================================================================\n";
                    }
                }

                if (!ada){
                    align(); cout << YELLOW << "[PERINGATAN] Belum ada riwayat pembayaran.\n" << RESET;
                }
                pauseLayar();
            }
            else if (pilihan == 3){
                isKembali = true;
            }
        }
    } while (!isKembali);
}

void cariDataPengguna() {
    int pilihan = 0;
    bool isKembali = false;
    do {
        hapusLayar();
        bannerUtama();
        align(); cout << GREEN  << "============================================================================" << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << CYAN   << "                            [ CARI DATA PENGGUNA ]                          " << endl;
        align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
        align(); cout << GREEN  << "============================================================================" << RESET << endl;
        
        if (pilihan == 0) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [1] Cari Berdasarkan Plat Nomor                     <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [1] Cari Berdasarkan Plat Nomor                      |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 1) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [2] Cari Berdasarkan Nama Pemilik                   <|\n";
            align(); cout << GREEN <<"============================================================================\n" << RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [2] Cari Berdasarkan Nama Pemilik                    |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [0] Kembali                                         <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [0] Kembali                                          |\n";
            align(); cout <<"============================================================================\n";
        }
        
        int keyCari = getch();
        if (keyCari == 224 || keyCari == 0) {
            keyCari = getch();
            if (keyCari == 72) {
                pilihan--;
                if (pilihan < 0) pilihan = 2;
            } else if (keyCari == 80) {
                pilihan++;
                if (pilihan > 2) pilihan = 0;
            }
        } else if (keyCari == '\r') {
            if (pilihan == 0) {
                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                      [ CARI BERDASARKAN PLAT NOMOR ]                       " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;    
                if (jumlahKendaraan == 0) {
                    align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                      [ CARI BERDASARKAN PLAT NOMOR ]                       " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                string cariPlat;
                align(); cout << "Masukkan Plat Nomor yang dicari: ";
                getline(cin, cariPlat);

                bool ditemukan = false;
                for (int i = 0; i < jumlahKendaraan; i++) {
                    if (platNomor[i].find(cariPlat) != string::npos) {
                        align(); cout << "  Detail Informasi Kendaraan:" << endl;
                        align(); cout << "  - Nomor Plat        : " << platNomor[i] << endl;
                        align(); cout << "  - Nama Pemilik      : " << namaPemilik[i] << endl;
                        align(); cout << "  - Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
                        align(); cout << "  - Pajak Tahunan     : Rp " << besarPajak[i] << endl;
                        align(); cout << "  --------------------------------------------------------" << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    align(); cout << RED << "  [ERROR] Data dengan plat nomor '" << cariPlat << "' tidak ditemukan.\n" << RESET;
                }
                pauseLayar();
            } 
            else if (pilihan == 1) {
                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                     [ CARI BERDASARKAN NAMA PEMILIK ]                      " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0) {
                    align(); cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                hapusLayar();
                bannerUtama();
                align(); cout << GREEN  << "============================================================================" << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << CYAN   << "                     [ CARI BERDASARKAN NAMA PEMILIK ]                      " << endl;
                align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
                align(); cout << GREEN  << "============================================================================" << RESET << endl;
                string cariNama;
                align(); cout << "Masukkan Nama Pemilik yang dicari: ";
                getline(cin, cariNama);

                bool ditemukan = false;
                for (int i = 0; i < jumlahKendaraan; i++) {
                    if (namaPemilik[i].find(cariNama) != string::npos) {
                        align(); cout << "  Detail Informasi Kendaraan:" << endl;
                        align(); cout << "  - Nomor Plat        : " << platNomor[i] << endl;
                        align(); cout << "  - Nama Pemilik      : " << namaPemilik[i] << endl;
                        align(); cout << "  - Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
                        align(); cout << "  - Pajak Tahunan     : Rp " << besarPajak[i] << endl;
                        align(); cout << "  --------------------------------------------------------" << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    align(); cout << RED << "  [ERROR] Data dengan nama pemilik '" << cariNama << "' tidak ditemukan.\n" << RESET;
                }
                pauseLayar();;
            } 
            else if (pilihan == 2) {
                align(); cout << "[LOADING] Kembali ke menu utama...\n";
                isKembali = true;
            }
        }
    } while (!isKembali);
}

void menuAdmin() {
    int pilihan = 0;
    bool isLogout = false;
    do{
        hapusLayar();
        bannerUtama();
        
        if (pilihan == 0) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [1] Manajemen Kendaraan                             <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [1] Manajemen Kendaraan                              |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 1) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [2] Laporan Pajak                                   <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [2] Laporan Pajak                                    |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [3] Cari Data Pengguna                              <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [3] Cari Data Pengguna                               |\n";
            align(); cout <<"============================================================================\n";
        }

        if (pilihan == 3) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [0] Logout                                          <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [0] Logout                                           |\n";
            align(); cout <<"============================================================================\n";
        }
        
        int keyMenuAdmin = getch();
        if (keyMenuAdmin == 224 || keyMenuAdmin == 0) {
            keyMenuAdmin = getch();
            if (keyMenuAdmin == 72) {
                pilihan--;
                if (pilihan < 0) pilihan = 3;
            } else if (keyMenuAdmin == 80) {
                pilihan++;
                if (pilihan > 3) pilihan = 0;
            }
        } else if (keyMenuAdmin == '\r') {
            if (pilihan == 0) {
                manajemenKendaraanAdmin();
            }
            else if (pilihan == 1) {
                laporanPajakAdmin();
            }
            else if (pilihan == 2) {
                cariDataPengguna();
            }
            else if (pilihan == 3) {
                isLogout = true;
            }
        }
    } while (!isLogout);
}

void lihatKendaraanSaya(string username)
{
    hapusLayar();
    bannerUtama();

    bool ditemukan = false;

    align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                          [ DAFTAR KENDARAAN SAYA ]                         " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username)
        {
            ditemukan = true;

            align(); cout << "Plat Nomor      : " << platNomor[i] << endl;
            align(); cout << "Nama Pemilik    : " << namaPemilik[i] << endl;
            align(); cout << "Jenis Kendaraan : " << jenisKendaraan[i] << endl;
            align(); cout << "Pajak Tahunan   : Rp " << besarPajak[i] << endl;

            if(statusBayar[i]){
                align(); cout << "Status Pajak    : " << GREEN << "LUNAS\n" << RESET;
            }
            else {
                align(); cout << "Status Pajak    : " << RED << "BELUM LUNAS\n" << RESET;
            }

            align(); cout << "----------------------------------------------------------------------------" << endl;
        }
    }

    if(!ditemukan)
    {
        align(); cout << YELLOW << "[PERINGATAN] Belum ada kendaraan terdaftar.\n" << RESET;
    }

    pauseLayar();
}
void bayarPajakPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ditemukan = false;
    int daftarIndex[100];
    int jumlahData=0;
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                            [ PEMBAYARAN PAJAK ]                            " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
{
    if(usernamePemilik[i] == username)
    {
        daftarIndex[jumlahData] = i;
        ditemukan = true;
        align(); cout << jumlahData + 1 << ". " << platNomor[i] << " | Rp " << besarPajak[i];
        if(statusBayar[i]) {
        cout << " | " << GREEN << "LUNAS" << RESET;
        }
        cout << endl;
        jumlahData++;
    }
}

    if(!ditemukan)
    {
        align(); cout << YELLOW << "[PERINGATAN] Tidak ada kendaraan.\n" << RESET;
        pauseLayar();
        return;
    }

    int pilih;
    align(); cout << "Pilih kendaraan : ";
    cin >> pilih;

    if(cin.fail() || pilih < 1 || pilih > jumlahData)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        align(); cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
        pauseLayar();
        return;
    }
    int idx = daftarIndex[pilih - 1];

    if(statusBayar[idx]){
        align(); cout << YELLOW << "[PERINGATAN] Kendaraan ini sudah LUNAS, tidak perlu dibayar lagi!\n" << RESET;
        cin.get();
        pauseLayar();
        return;
    }

    int *pPajak = &besarPajak[idx];
    int *pDenda = &denda[idx];
    int totalTagihan = *pPajak + *pDenda;
    align(); cout << "Pajak Pokok   : Rp " << *pPajak << endl;
    align(); cout << "Denda         : Rp " << *pDenda << endl;
    align(); cout << "Total Tagihan : Rp " << totalTagihan << endl;
    char bayar;
    align(); cout << "Bayar sekarang? (Y/N) : ";
    cin >> bayar;

    if(bayar == 'Y' || bayar == 'y'){
        statusBayar[idx] = true;
        align(); cout << GREEN << "[SISTEM] Pembayaran berhasil!\n" << RESET;
    }
    else if(bayar == 'N' || bayar == 'n'){
        align(); cout << YELLOW << "[SISTEM] Pembayaran dibatalkan.\n" << RESET;
    }
    else{
        align(); cout << RED << "[ERROR] Masukkan 'Y' atau 'N'.\n" << RESET;
    }
    cin.get();
    pauseLayar();
}

void hitungDendaPengguna(string username)
{
    hapusLayar();
    bannerUtama();

	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                           [ PERHITUNGAN DENDA ]                            " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    string plat;
    align(); cout << "Masukkan plat kendaraan : ";
    getline(cin, plat);

    bool ditemukan = false;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(platNomor[i] == plat && usernamePemilik[i] == username)
        {
            ditemukan = true;
            int bulan;
            align(); cout << "Jumlah bulan terlambat : ";
            cin >> bulan;
            if(cin.fail() || bulan < 0){
                cin.clear();
                cin.ignore(10000, '\n');
                align(); cout << RED << "[ERROR] Jumlah bulan tidak valid!\n" << RESET;
                pauseLayar();

                return;
            }
            cin.ignore(100000, '\n');
            int *pPajak = &besarPajak[i];
            int hasilDenda =
                (*pPajak * 2 * bulan) / 100;
            align(); cout << "Pajak Pokok : Rp " << *pPajak << endl;
            align(); cout << "Denda : Rp " << hasilDenda << endl;
            align(); cout << "Total : Rp " << *pPajak + hasilDenda << endl;
            pauseLayar();
            return;
        }
    }

    if(!ditemukan)
    {
        align(); cout << RED << "[ERROR] Kendaraan tidak ditemukan.\n" << RESET;
    }

    pauseLayar();
}
void riwayatPembayaranPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ada = false;

	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                           [ RIWAYAT PEMBAYARAN ]                           " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username &&
           statusBayar[i])
        {
            ada = true;
            align(); cout << "Plat Nomor : " << platNomor[i] << endl;
            align(); cout << "Pajak : Rp " << besarPajak[i] << endl;
            align(); cout << "Status : LUNAS\n";
            align(); cout << "---------------------------\n";
        }
    }

    if(!ada)
    {
        align(); cout << YELLOW << "[PERINGATAN] Belum ada riwayat pembayaran.\n" << RESET;
    }

    pauseLayar();
}

void menuPengguna(string username)
{ 
    int pilihan = 0;
    bool isLogout = false;
    do{
        hapusLayar();
        bannerUtama();
        
        if (pilihan == 0) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [1] Daftar Kendaraan Saya                           <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [1] Daftar Kendaraan Saya                            |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 1) {
            align(); cout << GREEN << "============================================================================\n";
            align(); cout << GREEN << "|                     [2] Pembayaran Pajak                                <|\n";
            align(); cout << GREEN << "============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [2] Pembayaran Pajak                                 |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [3] Perhitungan Denda                               <|\n";
            align(); cout << GREEN <<"============================================================================\n" << RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [3] Perhitungan Denda                                |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 3) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [4] Riwayat Pembayaran                              <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [4] Riwayat Pembayaran                               |\n";
            align(); cout <<"============================================================================\n";
        }
        
        if (pilihan == 4) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                     [0] Logout                                          <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                     [0] Logout                                           |\n";
            align(); cout <<"============================================================================\n";
        }

        int keyUser = getch();
        if (keyUser == 224 || keyUser == 0) {
            keyUser = getch();
            if (keyUser == 72) {
                pilihan--;
                if (pilihan < 0) pilihan = 4;
            } else if (keyUser == 80) {
                pilihan++;
                if (pilihan > 4) pilihan = 0;
            }
        } else if (keyUser == '\r') {
            if(pilihan == 0) {
                lihatKendaraanSaya(username);
            }
            else if(pilihan == 1) {
                bayarPajakPengguna(username);
            }
            else if(pilihan == 2) {
                hitungDendaPengguna(username);
            }
            else if(pilihan == 3) {
                riwayatPembayaranPengguna(username);
            }
            else if(pilihan == 4) {
                isLogout = true;
            }
        }
    }while(!isLogout);
}

void daftarAkun() {
    hapusLayar();
    bannerUtama();
    if (totalPengguna >= maksPengguna) {
        align(); cout << RED << "[ERROR] Memori pengguna penuh!" << endl << RESET;
        return;
    }
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                         [ REGISTRASI AKUN PAJAKKU]                         " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    string user, password, konfirmasiPassword, namaLengkap;
    bool isUserValid = false;
    do {
        align(); cout << "Masukkan Username     : "; getline(cin, user);
        align(); cout << "Masukkan Nama Lengkap : "; getline(cin, namaLengkap);
        
        if (user.empty())
        {
            align(); cout << RED << "[ERROR] Username atau nama lengkap tidak boleh kosong!\n" << RESET;
            return;
        }
        if (namaLengkap.empty())
        {
            align(); cout << RED << "[ERROR] Username atau nama lengkap tidak boleh kosong!\n" << RESET;
            return;
        }
        bool isSudahAda = false;
        for (int i = 0; i < totalPengguna; i++) {
            if (dataPengguna[i].username == user) {
                isSudahAda = true;
            }
        }
        if (isSudahAda == true) {
            align(); cout << RED << "[ERROR] Username sudah terdaftar!\n" << RESET;
        } else {
            isUserValid = true;
        }
    } while (isUserValid == false);
    
    bool isPasswordValid = false;
    do {
        align(); cout << "Masukkan Password     : ";
        getline(cin, password);
        align(); cout << "Konfirmasi Password   : ";
        getline(cin, konfirmasiPassword);
        
        if (password != konfirmasiPassword) {
            align(); cout << RED << "[ERROR] Password tidak cocok!" << endl << RESET;
        } else if (password == "") {
            align(); cout << RED << "[ERROR] Password tidak boleh kosong!" << endl << RESET;
        } else {
            isPasswordValid = true;
        }
    } while (isPasswordValid == false);
    
    dataPengguna[totalPengguna].username = user;
    dataPengguna[totalPengguna].namaLengkap = namaLengkap;
    dataPengguna[totalPengguna].password = password;
    dataPengguna[totalPengguna].admin = "pengguna";
    totalPengguna++;
    
    align(); cout << GREEN << "[SISTEM] Registrasi berhasil! Silahkan login." << endl << RESET;
}

void login() {
    hapusLayar();
    bannerUtama();
	align(); cout << GREEN  << "============================================================================" << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << CYAN   << "                              [ LOGIN KE PAJAKKU ]                          " << endl;
	align(); cout << PURPLE  << "----------------------------------------------------------------------------" << endl;
	align(); cout << GREEN  << "============================================================================" << RESET << endl;
    string user, password;
    align(); cout << "Username : "; getline(cin, user);
    align(); cout << "Password : "; getline(cin, password);
    
    bool isLoginBerhasil = false;
    for (int i = 0; i < totalPengguna; i++) {
        if (dataPengguna[i].username == user && dataPengguna[i].password == password) {
            align(); cout << GREEN << "[SISTEM] Login berhasil sebagai " << dataPengguna[i].admin << "!" << endl << RESET;
            pauseLayar();
            isLoginBerhasil = true;
            if (dataPengguna[i].admin == "admin") {
                menuAdmin();
            } else {
                menuPengguna(dataPengguna[i].username);
            }
            break;
        }
    }
    
    if (isLoginBerhasil == false) {
        align(); cout << RED << "[ERROR] Username atau Password salah!" << endl << RESET;
    }
}

void menuAwal() {
    int pilihMenu = 0;
    bool isKeluar = false;
    do {
        hapusLayar();
        bannerUtama();     
        if (pilihMenu == 0) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                                  [1] Login                              <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                                  [1] Login                               |\n";
            align(); cout <<"============================================================================\n";
        }

        if (pilihMenu == 1) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                                  [2] Daftar                             <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                                  [2] Daftar                              |\n";
            align(); cout <<"============================================================================\n";
        }

        if (pilihMenu == 2) {
            align(); cout << GREEN <<"============================================================================\n";
            align(); cout << GREEN <<"|                                  [0] Keluar                             <|\n";
            align(); cout << GREEN <<"============================================================================\n"<< RESET;
        } else {
            align(); cout <<"============================================================================\n";
            align(); cout <<"|                                  [0] Keluar                              |\n";
            align(); cout <<"============================================================================\n";
        }
        
        int keyLogin = getch();
        if (keyLogin == 224 || keyLogin == 0) {
            keyLogin = getch();
            if (keyLogin == 72) { // panah atas
                pilihMenu--;
                if (pilihMenu < 0) pilihMenu = 2;
            } else if (keyLogin == 80) { // panah bawah
                pilihMenu++;
                if (pilihMenu > 2) pilihMenu = 0;
            }
        } else if (keyLogin == '\r') { // enter
            if (pilihMenu == 0) {
                login();
                pauseLayar();
            } else if (pilihMenu == 1) {
                daftarAkun();
                pauseLayar();
            } else if (pilihMenu == 2) {
                align(); cout << "Keluar dari program..." << endl;
                hapusLayar();
                kreator();
                cin.ignore(1000, '\n');
                hapusLayar();
                isKeluar = true;
            }
        }
    } while (isKeluar == false);
}

int main() {
    dataPengguna[0].namaLengkap = "Administrator";
    dataPengguna[0].username = "admin";
    dataPengguna[0].password = "12345678";
    dataPengguna[0].admin = "admin";
    menuAwal();


    return 0;
} 