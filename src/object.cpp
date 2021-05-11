#pragma once
#include <iostream>
using namespace std;

const int maxRating = 50; // ganti jadi max rating = 5
const int maxElement = 10;

struct pelanggan {
    string namaPelanggan;
    int nilai;

    pelanggan *nextPelanggan;
};

struct queue {
    pelanggan* head;
    pelanggan* tail;
};

struct stack {
    //int jumlahBarang[maxElement];
    int poin[maxElement];
    // string tujuan[maxElement];
    int sum;  // sum akan terus terakumulasi setiap ada penilaian, sum <= maxRating
    int top;
};

struct  driver {
    string namaDriver;

    //pelanggan *firstPelanggan;
    queue antri;
    driver *nextDriver;
    driver *prevDriver;
    stack rating;  // tadinya tipe data pointer 
};


typedef driver* ptrdriver;
typedef pelanggan* ptrpelanggan;
typedef stack* ptrstack;