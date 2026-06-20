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
string jenisKendaraan[maxKendaraan];
int besarPajak[maxKendaraan];
int jumlahKendaraan = 0;

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
        cout << " [3] Jenis         : " << jenisKendaraan[idx] << endl;
        cout << " [4] Pajak Tahunan : Rp " << besarPajak[idx] << endl;
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
        else if (pilihanEdit == 3) {
            cin.ignore();
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
        cout << "3. Jenis Kendaraan   : " << jenisKendaraan[i] << endl;
        cout << "4. Pajak Tahunan     : Rp " << besarPajak[i] << endl;
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
                platNomor[i]      = platNomor[i + 1];
                namaPemilik[i]    = namaPemilik[i + 1];
                jenisKendaraan[i] = jenisKendaraan[i + 1];
                besarPajak[i]     = besarPajak[i + 1];
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

void menuAdmin() {
    hapusLayar();
    bannerUtama();
    int pilihan;
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
}

void menuPengguna()
{
    cout << "[1] Daftar Kendaraan Saya\n";
    cout << "[2] Pembayaran Pajak \n";
    cout << "[3] Perhitungan Denda \n";
    cout << "[4] Riwayat Pembayaran \n";
    cout << "[0] Logout\n";
    cout << "Masukkan pilihan : ";
    int pil;
    cin >> pil;
}

const int maksPengguna = 100;
struct Pengguna {
    string username;
    string password;
    string admin;
};
Pengguna dataPengguna[maksPengguna];
int totalPengguna = 1;

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
    string user, password, konfirmasiPassword;
    bool isUserValid = false;
    do {
        cout << "Masukkan Username     : "; getline(cin, user);
        
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
                menuPengguna();
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
    dataPengguna[0].username = "admin";
    dataPengguna[0].password = "12345678";
    dataPengguna[0].admin = "admin";
    
    menuAwal();
    return 0;
}