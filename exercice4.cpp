#include <iostream>
#include <string>

using namespace std;

class Contact {
public:
    string nom;
    string telephone;
    string email;
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    void afficher() {
        cout << "Nom : " << nom << " | Tel : " << telephone << " | Email : " << email << endl;
    }
};
void supprimerContact(Contact** tab, int& taille, string nomRecherche) {
    int index = -1;
    for(int i = 0; i < taille; i++) {
        if(tab[i]->nom == nomRecherche) {
            index = i;
            break;
        }
    }

    if(index != -1) {
        for(int i = index; i < taille - 1; i++) {
            tab[i] = tab[i + 1];
        }
        taille--;
        cout << "Contact supprime avec succes !" << endl;
    } else {
        cout << "Contact introuvable dans le carnet." << endl;
    }
}

int main() {
    int maxCapacite = 100;
    Contact** carnet = new Contact*[maxCapacite];
    int tailleActuelle = 0;

    int choix;
    do {
        cout << "     GESTION DE CARNET         " << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        if(choix == 1) {
            if(tailleActuelle < maxCapacite) {
                string n, t, e;
                cout << "Entrez le nom : ";
                cin >> n; 
                cout << "Entrez le telephone : ";
                cin >> t;
                cout << "Entrez l'email : ";
                cin >> e;
                carnet[tailleActuelle] = new Contact(n, t, e);
                tailleActuelle++;
                cout << "Contact ajoute" << endl;
            } else {
                cout << "Le carnet est plein" << endl;
            }
        } 
        else if(choix == 2) {
            if(tailleActuelle == 0) {
                cout << "Le carnet est vide." << endl;
            } else {
                cout << "\nListe des contacts (" << tailleActuelle << ")" << endl;
                for(int i = 0; i < tailleActuelle; i++) {
                    cout << i + 1 << ". ";
                    carnet[i]->afficher();
                }
            }
        } 
        else if(choix == 3) {
            string nomSup;
            cout << "Entrez le nom du contact a supprimer : ";
            cin >> nomSup;
            supprimerContact(carnet, tailleActuelle, nomSup);
        }

    } while(choix != 4);
    for(int i = 0; i < tailleActuelle; i++) {
        delete carnet[i];
    }
    delete[] carnet;
    cout << "Programme termine propre." << endl;
    return 0;
}