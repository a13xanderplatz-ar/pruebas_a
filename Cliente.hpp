#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>

class Cliente {
private:
    int id;
    char* nombre;
    char* direccion;
    char* telefono;
    int longitud_nombre;
    int longitud_direccion;
    int longitud_telefono;

public:
    // Constructores
    Cliente();
    Cliente(int _id, char* _nombre, char* _direccion, char* _telefono);
    Cliente(Cliente& otro);
    ~Cliente();
    
    // Operador de asignación
    Cliente& operator=(Cliente& otro);
    
    // Getters
    int& getId();
    char* getNombre();
    char* getDireccion();
    char* getTelefono();
    
    // Método print
    void print();

private:
    // Método auxiliar
    int calcularLongitud(char* str);
};

#endif