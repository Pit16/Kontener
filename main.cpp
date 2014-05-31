#include <iostream>
#include "Kontener.h"
using namespace std;

int main()
{
	cout<<"Hello world"<<endl;
    Kontener* nowy_kontener = new Kontener();
    nowy_kontener->dodaj_element(2);
    nowy_kontener->dodaj_element(7);
    cout<<*nowy_kontener;



	return 0;
}

