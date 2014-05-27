#ifndef WEZEL_H
#define WEZEL_H

class Wezel
{
public:
    Wezel(int wartosc);
   ~Wezel();
private:
    Wezel* nastepny;
    Wezel* poprzedni;
    int wartosc;
};


#endif //WEZEL_H
