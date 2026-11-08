#include <iostream>
#include <string>

using namespace std;

class Personne {
public:
    string nom;
    int age;
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    void afficher() {
        cout << "Nom : " << nom << " | Age : " << age << " ans" << endl;
    }
};

int main() {
    Personne* p = new Personne("Salma", 20);
    cout << " Les informations de la personne dynamique :" << endl;
    p->afficher();
    delete p;
    return 0;
}