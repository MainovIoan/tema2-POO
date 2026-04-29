#ifndef CATALOG_H
#define CATALOG_H

#include "Persoana.h"
#include "Student.h"
#include <vector>
#include <string>

class Catalog {
    string numeScoala;
    vector<Persoana*> persoane;   

    static int nrCataloage;

public:
    Catalog(const string &numeScoala);

    
    Catalog(const Catalog &c);

    Catalog& operator=(Catalog c);

    friend void swap(Catalog &a, Catalog &b);

    ~Catalog();

    void adaugaPersoana(Persoana *p);

    void afiseazaSituatii() const;

    void afiseazaToate() const;

    
    void afiseazaStudentiPromovati() const;

    static int getNrCataloage();

    friend ostream& operator<<(ostream &out, const Catalog &c);

private:
    void elibereazaMemorie();
};

#endif
