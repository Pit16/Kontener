#ifndef KONTENER_H
#define KONTENER_H
#include "Wezel.h"
#include <string>
#include <iostream>

template <class Typ> class Kontener;
template <class Typ>
std::ostream& operator<< (std::ostream& strumien, Kontener<Typ>& kontener);
template <class Typ>
std::ostream& operator>> (std::istream& strumien, Kontener<Typ>& kontener);

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
    void zapis_do_pliku(std::ofstream& plik);
    void odczyt_z_pliku(std::ifstream& plik);

    friend std::ostream & operator<< <>(std::ostream &, Kontener<Typ> &);
    friend std::ostream & operator>> <>(std::istream &, Kontener<Typ> &);
private:
    Wezel<Typ>* glowa;
    Wezel<Typ>* ogon;
    int liczba_elementow;
};

#include "Kontener_impl.h"

#endif //KONTENER_H
