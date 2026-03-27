#include <iostream>
using namespace std;

void ordenamientoSeleccion(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[min_idx])
                min_idx = j; // Encontramos un número más pequeño
        }
        // Intercambiamos el mínimo encontrado con el elemento de la posición i
        int temp = arreglo[min_idx];
        arreglo[min_idx] = arreglo[i];
        arreglo[i] = temp;
    }
}

int main() {
    int datos[] = {64, 25, 12, 22, 11};
    int n = sizeof(datos) / sizeof(datos[0]);

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";

    ordenamientoSeleccion(datos, n);

    cout << "\nArreglo ordenado (Seleccion): ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";

    return 0;
}