#include "Cliente.hpp"
#include <iostream>
#include <cstring>

Cliente::Cliente() {
    id = 0;
    nombre = nullptr;
    direccion = nullptr;
    telefono = nullptr;
    longitud_nombre = 0;
    longitud_direccion = 0;
    longitud_telefono = 0;
    std::cout << "Nuevo objeto creado con valores base" << std::endl;
}

Cliente::Cliente(int _id, char* _nombre, char* _direccion, char* _telefono) {
    id = _id;
    
    // Manejo del nombre
    longitud_nombre = calcularLongitud(_nombre);
    nombre = new char[longitud_nombre + 1];
    for (int i = 0; i < longitud_nombre; i++) {
        nombre[i] = _nombre[i];
    }
    nombre[longitud_nombre] = '\0';
    
    // Manejo de la dirección
    longitud_direccion = calcularLongitud(_direccion);
    direccion = new char[longitud_direccion + 1];
    for (int i = 0; i < longitud_direccion; i++) {
        direccion[i] = _direccion[i];
    }
    direccion[longitud_direccion] = '\0';
    
    // Manejo del teléfono
    longitud_telefono = calcularLongitud(_telefono);
    telefono = new char[longitud_telefono + 1];
    for (int i = 0; i < longitud_telefono; i++) {
        telefono[i] = _telefono[i];
    }
    telefono[longitud_telefono] = '\0';
}

Cliente::Cliente(Cliente& otro) {
    id = otro.id;
    
    // Copiar nombre
    longitud_nombre = otro.longitud_nombre;
    nombre = new char[longitud_nombre + 1];
    strcpy(nombre, otro.nombre);
    
    // Copiar dirección
    longitud_direccion = otro.longitud_direccion;
    direccion = new char[longitud_direccion + 1];
    strcpy(direccion, otro.direccion);
    
    // Copiar teléfono
    longitud_telefono = otro.longitud_telefono;
    telefono = new char[longitud_telefono + 1];
    strcpy(telefono, otro.telefono);
}

Cliente::~Cliente() {
    delete[] nombre;
    delete[] direccion;
    delete[] telefono;
}

Cliente& Cliente::operator=(Cliente& otro) {
    if (&otro != &(*this)) {  // Cambiamos esto por una comparación directa de direcciones
        // Liberar memoria existente
        delete[] nombre;
        delete[] direccion;
        delete[] telefono;
        
        // Copiar datos
        id = otro.id;
        
        longitud_nombre = otro.longitud_nombre;
        nombre = new char[longitud_nombre + 1];
        strcpy(nombre, otro.nombre);
        
        longitud_direccion = otro.longitud_direccion;
        direccion = new char[longitud_direccion + 1];
        strcpy(direccion, otro.direccion);
        
        longitud_telefono = otro.longitud_telefono;
        telefono = new char[longitud_telefono + 1];
        strcpy(telefono, otro.telefono);
    }
    return *this;  // Este this es necesario mantenerlo ya que es parte de la sintaxis del operador
}

int& Cliente::getId() {
    return id;
}

char* Cliente::getNombre() {
    return nombre;
}

char* Cliente::getDireccion() {
    return direccion;
}

char* Cliente::getTelefono() {
    return telefono;
}

void Cliente::print() {
    std::cout << "ID: " << id << ", Nombre: ";
    for (int i = 0; i < longitud_nombre; i++) {
        std::cout << nombre[i];
    }
    std::cout << ", Direccion: ";
    for (int i = 0; i < longitud_direccion; i++) {
        std::cout << direccion[i];
    }
    std::cout << ", Telefono: ";
    for (int i = 0; i < longitud_telefono; i++) {
        std::cout << telefono[i];
    }
    std::cout << std::endl;
}

int Cliente::calcularLongitud(char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}