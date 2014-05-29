#ifndef KONTENER_H
#define KONTENER_H
#include "Wezel.h"

class Kontener
{
public:
    Kontener();
    ~Kontener();
    void dodaj_element(int nowy_element);
private:
    Wezel* glowa;
    Wezel* ogon;
    int liczba_elementow;
};

#endif //KONTENER_H
