#include <iostream>
#include <fstream>
#include "Kontener.h"
#include "Panstwo.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;

    Kontener<int> int_kontener;
    int_kontener.dodaj_element(0);
    int_kontener.dodaj_element(1);
    int_kontener.dodaj_element(2);
    cout << int_kontener;


    ofstream plik1("plik1.txt");
//    plik1<<int_kontener;
    int_kontener.zapis_do_pliku(plik1);

    Kontener<int> nowy_kontener;


    ifstream plik2("plik1.txt");
//    plik1 >> nowy_kontener;
    nowy_kontener.odczyt_z_pliku(plik2);
    nowy_kontener.dodaj_element(3);
    nowy_kontener.zamien_obiekty(1,3);
    cout << nowy_kontener;

    Panstwo panstwo("nazwa", 100, 200);
    ofstream plik3("panstwo.txt");
    plik3 << panstwo;
    Panstwo panstwo2("cos", 1, 1);

    ifstream plik4("panstwo.txt");
    plik4 >> panstwo2;
    cout << panstwo2 << endl;

    return 0;
}

