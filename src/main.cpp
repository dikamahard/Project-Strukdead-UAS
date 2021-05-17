#include<iostream>
#include "menu.cpp"
using namespace std;


int main() {
    ptrdriver kepala, mangOjek;
    ptrpelanggan customer;
    kepala = nullptr;
    int pil;

    do {
        
        mainMenu();
        cout << ">> Pilihan: \n";
        cin >> pil;
        switch(pil) {

            case 1 : 
                menuDriver();
                cin >> pil;
                switch(pil) {

                    case 1 : 
                        menuListDriver(kepala);
                    break;

                    case 2 : 
                        menuTambahDriver(kepala, mangOjek);
                    break;

                    case 3 : 
                        menuHapusDriver(kepala);
                    break;
                }
            break;

            case 2 :
                menuPelanggan();
                cin >> pil;
                switch(pil) {

                    case 1 : 
                        menuTambahPelanggan(customer, kepala);
                    break;

                    case 2 :
                        // belom tau, mungkin buat cancel
                        system("PAUSE");
                    break;
                }
            break;

            case 3 :
                //buat nampilin driver dan pelanggan semua
                displayAll(kepala);
                system("PAUSE");
            break;

            case 4 :
                cout << ">> Selamat Tinggal \n";
            break;

            default :
                std::cout << ">> Pilihan tidak tersedia \n";
                system("PAUSE");
            break;

        
        }
    }while(pil != 4);
   
}