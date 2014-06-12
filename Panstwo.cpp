/*
 * Panstwo.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Panstwo.h"
#include "Debugowanie.h"

Panstwo::Panstwo(string nazwa, int powierzchnia, int populacja)
{
    debug("konstruktor z parametrem panstwa: " + nazwa);
    this->nazwa=nazwa;
    this->powierzchnia=powierzchnia;
    this->populacja=populacja;
    this->stolica="";
    this->jezyk="";
    this->pkb=0;
}

Panstwo::Panstwo(const Panstwo& p)
{
    debug("konstruktor kopiujacy panstwa: " + p.nazwa);
    this->nazwa=p.nazwa;
    this->powierzchnia=p.powierzchnia;
    this->populacja=p.populacja;
    this->stolica=p.stolica;
    this->jezyk=p.jezyk;
    this->pkb=p.pkb;
}
Panstwo::~Panstwo()
{
    debug("destruktor panstwa: " + nazwa);
}

string Panstwo::pobierz_nazwe()
{
    return nazwa;
}

int Panstwo::pobierz_powierzchnie()
{
    return powierzchnia;
}

int Panstwo::pobierz_populacje()
{
    return populacja;
}

string Panstwo::pobierz_stolice()
{
    return stolica;
}

string Panstwo::pobierz_jezyk()
{
    return jezyk;
}

int Panstwo::pobierz_pkb()
{
    return pkb;
}

void Panstwo::ustaw_stolice(string stolica)
{
    this->stolica=stolica;
}

void Panstwo::ustaw_jezyk(string jezyk)
{
    this->jezyk=jezyk;
}

void Panstwo::ustaw_pkb(int pkb)
{
    this->pkb=pkb;
}

bool Panstwo::operator<(const Panstwo& p1)
{
    //cout<<"operator mniejszosci"<<endl;
    //cout<<this->powierzchnia<<" < "<<p1.powierzchnia<<endl;
    return this->powierzchnia < p1.powierzchnia;
}

bool Panstwo::operator>(const Panstwo& p1)
{
    //cout<<"operator wiekszosci"<<endl;
    //cout<<this->powierzchnia<<" > "<<p1.powierzchnia<<endl;
    return this->powierzchnia > p1.powierzchnia;
}

bool Panstwo::operator !=(const Panstwo& p1)
{

    //cout<<"operator nierownosci"<<endl;
    //cout<<this->powierzchnia<<" != "<<p1.powierzchnia<<endl;
    return this->powierzchnia != p1.powierzchnia;
}

bool Panstwo::operator ==(const Panstwo& p1)
{

    //cout<<"operator rownosci"<<endl;
    //cout<<this->powierzchnia<<" == "<<p1.powierzchnia<<endl;
    return this->powierzchnia == p1.powierzchnia;
}

ostream& operator<< (ostream& strumien, Panstwo& panstwo)
{
//    strumien<<"nazwa panstwa: "<<panstwo.pobierz_nazwe()<<endl;
//    strumien<<"powierzchnia panstwa wynosi: "<<panstwo.pobierz_powierzchnie()<<endl;
//    strumien<<"populacja panstwa wynosi: "<<panstwo.pobierz_populacje()<<endl;
//    strumien<<"stolica panstwa jest: "<<panstwo.pobierz_stolice()<<endl;
//    strumien<<"jezyk panstwa to: "<<panstwo.pobierz_jezyk()<<endl;
//    strumien<<"pkb panstwa wynosi: "<<panstwo.pobierz_pkb()<<endl;

    strumien << panstwo.nazwa<<" "<< panstwo.powierzchnia<<" "<< panstwo.populacja;
    return strumien;
}

istream& operator>> (istream& strumien, Panstwo& panstwo)
{
    strumien>>panstwo.nazwa;
    strumien>>panstwo.powierzchnia;
    strumien>>panstwo.populacja;
    return strumien;
}

Panstwo& Panstwo::operator=(const Panstwo& p)
{
    this->nazwa=p.nazwa;
    this->powierzchnia=p.powierzchnia;
    this->populacja=p.populacja;
    this->stolica=p.stolica;
    this->jezyk=p.jezyk;
    this->pkb=p.pkb;

    return *this;
}

void Panstwo::zapisz_do_pliku(ofstream& plik)
{
    if(plik)
    {
        plik<<nazwa<<" "<<powierzchnia<<" "<<populacja<<" "<<stolica<<" "<<jezyk<<" "<<pkb<<endl;
    }
    else
        debug("Blad w zapisie panstwa do pliku");
}

void Panstwo::odczyt_z_pliku(istream& plik)
{
    if(plik)
    {
        plik>>this->nazwa;
        plik>>this->powierzchnia;
        plik>>this->populacja;

    }
    else
        debug("Blad w odczycie panstwa z pliku");
}

void Panstwo::odczyt_ze_strumienia(istream& stream)
{
    stream>>this->nazwa;
    stream>>this->powierzchnia;
    stream>>this->populacja;
}
