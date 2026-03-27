#include <iostream>
using namespace std;


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; 
    int i = (bajo - 1); 

    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        // Ordena los elementos antes y después de la partición
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main() {
    int datos[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(datos) / sizeof(datos[0]);
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";

    quickSort(datos, 0, n - 1);

    cout << "\nOrdenado (Quicksort): ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";
    
    return 0;
}