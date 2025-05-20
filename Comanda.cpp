#include "Comanda.h"

Comanda::Comanda() : Produs(), id(0), zi(0), luna(0), an(0), nrProduse(0){}

Comanda::Comanda(const int id, const int zi, const int luna, const int an, const int nrProduse, const Produs *produse){
    this->id=id;
    this->zi=zi;
    this->luna=luna;
    this->an=an;
    this->nrProduse=nrProduse;

    this->produse=new Produs[nrProduse];
    for (int i=0; i<nrProduse; i++){
        this->produse[i].setPret(produse[i].getPret());
        this->produse[i].setDenumire(produse[i].getDenumire());
        this->produse[i].setCantitate(produse[i].getCantitate());
    }
}

int Comanda::getComandaID() const{
    return id;
}

int Comanda::getZi() const{
    return zi;
}

int Comanda::getLuna() const{
    return luna;
}

int Comanda::getAn() const{
    return an;
}

int Comanda::getNrProduse() const{
    return nrProduse;
}

void Comanda::setComandaID(const int id){
    if(id==0) return;
    this->id=id;
}

void Comanda::setZi(const int zi){
    if(zi==0) return;
    this->zi=zi;
}
void Comanda::setLuna(const int luna){
    if(luna==0) return;
    this->luna=luna;
}
void Comanda::setAn(const int an){
    if(an==0) return;
    this->an=an;
}
void Comanda::setNrProduse(const int nrProduse){
    if(nrProduse==0) return;
    this->nrProduse=nrProduse;
}

void Comanda::citesteComanda(ifstream& inputFile, Comanda& comanda){
    inputFile>>comanda.zi;
    inputFile>>comanda.luna;
    inputFile>>comanda.an;
    inputFile>>comanda.nrProduse;

    comanda.produse = new Produs[comanda.nrProduse];

    char buffer[50];
    int qty;
    for (int i=0; i<comanda.nrProduse; i++) {
        inputFile >> buffer >> qty;
        comanda.produse[i].setDenumire(buffer);
        comanda.produse[i].setCantitate(qty);
    }
}

//trimite in functia produs denumirea care trebuie comparata si cantitatea care trebuie scazuta
void Comanda::produseCumparate(Produs*& produs, Comanda comanda, int numarProduse){
    for(int i=0; i<comanda.nrProduse; i++){
        produs->dupaComenzi(comanda.produse[i].getDenumire(), comanda.produse[i].getCantitate(), produs, numarProduse);
    }
}

//compara numele la fiecare obiect din vectorul comanda cu cel produs si egaleaza preturile
void Comanda::asociamPret(Comanda& comanda, Produs* produs, int numarProduse){
    for(int i=0; i<comanda.nrProduse;i++)
        for(int j=0; j<numarProduse; j++)
            if(strcmp(comanda.produse[i].getDenumire(), produs[j].getDenumire())==0)
                comanda.produse[i].setPret(produs[j].getPret());
}

void Comanda::outputComenzi2(ofstream& outputFile, Comanda comanda){
    outputFile<<"Data comenzii: "<<comanda.zi<<"/"<<comanda.luna<<"/"<<comanda.an<<"\nProduse comandate:\n";
    float pretTotal=0.0f;
    for(int i=0; i<comanda.nrProduse;i++){
        outputFile<<comanda.produse[i].getCantitate()<<" X "<<comanda.produse[i].getDenumire()<<" ("<<comanda.produse[i].getPret()<<")\n";
        pretTotal+=comanda.produse[i].getCantitate()*comanda.produse[i].getPret();
    }
    outputFile<<"Total comanda: "<<pretTotal<<" RON";
}
