#ifndef SodaHeader
#define SodaHeader

#include <string>

using namespace std;

class Soda
{
private:
	string sodaName;
	int sodaPrice;

public:
    Soda();
	Soda(string sodaName, int sodaPrice, int sold);
	void setPrice(int price);
	string getName();
	int getPrice();
};

#endif

