#include <iostream>
using namespace std;
const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string WHITE  = "\033[37m";
const string RESET  = "\033[0m";


void bannerUtama()
{
    cout << "+====================================================+" << endl;
    cout << "|                     PAJAKKU                        |" << endl;
    cout << "|        Sistem Pembayaran Pajak Kendaraan           |" << endl;
    cout << "+====================================================+" << endl;
}

void manajemenKendaraanAdmin(){
    bannerUtama();
    int pilihan;
    cout<<"[1] Tambah Kendaraan\n";
    cout<<"[2] Edit Data Kendaraan\n";
    cout<<"[3] Lihat Kendaraan\n";
    cout<<"[4] Hapus Kendaraan\n";
    cout<<"[0] Kembali\n";
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
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
    bannerUtama();
    int pilihan;
    cout << "[1] Manajemen Kendaraan\n";
    cout << "[2] Laporan Pajak\n";
    cout << "[0] Logout\n";
    cout << "Masukkan pilihan : ";
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