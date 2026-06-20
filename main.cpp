#include <iostream>
using namespace std;

const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string WHITE  = "\033[37m";
const string RESET  = "\033[0m";

void bannerUtama1() {
    cout << "\n\n\n\n"
         << RED    << "\t\t  XXXXXXX    XXXXXX       XXXXX   XXXXXX   XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n" 
                   << "\t\t  XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n"  
          		   << "\t\t  XXX  XXX  XXX  XXX      XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "\t\t  XXX  XXXX XXX  XXXX     XXXXX  XXX  XXXX XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "\t\t  XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
                   << "\t\t  XXXXXXX   XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
                   << "\t\t  XXX       XXX  XXX  XX  XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "\t\t  XXX       XXX  XXX  XXXXXXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXXXXXXXX \n"  
                   << "\t\t  XXX       XXX  XXX   XXXXXXX   XXX  XXX  XXXX  XXXX  XXXX  XXXX   XXXXXXXX  \n"  
                   << "\t\t   __________________________________________________________________________\n"
                   << "\t\t  |__________________________________________________________________________|\n"
                   << "\t\t  |                                                                          |\n"
                   << "\t\t  |                      SISTEM PEMBAYARAN PAJAK KENDARAAN                   |\n" 
                   << "\t\t  |__________________________________________________________________________|\n"
                   << "\t\t  |__________________________________________________________________________|\n" << RESET << endl;
}

void bannerUtama() {
    cout << " ====================================================" << endl;
    cout << "|        Sistem Pembayaran Pajak Kendaraan           |" << endl;
    cout << " ====================================================" << endl;
}

const int maxKendaraan = 100; 
string platNomor[maxKendaraan];
string namaPemilik[maxKendaraan];
string jenisKendaraan[maxKendaraan];
int besarPajak[maxKendaraan];
int jumlahKendaraan = 0;

void tambahKendaraan() {
	system("cls");
	if (jumlahKendaraan >= maxKendaraan) {
        cout << RED << "\n[Error] Memori penuh! Tidak dapat menambah kendaraan lagi.\n" << RESET;
        return;
    }
    cout  << "\n========================================"<< endl;
    cout  << "          MENU TAMBAH KENDARAAN       " << endl;
    cout  << "========================================" << endl;
    
    cin.ignore(); 
    while (true) {
        cout << "Masukkan Nomor Plat (contoh: DR 1234 AB) : ";
        getline(cin, platNomor[jumlahKendaraan]);
        if (!platNomor[jumlahKendaraan].empty()) {
            break; 
        }
        cout << RED << "[Error] Plat nomor tidak boleh kosong!\n" << RESET;
    }
    
    while (true) {
        cout << "Masukkan Nama Pemilik                  : ";
        getline(cin, namaPemilik[jumlahKendaraan]);
        if (!namaPemilik[jumlahKendaraan].empty()) {
            break;
        }
        cout << RED << "[Error] Nama pemilik tidak boleh kosong!\n" << RESET;
    }
    
    while (true) {
        cout << "Masukkan Jenis Kendaraan (Mobil/Motor) : ";
        getline(cin, jenisKendaraan[jumlahKendaraan]);
        if (jenisKendaraan[jumlahKendaraan] == "Mobil" || jenisKendaraan[jumlahKendaraan] == "Motor" || 
            jenisKendaraan[jumlahKendaraan] == "mobil" || jenisKendaraan[jumlahKendaraan] == "motor") {
            break;
        }
        cout << RED << "[Error] Jenis kendaraan harus berupa 'Mobil' atau 'Motor'!\n" << RESET;
    }
   
    while (true) {
        cout << "Masukkan Besar Pajak Tahunan (Rp)      : ";
        cin >> besarPajak[jumlahKendaraan];
  
        if (cin.fail() || besarPajak[jumlahKendaraan] < 0) {
            cin.clear();            
            cin.ignore(1000, '\n'); 
            cout << RED << "[Error] Input tidak valid! Masukkan nominal angka yang benar.\n" << RESET;
        } else {
            break;
        }
    }
    
    cout << GREEN << "\n[Sistem] Data kendaraan berhasil ditambahkan!\n" << RESET;
    cout << "----------------------------------------\n";
    cout << "Plat Nomor      : " << platNomor[jumlahKendaraan] << endl;
    cout << "Pemilik         : " << namaPemilik[jumlahKendaraan] << endl;
    cout << "Jenis           : " << jenisKendaraan[jumlahKendaraan] << endl;
    cout << "Pajak Tahunan   : Rp " << besarPajak[jumlahKendaraan] << endl;
    cout << "----------------------------------------\n";
    
    jumlahKendaraan++;
}

void editDataKendaraan() {
    if (jumlahKendaraan == 0) {
        cout << RED << "\n[Peringatan] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        return;
    }

    system("cls");
    cout << "========================================" << endl;
    cout << "        PILIH DATA YANG INGIN DIEDIT    " << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << " [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    cout << "----------------------------------------\n";
    
    int nomorData;
    while (true) {
        cout << "Masukkan nomor data kendaraan yang mau diedit: ";
        cin >> nomorData;
        if (cin.fail() || nomorData < 1 || nomorData > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[Error] Nomor tidak valid!\n" << RESET;
        } else {
            break;
        }
    }

    int idx = nomorData - 1; 
    int pilihanEdit;
    
    do {
        system("cls"); 
        cout << "\n========================================" << endl;
        cout << "          MENU EDIT DATA KENDARAAN      " << endl;
        cout << "========================================" << endl;

        cout << "Data Saat Ini:\n";
        cout << " [1] Plat Nomor    : " << platNomor[idx] << endl;
        cout << " [2] Nama Pemilik  : " << namaPemilik[idx] << endl;
        cout << " [3] Jenis         : " << jenisKendaraan[idx] << endl;
        cout << " [4] Pajak Tahunan : Rp " << besarPajak[idx] << endl;
        cout << " [0] Selesai Mengedit\n";
        cout << "----------------------------------------\n";
        cout << "Pilih nomor komponen data yang ingin diubah : ";
        cin >> pilihanEdit;

        if (pilihanEdit == 1) {
            cin.ignore(); 
            cout << "Masukkan Nomor Plat Baru (misal: DK 1234 AB): ";
            getline(cin, platNomor[idx]);
            cout << GREEN << "[Sistem] Plat nomor berhasil diperbarui!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihanEdit == 2) {
            cin.ignore();
            cout << "Masukkan Nama Pemilik Baru: ";
            getline(cin, namaPemilik[idx]);
            cout << GREEN << "[Sistem] Nama pemilik berhasil diperbarui!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihanEdit == 3) {
            cin.ignore();
            cout << "Masukkan Jenis Kendaraan Baru (Mobil/Motor): ";
            getline(cin, jenisKendaraan[idx]);
            cout << GREEN << "[Sistem] Jenis kendaraan berhasil diperbarui!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihanEdit == 4) {
            cout << "Masukkan Besar Pajak Tahunan Baru (Rp): ";
            cin >> besarPajak[idx];
            cout << GREEN << "[Sistem] Besar pajak berhasil diperbarui!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(); 
            cin.get();
        }
        else if (pilihanEdit == 0) {
            cout << GREEN << "\n[Sistem] Keluar dari menu edit. Perubahan disimpan!\n" << RESET;
        }
        else {
            cout << RED << "\nPilihan tidak valid!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihanEdit != 0);
}

void lihatKendaraan() {

    if (jumlahKendaraan == 0) {
    	cin.get();
        cout << RED << "\n[Peringatan] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        return;     
    }
    
	cout << GREEN  << "\n==============================================================" << endl;
	cout << WHITE  << "--------------------------------------------------------------" << endl;
	cout << CYAN   << "                  [ DAFTAR KENDARAAN TERDAFTAR ]              " << endl;
	cout << WHITE  << "--------------------------------------------------------------" << endl;
	cout << GREEN  << "==============================================================" << RESET << endl;

    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << YELLOW << "  Detail Informasi Kendaraan ke-" << i + 1 << ":" << RESET << endl;
        cout << "  1. Nomor Plat        : " << platNomor[i] << endl;
        cout << "  2. Nama Pemilik      : " << namaPemilik[i] << endl;
        cout << "  3. Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
        cout << "  4. Pajak Tahunan     : Rp " << besarPajak[i] << endl;
        cout << YELLOW << "  --------------------------------------------------------" << RESET << endl;
    }
    
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(); 
    cin.get();   
}



void hapusKendaraan() {
 
    if (jumlahKendaraan == 0) {
    	cin.get();
        cout << RED << "\n[Peringatan] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        return;  
    }

    cout << " ------------------------------------------------------------" << endl;
    cout << "¦                 MENU HAPUS DATA KENDARAAN                  ¦" << endl;
    cout << " ------------------------------------------------------------" << endl;
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "  [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    cout << "--------------------------------------------------------------\n";

    int nomorHapus;
    while (true) {
        cout << "Masukkan nomor kendaraan yang ingin dihapus : ";
        cin >> nomorHapus;

        if (cin.fail() || nomorHapus < 1 || nomorHapus > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[Error] Nomor tidak valid! Masukkan angka sesuai daftar di atas.\n" << RESET;
        } else {
            break; 
        }
    }

    int indeksHapus = nomorHapus - 1;

    char konfirmasi;
    while (true) {
        cout << RED << "\nYakin ingin menghapus data milik " << namaPemilik[indeksHapus] << "? (Y/N) : " << RESET;
        cin >> konfirmasi;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[Error] Input salah! Masukkan Y atau N.\n" << RESET;
            continue;
        }

        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            for (int i = indeksHapus; i < jumlahKendaraan - 1; i++) {
                platNomor[i]      = platNomor[i + 1];
                namaPemilik[i]    = namaPemilik[i + 1];
                jenisKendaraan[i] = jenisKendaraan[i + 1];
                besarPajak[i]     = besarPajak[i + 1];
            }

            jumlahKendaraan--; 
            cout << GREEN << "\n[Sistem] Data kendaraan berhasil dihapus secara permanen!\n" << RESET;
            break;
        } 
        else if (konfirmasi == 'N' || konfirmasi == 'n') {
            cout << YELLOW << "\n[Sistem] Penghapusan dibatalkan. Data tetap aman.\n" << RESET;
            break;
        } 
        else {
            cout << RED << "[Error] Masukkan 'Y' untuk setuju atau 'N' untuk batal.\n" << RESET;
        }
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}


void manajemenKendaraanAdmin(){
    int pilihan;
    do {
        system("cls");
        bannerUtama();
        cout << "[1] Tambah Kendaraan\n";
        cout << "[2] Edit Data Kendaraan\n";
        cout << "[3] Lihat Kendaraan\n";
        cout << "[4] Hapus Kendaraan\n";
        cout << "[0] Kembali\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahKendaraan();
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get(); 
        } 
        else if (pilihan == 2) {
            editDataKendaraan();
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == 3) {
            lihatKendaraan();
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        } 
        else if (pilihan == 4) {
            hapusKendaraan();
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        } 
        else if (pilihan == 0) {
            cout << "\nKembali ke menu utama...\n";
        } 
        else {
            cout << RED << "\nPilihan tidak valid!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    } while (pilihan != 0); 
}

void laporanPajakAdmin(){
    bannerUtama();
    cout<<"[1] Pembayaraan Pajak\n";
    cout<<"[2] Hitung Denda Keterlambatan\n";
    cout<<"[3] Riwayat Pembayaran\n";
    cout<<"[0] Kembali\n";
    cout << "Masukkan pilihan : ";
}

void cariDataAdmin(){
    bannerUtama();
    cout << "[1] Cari Berdasarkan Plat\n";
    cout << "[2] Cari Berdasarkan Pemilik\n";
    cout << "[0] Kembaki\n";
    cout << "Masukkan pilihan : ";
}

void menuAdmin()
{
    bannerUtama1();
    int pilihan;
    cout << "\t\t   ________________________________\n";
    cout << "\t\t  |                                |\n";
    cout << "\t\t  |  [1]   Manajemen Kendaraan     |\n";
    cout << "\t\t  |________________________________|\n";
    cout << "\t\t   ________________________________\n";
    cout << "\t\t  |                                |\n";
    cout << "\t\t  |  [2]   Laporan Pajak           |\n";
    cout << "\t\t  |________________________________|\n";
    cout << "\t\t   ________________________________\n";
    cout << "\t\t  |                                |\n";
    cout << "\t\t  |  [0]   Logout                  |\n";
    cout << "\t\t  |________________________________|\n\n";
    
    cout << "\t\t  Masukkan Pilihan:";
    cin >> pilihan;
    if (pilihan == 1)
    {
        manajemenKendaraanAdmin();
    }
    else if (pilihan == 2)
    {
        laporanPajakAdmin();
    }
    else if ( pilihan == 0){
        return;
    }
}

void menuPengguna()
{
    cout << "[1] Daftar Kendaraan Saya\n";
    cout << "[2] Pembayaran Pajak \n";
    cout << "[3] Perhitungan Denda \n";
    cout << "[4] Riwayat Pembayaran \n";
    cout << "[0] Logout\n";
    cout << "Masukkan pilihan : ";
}

int main()
{
    menuAdmin();
    return 0;
}