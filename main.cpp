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
    //kontener_panstw.dodaj_element(szwecja);
    //kontener_panstw.dodaj_element(anglia);
    plik2>>kontener_panstw;
    cout<<kontener_panstw;



    return 0;
}

