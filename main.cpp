#include <iostream>
#include <conio.h>
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
         << RED    << "XXXXXXX    XXXXXX       XXXXX   XXXXXX   XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n" 
                   << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXX  XXXX  XXXX  XXXX  XXXX  XXXX\n"  
          		   << "XXX  XXX  XXX  XXX      XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "XXX  XXXX XXX  XXXX     XXXXX  XXX  XXXX XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "XXXXXXXX  XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
                   << "XXXXXXX   XXXXXXXX      XXXXX  XXXXXXXX  XXXXXXXX    XXXXXXXX    XXXX  XXXX \n"  
                   << "XXX       XXX  XXX  XX  XXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXX  XXXX \n"  
                   << "XXX       XXX  XXX  XXXXXXXXX  XXX  XXX  XXX  XXXX   XXX  XXXX   XXXXXXXXXX \n"  
                   << "XXX       XXX  XXX   XXXXXXX   XXX  XXX  XXXX  XXXX  XXXX  XXXX   XXXXXXXX  \n"  
                   << "___________________________________________________________________________\n"
                   << "|__________________________________________________________________________|\n"
                   << "|                                                                          |\n"
                   << "|                      SISTEM PEMBAYARAN PAJAK KENDARAAN                   |\n" 
                   << "|__________________________________________________________________________|\n"
                   << "|__________________________________________________________________________|\n" << RESET << endl;
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
    
    cin.ignore(); 
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
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        cin.get();
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
            break;
        }
    }
    int idx = nomorData - 1; 
    int pilihanEdit;
    
    do {
        hapusLayar();
        bannerUtama();
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                            [ EDIT DATA KENDARAAN ]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

        cout << "Data Saat Ini:\n";
        cout << " [1] Plat Nomor    : " << platNomor[idx] << endl;
        cout << " [2] Nama Pemilik  : " << namaPemilik[idx] << endl;
        cout << " [3] Username Pemilik : " << usernamePemilik[idx] << endl;
        cout << " [4] Jenis         : " << jenisKendaraan[idx] << endl;
        cout << " [5] Pajak Tahunan : Rp " << besarPajak[idx] << endl;
        cout << " [0] Selesai Mengedit\n";
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Pilih nomor komponen data yang ingin diubah : "; cin >> pilihanEdit;

        if (pilihanEdit == 1) {
            cin.ignore(); 
            cout << "Masukkan Nomor Plat Baru (misal: DK 1234 AB): ";
            getline(cin, platNomor[idx]);
            cout << GREEN << "[SISTEM] Plat nomor berhasil diperbarui!\n" << RESET;
            pauseLayar();
        }
        else if (pilihanEdit == 2) {
            cin.ignore();
            cout << "Masukkan Nama Pemilik Baru: ";
            getline(cin, namaPemilik[idx]);
            cout << GREEN << "[SISTEM] Nama pemilik berhasil diperbarui!\n" << RESET;
            pauseLayar();
        }
        else if (pilihanEdit == 3){
            cin.ignore();
            cout << "Masukkan Username Baru : ";
            getline(cin, usernamePemilik[idx]);
            cout << GREEN << "[SISTEM] Username berhasil diperbarui!\n" << RESET;
            pauseLayar();
        }
        else if (pilihanEdit == 4) {
            cin.ignore();
            cout << "Masukkan Jenis Kendaraan Baru (Mobil/Motor): ";
            getline(cin, jenisKendaraan[idx]);
            cout << GREEN << "[SISTEM] Jenis kendaraan berhasil diperbarui!\n" << RESET;
            pauseLayar();
        }
        else if (pilihanEdit == 5) {
            cout << "Masukkan Besar Pajak Tahunan Baru (Rp): ";
            cin >> besarPajak[idx];
            cin.ignore(10000, '\n');
            cout << GREEN << "[SISTEM] Besar pajak berhasil diperbarui!\n" << RESET;
            pauseLayar();
        }
        else if (pilihanEdit == 0) {
            cout << GREEN << "[SISTEM] Keluar dari menu edit. Perubahan disimpan!\n" << RESET;
        }
        else {
            cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
            pauseLayar();
        }

    } while (pilihanEdit != 0);
}

void lihatKendaraan() {
    hapusLayar();
    bannerUtama();
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        cin.get();
        return;     
    }
	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                        [ DAFTAR KENDARAAN TERDAFTAR ]                      " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;

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
    cin.get();  
}

void hapusKendaraan() {
    hapusLayar();
    bannerUtama();
    if (jumlahKendaraan == 0) {
        cout << YELLOW << "[PERINGATAN] Belum ada data kendaraan yang terdaftar!\n" << RESET;
        pauseLayar();
        cin.get();
        return;  
    }

	cout << GREEN  << "============================================================================" << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << CYAN   << "                           [ HAPUS DATA KENDARAAN ]                         " << endl;
	cout << WHITE  << "----------------------------------------------------------------------------" << endl;
	cout << GREEN  << "============================================================================" << RESET << endl;
    
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
            pauseLayar();
            cin.get();
            break;
        } 
        else if (konfirmasi == 'N' || konfirmasi == 'n') {
            cout << YELLOW << "[SISTEM] Penghapusan dibatalkan. Data tetap aman.\n" << RESET;
            pauseLayar();
            cin.get();
            break;
        } 
        else {
            cout << RED << "[ERROR] Masukkan 'Y' untuk setuju atau 'N' untuk batal.\n" << RESET;
        }
    }
}

void manajemenKendaraanAdmin(){
    int pilihan;
    do {
        hapusLayar();
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
        } 
        else if (pilihan == 2) {
            editDataKendaraan();
        } 
        else if (pilihan == 3) {
            lihatKendaraan();
        } 
        else if (pilihan == 4) {
            hapusKendaraan();
        } 
        else if (pilihan == 0) {
            cout << "[LOADING] Kembali ke menu utama...\n";
        } 
        else {
            cout << RED << "[ERROR] Pilihan tidak valid!\n" << RESET;
            pauseLayar();
        }
    } while (pilihan != 0); 
}

void laporanPajakAdmin(){
    int pilihan;
    do{
        hapusLayar();
        bannerUtama();
        cout << "===== LAPORAN PAJAK ADMIN =====\n";
        cout << "[1] Pembayaran Pajak\n";
        cout << "[2] Hitung Denda Keterlambatan\n";
        cout << "[3] Riwayat Pembayaran\n";
        cout << "[0] Kembali\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -1;
        }
        switch (pilihan){
        case 1:{
            hapusLayar();
            bannerUtama();
            if (jumlahKendaraan == 0){
                cout << "Belum ada data kendaraan!\n";
                cin.ignore(10000, '\n');
                cin.get();
                break;
            }
            cout << "===== PEMBAYARAN PAJAK =====\n";
            for (int i = 0; i < jumlahKendaraan; i++){
                cout << i + 1 << ". " << platNomor[i] << " | " << namaPemilik[i];
                if (statusBayar[i])
                    cout << " (LUNAS)"<< endl;
            }
            int pilih;
            cout << "\nPilih kendaraan : ";
            cin >> pilih;
            if (pilih < 1 || pilih > jumlahKendaraan){
                cout << "Pilihan kendaraan tidak valid!\n";
                cin.ignore(10000, '\n');
                cin.get();
                break;
            }
            int idx = pilih - 1;
            if (statusBayar[idx]){
                cout << "\nPajak kendaraan ini sudah lunas!\n";
                cin.ignore(10000, '\n');
                cin.get();
                break;
            }
            int totalTagihan = besarPajak[idx] + denda[idx];
            cout << "\nPlat Nomor   : " << platNomor[idx] << endl;
            cout << "Pemilik      : " << namaPemilik[idx] << endl;
            cout << "Pajak Pokok  : Rp " << besarPajak[idx] << endl;
            cout << "Denda        : Rp " << denda[idx] << endl;
            cout << "Total Bayar  : Rp " << totalTagihan << endl;

            int uangDibayar;
            cout << "\nMasukkan uang pembayaran : Rp ";
            cin >> uangDibayar;

            if (uangDibayar < totalTagihan){
                cout << "\nPembayaran gagal!\n";
                cout << "Uang kurang Rp " << totalTagihan - uangDibayar << endl;
            }
            else{
                int kembalian = uangDibayar - totalTagihan;
                statusBayar[idx] = true;
                cout << "\nPembayaran berhasil!\n";
                cout << "Uang Dibayar : Rp " << uangDibayar << endl;
                cout << "Kembalian    : Rp " << kembalian << endl;
                cout << "Status Pajak : LUNAS\n";
            }
            cin.ignore(10000, '\n');
            cout << "\nTekan ENTER untuk kembali...";
            cin.get();
            break;
        }
        case 2:{
            hapusLayar();
            bannerUtama();
            if (jumlahKendaraan == 0){
                cout << "Belum ada data kendaraan!\n";
                cin.ignore(10000, '\n');
                cin.get();
                break;
            }
            cout << "===== HITUNG DENDA =====\n";
            for (int i = 0; i < jumlahKendaraan; i++){
                cout << i + 1 << ". "<< platNomor[i]<< " | "<< namaPemilik[i]<< endl;
            }

            int pilih;
            cout << "\nPilih kendaraan : ";
            cin >> pilih;

            if (pilih < 1 || pilih > jumlahKendaraan){
                cout << "Pilihan tidak valid!\n";
            }
            else{
                int bulan;
                cout << "Masukkan jumlah bulan keterlambatan : ";
                cin >> bulan;
                int idx = pilih - 1;
                denda[idx] = besarPajak[idx] * 2 * bulan / 100;
                cout << "\nPajak Pokok : Rp "<< besarPajak[idx] << endl;
                cout << "Denda       : Rp "<< denda[idx] << endl;
                cout << "Total Tagihan : Rp "<< besarPajak[idx] + denda[idx]<< endl;
            }
            cin.ignore(10000, '\n');
            cout << "\nTekan ENTER untuk kembali...";
            cin.get();
            break;
        }

        case 3:{
            hapusLayar();
            bannerUtama();
            cout << "===== RIWAYAT PEMBAYARAN =====\n\n";
            bool ada = false;
            for (int i = 0; i < jumlahKendaraan; i++){
                if (statusBayar[i]){
                    ada = true;
                    cout << "====================================\n";
                    cout << "Plat Nomor      : " << platNomor[i] << endl;
                    cout << "Nama Pemilik    : "<< namaPemilik[i] << endl;
                    cout << "Jenis Kendaraan : " << jenisKendaraan[i] << endl;
                    cout << "Pajak Pokok     : Rp " << besarPajak[i] << endl;
                    cout << "Denda           : Rp "<< denda[i] << endl;
                    cout << "Total Bayar     : Rp "<< besarPajak[i] + denda[i]<< endl;
                    cout << "Status          : LUNAS\n";
                    cout << "====================================\n";
                }
            }

            if (!ada){
                cout << "Belum ada riwayat pembayaran.\n";
            }
            cin.ignore(10000, '\n');
            cout << "\nTekan ENTER untuk kembali...";
            cin.get();
            break;
        }
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            cin.ignore(10000, '\n');
            cin.get();
        }

    } while (pilihan != 0);
}

void menuAdmin() {
    int pilihan;
    do{
    hapusLayar();
    bannerUtama();
    cout << "[1] Manajemen Kendaraan\n";
    cout << "[2] Laporan Pajak\n";
    cout << "[0] Logout\n";
    cout << "Masukkan Pilihan: "; cin >> pilihan;
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
}while(pilihan != 0);
}

void lihatKendaraanSaya(string username)
{
    hapusLayar();
    bannerUtama();

    bool ditemukan = false;

    cout << "===== KENDARAAN SAYA =====\n\n";

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
                cout << "Status Pajak    : LUNAS\n";
            else
                cout << "Status Pajak    : BELUM LUNAS\n";

            cout << "-------------------------------------\n";
        }
    }

    if(!ditemukan)
    {
        cout << "Belum ada kendaraan terdaftar.\n";
    }

    pauseLayar();
}
void bayarPajakPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ditemukan = false;

    cout << "===== PEMBAYARAN PAJAK =====\n\n";

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username)
        {
            ditemukan = true;

            cout << i + 1 << ". " << platNomor[i] << " | Rp " << besarPajak[i];

            if(statusBayar[i])
                cout << " | LUNAS";

            cout << endl;
        }
    }

    if(!ditemukan)
    {
        cout << "Tidak ada kendaraan.\n";
        pauseLayar();
        return;
    }

    int pilih;
    cout << "\nPilih kendaraan : ";
    cin >> pilih;

    if(pilih < 1 || pilih > jumlahKendaraan)
    {
        cout << "Pilihan tidak valid!\n";
        pauseLayar();
        return;
    }

    pilih--;

    int *tagihan = &besarPajak[pilih];

    cout << "\nTotal Tagihan : Rp "
         << *tagihan << endl;

    char bayar;

    cout << "Bayar sekarang? (Y/N) : ";
    cin >> bayar;

    if(bayar == 'Y' || bayar == 'y')
    {
        statusBayar[pilih] = true;

        cout << "\nPembayaran berhasil!\n";
    }

    pauseLayar();
}
void hitungDendaPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    cout << "===== HITUNG DENDA =====\n\n";

    string plat;

    cin.ignore();

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

            cout << "\nPajak Pokok : Rp "
                 << *pPajak << endl;

            cout << "Denda : Rp "
                 << hasilDenda << endl;

            cout << "Total : Rp "
                 << *pPajak + hasilDenda
                 << endl;

            break;
        }
    }

    if(!ditemukan)
    {
        cout << "Kendaraan tidak ditemukan.\n";
    }

    pauseLayar();
}
void riwayatPembayaranPengguna(string username)
{
    hapusLayar();
    bannerUtama();

    bool ada = false;

    cout << "===== RIWAYAT PEMBAYARAN =====\n\n";

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
        cout << "Belum ada riwayat pembayaran.\n";
    }

    pauseLayar();
}
void cariKendaraanSaya(string username)
{
    hapusLayar();
    bannerUtama();

    string plat;

    cin.ignore();

    cout << "Masukkan plat kendaraan : ";
    getline(cin, plat);

    bool ditemukan = false;

    for(int i = 0; i < jumlahKendaraan; i++)
    {
        if(usernamePemilik[i] == username &&
           platNomor[i].find(plat) != string::npos)
        {
            ditemukan = true;

            cout << "\nPlat Nomor      : "
                 << platNomor[i] << endl;

            cout << "Nama Pemilik    : "
                 << namaPemilik[i] << endl;

            cout << "Jenis Kendaraan : "
                 << jenisKendaraan[i] << endl;

            cout << "Pajak Tahunan   : Rp "
                 << besarPajak[i] << endl;
        }
    }

    if(!ditemukan)
    {
        cout << "\nData tidak ditemukan.\n";
    }

    pauseLayar();
}
void menuPengguna(string username)
{ 
    int pilihan;
    do{
    hapusLayar();
    bannerUtama();
    cout << "[1] Daftar Kendaraan Saya\n";
    cout << "[2] Pembayaran Pajak \n";
    cout << "[3] Perhitungan Denda \n";
    cout << "[4] Riwayat Pembayaran \n";
    cout << "[5] Cari Data Kendaraan \n";
    cout << "[0] Logout\n";
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "[ERROR] Input harus berupa angka!\n" << RESET;
            pauseLayar();
            cin.get();
            continue;
        }
    if(pilihan == 1)
        {
            lihatKendaraanSaya(username);
        }
        else if(pilihan == 2)
        {
            bayarPajakPengguna(username);
        }
        else if(pilihan == 3)
        {
            hitungDendaPengguna(username);
        }
        else if(pilihan == 4)
        {
            riwayatPembayaranPengguna(username);
        }
        else if(pilihan == 5)
        {
            cariKendaraanSaya(username);
        }
        else if(pilihan == 0)
        {
            return;
        }
        else
        {
            cout << RED
                 << "[ERROR] Pilihan tidak valid!\n"
                 << RESET;

            pauseLayar();
        }

    }while(pilihan != 0);
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

void cariDataPengguna() {
    int pilihan;
    do {
        hapusLayar();
        bannerUtama();
        cout << "========================================\n";
        cout << "            MENU PENCARIAN DATA         \n";
        cout << "========================================\n";
        cout << "[1] Cari Berdasarkan Plat Nomor\n";
        cout << "[2] Cari Berdasarkan Nama Pemilik\n";
        cout << "[0] Kembali\n";
        cout << "----------------------------------------\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "\n[Error] Input harus berupa angka!\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            continue;
        }

        if (pilihan == 1) {
            if (jumlahKendaraan == 0) {
                cout << RED << "\n[Peringatan] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                continue;
            }

            string cariPlat;
            cin.ignore();
            cout << "\nMasukkan Plat Nomor yang dicari: ";
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
                cout << RED << "  [Sistem] Data dengan plat nomor '" << cariPlat << "' tidak ditemukan.\n" << RESET;
            }
            cout << "\nTekan Enter untuk kembali...";
            cin.get();
        } 
        else if (pilihan == 2) {
            if (jumlahKendaraan == 0) {
                cout << RED << "\n[Peringatan] Belum ada data kendaraan yang terdaftar!\n" << RESET;
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                continue;
            }

            string cariNama;
            cin.ignore();
            cout << "\nMasukkan Nama Pemilik yang dicari: ";
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
                cout << RED << "  [Sistem] Data dengan nama pemilik '" << cariNama << "' tidak ditemukan.\n" << RESET;
            }
            cout << "\nTekan Enter untuk kembali...";
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
            cout << GREEN;
            cout << "[1] Login <" << endl;
            cout << RESET;
        } else {
            cout << "[1] Login " << endl;
        }

        if (pilihMenu == 1) {
            cout << GREEN;
            cout << "[2] Daftar <" << endl;
            cout << RESET;
        } else {
            cout << "[2] Daftar " << endl;
        }

        if (pilihMenu == 2) {
            cout << GREEN;
            cout << "[0] Keluar <" << endl;
            cout << RESET;
        } else {
            cout << "[0] Keluar " << endl;
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