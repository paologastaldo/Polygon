/// \file rhombus.cpp
///	\brief class Rhombus: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "Rhombus.h"

/// @brief default constructor 
Rhombus::Rhombus() {

	cout << "Rhombus - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param dH horizontal diagonal
/// @param dV vertical diagonal
Rhombus::Rhombus(float dH, float dV) {

	Init();

	cout << "Rhombus - constructor" << endl;

	if (dH <= 0.)
		WarningMessage("constructor: diagonal should be > 0");
	else
		diagH = dH;

	if (dV <= 0.)
		WarningMessage("constructor: diagonal should be > 0");
	else
		diagV = dV;



}

/// @brief destructor 
Rhombus::~Rhombus() {

	cout << "Rhombus - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
Rhombus::Rhombus(const Rhombus& r) {

	cout << "Rhombus - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rhombus& Rhombus::operator=(const Rhombus& r) {

	cout << "Rhombus - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagonals  
bool Rhombus::operator==(const Rhombus& r) {

	if (r.diagH == diagH && r.diagV == diagV)
		return true;

	return false;
}

/// @brief default initialization of the object
void Rhombus::Init() {
	Reset();
	diagH = 0.;
	diagV = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rhombus::Init(const Rhombus& r) {
	Reset();
	diagH = r.diagH;
	diagV = r.diagV;
}

/// @brief total reset of the object  
void Rhombus::Reset() {
	diagH = 0.;
	diagV = 0.;
}


/// @brief set the horizontal diagonal of the object
/// @param dH horizontal diagonal 
void Rhombus::SetDiagH(float dH) {

	if (dH < 0.) {
		WarningMessage("SetDiagH: diagonal should be > 0");
		return;
	}

	diagH = dH;

}

/// @brief set vertical diagonal of the object
/// @param dV vertical diagonal 
void Rhombus::SetDiagV(float dV) {

	if (dV < 0.) {
		WarningMessage("SetDiagV: diagonal should be > 0");
		return;
	}

	diagV = dV;

}

/// @brief set the two diagonals of the object
/// @param dH horizontal diagonal 
/// @param dV vertical diagonal
void Rhombus::SetDim(float dH, float dV) {

	SetDiagH(dH);
	SetDiagV(dV);
}


/// @brief get the horizontal diagonal of the object
/// @return horizontal diagonal 
float Rhombus::GetDiagH() {

	return diagH;

}

/// @brief get vertical diagonal of the object
/// @return vertical diagonal
float Rhombus::GetDiagV() {

	return diagV;
}

/// @brief get the diagonals of the object
/// @param dH horizontal diagonal 
/// @param dV vertical diagonal
void Rhombus::GetDim(float& dH, float& dV) {

	dH = diagH;
	dV = diagV;

	return;
}

/// @brief get the side of the object
/// @return side of the rombus
float Rhombus::GetSide() {

	return Side();
}




/// @brief write an error message 
/// @param string message to be printed
void Rhombus::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rhombus::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rhombus::Dump() {
	cout << endl;

	cout << "---Rhombus---" << endl;
	cout << endl;

	cout << "Diagonal - Horizontal = " << diagH << endl;
	cout << "Diagonal - Vertical = " << diagV << endl;

	Polygon::Dump();

	cout << endl << flush;

}


/// @brief compute the area of the object
/// @return area of the rhombus
float Rhombus::Area() {

	return diagH*diagV/2.;

}

/// @brief compute the perimeter of the object
/// @return perimeter of the rhombus
float Rhombus::Perimeter() {

	return 4. * Side();

}

/// @brief compute the side of the object
/// @return side of the rhombus
float Rhombus::Side() {

	return sqrt((diagH/2. * diagH / 2.) + (diagV / 2. * diagV / 2.));

}


