#pragma once
#include <iostream>
#include "object.cpp"
using namespace std;


// ==============>  FUNGSI STACK  <============= //

void createStack(stack& s) {
    s.top = -1;
    s.poin[s.top] = 0;
    s.sum = 0;
}

void push(stack& s, int nilai, string nama) {
    if(s.top == maxElement-1 || s.sum + nilai > maxRating) {
        cout << ">> Kuota driver hari ini habis (max 10 order)\n";
    }else {
        // masukin nilai
        s.top += 1;
        s.poin[s.top] = nilai;
        s.sum += nilai;
        // masukin nama
        s.passanger[s.top] = nama;

    }
}

int peek(stack s) {
    return s.poin[s.top];
}

bool isEmpty(stack s) {
    if(s.top < 0) {
        return true;
    }else {
        return false;
    }
}

void pop(stack& s, int& atas) {
    if(isEmpty(s)) {
        cout << ">> Belum ada rating driver \n";
    }else {
        atas = peek(s);
        s.sum -= atas;
        s.top -= 1;
    }
}

void printPoin(stack s) {   // apa butuh ?? masi ragu
    if(isEmpty(s)) {
        cout << ">> Belum ada rating driver \n";
    }else {
        for(int i=s.top; i>=0; i--) {
            cout << s.poin[i] << '\n';
        }
    }
}


// ==========>  BATAS FUNGSI STACK  <============  //

// =========>   FUNGSI DRIVER  <===========  //

void createQueue(queue& Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

void enqueue(ptrpelanggan pelanggan, ptrdriver& driver) {
    if (driver->antri.head  == nullptr) {
        driver->antri.head = pelanggan;
        driver->antri.tail = pelanggan;
        //driver->firstPelanggan = pelanggan;
    }else {
        // ptrpelanggan temp = driver->firstPelanggan;
        // while(temp->nextPelanggan != nullptr){
        //     temp = temp->nextPelanggan;
        // }
        // temp->nextPelanggan = pelanggan;
        driver->antri.tail->nextPelanggan = pelanggan;
        driver->antri.tail = pelanggan;
    }
}

void dequeue(/*ptrpelanggan pelanggan, */ ptrdriver& driver) {
    ptrpelanggan del;

    if(driver->antri.head == nullptr) {
        cout << ">> Antrean kosong \n";
    }else if(driver->antri.head->nextPelanggan == nullptr) {
        del = driver->antri.head;
        driver->antri.head = nullptr;
        driver->antri.tail = nullptr;
    }else {
        del = driver->antri.head;
        driver->antri.head = driver->antri.head->nextPelanggan;
        del->nextPelanggan = nullptr;
    }
    delete(del);
    
}


void createDriver(ptrdriver& newDriver) {
    newDriver = new driver;

    cout << ">> Masukkan Nama Driver : \n";
    cin >> newDriver->namaDriver;
    
    newDriver->nextDriver = nullptr;
    newDriver->prevDriver = nullptr;
    createStack(newDriver->rating);
    newDriver->antri = queue{nullptr, nullptr};
}

void insertDriver(ptrdriver& head, ptrdriver newDriver) {         // Insert last
    ptrdriver temp = head; 

    if(head == nullptr) {
        head = newDriver;
    }else {
        while(temp->nextDriver != nullptr) {
            temp = temp->nextDriver;
        }
        temp->nextDriver = newDriver;
        newDriver->prevDriver = temp;
    }
}

void searchDriver(ptrdriver head, ptrdriver& psearch, string key, bool& found) {
    psearch = head;
    found = false;

    while(psearch != nullptr) {
        if (psearch->namaDriver == key ){
            found = true;
            break;
        }else {
            psearch = psearch->nextDriver;
        }
    }
    // if(!found) {
    //     cout << "Not Found!! \n";
    // }
}

void delDriver(ptrdriver& head, string key) {                  // Delete by key
    ptrdriver del; bool found;

    searchDriver(head, del, key, found);
    // apakah bisa diganti if !found?
    if(head == nullptr || del == nullptr){                     // List kosong
        cout << "NOT FOUND" << endl;
    }else {
        if (del == head){                                      // Delete first
            head = head->nextDriver;
            del->nextDriver = nullptr;
        } else if (del->nextDriver == nullptr){                // Delete last
            del->prevDriver->nextDriver = nullptr;
            del->prevDriver = nullptr;
        } else {
            del->prevDriver->nextDriver = del->nextDriver;
            del->nextDriver->prevDriver = del->prevDriver;
            del->nextDriver = nullptr;
            del->prevDriver = nullptr;
        }
    }
    delete(del);
}

void printDriver(ptrdriver head) {
    ptrdriver temp = head;

    if(head == nullptr) {
        cout << "Tidak ada driver \n";
    }else {
        while(temp != nullptr) {
            cout << temp->namaDriver << '\n';
            temp = temp->nextDriver;
        }
    }
}

void pelangganSelesai(ptrdriver& driver) {
    int nilai;
    //dequeue(driver);
    cout << ">> Beri penilaian pada driver kami (1-5) \n";
    cin >> nilai;
    if(nilai > 5) {
        cout << ">> Maaf nilai terlalu besar, akan kami anggap 5 poin ^_^\n";
        nilai = 5;
    }else if (nilai < 1) {
        cout << ">> Maaf nilai terlalu kecil, akan kami anggap 1 poin ^_^ \n";
        nilai = 1;
    }
    cout << ">> Terimakasih telah menggunakan jasa kami \n";
    // mungkin bisa di push nama nya sekalian buat rancana history nanti
    push(driver->rating, nilai, driver->antri.head->namaPelanggan);
    //push(driver->rating)
    dequeue(driver);
}

void printRatingDriver(ptrdriver driver) {
    // rencananya buat history rating orderan dari si driver
    cout << ">> Rating dari driver " << driver->namaDriver << '\n';
    for(int i = driver->rating.top; i>=0; i--) {
        cout << driver->rating.passanger[i] << " - ";
        cout << driver->rating.poin[i] << '\n';
    }
}

void displayAll(ptrdriver driver) {
    ptrdriver temp = driver;
    ptrpelanggan tmp;  

    if(driver == nullptr) {
        cout << "Nothing to Display \n";
    }else {
        while(temp != nullptr) {
            cout << "Driver " << temp->namaDriver << '\n';
            tmp = temp->antri.head;
            while(tmp != nullptr) {
                cout << "- " << tmp->namaPelanggan << '\n'; 
                tmp = tmp->nextPelanggan;
            }
            cout << '\n';
            temp = temp->nextDriver;
        }
    }    
}

// ========>  BATAS FUNGSI UNTUK DRIVER   <=========  //

// ========>  FUNGSI PELANGGAN  <=========  //



void pilihDriver(ptrpelanggan pelanggan, ptrdriver& driver, ptrdriver& target) {
    string nama;
    //ptrdriver target;
    //stack b;
    bool found;

    cout << ">> Pilih Driver Pengantar \n";
    printDriver(driver);
    cout << "----------------------------------------------" << '\n';
    cin >> nama;

    searchDriver(driver, target, nama, found);
    //createStack(b);
    //push(target->barang, pelanggan->barang);
    //masukin barang ke stack barang driver

    //masukkin pelanggan ke queue si driver yg dipilih
    //driver->firstPelanggan = pelanggan;

    //ptrpelanggan temp = target->firstPelanggan;
    if(found){
        // if(target->firstPelanggan == nullptr) {
        //     target->firstPelanggan = pelanggan;
        // }else {
        //     ptrpelanggan temp = target->firstPelanggan;
        //     while(temp->nextPelanggan != nullptr){
        //         temp = temp->nextPelanggan;
        //     }
        //     temp->nextPelanggan = pelanggan;
        // }
        enqueue(pelanggan, target);
    }else{
        cout << ">> Tidak ada driver \n";
    }
    //driver->nextDriver->firstPelanggan = pelanggan; // KOK BISA???
}

void createPelanggan(ptrpelanggan& newPelanggan, ptrdriver& driver) {
    newPelanggan = new pelanggan;
    string nama;
    ptrdriver target;  

    cout << ">> Masukkan Nama Pelanggan \n";
    cin >> newPelanggan->namaPelanggan;
    //cout << "Masukkan Jumlah Barang \n";
    //cin >> newPelanggan->nilai; 
    // bakal ditaroh fungsi pilih driver disini
    pilihDriver(newPelanggan, driver, target);
    // fungsi pilih driver akan langsung menyambumngkan pelanggan ke queue & barang
    newPelanggan->nextPelanggan = nullptr;
}

void kapsulasi(ptrpelanggan p, ptrdriver d) {
    // kapsulasi pembuatan pelanggan dan input barang serta pilih driver
    // driver akan terhubung dengan antrian dan stack
}

void printPelanggan(ptrdriver target) {
    ptrpelanggan temp = target->antri.head;

    if(temp == nullptr) {
        cout << "Antrean Kosong \n";
    }else {
        //cout << "Pelanggan yang mengantre \n";
        while(temp != nullptr) {
        cout << temp->namaPelanggan << '\n';
        temp = temp->nextPelanggan;
    }
    }
    
    // masih ragu
}


// ================= BATAS FUNGSI PELANGGAN ============= //



