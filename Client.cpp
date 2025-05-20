#include "Client.h"

Client::Client() : Comanda()
{
    nume[0]='\0';
}

Client::Client(const char* nume, const Comanda comanda){
    strcpy(this->nume, nume);

    this->comanda.setZi(comanda.getZi());
    this->comanda.setLuna(comanda.getLuna());
    this->comanda.setAn(comanda.getAn());
    this->comanda.setNrProduse(comanda.getNrProduse());
}

const char* Client::getNume() const{
    return nume;
}

void Client::setNume(const char *nume){
    strcpy(this->nume, nume);
}

bool Client::citesteClient(const char* fileName,Client*& client,int& nrClienti){
    ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return false;
    }

    inputFile>>nrClienti;

    client=new Client[nrClienti];
    for(int i=0; i<nrClienti; i++){
        char buffer1[25], buffer2[25];
        inputFile>>buffer1>>buffer2;
        strcat(buffer1, " ");
        strcat(buffer1,buffer2);
        strcpy(client[i].nume, buffer1);
        citesteComanda(inputFile, client[i].comanda);
    }

    inputFile.close();
    return true;
}

void Client::comandaClient(int numarProduse, int nrClienti, Client *client, Produs*& produs){
    for(int i=0; i<nrClienti;i++){
        produseCumparate(produs, client[i].comanda, numarProduse);
    }
}

void Client::outputComenzi(Client* client, int nrClienti, Produs* produs, int numarProduse){
    ofstream outputFile("output_comenzi.txt");
    if(nrClienti==0)
        outputFile<<"Nu exista clienti in magazin.";
    for(int i=0; i<nrClienti; i++){
        client[i].comanda.setComandaID(i);
        asociamPret(client[i].comanda, produs, numarProduse);
        if(i==0)//iful asta e ca sa n-am enter-uri in plus
            outputFile<<"Nume: "<<client[i].nume<<"\nComanda ID: "<< client[i].comanda.getComandaID()<<"\n";
        else if(i>0)
            outputFile<<"\n\nNume: "<<client[i].nume<<"\nComanda ID: "<<client[i].comanda.getComandaID()<<"\n";
        outputComenzi2(outputFile, client[i].comanda);
    }
    outputFile.close();
}
