#include<iostream>

#include "Rectangle.h"
#include "Rhombus.h"


int main() {

	Rectangle *r1 = new Rectangle(3.5, 7);
	Rectangle *r2 = new Rectangle(1.5, 2.5); 
	Rhombus* rh1 = new Rhombus(3,6);


	Polygon* A = r1; 
	Polygon* B = rh1;

	cout << "==Dump A==" << endl;
	A->Dump();
	cout << "==Dump r1==" << endl;
	r1->Dump();

	cout << "==Dump B==" << endl;
	B->Dump();
	cout << "==Dump rh1==" << endl;
	rh1->Dump();

	A = r2;

	cout << "==Dump A==" << endl;
	A->Dump();
	cout << "==Dump r2==" << endl;
	r2->Dump();


	delete r1;
	delete r2; 
	delete rh1;

	return 0;

}