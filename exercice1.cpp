#include <iostream>

using namespace std;

int main() {
    int taille;
    cout << "Donner la taille du tableau : ";
    cin >> taille;
    int* t = new int[taille];
    cout << "Veuillez saisir les elements du tableau :" << endl;
    for(int i = 0; i < taille; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> t[i];
    }
    cout << "Les valeurs du tableau sont : ";
    for(int i = 0; i < taille; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    delete[] t;
    t = nullptr;
    return 0;
}