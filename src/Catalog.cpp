#include "Catalog.h"
#include <algorithm>

int Catalog::nrCataloage = 0;


Catalog::Catalog(const string &numeScoala) {
    this->numeScoala = numeScoala;
    nrCataloage++;
}


Catalog::Catalog(const Catalog &c) {
    this->numeScoala = c.numeScoala;
    for (int i = 0; i < (int)c.persoane.size(); i++)
        this->persoane.push_back(c.persoane[i]->clone());
    nrCataloage++;
}


void swap(Catalog &a, Catalog &b) {
    std::swap(a.numeScoala, b.numeScoala);
    std::swap(a.persoane, b.persoane);
}


Catalog& Catalog::operator=(Catalog c) {
    swap(*this, c);
    return *this;
}

void Catalog::elibereazaMemorie() {
    for (int i = 0; i < (int)persoane.size(); i++)
        delete persoane[i];
    persoane.clear();
}

Catalog::~Catalog() {
    elibereazaMemorie();
}

void Catalog::adaugaPersoana(Persoana *p) {
    persoane.push_back(p->clone());
}


void Catalog::afiseazaSituatii() const {
    cout << "=== Situatii: " << numeScoala << " ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++)
        cout << persoane[i]->getSituatie() << endl;
}

void Catalog::afiseazaToate() const {
    cout << "=== Catalog: " << numeScoala << " ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++)
        cout << *persoane[i] << endl;
}


void Catalog::afiseazaStudentiPromovati() const {
    cout << "=== Studenti promovati ===" << endl;
    for (int i = 0; i < (int)persoane.size(); i++) {
        Student *s = dynamic_cast<Student*>(persoane[i]);
        if (s != NULL && s->estePromovat())
            cout << *s << endl;
    }
}

int Catalog::getNrCataloage() {
    return nrCataloage;
}

ostream& operator<<(ostream &out, const Catalog &c) {
    out << "Catalog[" << c.numeScoala << ", " << c.persoane.size() << " persoane]";
    return out;
}
