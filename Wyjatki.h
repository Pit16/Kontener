//wyjatek dziedziczacy po +++
#ifndef WYJATEK_K
#define WYJATEK_H
#include <iostream>
class Wyjatek: std::exception
{
public:
    Wyjatek();
    ~Wyjatek();
    void przekroczenie_tablicy();


};
#endif WYJATEK_H
