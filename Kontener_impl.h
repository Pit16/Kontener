#ifndef KONTENER_IMPL_H
#define KONTENER_IMPL_H

#include <iostream>
using namespace std;

template <class Typ>
Kontener<Typ>::Kontener()
{
    liczba_elementow=0;
    glowa=NULL;
    ogon=NULL;
}

template <class Typ>
Kontener<Typ>::~Kontener()
{
    //TODO: usuwanie wezlow
}

template <class Typ>
void Kontener<Typ>::dodaj_element(Typ nowy_element)
{
    Wezel<Typ>* nowy_wezel = new Wezel<Typ>(nowy_element);
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
        Wezel<Typ>* ogon = glowa->poprzedni;
        nowy_wezel->nastepny=glowa;
        nowy_wezel->poprzedni=ogon;
        ogon->nastepny=nowy_wezel;
        glowa->poprzedni=nowy_wezel;
    }


    liczba_elementow++;
}


template <class Typ>
std::ostream& operator<< (std::ostream& strumien, Kontener<Typ>& kontener)
{
    strumien<<"liczba elementow: "<<kontener.liczba_elementow<<std::endl;
//    Wezel<Typ>* znacznik =kontener.glowa;
    for(int i=0; i<kontener.liczba_elementow; i++)
    {
        strumien<<" ["<<i<<"] "<<kontener.pobierz_element(i)<<std::endl;
//        strumien<<" ["<<i<<"] "<<*znacznik<<std::endl;
//        znacznik=znacznik->nastepny;
    }
    return strumien;
}

template <class Typ>
void Kontener<Typ>::usun_element(Typ stary_element)
{
    if(glowa==NULL)
        return;
    Wezel<Typ>* znacznik = this->glowa;
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

template <class Typ>
Typ Kontener<Typ>::operator[](int indeks)
{
    if(liczba_elementow>=indeks)
    {
        Wezel<Typ>* znacznik = this->glowa;
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

template <class Typ>
Typ Kontener<Typ>::pobierz_element(int indeks)
{
    if(liczba_elementow>=indeks)
    {
        Wezel<Typ>* znacznik = this->glowa;
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

template <class Typ>
void Kontener<Typ>::zamien_obiekty(int pierwszy, int drugi)
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
        Wezel<Typ>* temp1=glowa;
        Wezel<Typ>* temp2=glowa->nastepny;
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
        Wezel<Typ>* znacznik1= glowa;
        for(int i=0; i<pierwszy; i++)
            znacznik1=znacznik1->nastepny;
        Wezel<Typ>* temp1 = znacznik1;
        Wezel<Typ>* znacznik2= glowa;
        for(int i=0; i<drugi; i++)
            znacznik2=znacznik2->nastepny;
        Wezel<Typ>* temp2 = znacznik2->nastepny;

        temp1->poprzedni->nastepny=temp2->poprzedni;
        temp1->nastepny->poprzedni=temp1->poprzedni;
        temp1->nastepny=temp2;
        temp1->poprzedni=temp2->poprzedni;
        temp2->poprzedni->nastepny=temp1;
        temp2->poprzedni=temp1;
    }
    else if(pierwszy==0 && drugi==liczba_elementow-1)
    {
        Wezel<Typ>* temp1 = glowa;
        Wezel<Typ>* temp2 = glowa->poprzedni;
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
        Wezel<Typ>* znacznik1= glowa;
        for(int i=0; i<pierwszy; i++)
            znacznik1=znacznik1->nastepny;
        Wezel<Typ>* temp1 = znacznik1;
        Wezel<Typ>* znacznik2= glowa;
        for(int i=0; i<drugi; i++)
            znacznik2=znacznik2->nastepny;
        Wezel<Typ>* temp2 = znacznik2;
        temp1->poprzedni->nastepny=temp2;
        temp1->nastepny->poprzedni=temp2;
        temp2->nastepny->poprzedni=temp1;
        temp2->poprzedni->nastepny=temp1;

        Wezel<Typ>* temp11=temp1->nastepny;
        Wezel<Typ>* temp12=temp1->poprzedni;

        temp1->nastepny=temp2->nastepny;
        temp1->poprzedni=temp2->poprzedni;
        temp2->nastepny=temp11;
        temp2->poprzedni=temp12;
        if(pierwszy==0)
            glowa=temp2;
    }

}

#endif //KONTENER_IMPL_H
