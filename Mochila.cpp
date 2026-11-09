#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

// Creamos una estructura representando el objeto
// con su nombre, valor y peso
struct Objeto {
    string nombre;
    double valor, peso;
};

void mochilaFraccional(vector<Objeto> objetos, double capacidad) {
    // Ordenamos los objetos por valor/peso de mayor a menor
    auto mayorValorPorPeso = [](const Objeto& a, const Objeto& b) {
        return a.valor / a.peso > b.valor / b.peso;
    };
    // Usamos stable_sort para mantener el orden relativo
    // de los objetos con el mismo valor/peso
    stable_sort(objetos.begin(), objetos.end(), mayorValorPorPeso);

    double restante = capacidad, total = 0;
    cout << fixed << setprecision(2);
    cout << "Objetos seleccionados: " << endl;

    // Tomamos los objetos en orden hasta llenar la mochila
    for (const Objeto& obj : objetos) {
        if (restante <= 0) break;
        double tomado = min(obj.peso, restante);
        double fraccion = tomado / obj.peso;
        total += obj.valor * fraccion;
        if (tomado == obj.peso)
            cout << obj.nombre << " completo" << endl;
        else
            cout << obj.nombre << " parcial: " << tomado
                 << "/" << obj.peso << endl;
        restante -= tomado;
    }
    cout << "Valor total: " << total << endl;
}

int main() {
    int cantidad;
    double capacidad;
    // Leer la cantidad de objetos y la capacidad de la mochila.
    if (!(cin >> cantidad >> capacidad)) {
        cerr << "Error: no se pudo leer la cantidad de objetos y la capacidad." << endl;
        return 1;
    }
    // Comprobar que la cantidad y la capacidad sean válidas.
    if (cantidad < 0 || capacidad < 0) {
        cerr << "Error: la cantidad de objetos y la capacidad deben ser no negativas." << endl;
        return 1;
    }

    // Leer el nombre, valor y peso de cada objeto.
    vector<Objeto> objetos(cantidad);
    for (Objeto& objeto : objetos) {
        if (!(cin >> objeto.nombre >> objeto.valor >> objeto.peso)) {
            cerr << "Error: faltan datos de uno o mas objetos." << endl;
            return 1;
        }
        // El valor no puede ser negativo y el peso debe ser positivo.
        if (objeto.valor < 0 || objeto.peso <= 0) {
            cerr << "Error: el valor debe ser no negativo y el peso debe ser positivo." << endl;
            return 1;
        }
    }

    mochilaFraccional(objetos, capacidad);
    return 0;
}
