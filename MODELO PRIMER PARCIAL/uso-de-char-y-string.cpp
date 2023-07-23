/*

    FECHA: 21/09/2022
    RECURSO ARMADO POR: Nahuel Alvez
    DETALLE: Uso de char y string - con y sin clases
    VERSIÓN: v.1.0

*/

#include <iostream>
#include <string.h>
#include <clocale>
#include <string>

using namespace std;

/* -------------------- PROTOTIPOS -------------------- */

void usoCharDirecto();
void usoCharConIngreso();
void usoStringDirecto();
void usoStringConIngreso();

/* ---------------------- CLASES ---------------------- */

class PersonaChar {

    private:
        char _nombre[30];
        char _apellido[30];
        int _edad;

    public:
        PersonaChar();
        PersonaChar(const char *nombre, const char *apellido, int edad);
        void cargar();
        void mostrar();
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setEdad(int edad);
        char getNombre();
        char getApellido();
        int getEdad();

};

class PersonaString {

    private:
        string _nombre;
        string _apellido;
        int _edad;

    public:
        PersonaString();
        PersonaString(string nombre, string apellido, int edad);
        void cargar();
        void mostrar();
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setEdad(int edad);
        string getNombre();
        string getApellido();
        int getEdad();

};

/* ----------------------- MAIN ----------------------- */

int main() {

    // Agregamos idioma español para la consola

    // Para CodeBlocks
    setlocale(LC_ALL, "Spanish");

    // Para Visual Studio



    // Uso de char y string con clases

    const int cantidadPersonas = 2;

    PersonaChar personasChar[cantidadPersonas];

    PersonaString personasString[cantidadPersonas];

    // Menu

    menu(personasChar, personasString, cantidadPersonas);

    return 0;
}

/* ---------------- FUNCIONES GLOBALES ---------------- */

// Para char y string utilizar la biblioteca string.h - No hay que complicarse la vida

void usoCharDirecto() {

    char nombre[7];

    strcpy(nombre, "Nahuel");

    cout << "Uso char directo: " << nombre;
}

void usoCharConIngreso() {
    // Biblioteca string.h

    char nombre[7];


    cout << "Ingrese nombre para el char: ";

    cin.getline(nombre, 7);

    // 1er parámetro es nombre de la variable char.
    // 2do parámetro es la cantidad de caracteres que se aceptan ingresar.
    // El 7 es porque en la última posición va el caracter nulo terminador.

    cout << endl;
    cout << "Usé char con ingreso: "  << nombre;
}

void usoStringDirecto() {
    string nombre;
    nombre = "Nahuel";

    cout << "Uso string directo: " << nombre;
}

void usoStringConIngreso() {
    string nombre;

    cout << "Ingrese nombre para el string: ";
    getline(cin, nombre);

    // 1er parámetro es el método de ingreso, es decir, cin.
    // 2do parámetro es el nombre de la variable string que almacena la cadena de texto ingresada por teclado.

    cout << endl;

    cout << "Usé string con ingreso: ";
    cout << nombre;
}

// Funciones globales para método cargar de las clases Persona

void menu(PersonaChar *personasChar, PersonaString *personasString, int tamanio) {
    int opcion;

    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "------------------------------" << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "------------------------------" << endl;
        cout << "0. SALIR";
        cout << "------------------------------" << endl;
        cout << "OPCION SELECCIONADA: ";
        cin >> opcion;

        cout << endl;

        switch(opcion) {
            case 0:
                cout << "Adios" << endl;
                system("pause");
                break;
            case 1:
                cout << "USO DE CHAR Y STRING" << endl;
                cout << "-------------------------------------------" << endl;
                cout << endl;
                usoCharDirecto();
                cout << endl;
                cout << endl;
                usoCharConIngreso();
                cout << endl;
                cout << endl;
                usoStringDirecto();
                cout << endl;
                cout << endl;
                usoStringConIngreso();
                cout << endl;
                cout << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                cargarPersonasConChar(personasChar, tamanio);
                break;
            case 3:
                mostrarPersonasConChar(personasChar, tamanio);
                break;
            case 4:
                cargarPersonasConString(personasString, tamanio);
                break;
            case 5:
                cargarPersonasConString(personasString, tamanio);
                break;
            default:
                cout << "La opción ingresada es incorrecta, intente de nuevo";
                system("pause");
                system("cls");
        }

    }

    while(opcion != 0);
}

void cargarPersonasConChar(PersonaChar *vectorPersonas, int tamanio) {
    cout << "CARGAR PERSONAS CON CHAR" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < tamanio; i++) {
        vectorPersonas[i].cargar();
        cout << endl;
    }

    cout << ">> Fin de carga de personas con char" << endl;
    system("pause");
    system("cls");
}

void mostrarPersonasConChar(PersonaChar *vectorPersonas, int tamanio) {
    cout << "LISTA DE PERSONAS CARGADAS CON CHAR" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < tamanio; i++) {
        vectorPersonas[i].mostrar();
        cout << endl;
    }

    cout << ">> Finalizó la muestra completa de personas cargadas con char" << endl;
    system("pause");
    system("cls");
}

void cargarPersonasConString(PersonaString *vectorPersonas, int tamanio) {
    cout << "CARGAR PERSONA CON STRING" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < tamanio; i++) {
        vectorPersonas[i].cargar();
        cout << endl;
    }

    cout << ">> Fin de carga de personas con string" << endl;
    system("pause");
    system("cls");
}

void mostrarPersonasConString(PersonaString *vectorPersonas, int tamanio) {
    cout << "LISTA DE PERSONAS CARGADAS CON STRING" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 0; i < tamanio; i++) {
        vectorPersonas[i].mostrar();
        cout << endl;
    }

    cout << ">> Finalizó la muestra completa de personas cargadas con string" << endl;
    system("pause");
    system("cls");
}

/* ----------------- MÉTODOS DE CLASE ----------------- */

// Constructores

// Pueden existir varios constructores siempre y cuando estas puedan ser diferenciadas por los parámetros que reciben.
// A esto se le llama SOBRECARGA DE FUNCIONES.

PersonaChar::PersonaChar() {
    strcpy(_nombre, "null");
    strcpy(_apellido, "null");
    _edad = 0;
}

PersonaChar::PersonaChar(const char *nombre, const char *apellido, int edad) {
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _edad = edad;
}

// Métodos de clase

void PersonaChar::cargar() {
    cout << "Ingrese Nombre: ";
    cin.getline(_nombre, 30);
    cout << "Ingrese Apellido: ";
    cin.getline(_apellido, 30);
    cout << "Ingrese edad: ";
    cin >> _edad;
}

void PersonaChar::mostrar() {
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Edad: " << _edad << endl;
}

void PersonaChar::setNombre(const char *nombre) {
    strcpy(_nombre, nombre); // 1er parámetro es la propiedad y el 2do es el que uso para ingresar la cadena de texto.
}

void PersonaChar::setApellido(const char *apellido) {
    strcpy(_apellido, apellido);
}

void PersonaChar::setEdad(int edad) {
    _edad = edad;
}

char PersonaChar::getNombre() {
    return *_nombre;
}

char PersonaChar::getApellido() {
    return *_apellido;
}

int PersonaChar::getEdad() {
    return _edad;
}

/************************************/

PersonaString::PersonaString() {
    _nombre = "null";
    _apellido = "null";
    _edad = 0;
}

PersonaString::PersonaString(string nombre, string apellido, int edad) {
    _nombre = nombre;
    _apellido = apellido;
    _edad = edad;
}

void PersonaString::cargar() {
    cout << "Ingrese Nombre: ";
    getline(cin, _nombre);
    cout << "Ingrese Apellido: ";
    getline(cin, _apellido);
    cout << "Ingrese edad: ";
    cin >> _edad;
}

void PersonaString::mostrar() {
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Edad: " << _edad << endl;
}

void PersonaString::setNombre(string nombre) {
    _nombre = nombre;
}

void PersonaString::setApellido(string apellido) {
    _apellido = apellido;
}

void PersonaString::setEdad(int edad) {
    _edad = edad;
}

string PersonaString::getNombre() {
    return _nombre;
}

string PersonaString::getApellido() {
    return _apellido;
}

int PersonaString::getEdad() {
    return _edad;
}
