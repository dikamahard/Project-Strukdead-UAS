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
    cout << "3. belom tau \n";
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
    cout << ">> Pilih Driver \n";
}

void menuPilihDriver(string& nama) {
    //cout << ">> Pilih Driver \n";
    cout << "==============================================" << '\n';
    cin >> nama;
}

void menuTambahDriver(ptrdriver& head, ptrdriver driver) {
    cout << "==============================================" << '\n';
    cout << ">> Tambah Driver \n";
    createDriver(driver);
    insertDriver(head, driver);
}

void menuHapusDriver(ptrdriver& head) {
    string nama;
    cout << "==============================================" << '\n';
    cout << ">> Hapus Driver \n";
    printDriver(head);
    cout << "Tulis nama driver yg ingin dihapus \n";
    cin >> nama;
    delDriver(head, nama);
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
    cout << ">> Tambah Driver \n";
    createPelanggan(pelanggan, head);
}


