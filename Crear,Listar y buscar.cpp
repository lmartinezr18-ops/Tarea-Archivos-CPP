#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

// Estructura para el archivo de texto
struct Alumno {
    int id;
    string nombre;
    float nota;
};

// Estructura para el archivo binario, para archivos binarios se utiliza char[] en lugar de string
struct AlumnoBinario {         //porque el binario necesita saber exactamente cuánto mide el texto 
    int id;
    char nombre[50];
    float nota;
};

// Esta función guarda los datos al final del .txt sin borrar lo que ya estaba 
void guardarTexto() {
    //Se abre el archivo en modo "app" (append) para añadir al fina ofstream archivo ("alumnos.txt"), ios::app); 
    ofstream archivo("alumnos.txt", ios::app);
    if (archivo.is_open()) {
        Alumno a;
        cout << "ID: "; cin >> a.id;
        //El ignore es para que el getline no se salte en el nombre por el enter anterior 
        cout << "Nombre: "; cin.ignore(); getline(cin, a.nombre);
        cout << "Nota: "; cin >> a.nota;
        //Se guardan los datos separados por espacio o pestaña
        archivo << a.id << " " << a.nombre << " " << a.nota << endl;
        archivo.close(); //Siempre hay que cerrarlo para que se guarde correctamente 
        cout << "Guardado en texto.\n";
    }
}

// Actualiza con archivo temporal
void actualizarNota(int idBusqueda, float nuevaNota) {
    ifstream archivo("alumnos.txt");
    ofstream temporal("temp.txt");
    int id; string nombre; float nota;

    while (archivo >> id >> nombre >> nota) {
        if (id == idBusqueda) {
            temporal << id << " " << nombre << " " << nuevaNota << endl;
        } else {
            temporal << id << " " << nombre << " " << nota << endl;
        }
    }
    archivo.close();
    temporal.close();
    remove("alumnos.txt");
    rename("temp.txt", "alumnos.txt");
    cout << "Nota actualizada.\n";
}

// Acceso Aleatorio Binario
void leerBinarioAleatorio(int pos) {
    ifstream archivo("alumnos.dat", ios::binary);
    if (!archivo.is_open()) return;
    AlumnoBinario ab;
    archivo.seekg(pos * sizeof(AlumnoBinario), ios::beg);
    if (archivo.read((char*)&ab, sizeof(AlumnoBinario))) {
        cout << "Registro " << pos << ": " << ab.nombre << endl;
    }
    archivo.close();
}

int main() {
    int op;
    do {
        cout << "\n1. Guardar Texto\n2. Actualizar Nota\n3. Leer Binario Aleatorio\n0. Salir\nOpcion: ";
        cin >> op;
        if(op == 1) guardarTexto();
        if(op == 2) {
            int id; float n;
            cout << "ID a buscar: "; cin >> id;
            cout << "Nueva nota: "; cin >> n;
            actualizarNota(id, n);
        }
    } while (op != 0);
    return 0;
}