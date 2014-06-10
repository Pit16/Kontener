#include <iostream>
#include "Kontener.h"
using namespace std;

int main()
{
    cout<<"Hello world"<<endl;
    Kontener* nowy_kontener = new Kontener();
    nowy_kontener->dodaj_element(0);
    nowy_kontener->dodaj_element(1);
    nowy_kontener->dodaj_element(2);
    nowy_kontener->dodaj_element(3);
    nowy_kontener->dodaj_element(4);
    nowy_kontener->dodaj_element(5);
    cout<<*nowy_kontener<<endl;
    nowy_kontener->zamien_obiekty(2,0);
    cout<<*nowy_kontener;



    return 0;
}

