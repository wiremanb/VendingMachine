#include "ChangeManager.h"

ChangeManager::ChangeManager()
{
    quartersLeft = 0;
    dimesLeft = 0;
    nickelsLeft = 0;
}

ChangeManager::ChangeManager(int quarterLeft, int dimeLeft, int nickelLeft)
{
	quartersLeft = quarterLeft;
	dimesLeft = dimeLeft;
	nickelsLeft = nickelLeft;
}

int ChangeManager::QuartersLeft()
{
	return quartersLeft;
}

int ChangeManager::DimesLeft()
{
	return dimesLeft;
}

int ChangeManager::NickelsLeft()
{
	return nickelsLeft;
}

void ChangeManager::addCoin(int coinValue)
{
    if (coinValue == QUARTERS)
	{
		quartersLeft++;
	}
	if (coinValue == DIMES)
	{
		dimesLeft++;
	}
	if (coinValue == NICKELS)
	{
		nickelsLeft++;
	}
}
void ChangeManager::customerChange(int customerPaid, int drinkPrice)
{
    if(customerPaid > drinkPrice)
    {
        int returned = 0;
        do
        {
            if(returned+QUARTERS <= customerPaid-drinkPrice && QuartersLeft() > 0)
            {
                returned += QUARTERS;
//                std::cout << customerPaid-drinkPrice << " cents Returned." << std::endl;
                quartersLeft--;
            }
            else if(QuartersLeft() <= 0)
            {
                std::cout << "Out of Quarters! Sorry!" << std::endl;
                break;
            }
            
            if(returned+DIMES <= customerPaid-drinkPrice && DimesLeft() > 0)
            {
                returned += DIMES;
//                std::cout << customerPaid-drinkPrice << " cents Returned." << std::endl;
                dimesLeft--;
            }
            else if(DimesLeft() <= 0)
            {
                std::cout << "Out of Dimes! Sorry!" << std::endl;
                break;
            }
            
            if(returned+NICKELS <= customerPaid-drinkPrice && NickelsLeft() > 0)
            {
                returned += NICKELS;
//                std::cout << customerPaid-drinkPrice << " cents Returned." << std::endl;
                nickelsLeft--;
            }
            else if(NickelsLeft() <= 0)
            {
                std::cout << "Out of Nickels! Sorry!" << std::endl;
                break;
            }
            
        } while(returned < customerPaid-drinkPrice);
        
        if(returned != customerPaid-drinkPrice)
            std::cout << "Only " << returned << " cents returned out of " << customerPaid-drinkPrice << " . Sorry!" << std::endl;
        else
            std::cout << returned << " cents returned" << std::endl;
    }
    else
        std::cout << "No change returned, Thank you!" << std::endl;
    
    std::cout << "I currently have " << quartersLeft << " Quarters, " << dimesLeft << " Dimes, and " << nickelsLeft << " Nickels left." << std::endl;
}

