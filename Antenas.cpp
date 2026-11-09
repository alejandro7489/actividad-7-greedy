#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Función para colocar antenas en las casas
vector<long long> colocarAntenas(vector<long long> casas, long long R) {
    sort(casas.begin(), casas.end()); // Ordenamos las casas de menor a mayor
    vector<long long> antenas;
    // Colocamos antenas en las casas de manera que cada antena
    //  cubra la mayor cantidad de casas posible
    size_t i = 0;

    // Mientras haya casas sin cubrir, colocamos una antena
    //  en la casa más lejana que aún no esté cubierta
    while (i < casas.size()) {
        long long x = casas[i] + R;
        antenas.push_back(x);
        while (i < casas.size() && casas[i] <= x + R) {
            i++;
        }
    }
    return antenas;
}
// Función para mostrar las casas y las antenas colocadas
void mostrar(const vector<long long>& casas, long long R) {
    vector<long long> antenas = colocarAntenas(casas, R);
    cout << "Antenas colocadas en:" << endl;
    for (long long x : antenas) cout << x << endl;
    cout << "Cantidad total: " << antenas.size() << endl;
}

int main() {
    int cantidad;
    long long R;

    // Leer la cantidad de casas y el radio de cobertura.
    if (!(cin >> cantidad >> R)) {
        cerr << "Error: no se pudo leer la cantidad de casas y el radio." << endl;
        return 1;
    }

    // Rechazar valores que no tienen sentido para este problema.
    if (cantidad < 0 || R < 0) {
        cerr << "Error: la cantidad de casas y el radio deben ser no negativos." << endl;
        return 1;
    }

    // Leer la posición de cada casa.
    vector<long long> casas(cantidad);
    for (int i = 0; i < cantidad; ++i) {
        if (!(cin >> casas[i])) {
            cerr << "Error: falta la posicion de una o mas casas." << endl;
            return 1;
        }
    }

    mostrar(casas, R);
    return 0;
}
