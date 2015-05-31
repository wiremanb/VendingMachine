#include "InventoryManager.h"

InventoryManager::InventoryManager()
{
    
}

InventoryManager::InventoryManager(Soda* sodaArray[], int itemCountArray[], int sold)
{
    for(int i=0; i<SODA_ARRAY_SIZE; i++)
    {
        sodas[i].name = sodaArray[i]->getName();
        sodas[i].price = sodaArray[i]->getPrice();
        sodas[i].count = itemCountArray[i];
        sodas[i].sold = sold;
    }
}

string InventoryManager::productName(int product)
{
	return this->sodas[product].name;
}

int InventoryManager::productPrice(int product)
{
	return this->sodas[product].price;
}

int InventoryManager::sodaCount(int product)
{
	return this->sodas[product].count;
}

int InventoryManager::numberOfProducts()
{
    return SODA_ARRAY_SIZE;
}
    
void InventoryManager::checkProduct(int product)
{
	this->sodas[product].count = this->sodas[product].count - 1;
    this->sodas[product].sold += 1;
}

int InventoryManager::productSold(int product)
{
    return this->sodas[product].sold;
}