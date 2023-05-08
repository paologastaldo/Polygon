/*! \file rhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/


#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "polygon.h"
using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus : public Polygon
{
protected:
	float diagH;
	float diagV;

	float Side();

	/// @name PURE VIRTUAL FUNCTIONS - IMPLEMENTATION
	/// @{
	float Area();
	float Perimeter();
	/// @}

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus();
	Rhombus(float dH, float dV);
	Rhombus(const Rhombus& r);

	~Rhombus();
	/// @}

	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus& r);
	bool operator==(const Rhombus& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Rhombus& r);
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS 
	/// @{
	void SetDim(float dH, float dV);
	void SetDiagH(float dH);
	void SetDiagV(float dV);

	void GetDim(float& dH, float& dV);
	float GetDiagH();
	float GetDiagV();
	float GetSide(); 
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}


};

#endif
