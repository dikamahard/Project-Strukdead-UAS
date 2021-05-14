#include<iostream>
#include "menu.cpp"
using namespace std;


int main() {
    ptrdriver pala, coba;
    ptrpelanggan test;
    pala = nullptr;
    int pil; //string nama;

    do {
        //system ("PAUSE");
        mainMenu();
        cout << ">> Pilihan: \n";
        cin >> pil;
        switch(pil) {

            case 1 : 
                menuDriver();
                cin >> pil;
                switch(pil) {

                    case 1 : 
                        menuListDriver(pala);
                        //harusnya if control disini janagan di fungsi menuPilihDriver
                        menuPilihDriver(pala);
                    break;

                    case 2 : 
                        menuTambahDriver(pala, coba);
                    break;

                    case 3 : 
                        menuHapusDriver(pala);
                    break;
                }
            break;

            case 2 :
                menuPelanggan();
                cin >> pil;
                switch(pil) {

                    case 1 : 
                        menuTambahPelanggan(test, pala);
                    break;

                    case 2 :
                        // belom tau
                    break;
                }
            break;

            case 3 :
                // belom tau, mungkin buat nampilin driver dan pelanggan semua
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