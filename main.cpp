#include <iostream>
#include "Kontener.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;
    Kontener<int>* nowy_kontener = new Kontener<int>();
//    Kontener<int> nowy_kontener;
    Wezel<int> wezel(7);
    cout << wezel.pokaz_wartosc() << endl;
//    nowy_kontener.dodaj_element(0);
//    nowy_kontener.dodaj_element(1);
//    cout << nowy_kontener;
    nowy_kontener->dodaj_element(0);
    nowy_kontener->dodaj_element(1);
    nowy_kontener->dodaj_element(2);
    nowy_kontener->dodaj_element(3);
    nowy_kontener->dodaj_element(4);
    nowy_kontener->dodaj_element(5);
    cout<<*nowy_kontener<<endl;
    nowy_kontener->zamien_obiekty(2,0);
    cout<<*nowy_kontener;
    Kontener<double> double_kontener;
    double_kontener.dodaj_element(1.2);
    double_kontener.dodaj_element(1.0);
    double_kontener.dodaj_element(2.2);
    cout<<double_kontener;
    double_kontener.zamien_obiekty(0,1);
    cout<<double_kontener;
    Kontener<string> string_kontener;
    string_kontener.dodaj_element("dom");
    string_kontener.dodaj_element("samo");
    string_kontener.dodaj_element("dome");
    cout<<string_kontener;
    string_kontener.zamien_obiekty(0,1);
    cout<<string_kontener;



    return 0;
}

