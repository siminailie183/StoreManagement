#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"
#include <iostream>
#include <cstring>
#include <fstream>

class Client : public Comanda{
private:
    char nume[60];  // Numele clientului
    Comanda comanda; //comanda clientului

public:
    Client();
    Client(const char* nume, const Comanda comanda);

    const char* getNume() const;
    int getNrClienti() const;

    void setNume(const char* nume);
    void setNrClienti(const int nrClienti);

    bool citesteClient(const char* fileName, Client*& client, int& nrClienti);
    void comandaClient(int numarProduse, int nrClienti, Client* client, Produs*& produs);
    void outputComenzi(Client* client, int nrClienti, Produs* produs, int numarProduse);

};

#endif
