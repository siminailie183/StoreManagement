#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Comanda : public Produs{
protected:
    int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:

    Comanda();
    Comanda(const int id, const int zi, const int luna, const int an, const int nrProduse, const Produs *produse);

    int getComandaID() const;
    int getZi() const;
    int getLuna() const;
    int getAn() const;
    int getNrProduse() const;

    void setComandaID(const int id);
    void setZi(const int zi);
    void setLuna(const int luna);
    void setAn(const int an);
    void setNrProduse(const int nrProduse);

    void citesteComanda(ifstream& inputFile, Comanda& comanda);
    void produseCumparate(Produs*& produs, Comanda comanda, int numarProduse);
    void asociamPret(Comanda& comanda, Produs* produs, int numarProduse);
    void outputComenzi2(ofstream& outputFile, Comanda comanda);
};

#endif
