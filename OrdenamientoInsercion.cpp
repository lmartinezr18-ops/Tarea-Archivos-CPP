#include <iostream>
using namespace std;

void ordenamientoInsercion(int arreglo[], int n) {
    int i, llave, j;
    for (i = 1; i < n; i++) {
        llave = arreglo[i]; 
        j = i - 1;

        // Compara y desplaza los elementos mayores a la derecha
        while (j >= 0 && arreglo[j] > llave) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = llave; 
    }
}

int main() {
    int datos[] = {15, 3, 9, 1, 10, 4};
    int n = sizeof(datos) / sizeof(datos[0]);

    cout << "Arreglo antes: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";

    ordenamientoInsercion(datos, n);

    cout << "\nArreglo despues: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";

    return 0;
}