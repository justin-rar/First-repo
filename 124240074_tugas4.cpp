#include <iostream>
using namespace std;

struct Karyawan {
    string nama, jabatan;
    int usia, jam, gaji, totalgaji;
};

struct Makanan {
    string nama, tipe;
    int harga;
};

void InputKaryawan(Karyawan ky[], int &jumlahKaryawan) {
    system("cls");
    int jumlah = 0;
    bool adaPemilik = false;
    cout << "ANDA PADA MENU INPUT KARYAWAN" << endl;
    cout << "Ingin berapa data: "; cin >> jumlah;
    cin.ignore(); 
    for (int i = 0; i < jumlah; i++) {
        cout<<"Masukan nama             : "; getline(cin, ky[jumlahKaryawan].nama);
        while (true) {
        cout<<"Masukan jabatan\n(pemilik, chef, waiters) : "; cin >> ky[jumlahKaryawan].jabatan;
        cin.ignore();
        if (ky[jumlahKaryawan].jabatan=="pemilik" || ky[jumlahKaryawan].jabatan=="chef" || ky[jumlahKaryawan].jabatan=="waiters") {
            if (ky[jumlahKaryawan].jabatan=="pemilik" && adaPemilik) {
                cout<<"Sudah ada pemilik untuk restoran ini!"<<endl;
                continue;
            } else {
                if (ky[jumlahKaryawan].jabatan=="pemilik") {
                    ky[jumlahKaryawan].jam = 0;
                    ky[jumlahKaryawan].gaji = 0;
                    cout<<"Masukan jam kerja         : "<<ky[jumlahKaryawan].jam<<endl;
                    adaPemilik = true;
                }
            } if (ky[jumlahKaryawan].jabatan=="chef" || ky[jumlahKaryawan].jabatan=="waiters") {
            cout << "Masukan jam kerja        : "; cin >> ky[jumlahKaryawan].jam;
        }
            break;
        } else {
            cout<<"Pilihan anda salah!"<<endl;
            continue;
        }
        }
        cout << "Masukan usia             : "; cin >> ky[jumlahKaryawan].usia;
        jumlahKaryawan++;
        cout << endl;
        cin.ignore(); 
    }
}

void CariDataKaryawan(Karyawan ky[], int &jumlahKaryawan) {
    system("cls");
    if (jumlahKaryawan == 0) {
        cout << "Data masih kosong!" << endl;
        cin.ignore();
    } else {
        string cari;
        cout << "Masuka nama yang ingin dicari : "; cin.ignore(); getline(cin, cari);
        bool ada = false;
        for (int i = 0; i < jumlahKaryawan; i++) {
        if (ky[i].nama == cari) {
        if (ky[i].jabatan=="pemilik") {
            ky[i].gaji = 0;
            ky[i].totalgaji = 0;
        } else if (ky[i].jabatan=="chef") {
            ky[i].gaji = 450000;
            ky[i].totalgaji = ky[i].gaji*ky[i].jam*30;
        } else if (ky[i].jabatan=="waiters") {
            ky[i].gaji = 250000;
            ky[i].totalgaji = ky[i].gaji*ky[i].jam*30;
        }
                cout << "Data ditemukan!" << endl;
                cout << "Nama       : " << ky[i].nama << endl;
                cout << "Jabatan    : " << ky[i].jabatan << endl;
                cout << "Usia       : " << ky[i].usia << endl;
                cout << "Jam Kerja  : " << ky[i].jam << endl;
                cout << "Total gaji : " << ky[i].totalgaji<<endl;
                ada = true;
                break;
            }
        }
        if (!ada) {
            cout << "Karyawan tidak ditemukan!";
        } 
    }
    cin.ignore();
}

void InputMenu(Makanan mn[], int &jumlahMenu, int &jumlahMakan) {
    system("cls");
    cout << "Ini input menu makanan" << endl;
    cout << "Ingin berapa menu: "; cin >> jumlahMakan;
    cin.ignore(); 

    for (int i = 0; i < jumlahMakan; i++) {
        cout << "Masukan nama makanan       : "; getline(cin, mn[jumlahMenu].nama);
        while (true) {
        cout << "Masukan tipe makanan\n(pembuka, utama, penutup ) : "; cin>>mn[jumlahMenu].tipe;
        cin.ignore();
        if (mn[jumlahMenu].tipe=="pembuka" || mn[jumlahMenu].tipe=="utama" || mn[jumlahMenu].tipe=="penutup") {
            cout << "Masukan harga makanan      : "; cin >> mn[jumlahMenu].harga;
            break;
        } else {
            cout<<"Pilihan tipe makanan anda salah!"<<endl;
            continue;
        }
    }
        jumlahMenu++;
        cout<<endl;
        cin.ignore(); 
    }
}

void CetakMenu(Makanan mn[], int jumlahMenu) {
    system("cls");
    if (jumlahMenu == 0) {
    cout<<"Menu masih kosong!";
    cin.get();
    cin.ignore();
    } else {
    cout<<"=================="<<endl;
    cout<<"|| MENU MAKANAN ||"<<endl;
    cout<<"=================="<<endl;
    for (int i = jumlahMenu-1; i >= 0; i--) {
        cout<<"==============================="<<endl;
        cout<<"Nama Makanan : "<<mn[i].nama<<endl;
        cout<<"Tipe Makanan : "<<mn[i].tipe<<endl;
        cout<<"Harga Makanan :"<<mn[i].harga<<endl;
    }
    cout<<"===============================";
    cin.get();
    cin.ignore();
    }
}

int main() {
    int menu;
    Karyawan ky[100];
    Makanan mn[100];
    int jumlahKaryawan = 0, jumlahMenu = 0, jumlahMakan = 0;

    while (true) {
        system("cls");
        cout << "1. Input data          " << endl;
        cout << "2. Cari data           " << endl;
        cout << "3. Input Menu Makanan  " << endl;
        cout << "4. Cetak Menu Makanan  " << endl;
        cout << "5. Keluar              " << endl; 
        cout << "Pilih   : "; 
        cin >> menu;

        switch (menu) {
            case 1:
                InputKaryawan(ky, jumlahKaryawan);
                break;
            case 2:
                CariDataKaryawan(ky, jumlahKaryawan);
                break;
            case 3:
                InputMenu(mn, jumlahMenu, jumlahMakan);
                break;
            case 4:
                CetakMenu(mn, jumlahMenu);
                break;
            case 5: 
                cout << "Terima kasih untuk programnya ^-^" << endl;
                return 0;
            default:
                cout << "Pilihan tidak ada di menu, silakan coba lagi!" << endl;
                break;
        }
    }
    return 0;
}