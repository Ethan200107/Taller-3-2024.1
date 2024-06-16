#include "Usuario.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

void Usuario::ingresarfechas(std::string fecha)
{
	bool bandera = true;
	for (int i = 0;i<fechas.size();i++) {
		if (fechas[i] == fecha) {
			bandera = false;
			break;
		}
	}
	if (bandera) {
		fechas.push_back(fecha);
	}
}

void Usuario::ingresarRuts(std::string rut)
{
	bool bandera = true;
	for (int i = 0; i < ruts.size(); i++) {
		if (ruts[i] == rut) {
			bandera = false;
			break;
		}
	}
	if (bandera) {
		ruts.push_back(rut);
	}
}

Usuario::Usuario(std::string nombre, std::string contrasena)
{
	this->nombre = nombre;
	this->contrasena = contrasena;
	monto = 0;
	transfe = nullptr;
}

Usuario::~Usuario(){}

std::string Usuario::getNombre()
{
	return nombre;
}

std::string Usuario::getContrasena()
{
	return contrasena;
}

int Usuario::getMonto()
{
	return monto;
}

Transferencia* Usuario::getArbol()
{
	return transfe;
}

void Usuario::setNombre(std::string nom)
{
	nombre = nom;
}

void Usuario::setContrasena(std::string cont)
{
	contrasena = cont;
}

void Usuario::setMonto(int monto)
{
	this->monto = monto;
}

// Función para obtener la altura de un nodo
int obtenerAltura(Transferencia* nodo) {
	return nodo ? nodo->getAltura() : 0;
}

// Función para obtener el factor de balanceo de un nodo
int obtenerFactorBalanceo(Transferencia* nodo) {
	return nodo ? obtenerAltura(nodo->getIzquierda()) - obtenerAltura(nodo->getDerecha()) : 0;
}

// Rotación a la derecha
Transferencia* rotarDerecha(Transferencia* y) {
	Transferencia* x = y->getIzquierda();
	Transferencia* T2 = x->getDerecha();

	// Realizar rotación
	x->setDerecha(y);
	y->setIzquierda(T2);

	// Actualizar alturas
	y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);
	x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);

	// Retornar nueva raíz
	return x;
}

// Rotación a la izquierda
Transferencia* rotarIzquierda(Transferencia* x) {
	Transferencia* y = x->getDerecha();
	Transferencia* T2 = y->getIzquierda();

	// Realizar rotación
	y->setIzquierda(x);
	x->setDerecha(T2);

	// Actualizar alturas
	x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);
	y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);

	// Retornar nueva raíz
	return y;
}

Transferencia* balancearNodo(Transferencia* nodo) {
	nodo->setAltura(std::max(obtenerAltura(nodo->getIzquierda()), obtenerAltura(nodo->getDerecha())) + 1);

	int balance = obtenerFactorBalanceo(nodo);

	// Caso izquierda izquierda
	if (balance > 1 && obtenerFactorBalanceo(nodo->getIzquierda()) >= 0)
		return rotarDerecha(nodo);

	// Caso izquierda derecha
	if (balance > 1 && obtenerFactorBalanceo(nodo->getIzquierda()) < 0) {
		nodo->setIzquierda(rotarIzquierda(nodo->getIzquierda()));
		return rotarDerecha(nodo);
	}

	// Caso derecha derecha
	if (balance < -1 && obtenerFactorBalanceo(nodo->getDerecha()) <= 0)
		return rotarIzquierda(nodo);

	// Caso derecha izquierda
	if (balance < -1 && obtenerFactorBalanceo(nodo->getDerecha()) > 0) {
		nodo->setDerecha(rotarDerecha(nodo->getDerecha()));
		return rotarIzquierda(nodo);
	}

	return nodo;
}

// Función para insertar un nodo en el árbol AVL
Transferencia* insertarAVL(Transferencia* nodo, Transferencia* nuevaTrans) {
	if (!nodo)
		return nuevaTrans;

	if (nuevaTrans->getMonto() < nodo->getMonto())
		nodo->setIzquierda(insertarAVL(nodo->getIzquierda(), nuevaTrans));
	else if (nuevaTrans->getMonto() > nodo->getMonto())
		nodo->setDerecha(insertarAVL(nodo->getDerecha(), nuevaTrans));
	else
		return nodo;

	return balancearNodo(nodo);
}

void Usuario::ingresarTransferencia(Transferencia* nuevaTrans)
{
	transfe = insertarAVL(transfe, nuevaTrans);
	ingresarfechas(nuevaTrans->getFecha());
	if (nombre == nuevaTrans->getCuentaD()) {
		ingresarRuts(nuevaTrans->getCuentaO());
	}
	else {
		ingresarRuts(nuevaTrans->getCuentaD());

	}
}

void Usuario::MostrarTransferencias()
{
	
}

void Usuario::MostrarFechas()
{
	for (int i = 0;i<fechas.size();i++) {
		std::cout << fechas[i] << std::endl;
	}
}

void Usuario::MostrarVerDepositosFavor(Transferencia* act)
{

	if (act == nullptr) {
		return;
	}

	MostrarVerDepositosFavor(act->getIzquierda());

	if (act->getMonto() > 0) {
		act->generarBoleta();
	}

	MostrarVerDepositosFavor(act->getDerecha());
}

void Usuario::MostrarVerDepositosContra(Transferencia* act)
{
	if (act == nullptr) {
		return;
	}

	MostrarVerDepositosContra(act->getIzquierda());

	if (act->getMonto() < 0) {
		act->generarBoleta();
	}

	MostrarVerDepositosContra(act->getDerecha());
}
