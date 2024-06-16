#include "Transferencia.h"
#include <iostream>

Transferencia::Transferencia(std::string ID, std::string CuentaO, std::string CuentaD, int monto, std::string Fecha, std::string Hora)
{
    this->ID = ID;
    CuentaOrigen = CuentaO;
    CuentaDestino = CuentaD;
    this->monto = monto;
    this->Fecha = Fecha;
    this->hora = Hora;
    derecha = nullptr;
    izquierda = nullptr;
    altura = 1;  // Inicialmente, la altura del nodo es 1
}

Transferencia::~Transferencia() {}

// gets
std::string Transferencia::getID()
{
    return ID;
}

std::string Transferencia::getCuentaO()
{
    return CuentaOrigen;
}

std::string Transferencia::getCuentaD()
{
    return CuentaDestino;
}

int Transferencia::getMonto()
{
    return monto;
}

std::string Transferencia::getFecha()
{
    return Fecha;
}

std::string Transferencia::getHora()
{
    return hora;
}

// Nodo
Transferencia* Transferencia::getDerecha()
{
    return derecha;
}

Transferencia* Transferencia::getIzquierda()
{
    return izquierda;
}

void Transferencia::setDerecha(Transferencia* sig)
{
    derecha = sig;
}

void Transferencia::setIzquierda(Transferencia* sig)
{
    izquierda = sig;
}

void Transferencia::generarBoleta()
{
    // vamos a generar una boleta 
    std::cout << std::endl << "----------------------------" << std::endl;
    std::cout << "    ****** Boleta ******    " << std::endl << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Cuenta de origen: " << CuentaOrigen << std::endl;
    std::cout << "Cuenta de destino: " << CuentaDestino << std::endl;
    if (monto < 0) {
        std::cout << "Monto: $" << monto*-1 << std::endl;
    }
    else {
        std::cout << "Monto: $" << monto << std::endl;
    }
    std::cout << "Fecha: " << Fecha << std::endl;
    std::cout << "Hora: " << hora << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;
}

// sets
void Transferencia::setID(std::string ID)
{
    this->ID = ID;
}

void Transferencia::setCuentaO(std::string CuentaO)
{
    this->CuentaOrigen = CuentaO;
}

void Transferencia::setCuentaD(std::string CuentaD)
{
    CuentaDestino = CuentaD;
}

void Transferencia::setMonto(int monto)
{
    this->monto = monto;
}

void Transferencia::setFecha(std::string Fecha)
{
    this->Fecha = Fecha;
}

void Transferencia::setHora(std::string hora)
{
    this->hora = hora;
}

int Transferencia::getAltura()
{
    return altura;
}

void Transferencia::setAltura(int altura)
{
    this->altura = altura;
}
