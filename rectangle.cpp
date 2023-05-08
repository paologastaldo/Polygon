/// \file rectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "Rectangle.h"

/// @brief default constructor 
Rectangle::Rectangle() {

	cout << "Rectangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the rectangle
/// @param h length of the rectangle
Rectangle::Rectangle(float w, float l) {

	Init();

	cout << "Rectangle - constructor" << endl;

	if (w <= 0.)
		WarningMessage("constructor: width should be > 0");
	else
		width = w;

	if (l <= 0.) 
		WarningMessage("constructor: length should be > 0");
	else
		length = l;



}

/// @brief destructor 
Rectangle::~Rectangle() {

	cout << "Rectangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
Rectangle::Rectangle(const Rectangle &r) { 

	cout << "Rectangle - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rectangle& Rectangle::operator=(const Rectangle &r) { 

	cout << "Rectangle - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool Rectangle::operator==(const Rectangle &r) { 

	if (r.width == width && r.length == length)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Rectangle::Init() {
	Reset();
	width = 0.;
	length = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rectangle::Init(const Rectangle &r) {
	Reset();
	width = r.width;
	length = r.length;
}

/// @brief total reset of the object  
void Rectangle::Reset() {
	width = 0.;
	length = 0.;
}


/// @brief set width of the object
/// @param w width 
void Rectangle::SetWidth(float w) {

	if (w < 0.) {
		WarningMessage("SetWidth: width should be > 0");
		return;
	}

	width = w;

}

/// @brief set length of the object
/// @param l length 
void Rectangle::SetLength(float l) {

	if (l < 0.) {
		WarningMessage("SetLength: length should be > 0");
		return;
	}

	length = l;

}

/// @brief set width and length of the object
/// @param w width 
/// @param l length 
void Rectangle::SetDim(float w, float l) {

	SetWidth(w);
	SetLength(l);
}


/// @brief get width of the object
/// @return width 
float Rectangle::GetWidth() {

	return width;

}

/// @brief get length of the object
/// @return length
float Rectangle::GetLength() {

	return length;
}

/// @brief get width and length of the object
/// @param w width 
/// @param l length
void Rectangle::GetDim(float &w, float &l) {

	w = width;
	l = length; 
	
	return;
}


/// @brief write an error message 
/// @param string message to be printed
void Rectangle::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Rectangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rectangle::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Rectangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rectangle::Dump() {
	cout << endl;
	cout << "---Rectangle---" << endl; 
	cout << endl;
	
	cout << "Width = " << width << endl;
	cout << "Length = " << length << endl;
	
	Polygon::Dump();
	
	cout << endl << flush;

}


/// @brief copmpute the area of the object
/// @return area of the rectangle
float Rectangle::Area() {

	return width * length;

}

/// @brief compute the perimeter of the object
/// @return perimeter of the rectangle
float Rectangle::Perimeter() {

	return 2. * (width + length);

}


