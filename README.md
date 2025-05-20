# Store Management

## Short Description:

C++ program which reads orders from a file and the initial storage contents, displays the details of each order and updates the storage file

## Resources:

- 2 input files: one for the clients with what each client ordered and one for the products with all the products initially in the storage
- 2 output files: one with the orders detailed and one with the products remaining in storage

## Idea explained:

- I started with defining 3 classes:
  - one for products ("Produse")
  - one for orders ("Comenzi")
  - one for clients ("Clienti")
- I read the data from the two input files and save each iteration as an elemnt of type product for the storage file and type client for the client file. This is done using arrays that I defined in the main class;
- When reading the data from the input files the first thing read is the number of clients and products. That helps with handling edgecases like when I don't have any clients, for example. In that case, in my output file for orders I specify that there are no clients;
- I remove the products that were in the clients file, since they are part of the orders, and write in the products output file what remains;
- For the orders I write the details from the clients input file and also the prices of each object and total cost of each order.

## Example:

<section align=center>

### Input files :

#### Clients ("Clients.txt")

![alt text](clienti.png)

#### Products ("Produse.txt")

![alt text](produse.png)

### Output files :

#### Orders ("Output_comenzi.txt")

![alt text](comenzi.png)

### Storage ("Output_stoc_ramas.txt")

![alt text](stoc_ramas.png)

</section>

## Development Info:

- System: Windows
- Language: C++
- Program used: Codeblocks
