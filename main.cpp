#include <iostream>
#include <fstream>
#include "Kontener.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;
//    Kontener<int>* nowy_kontener = new Kontener<int>();
//    nowy_kontener->dodaj_element(0);
//    nowy_kontener->dodaj_element(1);
//    nowy_kontener->dodaj_element(2);
//    nowy_kontener->dodaj_element(3);
//    nowy_kontener->dodaj_element(4);
//    nowy_kontener->dodaj_element(5);
//    cout<<*nowy_kontener<<endl;
//    nowy_kontener->zamien_obiekty(2,0);
//    cout<<*nowy_kontener;
//    Kontener<double> double_kontener;
//    double_kontener.dodaj_element(1.2);
//    double_kontener.dodaj_element(1.0);
//    double_kontener.dodaj_element(2.2);
//    cout<<double_kontener;
//    double_kontener.zamien_obiekty(0,1);
//    cout<<double_kontener;
//    Kontener<string> string_kontener;
//    string_kontener.dodaj_element("dom");
//    string_kontener.dodaj_element("samo");
//    string_kontener.dodaj_element("dome");
//    cout<<string_kontener;
//    string_kontener.zamien_obiekty(0,1);
//    cout<<string_kontener;

//    Kontener<double> double_kontener;
//    double_kontener.dodaj_element(1.2);
//    double_kontener.dodaj_element(1.0);
//    double_kontener.dodaj_element(2.2);
//    cout<<double_kontener;

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

    return 0;
}

