#ifndef InventoryHeader
#define InventoryHeader

#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <array>
#include "Soda.h"

using namespace std;

const int SODA_ARRAY_SIZE = 10;
const int INVENTORY_ARRAY_SIZE = 10;
const int ITEM_COUNT_ARRAY_SIZE = 10;

class InventoryManager
{
    
private:
	struct soda_Info
    {
        std::string name;
        int price;
        int count;
        int sold;
        
        soda_Info()
        {
            this->name = "NONE";
            this->price = -9999;
            this->count = -9999;
            this->sold = -9999;
        }
    };
    
    soda_Info sodas[SODA_ARRAY_SIZE];
	
public:
    InventoryManager();
	InventoryManager(Soda* sodaArray[], int itemCountArray[], int sold);
	string productName(int product);
	int productPrice(int product);
	int sodaCount(int product);
    int numberOfProducts();
    int productSold(int product);
	void checkProduct(int product);

};
#endif