#ifndef WEZEL_H
#define WEZEL_H
#include <iostream>

class Wezel
{
public:
    Wezel(int wartosc);
   ~Wezel();
    Wezel* nastepny;
    Wezel* poprzedni;
    int pokaz_wartosc();
private:
    int wartosc;
};
std::ostream& operator<< (std::ostream& strumien, Wezel& wezel);

#endif //WEZEL_H
