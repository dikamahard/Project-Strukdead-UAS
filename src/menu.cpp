#pragma once
#include <iostream>
#include "object.cpp"
#include "func.cpp"
using namespace std;



void mainMenu() {
    int pil;
    cout << "==============================================" << '\n';
    cout << "               PROGRAM CLONE GO-JEK           " << '\n';
    cout << "==============================================" << '\n' << '\n';

    cout << "==============================================" << '\n';
    cout << ">>>>>>>>>>>>>>>>> MAIN MENU <<<<<<<<<<<<<<<<<<" << '\n';
    cout << "==============================================" << '\n';
    cout << "1. Driver \n";
    cout << "2. Pelanggan \n";
    cout << "3. Show All \n";
    cout << "4. Keluar \n";
    cout << "----------------------------------------------" << '\n';
}

void menuDriver() {
    cout << "==============================================" << '\n'; 
    cout << "                [MENU DRIVER]                 " << '\n';
    cout << "==============================================" << '\n' << '\n';

    cout << "1. List Driver \n";
    cout << "2. Tambah Driver \n";
    cout << "3. Hapus Driver \n";
    cout << "----------------------------------------------" << '\n';

}

void menuListDriver(ptrdriver head) {
    cout << "==============================================" << '\n';
    cout << ">> List Driver \n";
    printDriver(head);
}

void menuAntreanDriver(ptrdriver& driver) {
    char ans;
    cout << ">> List Antrean \n";
                printPelanggan(driver);
                if(driver->antri.head == nullptr){
                    system("PAUSE");
                }else {
                    // drop pelanggan
                    cout << ">> Drop Pelanggan (y/n)\n";
                    cin >> ans;
                    if(ans == 'y' || ans == 'Y') {
                        pelangganSelesai(driver);
                        system("PAUSE");  
                    }else { 
                        system("PAUSE");
                    }
                }
}

void menuHistoryDriver(ptrdriver driver) {
    printRatingDriver(driver);
    cout << "Total : " << driver->rating.sum << '\n';
    system("PAUSE");
}

void menuPilihDriver(ptrdriver head) { // perlu di modularize
    string nama; int num;
    ptrdriver target;
    bool found;
    if(head == nullptr) {   // kalau tidak ada driver
        system("PAUSE");
    }else {                 // kalau ada driver dalam list
        cout << "==============================================" << '\n';
        cout << ">> Pilih Driver \n";
        cout << "----------------------------------------------" << '\n';
        cin >> nama;
        searchDriver(head, target, nama, found);
        if(found) {
            cout << "1. Lihat antrean \n";
            cout << "2. Lihat rating \n";
            cout << "----------------------------------------------" << '\n';
            cin >> num;
            if(num == 2){ // rencananya history
                // // tampilkan stack
                menuHistoryDriver(target);
            }else {        // buat antrean
                // tampilkan queue
                menuAntreanDriver(target);
            }
        }
        
    }
    
}

void menuTambahDriver(ptrdriver& head, ptrdriver driver) {
    cout << "==============================================" << '\n';
    cout << ">> Tambah Driver \n";
    createDriver(driver);
    insertDriver(head, driver);
}

void menuHapusDriver(ptrdriver& head) {
    string name;
    cout << "==============================================" << '\n';
    cout << ">> Hapus Driver \n";
    printDriver(head);
    if(head == nullptr) {
        system("PAUSE");
    }else {
        cout << ">> Tulis nama driver yg ingin dihapus \n";
        cin >> name;
        delDriver(head, name);
    }
}

void menuPelanggan() {
    cout << "==============================================" << '\n'; 
    cout << "                [MENU PELANGGAN]                 " << '\n';
    cout << "==============================================" << '\n' << '\n';

    cout << "1. Tambah Pelanggan \n";
    cout << "2. belom tau \n";
    cout << "----------------------------------------------" << '\n';
}

void menuTambahPelanggan(ptrpelanggan& pelanggan, ptrdriver head) {
    cout << "==============================================" << '\n';
    cout << ">> Tambah Pelanggan \n";
    createPelanggan(pelanggan, head);
}


