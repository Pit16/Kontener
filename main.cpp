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
    cout<< nowy_kontener[3] <<endl;



	return 0;
}

