#ifndef WEZEL_H
#define WEZEL_H

class Wezel
{
public:
    Wezel(int wartosc);
   ~Wezel();
    Wezel* nastepny;
    Wezel* poprzedni;
private:
    int wartosc;
};

#endif //WEZEL_H
