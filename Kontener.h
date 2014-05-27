#ifndef KONTENER_H
#define KONTENER_H
#include "Wezel.h"

class Kontener
{
public:
    Kontener();
    ~Kontener();
private:
    Wezel* glowa;
    int liczba_elementow;
};

#endif //KONTENER_H
