#pragma once
#include <string>
#include <vector>
#include <tuple>
#include "Transferencia.h"
class Usuario
{

private:
	std::string nombre;
	std::string contrasena;
	int monto;
	
	// arboles
	Transferencia* transfe;  // arbol completo 
	std::vector<std::string> fechas;
	std::vector<std::string> ruts;

	void ingresarfechas(std::string fecha);
	void ingresarRuts(std::string ruts);
 
public:

	//constructor
	Usuario(std::string nombre, std::string contrasena);

	// destructor
	~Usuario();

	//gets
	std::string getNombre();
	std::string getContrasena();
	int getMonto();
	Transferencia* getArbol();

	// sets
	void setNombre(std::string nom);
	void setContrasena(std::string cont);
	void setMonto(int monto);

	// transferencias
	void ingresarTransferencia(Transferencia* nuevaTrans);
	void MostrarTransferencias();
	void MostrarFechas();
	void MostrarVerDepositosFavor(Transferencia* act);
	void MostrarVerDepositosContra(Transferencia* act);

};

