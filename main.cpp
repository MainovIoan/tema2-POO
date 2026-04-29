#include <iostream>
#include "Catalog.h"
#include "Student.h"
#include "Profesor.h"
#include "Parinte.h"
#include "Exceptii.h"
using namespace std;

int main() {

    Catalog catalog("Facultatea de Matematica si Informatica");

    {
        Student s1("Popescu", "Ion", 20, "132");
        s1.adaugaNota(8.5);
        s1.adaugaNota(7);
        s1.adaugaNota(9);
        catalog.adaugaPersoana(&s1);

        Student s2("Ionescu", "Maria", 21, "131");
        s2.adaugaNota(4);
        s2.adaugaNota(3.5);
        catalog.adaugaPersoana(&s2);

        Profesor p1("Marinescu", "Andrei", 45, "POO", "Conf.");
        p1.adaugaGrupa("131");
        p1.adaugaGrupa("132");
        catalog.adaugaPersoana(&p1);

        Parinte par1("Dumitrescu", "Elena", 48, "Inginer");
        par1.adaugaCopil("Ion Popescu");
        catalog.adaugaPersoana(&par1);

        
    }
    
    catalog.afiseazaToate();
    cout << endl;

    
    catalog.afiseazaSituatii();
    cout << endl;

    
    catalog.afiseazaStudentiPromovati();
    cout << endl;

    
    Catalog catalog2("Copie");
    catalog2 = catalog;
    cout << catalog2 << endl;
    cout << "Numar cataloage create: " << Catalog::getNrCataloage() << endl;
    cout << "Numar total persoane create: " << Persoana::getNumarTotal() << endl;
    cout << endl;

    
    cout << "--- Test exceptii ---" << endl;

    
    try {
        Student sTest("Test", "Test", 20, "100");
        sTest.adaugaNota(15);
    }
    catch (const DateInvalide &e) {
        cout << e.what() << endl;
    }

    try {
        Student sTest2("Test", "Test", 20, "");
    }
    catch (const DateLipsa &e) {
        cout << e.what() << endl;
    }

    try {
        Student sTest3("Test", "Test", 20, "100");
        for (int i = 0; i < 21; i++)
            sTest3.adaugaNota(8);
    }
    catch (const DepasireCapacitate &e) {
        cout << e.what() << endl;
    }

    return 0;
}
