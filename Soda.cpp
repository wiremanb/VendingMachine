#include "Soda.h"

Soda::Soda()
{
    this->sodaName = "NONE";
    this->sodaPrice = -9999;
}

Soda::Soda(string sodaName, int price, int sold)
{
	this->sodaName = sodaName;
	this->setPrice(price);
}


void Soda::setPrice(int newPrice)
{
	if (newPrice > 0)
		this->sodaPrice = newPrice;
}

string Soda::getName()
{
	return this->sodaName;
}

int Soda::getPrice()
{
	
	return this->sodaPrice;
}