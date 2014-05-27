#include "Kontener.h"
#include <iostream>

Kontener::Kontener()
{
    liczba_elementow=0;
    glowa=NULL;
}

Kontener::~Kontener()
{
    //TODO: usuwanie wezlow
}

void Kontener::dodaj_element(int nowy_element)
{
    Wezel* nowy_wezel = new Wezel(nowy_element);
    if(glowa==NULL)
        glowa=nowy_wezel;
    else if(glowa->nastepny==NULL)
    {
        glowa->poprzedni=nowy_wezel;
        glowa->nastepny=nowy_wezel;
        nowy_wezel->poprzedni=glowa;
        nowy_wezel->nastepny=glowa;
    }

    else
    {
        Wezel* ogon = glowa->poprzedni;
        nowy_wezel->nastepny=glowa;
        nowy_wezel->poprzedni=ogon;
        ogon->nastepny=nowy_wezel;
        glowa->poprzedni=nowy_wezel;
    }


    liczba_elementow++;
}
