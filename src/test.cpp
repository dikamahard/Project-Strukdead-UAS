#include <iostream>
#include "func.cpp"
using namespace std;


int main() {
    ptrdriver test, pala;
    pala = nullptr;
    ptrpelanggan antri = nullptr;
    int h;
    stack s;
    createStack(s);

    //int barang = 3;
    /*
    push(s, barang);

    cout << s.jumlahBarang[s.top] << '\n';
    cout << s.sum << '\n';
    cout << s.top << '\n' ;
    
    push(s, 3);

    cout << s.jumlahBarang[s.top] << '\n';
    cout << s.sum << '\n';
    cout << s.top << '\n';

    push(s, 3);

    cout << s.jumlahBarang[s.top] << '\n';
    cout << s.sum << '\n';
    cout << s.top << '\n';

    push(s, 1);

    cout << s.jumlahBarang[s.top] << '\n';
    cout << s.sum << '\n';
    cout << s.top << '\n';

    cout << peek(s) << '\n';
    pop(s, h);
    cout << h << '\n';
    cout << s.jumlahBarang[s.top] << '\n';
    cout << s.sum << '\n';
    cout << s.top << '\n'; */

    createDriver(test);
    insertDriver(pala, test);
    createDriver(test);
    insertDriver(pala, test);
    createPelanggan(antri, pala);
    createPelanggan(antri, pala);

    //cout << "Driver yg dipilih \n" << pala->nextDriver->namaDriver << '\n';
    //cout << "Pelanggan si driver \n" << pala->nextDriver->firstPelanggan->namaPelanggan << '\n';
    //cout << pala->nextDriver->firstPelanggan->nextPelanggan->namaPelanggan;
    
    //cout << pala->barang.jumlahBarang[barang.top] << '\n';
    //cout << pala->barang.jumlahBarang[0];
    //cout << endl << pala->barang.top;

    cout << "Driver yg dipilih \n" << pala->namaDriver << '\n';
    cout << "Pelanggannya \n"; //<< pala->nextDriver->antri.head->namaPelanggan << "\n";
    //cout << pala->nextDriver->antri.tail->namaPelanggan << '\n';
    printPelanggan(pala);
    cout << "Drop pelanggan \n";
    pelangganSelesai(pala);
    cout << "Setelah di dequeque \n";
    printPelanggan(pala);
    cout << pala->rating.poin[pala->rating.top];
    //cout << peek(pala->rating);

}