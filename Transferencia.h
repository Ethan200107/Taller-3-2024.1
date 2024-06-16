#pragma once
#include <string>

class Transferencia
{
private:
    std::string ID;
    std::string CuentaOrigen;
    std::string CuentaDestino;
    int monto;
    std::string Fecha;
    std::string hora;

    Transferencia* derecha;
    Transferencia* izquierda;
    int altura;  // Nueva variable para la altura del nodo

public:
    // constructor
    Transferencia(std::string ID, std::string CuentaO, std::string CuentaD, int monto, std::string Fecha, std::string Hora);

    // destructor
    ~Transferencia();

    // gets
    std::string getID();
    std::string getCuentaO();
    std::string getCuentaD();
    int getMonto();
    std::string getFecha();
    std::string getHora();

    // Nodo
    Transferencia* getDerecha();
    Transferencia* getIzquierda();
    void setDerecha(Transferencia* sig);
    void setIzquierda(Transferencia* sig);
    void generarBoleta();

    // sets
    void setID(std::string ID);
    void setCuentaO(std::string CuentaO);
    void setCuentaD(std::string CuentaD);
    void setMonto(int monto);
    void setFecha(std::string Fecha);
    void setHora(std::string hora);

    int getAltura();  // Nueva función para obtener la altura del nodo
    void setAltura(int altura);  // Nueva función para establecer la altura del nodo
};
