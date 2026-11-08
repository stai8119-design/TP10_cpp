#include <iostream>
#include <string>

using namespace std;

class Livre {
public:
    string titre;
    float prix;
};

int main() {
    int n;
    cout << "Veuillez entrer le nombre de livres que vous voulez creer : ";
    cin >> n;
    cin.ignore();
    Livre* tab = new Livre[n];

    for(int i = 0; i < n; i++) {
        cout << "\nLivre numero " << i + 1 << endl;
        cout << "Entrez le titre : ";
        getline(cin, tab[i].titre); 
        
        cout << "Entrez le prix : ";
        cin >> tab[i].prix;
        cin.ignore();
    }
    cout << "LISTE DES LIVRES" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Livre " << i + 1 << " -> Titre : " << tab[i].titre << " | Prix : " << tab[i].prix << " MAD" << endl;
    }
    delete[] tab;
    tab = nullptr; 
    return 0;
}