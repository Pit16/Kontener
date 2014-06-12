#ifndef WEZEL_IMPL_H
#define WEZEL_IMPL_H

#include <iostream>
using namespace std;

template <class Typ>
Wezel<Typ>::Wezel(Typ wartosc)
{
    nastepny = NULL;
    poprzedni = NULL;
    this->wartosc=wartosc;
}

template <class Typ>
Wezel<Typ>::~Wezel()
{
    if(poprzedni==NULL || nastepny==NULL)
        return;
    poprzedni->nastepny=nastepny;
    nastepny->poprzedni=poprzedni;
    if(nastepny==poprzedni)
    {
        nastepny->nastepny=NULL;
        poprzedni->poprzedni=NULL;
    }
}

template <class Typ>
Typ& Wezel<Typ>::pokaz_wartosc()
{
    return wartosc;
}

template <class Typ>
ostream& operator<< (ostream& strumien, Wezel<Typ>& wezel)
 {
   strumien<<wezel.pokaz_wartosc();

   return strumien;
 }

#endif //WEZEL_IMPL_H
