StoreManagement
C++ program which reads orders from a file, displays them and updates a store's storage

Ilie Simina 322AB

windows Codeblocks

Tema cerea sa simulam un magazin prin 3 clase: produse, comenzi si clienti.
Produs are un vector de prosude citit din primul fisier, iar clienti are un vector de clienti citit din al doilea.
Se pun in fisier comenzile cu tot cu numele clientului si produse si tot
Se verifica care produse si cate sunt in comanda din vectorul de produse si se scad din vectorul de produse
Dupa se pune in fisiererul de stoc vectorul de produse ramase aranjat
Daca nu ai niciun client/nicio comanda pui in fisierul de comenzi un comentariu ca nu sunt clienti
Respectiv la stocul ramas dupa comanda apare doar "Stoc ramas" daca nu mai ai nimic
Altfel apare "stoc ramas" si cu ce a ramas

Main:

definesc vectorul \*produs si presupun ca are un element si scriu numarul de produse ca 0 dupa care apelez functia de citire din fisier unde se modifica vectorul produs
fac acelasi lucru ca la produs si pentru vectorul client si numarul sau de elemente
apelez functia care scade din stoc produsele din comanda
apelez functiile de scriere in cele 2 fisiere
