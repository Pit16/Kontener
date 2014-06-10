#ifndef KONTENER_H
#define KONTENER_H
#include "Wezel.h"
#include <string>
#include <iostream>

template <class Typ>
class Kontener
{
public:
    Kontener();
    ~Kontener();
    void dodaj_element(Typ nowy_element);
    void usun_element(Typ stary_element);
    Typ operator[](int indeks);
    Typ pobierz_element(int indeks);
    void zamien_obiekty(int pierwszy, int drugi);

//    friend std::ostream & operator<< (std::ostream &, Kontener &);
private:
    Wezel<Typ>* glowa;
    Wezel<Typ>* ogon;
    int liczba_elementow;
};

template <class Typ>
std::ostream& operator<< (std::ostream& strumien, Kontener<Typ>& kontener);

#endif //KONTENER_H
