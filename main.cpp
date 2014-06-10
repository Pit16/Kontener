#include <iostream>
#include "Kontener.h"
using namespace std;

int main()
{
	cout<<"Hello world"<<endl;
    Kontener* nowy_kontener = new Kontener();
    nowy_kontener->dodaj_element(2);
    nowy_kontener->dodaj_element(7);
    nowy_kontener->dodaj_element(3);
    nowy_kontener->dodaj_element(9);
    cout<<*nowy_kontener;
    int liczba = (*nowy_kontener)[2];
    cout << liczba<<endl;
    int liczba2 = nowy_kontener->pobierz_element(2);
    cout<<liczba2<<endl;


	return 0;
}

