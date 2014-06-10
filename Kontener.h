#ifndef KONTENER_H
#define KONTENER_H
#include "Wezel.h"
#include <string>
#include <iostream>

class Kontener
{
public:
    Kontener();
    ~Kontener();
    void dodaj_element(int nowy_element);
    void usun_element(int stary_element);
    int operator[](int indeks);
    int pobierz_element(int indeks);
    friend std::ostream & operator<< (std::ostream &, Kontener &);
    void zamien_obiekty(int pierwszy, int drugi);
private:
    Wezel* glowa;
    Wezel* ogon;
    int liczba_elementow;
};
std::ostream& operator<< (std::ostream& strumien, Kontener& kontener);

#endif //KONTENER_H
