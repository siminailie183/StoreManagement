#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>
#include <fstream>

class Produs {
    const int id;           // Cod unic al produsului
    char denumire[50];      // Denumirea produsului (șir de caractere)
    float pret;             // Prețul produsului
    int cantitate;          // Cantitatea pe stoc a produsului

    int nextID; //da, nush cum sa fac sa nu modific cu ala constant asa ca am fct altul :)
public:

    Produs();
    Produs(const int& id, const char* denumire, const float& pret, const int& cantitate);

    const char* getDenumire() const;
    float getPret() const;
    int getCantitate() const;
    int getNextID() const;

    void setDenumire(const char* denumire);
    void setPret(const float& pret);
    void setCantitate(const int& cantitate);
    void setID(const int& nextID);

    bool citesteProduse(const char* fileName, Produs*& produs, int& numarProduse);
    void dupaComenzi(const char* denumire, int cantitate, Produs*& produs, int numarProduse);
    void stocRamas(Produs* produs, int numarProduse);
};

#endif
