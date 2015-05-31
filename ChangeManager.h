#ifndef ChangeHeader
#define ChangeHeader

#include <iostream>
#include <string>
#include <cmath>
#include <array>

using namespace std;

class ChangeManager
{
private:
	int quartersLeft;
	int dimesLeft;
	int nickelsLeft;

public:
	enum COIN
    {
        QUARTERS = 25,
        DIMES = 10,
        NICKELS = 5
    };
    
    ChangeManager();                                                // Default Constructor.
	ChangeManager(int quarterLeft, int dimeLeft, int nickelLeft);   // Init values.
	void customerChange(int, int);                                  // Calculate Customer Change.
	int QuartersLeft();
	int DimesLeft();
	int NickelsLeft();
	void addCoin(int);
};
#endif

