#include <iostream>
#include "Cliente.hpp"

int main() {
    // Constructor por defecto
    Cliente cliente1;
    
    // Variables para entrada
    int id;
    char* nombre = new char[1];
    char* direccion = new char[1];
    char* telefono = new char[1];
     
    int pos_nombre = 0;
    int pos_direccion = 0;
    int pos_telefono = 0;
    
    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id;
    std::cin.ignore();
    
    std::cout << "Ingrese el nombre del cliente: ";
    while((nombre[pos_nombre] = std::cin.get()) != '\n') {
        pos_nombre++;
        char* aux = new char[pos_nombre + 1];
        for(int i = 0; i < pos_nombre; i++) {
            aux[i] = nombre[i];
        }
        delete[] nombre;
        nombre = aux;
    }
    nombre[pos_nombre] = '\0';
    
    std::cout << "Ingrese la dirección del cliente: ";
    while((direccion[pos_direccion] = std::cin.get()) != '\n') {
        pos_direccion++;
        char* aux = new char[pos_direccion + 1];
        for(int i = 0; i < pos_direccion; i++) {
            aux[i] = direccion[i];
        }
        delete[] direccion;
        direccion = aux;
    }
    direccion[pos_direccion] = '\0';
    
    std::cout << "Ingrese el teléfono del cliente: ";
    while((telefono[pos_telefono] = std::cin.get()) != '\n') {
        pos_telefono++;
        char* aux = new char[pos_telefono + 1];
        for(int i = 0; i < pos_telefono; i++) {
            aux[i] = telefono[i];
        }
        delete[] telefono;
        telefono = aux;
    }
    telefono[pos_telefono] = '\0';
    
    // Constructor con parámetros
    Cliente cliente2(id, nombre, direccion, telefono);
    
    // Constructor de copia
    Cliente cliente3 = cliente2;
    
    // Operador de asignación
    cliente1 = cliente2;
    
    // Mostrar información de los clientes
    std::cout << "\nInformación del Cliente 1 (asignado):" << std::endl;
    cliente1.print();
    
    std::cout << "\nInformación del Cliente 2 (original):" << std::endl;
    cliente2.print();
    
    std::cout << "\nInformación del Cliente 3 (copiado):" << std::endl;
    cliente3.print();
    
    // Liberar memoria
    delete[] nombre;
    delete[] direccion;
    delete[] telefono;
    
    return 0;
}