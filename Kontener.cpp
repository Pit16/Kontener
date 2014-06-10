#include "Kontener.h"
#include <iostream>
using namespace std;
Kontener::Kontener()
{
    liczba_elementow=0;
    glowa=NULL;
    ogon=NULL;
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
std::ostream& operator<< (std::ostream& strumien, Kontener& kontener)
{
    strumien<<"liczba elementow: "<<kontener.liczba_elementow<<std::endl;
    Wezel* znacznik =kontener.glowa;
    for(int i=0; i<kontener.liczba_elementow; i++)
    {
        strumien<<"Wezel numer: "<<i<<*znacznik<<std::endl;
        znacznik=znacznik->nastepny;
    }
    return strumien;
}

void Kontener::usun_element(int stary_element)
{
    if(glowa==NULL)
        return;
    Wezel* znacznik = this->glowa;
    if(stary_element==0)
    {
        glowa=glowa->nastepny;
    }
    for(int i=0; i<stary_element; i++)
    {
        znacznik=znacznik->nastepny;
    }
    delete znacznik;
    liczba_elementow--;
}
int Kontener::operator[](int indeks)
{
    if(liczba_elementow>=indeks)
    {
        Wezel* znacznik = this->glowa;
        for(int i=0; i<indeks; i++)
        {
            znacznik=znacznik->nastepny;
        }
        return znacznik->pokaz_wartosc();
    }
    else
        cout<<"Brak elementow"<<endl;
    return 0;
}

int Kontener::pobierz_element(int indeks)
{
    if(liczba_elementow>=indeks)
    {
        Wezel* znacznik = this->glowa;
        for(int i=0; i<indeks; i++)
        {
            znacznik=znacznik->nastepny;
        }
        return znacznik->pokaz_wartosc();
    }
    else
        cout<<"Brak elementow"<<endl;
    return 0;
}

void Kontener::zamien_obiekty(int pierwszy, int drugi)
{
    //czy glowa dziala dobrze? nie sądze...


    if(pierwszy>drugi)
    {
        int zmienna=0;
        zmienna=drugi;
        drugi=pierwszy;
        pierwszy=zmienna;
    }

    if(drugi-pierwszy==1 && pierwszy==0)
    {
        // gdy jeden z zamienianych obiektowy (stojacych obok siebie) jest glową
        Wezel* temp1=glowa;
        Wezel* temp2=glowa->nastepny;
        temp2->nastepny->poprzedni=temp1;
        glowa->poprzedni->nastepny=temp2;
        temp2->poprzedni=temp1->poprzedni;
        temp1->poprzedni=temp2;
        temp1->nastepny=temp2->nastepny;
        temp2->nastepny=temp1;
        glowa=temp2;
    }
    else if(drugi-pierwszy==1)
    {
        // gdy stoja dwa obiekty obok siebie
        Wezel* znacznik1= glowa;
        for(int i=0; i<pierwszy; i++)
            znacznik1=znacznik1->nastepny;
        Wezel* temp1 = znacznik1;
        Wezel* znacznik2= glowa;
        for(int i=0; i<drugi; i++)
            znacznik2=znacznik2->nastepny;
        Wezel* temp2 = znacznik2->nastepny;

        temp1->poprzedni->nastepny=temp2->poprzedni;
        temp1->nastepny->poprzedni=temp1->poprzedni;
        temp1->nastepny=temp2;
        temp1->poprzedni=temp2->poprzedni;
        temp2->poprzedni->nastepny=temp1;
        temp2->poprzedni=temp1;
    }
    else if(pierwszy==0 && drugi==liczba_elementow-1)
    {
        Wezel* temp1 = glowa;
        Wezel* temp2 = glowa->poprzedni;
        temp1->nastepny->poprzedni=temp2;
        temp2->poprzedni->nastepny=temp1;
        temp2->nastepny=temp1->nastepny;
        temp1->poprzedni=temp2->poprzedni;
        temp1->nastepny=temp2;
        temp2->poprzedni=temp1;
        glowa=temp2;

    }

    else if(drugi-pierwszy>1)
    {
        Wezel* znacznik1= glowa;
        for(int i=0; i<pierwszy; i++)
            znacznik1=znacznik1->nastepny;
        Wezel* temp1 = znacznik1;
        Wezel* znacznik2= glowa;
        for(int i=0; i<drugi; i++)
            znacznik2=znacznik2->nastepny;
        Wezel* temp2 = znacznik2;
        temp1->poprzedni->nastepny=temp2;
        temp1->nastepny->poprzedni=temp2;
        temp2->nastepny->poprzedni=temp1;
        temp2->poprzedni->nastepny=temp1;

        Wezel* temp11=temp1->nastepny;
        Wezel* temp12=temp1->poprzedni;

        temp1->nastepny=temp2->nastepny;
        temp1->poprzedni=temp2->poprzedni;
        temp2->nastepny=temp11;
        temp2->poprzedni=temp12;
        if(pierwszy==0)
            glowa=temp2;
    }

}
