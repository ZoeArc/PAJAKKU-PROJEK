#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string WHITE  = "\033[37m";
const string RESET  = "\033[0m";

void hapusLayar() {
    system("cls");
    cout << "\033[2J\033[1;1H";
}

void pauseLayar() {
    cout << endl << "Tekan ENTER untuk melanjutkan...";
    cin.ignore(10000, '\n');
}

void bannerUtama() {
    cout
         << CYAN   << "XXXXXXX    XXXXXX       XXXXX   XXXXXX   XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n" 
         << CYAN   << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n"  
         << CYAN   << "XXX  XXX  XXX  XXX      XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
         << WHITE  << "XXX  XXXX XXX  XXXX     XXXXX  XXX  XXXX XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
         << WHITE  << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
         << WHITE  << "XXXXXXX   XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
         << CYAN   << "XXX       XXX  XXX  XX  XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
         << CYAN   << "XXX       XXX  XXX  XXXXXXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXXXXXXXX \n"  
         << CYAN   << "XXX       XXX  XXX   XXXXXXX   XXX  XXX  XXXX  XXXX  XXXX  XXXX   XXXXXXXX  \n"  
         << WHITE  << "___________________________________________________________________________\n"
         << WHITE  << "|__________________________________________________________________________|\n"
         << WHITE  << "|                                                                          |\n"
         << WHITE  << "|" << YELLOW << "                      SISTEM PEMBAYARAN PAJAK KENDARAAN                   " << WHITE << "|\n" 
         << WHITE  << "|__________________________________________________________________________|\n"
         << WHITE  << "|__________________________________________________________________________|\n" << RESET << endl;
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
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                          [ TAMBAH DATA KENDARAAN ]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    
    while (true) {
        cout << "Masukkan Nomor Plat (contoh: DR 1234 AB) : ";
        getline(cin, platNomor[jumlahKendaraan]);
        if (!platNomor[jumlahKendaraan].empty()) {
            break; 
        }
        cout << RED << "[ERROR] Plat nomor tidak boleh kosong!\n" << RESET;
    }
    
    while (true) {
        cout << "Masukkan Nama Pemilik                    : ";
        getline(cin, namaPemilik[jumlahKendaraan]);
        if (!namaPemilik[jumlahKendaraan].empty()) {
            break;
        }
        cout << RED << "[ERROR] Nama pemilik tidak boleh kosong!\n" << RESET;
    }
    while(true)
{
    cout << "Masukkan Username Pemilik                : ";
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
    cout << RED
         << "[ERROR] Username tidak terdaftar!\n"
         << RESET;
}
    while (true) {
        cout << "Masukkan Jenis Kendaraan (Mobil/Motor)   : ";
        getline(cin, jenisKendaraan[jumlahKendaraan]);
        if (jenisKendaraan[jumlahKendaraan] == "Mobil" || jenisKendaraan[jumlahKendaraan] == "Motor" || 
            jenisKendaraan[jumlahKendaraan] == "mobil" || jenisKendaraan[jumlahKendaraan] == "motor") {
            break;
        }
        cout << RED << "[ERROR] Jenis kendaraan harus berupa 'Mobil' atau 'Motor'!\n" << RESET;
    }
   
    while (true) {
        cout << "Masukkan Besar Pajak Tahunan (Rp)        : "; cin >> besarPajak[jumlahKendaraan];
  
        if (cin.fail() || besarPajak[jumlahKendaraan] < 0) {
            cin.clear();            
            cin.ignore(1000, '\n'); 
            cout << RED << "[ERROR] Input tidak valid! Masukkan nominal angka yang benar.\n" << RESET;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    
    cout << endl << GREEN << "[SISTEM] Data kendaraan berhasil ditambahkan!\n" << RESET;
    cout << endl << "----------------------------------------------------------------------------" << endl;
    cout << "Plat Nomor      : " << platNomor[jumlahKendaraan] << endl;
    cout << "Pemilik         : " << namaPemilik[jumlahKendaraan] << endl;
    cout << "Jenis           : " << jenisKendaraan[jumlahKendaraan] << endl;
    cout << "Pajak Tahunan   : Rp " << besarPajak[jumlahKendaraan] << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    jumlahKendaraan++;
    pauseLayar();
}

void editDataKendaraan() {
    hapusLayar();
    bannerUtama();
    cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                     [ PILIH DATA YANG INGIN DI EDIT ]                      " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;
    }
    hapusLayar();
    bannerUtama();
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                     [ PILIH DATA YANG INGIN DI EDIT ]                      " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << " [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    
    int nomorData;
    while (true) {
        cout << "Masukkan nomor data kendaraan yang mau diedit: ";
        cin >> nomorData;
        if (cin.fail() || nomorData < 1 || nomorData > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[ERROR] Nomor tidak valid!\n" << RESET;
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
        cout << GREEN  << "============================================================================" << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << CYAN   << "                            [ EDIT DATA KENDARAAN ]                         " << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << GREEN  << "============================================================================" << RESET << endl;

        cout << "Data Saat Ini:\n";
        if (pilihanEdit == 0) cout << GREEN << " [1] Plat Nomor         : " << platNomor[idx] << " <\n" << RESET;
        else cout << "[1] Plat Nomor         : " << platNomor[idx] << "\n";
        
        if (pilihanEdit == 1) cout << GREEN << " [2] Nama Pemilik       : " << namaPemilik[idx] << " <\n" << RESET;
        else cout << "[2] Nama Pemilik       : " << namaPemilik[idx] << "\n";
        
        if (pilihanEdit == 2) cout << GREEN << " [3] Username Pemilik   : " << usernamePemilik[idx] << " <\n" << RESET;
        else cout << "[3] Username Pemilik   : " << usernamePemilik[idx] << "\n";
        
        if (pilihanEdit == 3) cout << GREEN << " [4] Jenis Kendaraan    : " << jenisKendaraan[idx] << " <\n" << RESET;
        else cout << "[4] Jenis Kendaraan    : " << jenisKendaraan[idx] << "\n";
        
        if (pilihanEdit == 4) cout << GREEN << " [5] Pajak Tahunan      : Rp " << besarPajak[idx] << " <\n" << RESET;
        else cout << "[5] Pajak Tahunan      : Rp " << besarPajak[idx] << "\n";
        
        if (pilihanEdit == 5) cout << GREEN << " [0] Selesai Mengedit <\n" << RESET;
        else cout << " [0] Selesai Mengedit\n";
        cout << "----------------------------------------------------------------------------" << endl;

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

            if (pilihanEdit == 0) {
                cout << "Masukkan Nomor Plat Baru (misal: DK 1234 AB): ";
                getline(cin, platNomor[idx]);
                cout << GREEN << "[SISTEM] Plat nomor berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 1) {
                cout << "Masukkan Nama Pemilik Baru: ";
                getline(cin, namaPemilik[idx]);
                cout << GREEN << "[SISTEM] Nama pemilik berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 2){
                cout << "Masukkan Username Baru : ";
                getline(cin, usernamePemilik[idx]);
                cout << GREEN << "[SISTEM] Username berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 3) {
                cout << "Masukkan Jenis Kendaraan Baru (Mobil/Motor): ";
                getline(cin, jenisKendaraan[idx]);
                cout << GREEN << "[SISTEM] Jenis kendaraan berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 4) {
                cout << "Masukkan Besar Pajak Tahunan Baru (Rp): ";
                cin >> besarPajak[idx];
                cin.ignore(10000, '\n');
                cout << GREEN << "[SISTEM] Besar pajak berhasil diperbarui!\n" << RESET;
                pauseLayar();
            }
            else if (pilihanEdit == 5) {
                cout << GREEN << "[SISTEM] Keluar dari menu edit. Perubahan disimpan!\n" << RESET;
                isSelesai = true;
            }
        }
    } while (!isSelesai);
}

void lihatKendaraan() {
    hapusLayar();
    bannerUtama();
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                        [ DAFTAR KENDARAAN TERDAFTAR ]                      " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;     
    }

    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << YELLOW << "Detail Informasi Kendaraan ke-" << i + 1 << ":" << RESET << endl;
        cout << "1. Nomor Plat        : " << platNomor[i] << endl;
        cout << "2. Nama Pemilik      : " << namaPemilik[i] << endl;
        cout << "3. Username Pemilik  : " << usernamePemilik[i] << endl;
        cout << "4. Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
        cout << "5. Pajak Tahunan     : Rp " << besarPajak[i] << endl;
        cout << YELLOW << "----------------------------------------------------------------------------" << RESET << endl;
    }
    pauseLayar();
}

void hapusKendaraan() {
    hapusLayar();
    bannerUtama();
    cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                           [ HAPUS DATA KENDARAAN ]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        return;  
    }

    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "  [" << i + 1 << "] Plat: " << platNomor[i] << " | Pemilik: " << namaPemilik[i] << endl;
    }
    cout << "--------------------------------------------------------------\n";

    int nomorHapus;
    while (true) {
        cout << "Masukkan nomor kendaraan yang ingin dihapus : "; cin >> nomorHapus;

        if (cin.fail() || nomorHapus < 1 || nomorHapus > jumlahKendaraan) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[ERROR] Nomor tidak valid! Masukkan angka sesuai daftar di atas.\n" << RESET;
        } else {
            break; 
        }
    }

    int indeksHapus = nomorHapus - 1;

    char konfirmasi;
    while (true) {
        cout << RED << "Yakin ingin menghapus data milik " << namaPemilik[indeksHapus] << "? (Y/N) : " << RESET;
        cin >> konfirmasi;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "[ERROR] Input salah! Masukkan Y atau N.\n" << RESET;
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
            cout << GREEN << "[SISTEM] Data kendaraan berhasil dihapus secara permanen!\n" << RESET;
            cin.get();
            pauseLayar();
            break;
        } 
        else if (konfirmasi == 'N' || konfirmasi == 'n') {
            cout << YELLOW << "[SISTEM] Penghapusan dibatalkan. Data tetap aman.\n" << RESET;
            cin.get();
            pauseLayar();
            break;
        } 
        else {
            cout << RED << "[ERROR] Masukkan 'Y' untuk setuju atau 'N' untuk batal.\n" << RESET;
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
            cout << GREEN <<
            "============================================================================\n"
            "|                     [1] Tambah Kendaraan                                <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [1] Tambah Kendaraan                                 |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [2] Edit Data Kendaraan                             <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [2] Edit Data Kendaraan                              |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [3] Lihat Kendaraan                                 <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [3] Lihat Kendaraan                                  |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 3) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [4] Hapus Kendaraan                                 <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [4] Hapus Kendaraan                                  |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 4) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [0] Kembali                                         <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [0] Kembali                                          |\n"
            "============================================================================\n";
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
                cout << "[LOADING] Kembali ke menu utama...\n";
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
        cout << GREEN  << "============================================================================" << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << CYAN   << "                           [ LAPORAN PAJAK ADMIN ]                          " << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << GREEN  << "============================================================================" << RESET << endl;
        
        if (pilihan == 0) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [1] Pembayaran Pajak                                <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [1] Pembayaran Pajak                                 |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [2] Hitung Denda Keterlambatan                      <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [2] Hitung Denda Keterlambatan                       |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [3] Riwayat Pembayaran                              <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [3] Riwayat Pembayaran                               |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 3) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [0] Kembali                                         <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [0] Kembali                                          |\n"
            "============================================================================\n";
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
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                             [ PEMBAYARAN PAJAK ]                           " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0){
                    cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                for (int i = 0; i < jumlahKendaraan; i++){
                    cout << i + 1 << ". " << platNomor[i] << " | " << namaPemilik[i];
                    if (statusBayar[i])
                        cout << " ("<<GREEN<<"LUNAS"<<RESET<<")"<< endl;
                    else 
                        cout << endl;
                }
                int pilih;
                cout << "Pilih kendaraan : ";
                cin >> pilih;
                if (cin.fail() || pilih < 1 || pilih > jumlahKendaraan){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << RED << "[ERROR] Pilihan kendaraan tidak valid!\n" << RESET;
                    pauseLayar();
                    continue;
                }
                int idx = pilih - 1;
                if (statusBayar[idx]){
                    cout << GREEN << "[SISTEM] Pajak kendaraan ini sudah lunas!\n" << RESET;
                    cin.get();
                    pauseLayar();
                    continue;
                }
                int totalTagihan = besarPajak[idx] + denda[idx];
                cout << "Plat Nomor      : " << platNomor[idx] << endl;
                cout << "Pemilik         : " << namaPemilik[idx] << endl;
                cout << "Pajak Pokok     : Rp " << besarPajak[idx] << endl;
                cout << "Denda           : Rp " << denda[idx] << endl;
                cout << "Total Bayar     : Rp " << totalTagihan << endl;

                int uangDibayar;
                cout << "Masukkan uang pembayaran : Rp ";
                cin >> uangDibayar;

                if (uangDibayar < totalTagihan){
                    cout << RED << "Pembayaran gagal!\n" << RESET;
                    cout << "Uang kurang Rp " << totalTagihan - uangDibayar << endl;
                }
                else{
                    int kembalian = uangDibayar - totalTagihan;
                    statusBayar[idx] = true;
                    cout << GREEN << "\nPembayaran berhasil!\n" << RESET;
                    cout << "Uang Dibayar    : Rp " << uangDibayar << endl;
                    cout << "Kembalian       : Rp " << kembalian << endl;
                    cout << "Status Pajak    : LUNAS\n";
                }
                cin.get();
                pauseLayar();
            }
            else if (pilihan == 1){
                hapusLayar();
                bannerUtama();
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                      [ HITUNG DENDA KETERLAMBATAN ]                        " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0){
                    cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                for (int i = 0; i < jumlahKendaraan; i++){
                    cout << i + 1 << ". "<< platNomor[i]<< " | "<< namaPemilik[i]<< endl;
                }

                int pilih;
                cout << "Pilih kendaraan : ";
                cin >> pilih;

                if (cin.fail() || pilih < 1 || pilih > jumlahKendaraan){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
                }
                else{
                    int bulan;
                    cout << "Masukkan jumlah bulan keterlambatan : ";
                    cin >> bulan;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    } else {
                        int idx = pilih - 1;
                        denda[idx] = besarPajak[idx] * 2 * bulan / 100;
                        cout << "Pajak Pokok     : Rp "<< besarPajak[idx] << endl;
                        cout << "Denda           : Rp "<< denda[idx] << endl;
                        cout << "Total Tagihan   : Rp "<< besarPajak[idx] + denda[idx]<< endl;
                    }
                }
                cin.get();
                pauseLayar();
            }
            else if (pilihan == 2){
                hapusLayar();
                bannerUtama();
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                            [ RIWAYAT PEMBAYARAN ]                          " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                bool ada = false;
                for (int i = 0; i < jumlahKendaraan; i++){
                    if (statusBayar[i]){
                        ada = true;
                        cout << "============================================================================\n";
                        cout << "Plat Nomor      : " << platNomor[i] << endl;
                        cout << "Nama Pemilik    : "<< namaPemilik[i] << endl;
                        cout << "Jenis Kendaraan : " << jenisKendaraan[i] << endl;
                        cout << "Pajak Pokok     : Rp " << besarPajak[i] << endl;
                        cout << "Denda           : Rp "<< denda[i] << endl;
                        cout << "Total Bayar     : Rp "<< besarPajak[i] + denda[i]<< endl;
                        cout << "Status          : LUNAS\n";
                        cout << "============================================================================\n";
                    }
                }

                if (!ada){
                    cout << YELLOW << "[PERINGATAN] Belum ada riwayat pembayaran.\n" << RESET;
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
        cout << GREEN  << "============================================================================" << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << CYAN   << "                            [ CARI DATA PENGGUNA ]                          " << endl;
        cout << WHITE  << "----------------------------------------------------------------------------" << endl;
        cout << GREEN  << "============================================================================" << RESET << endl;
        
        if (pilihan == 0) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [1] Cari Berdasarkan Plat Nomor                     <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [1] Cari Berdasarkan Plat Nomor                      |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [2] Cari Berdasarkan Nama Pemilik                   <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [2] Cari Berdasarkan Nama Pemilik                    |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [0] Kembali                                         <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [0] Kembali                                          |\n"
            "============================================================================\n";
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
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                      [ CARI BERDASARKAN PLAT NOMOR ]                       " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;    
                if (jumlahKendaraan == 0) {
                    cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                hapusLayar();
                bannerUtama();
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                      [ CARI BERDASARKAN PLAT NOMOR ]                       " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                string cariPlat;
                cout << "Masukkan Plat Nomor yang dicari: ";
                getline(cin, cariPlat);

                bool ditemukan = false;
                for (int i = 0; i < jumlahKendaraan; i++) {
                    if (platNomor[i].find(cariPlat) != string::npos) {
                        cout << "  Detail Informasi Kendaraan:" << endl;
                        cout << "  - Nomor Plat        : " << platNomor[i] << endl;
                        cout << "  - Nama Pemilik      : " << namaPemilik[i] << endl;
                        cout << "  - Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
                        cout << "  - Pajak Tahunan     : Rp " << besarPajak[i] << endl;
                        cout << "  --------------------------------------------------------" << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    cout << RED << "  [ERROR] Data dengan plat nomor '" << cariPlat << "' tidak ditemukan.\n" << RESET;
                }
                pauseLayar();
            } 
            else if (pilihan == 1) {
                hapusLayar();
                bannerUtama();
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                     [ CARI BERDASARKAN NAMA PEMILIK ]                      " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                if (jumlahKendaraan == 0) {
                    cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                    pauseLayar();
                    continue;
                }

                hapusLayar();
                bannerUtama();
                cout << GREEN  << "============================================================================" << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << CYAN   << "                     [ CARI BERDASARKAN NAMA PEMILIK ]                      " << endl;
                cout << WHITE  << "----------------------------------------------------------------------------" << endl;
                cout << GREEN  << "============================================================================" << RESET << endl;
                string cariNama;
                cout << "Masukkan Nama Pemilik yang dicari: ";
                getline(cin, cariNama);

                bool ditemukan = false;
                for (int i = 0; i < jumlahKendaraan; i++) {
                    if (namaPemilik[i].find(cariNama) != string::npos) {
                        cout << "  Detail Informasi Kendaraan:" << endl;
                        cout << "  - Nomor Plat        : " << platNomor[i] << endl;
                        cout << "  - Nama Pemilik      : " << namaPemilik[i] << endl;
                        cout << "  - Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
                        cout << "  - Pajak Tahunan     : Rp " << besarPajak[i] << endl;
                        cout << "  --------------------------------------------------------" << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    cout << RED << "  [ERROR] Data dengan nama pemilik '" << cariNama << "' tidak ditemukan.\n" << RESET;
                }
                pauseLayar();;
            } 
            else if (pilihan == 2) {
                cout << "[LOADING] Kembali ke menu utama...\n";
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
            cout << GREEN <<
            "============================================================================\n"
            "|                     [1] Manajemen Kendaraan                             <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [1] Manajemen Kendaraan                              |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [2] Laporan Pajak                                   <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [2] Laporan Pajak                                    |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [3] Cari Data Pengguna                              <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [3] Cari Data Pengguna                               |\n"
            "============================================================================\n";
        }

        if (pilihan == 3) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [0] Logout                                          <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [0] Logout                                           |\n"
            "============================================================================\n";
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

    cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                          [ DAFTAR KENDARAAN SAYA ]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username)
        {
            ditemukan = true;

            cout << "Plat Nomor      : " << platNomor[i] << endl;
            cout << "Nama Pemilik    : " << namaPemilik[i] << endl;
            cout << "Jenis Kendaraan : " << jenisKendaraan[i] << endl;
            cout << "Pajak Tahunan   : Rp " << besarPajak[i] << endl;

            if(statusBayar[i])
                cout << "Status Pajak    : " << GREEN << "LUNAS\n" << RESET;
            else
                cout << "Status Pajak    : " << RED << "BELUM LUNAS\n" << RESET;

            cout << "----------------------------------------------------------------------------" << endl;
        }
    }

    if(!ditemukan)
    {
        cout << YELLOW << "[PERINGATAN] Belum ada kendaraan terdaftar.\n" << RESET;
    }

    pauseLayar();
}
void bayarPajakPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ditemukan = false;

	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                            [ PEMBAYARAN PAJAK ]                            " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username)
        {
            ditemukan = true;

            cout << i + 1 << ". " << platNomor[i] << " | Rp " << besarPajak[i];

            if(statusBayar[i])
                cout << " | " << GREEN << "LUNAS" << RESET;

            cout << endl;
        }
    }

    if(!ditemukan)
    {
        cout << YELLOW << "[PERINGATAN] Tidak ada kendaraan.\n" << RESET;
        pauseLayar();
        return;
    }

    int pilih;
    cout << "Pilih kendaraan : ";
    cin >> pilih;

    if(pilih < 1 || pilih > jumlahKendaraan)
    {
        cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
        pauseLayar();
        cin.ignore();
        return;
    }

    pilih--;

    int *tagihan = &besarPajak[pilih];

    cout << "Total Tagihan : Rp "
         << *tagihan << endl;

    char bayar;

    cout << "Bayar sekarang? (Y/N) : ";
    cin >> bayar;

    if(bayar == 'Y' || bayar == 'y')
    {
        statusBayar[pilih] = true;

        cout << GREEN << "[SISTEM] Pembayaran berhasil!\n" << RESET;
    }
    cin.get();
    pauseLayar();
}
void hitungDendaPengguna(string username)
{
    hapusLayar();
    bannerUtama();

	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                           [ PERHITUNGAN DENDA ]                            " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

    string plat;

    cout << "Masukkan plat kendaraan : ";
    getline(cin, plat);

    bool ditemukan = false;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(platNomor[i] == plat &&
           usernamePemilik[i] == username)
        {
            ditemukan = true;

            int bulan;

            cout << "Jumlah bulan terlambat : ";
            cin >> bulan;

            int *pPajak = &besarPajak[i];

            int hasilDenda =
                (*pPajak * 2 * bulan) / 100;

            cout << "Pajak Pokok : Rp " << *pPajak << endl;

            cout << "Denda : Rp " << hasilDenda << endl;

            cout << "Total : Rp " << *pPajak + hasilDenda << endl;

            break;
        }
    }

    if(!ditemukan)
    {
        cout << RED << "[ERROR] Kendaraan tidak ditemukan.\n" << RESET;
    }

    pauseLayar();
}
void riwayatPembayaranPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ada = false;

	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                           [ RIWAYAT PEMBAYARAN ]                           " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username &&
           statusBayar[i])
        {
            ada = true;

            cout << "Plat Nomor : " << platNomor[i] << endl;

            cout << "Pajak : Rp " << besarPajak[i] << endl;

            cout << "Status : LUNAS\n";

            cout << "---------------------------\n";
        }
    }

    if(!ada)
    {
        cout << YELLOW << "[PERINGATAN] Belum ada riwayat pembayaran.\n" << RESET;
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
            cout << GREEN <<
            "============================================================================\n"
            "|                     [1] Daftar Kendaraan Saya                           <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [1] Daftar Kendaraan Saya                            |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [2] Pembayaran Pajak                                <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [2] Pembayaran Pajak                                 |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [3] Perhitungan Denda                               <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [3] Perhitungan Denda                                |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 3) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [4] Riwayat Pembayaran                              <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [4] Riwayat Pembayaran                               |\n"
            "============================================================================\n";
        }
        
        if (pilihan == 4) {
            cout << GREEN <<
            "============================================================================\n"
            "|                     [0] Logout                                          <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                     [0] Logout                                           |\n"
            "============================================================================\n";
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
        cout << RED << endl << "[ERROR] Memori pengguna penuh!" << endl << RESET;
        return;
    }
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                         [ REGISTRASI AKUN PAJAKKU]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    string user, password, konfirmasiPassword, namaLengkap;
    bool isUserValid = false;
    do {
        cout << "Masukkan Username     : "; getline(cin, user);
        cout << "Masukkan Nama Lengkap : "; getline(cin, namaLengkap);
        bool isSudahAda = false;
        for (int i = 0; i < totalPengguna; i++) {
            if (dataPengguna[i].username == user) {
                isSudahAda = true;
            }
        }
        
        if (isSudahAda == true) {
            cout << RED << "[ERROR] Username sudah terdaftar!" << endl << RESET;
        } else if (user == "") {
            cout << RED << "[ERROR] Username tidak boleh kosong!" << endl << RESET;
        } else {
            isUserValid = true;
        }
    } while (isUserValid == false);
    
    bool isPasswordValid = false;
    do {
        cout << "Masukkan Password     : ";
        getline(cin, password);
        cout << "Konfirmasi Password   : ";
        getline(cin, konfirmasiPassword);
        
        if (password != konfirmasiPassword) {
            cout << RED << "[ERROR] Password tidak cocok!" << endl << RESET;
        } else if (password == "") {
            cout << RED << "[ERROR] Password tidak boleh kosong!" << endl << RESET;
        } else {
            isPasswordValid = true;
        }
    } while (isPasswordValid == false);
    
    dataPengguna[totalPengguna].username = user;
    dataPengguna[totalPengguna].namaLengkap = namaLengkap;
    dataPengguna[totalPengguna].password = password;
    dataPengguna[totalPengguna].admin = "pengguna";
    totalPengguna++;
    
    cout << GREEN << endl << "[SISTEM] Registrasi berhasil! Silahkan login." << endl << RESET;
}

void login() {
    hapusLayar();
    bannerUtama();
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                              [ LOGIN KE PAJAKKU ]                          " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    string user, password;
    cout << "Username : "; getline(cin, user);
    cout << "Password : "; getline(cin, password);
    
    bool isLoginBerhasil = false;
    for (int i = 0; i < totalPengguna; i++) {
        if (dataPengguna[i].username == user && dataPengguna[i].password == password) {
            cout << GREEN << endl << "[SISTEM] Login berhasil sebagai " << dataPengguna[i].admin << "!" << endl << RESET;
            pauseLayar();
            isLoginBerhasil = true;
            if (dataPengguna[i].admin == "admin") {
                menuAdmin();
            } else {
                menuPengguna(dataPengguna[i].username);
            }
        }
    }
    
    if (isLoginBerhasil == false) {
        cout << RED << endl << "[ERROR] Username atau Password salah!" << endl << RESET;
    }
}

void menuAwal() {
    int pilihMenu = 0;
    bool isKeluar = false;
    do {
        hapusLayar();
        bannerUtama();     
        if (pilihMenu == 0) {
            cout << GREEN <<
            "============================================================================\n"
            "|                                  [1] Login                              <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout << 
            "============================================================================\n"
            "|                                  [1] Login                               |\n"
            "============================================================================\n";
        }

        if (pilihMenu == 1) {
            cout << GREEN <<
            "============================================================================\n"
            "|                                  [2] Daftar                             <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout <<
            "============================================================================\n"
            "|                                  [2] Daftar                              |\n"
            "============================================================================\n";
        }

        if (pilihMenu == 2) {
            cout << GREEN <<
            "============================================================================\n"
            "|                                  [0] Keluar                             <|\n"
            "============================================================================\n"
            << RESET;
        } else {
            cout <<
            "============================================================================\n"
            "|                                  [0] Keluar                              |\n"
            "============================================================================\n";
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
                cout << endl << "Keluar dari program..." << endl;
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