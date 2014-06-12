#include <iostream>
#include <fstream>
#include "Kontener.h"
#include "Panstwo.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;


    Panstwo anglia("Anglia", 100, 1000);
    Panstwo szwecja("Szwecja", 200, 3000);

    ifstream plik2("testpanstwo");


    Kontener<Panstwo> kontener_panstw;
    plik2>>kontener_panstw;
    cout<<kontener_panstw;


    Kontener<int> kontener;
    kontener.dodaj_element(1);
    kontener.dodaj_element(2);
    try
    {
        cout<<kontener.pobierz_element(1)<<endl;
    }
    catch(string wyjatek)
    {
            cout<<"Wyrzucono wyjatek: "<<endl;
            cout<<wyjatek<<endl;
    }

    return 0;
}

