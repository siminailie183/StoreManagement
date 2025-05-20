#include <iostream>
#include <fstream>
#include "Client.h"

int main(int argc, char* argv[]) {

    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    //citim produsele din primul fisier
    Produs *produs=new Produs;
    int numarProduse=0;
    if (produs->citesteProduse(argv[1], produs, numarProduse)) {
        std::cout << "Produsele s-au citit bine\n";
    }

    //citim comenzile clientilor din al doilea fisier
    Client *client=new Client;
    int nrClienti=0;
    if(client->citesteClient(argv[2], client, nrClienti)){
        std::cout<<"Clientii s-au citit bine\n";
    }

    //se elimina produsele din comenzi
    client->comandaClient(numarProduse, nrClienti, client, produs);

    //scriere rezultate in fisierele de output
    produs->stocRamas(produs, numarProduse);
    client->outputComenzi(client, nrClienti, produs, numarProduse);

    return 0;

}
