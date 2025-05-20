#include "Produs.h"

 using namespace std;

Produs::Produs() : id(0), pret(0.0f), cantitate(0), nextID(0)
{
    denumire[0]='\0';
}

Produs::Produs(const int& id, const char* denumire, const float& pret, const int& cantitate) : id(id){

    this->pret=pret;
    this->cantitate=cantitate;

   strcpy(this->denumire, denumire);
}

const char* Produs::getDenumire() const{
    return denumire;
}

float Produs::getPret() const{
    return pret;
}

int Produs::getCantitate() const{
    return cantitate;
}

int Produs::getNextID()const{
    return nextID;
}

void Produs::setDenumire(const char* denumire){
    strcpy(this->denumire, denumire);
}

void Produs::setPret(const float& pret){
    if(pret==0.0f) return;
    this->pret=pret;
}

void Produs::setCantitate(const int& cantitate){
    if(cantitate==0) return;
    this->cantitate=cantitate;

}

void Produs::setID(const int& nextID){
    this->nextID=nextID;
}

//citire din fisierul argv[1]
bool Produs::citesteProduse(const char* fileName, Produs*& produs, int& numarProduse){
    ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return false;
    }

    inputFile >> numarProduse;
    produs = new Produs[numarProduse]; //vectorul in care salvez toate produsele

    char buffer[50];
    float p=0;
    int cant=0;
    for (int i = 0; i < numarProduse; i++) {
        inputFile >> buffer>> p >>cant;
        produs[i].setDenumire(buffer);
        produs[i].setPret(p);
        produs[i].setCantitate(cant);
        produs[i].setID(i);
    }

    inputFile.close();
    return true;
}

//compara denumirea fiecarui produs cu caracterul denumire si daca sunt egale scade cantitatea cu cat e dat
void Produs::dupaComenzi(const char* denumire, int cantitate, Produs*& produs, int numarProduse){
    for(int i=0; i<numarProduse; i++){
        if(strcmp(produs[i].denumire, denumire)==0){
            produs[i].cantitate-=cantitate;
            if(produs[i].cantitate<0)
                produs[i].cantitate=0;
            break;
        }
    }
}

void Produs::stocRamas(Produs* produs, int numarProduse){
    ofstream outputFile("output_stoc_ramas.txt");
    outputFile<<"Stoc ramas\n";
    for(int i=0; i<numarProduse; i++)
        outputFile<<produs[i].getNextID()<<". "<<produs[i].getDenumire()<<": "<<produs[i].getCantitate()<<", Pret: "<<produs[i].getPret()<<"\n";
    outputFile.close();
}
