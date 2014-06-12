#include <iostream>
#include <fstream>
#include "Kontener.h"
#include "Panstwo.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;

    //tworzenie obiektu i dodanie elementow
    Kontener<int> kontener;
    kontener.dodaj_element(0);
    kontener.dodaj_element(1);
    kontener.dodaj_element(2);
    kontener.dodaj_element(3);
    kontener.dodaj_element(4);
    kontener.dodaj_element(5);
    cout<<kontener<<endl;
    //usuniecie obiektu
    kontener.usun_element(2);
    cout<<kontener<<endl;
    //zamania obiektu
    kontener.zamien_obiekty(2,4);
    cout<<kontener<<endl;

    //zastosowanie wyjatku
    try
    {
        cout<<kontener.pobierz_element(-3)<<endl;
    }
    catch(string wyjatek)
    {
            cout<<"Wyrzucono wyjatek: "<<endl;
            cout<<wyjatek<<endl;
    }

    Panstwo anglia("Anglia", 100, 1000);
    Panstwo szwecja("Szwecja", 200, 3000);
    //zapis do pliku obiektu z pierwszego projektu
    ofstream plik2("kpanstwo");

    Kontener<Panstwo> kontenerPanstw;
    kontenerPanstw.dodaj_element(anglia);
    kontenerPanstw.dodaj_element(szwecja);
    plik2<<kontenerPanstw;

    ifstream plik3("kpanstwo");


    Kontener<Panstwo> kontener_panstw;
    plik3>>kontener_panstw;
    cout<<kontener_panstw;





    return 0;
}

