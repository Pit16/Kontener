#ifndef WEZEL_H
#define WEZEL_H
#include <iostream>

template <class Typ>
class Wezel
{
public:
    Wezel(Typ wartosc);
   ~Wezel();
    Wezel* nastepny;
    Wezel* poprzedni;
    Typ pokaz_wartosc();
private:
    Typ wartosc;
};

template <class Typ>
std::ostream& operator<< (std::ostream& strumien, Wezel<Typ>& wezel);

#include "Wezel_impl.h"

#endif //WEZEL_H
