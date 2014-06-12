#include <iostream>
#include "Kontener.h"
using namespace std;

int main()
{

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

