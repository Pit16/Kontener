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

