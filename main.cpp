//
//  main.cpp
//  
//
//  Created by Benjamin Wireman on 2/5/15.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include "InventoryManager.h"
#include "ChangeManager.h"
#include "Soda.h"
#include "VendingLog.h"

enum states{IDLE=0, SELECT, DISPENSE, CHANGE, QUIT, ERROR};
states currentState = IDLE;
bool quit = false;
bool waitForChange = false;
int coinInput = 0;
int drinkInput = 0;
int selectedDrink = -9999;
int totalInput = 0;
int logTimer = 0;
int sodaPrices[10] = {60,100,60,60,100,60,100,60,60,100};
int inventoryCounts[10] = {0};
std::string userInput;
std::string sodaNames[10] = {"Dr. Pepper", "Pepsi", "Coke", "Sprite", "Root Beer", "Diet Dr. Pepper", "Diet Pepsi", "Diet Coke", "Diet Sprite", "Diet Root Beer"};
Soda *sodas[10];
ChangeManager *changeManager;
InventoryManager *inventoryManager;
VendingLog vendingLog;

void stateMachine();
int chooseDrink(int input);

int main(int argc, char* argv[])
{
    for(int i=0; i<10; i++)
    {
        sodas[i] = new Soda(sodaNames[i], sodaPrices[i], 0);
    }
    vendingLog.init();
    inventoryManager = new InventoryManager(sodas, inventoryCounts, 0);
    changeManager = new ChangeManager(5,5,5);
    
    while(!quit)
    {
        stateMachine();
        if(logTimer++ >= 1)
        {
            for(int i=0; i<inventoryManager->numberOfProducts(); i++)
            {
                vendingLog.output(inventoryManager->productName(i), inventoryManager->productPrice(i),
                                  inventoryManager->productSold(i));
            }
            logTimer = 0;
        }
        usleep(100000);
    }
    
    for(int i=0; i<10; i++)
        delete sodas[i];
    delete inventoryManager;
    delete changeManager;
    return 0;
}

void stateMachine()
{
    switch(currentState)
    {
        case IDLE:
            static bool displayDrinkList = true;
            if(displayDrinkList)
            {
                std::cout << "What drink would you like? " << std::endl;
                for(int i=0; i<inventoryManager->numberOfProducts(); i++)
                {
                    std::cout << i+1 << ") " << inventoryManager->productName(i) << ", price: " << inventoryManager->productPrice(i) << std::endl;
                }
                displayDrinkList = false;
            }
            
            std::cout << std::endl;
            cin >> drinkInput;
            selectedDrink = chooseDrink(drinkInput);
            if(selectedDrink > 0 && selectedDrink <= 10)
            {
                displayDrinkList = true;
                currentState = SELECT;
            }
            
            // The user shouldn't know about this. This is only for a developer.
            else if(selectedDrink == 100)
            {
                quit = true;
                std::cout << "Shutting down..." << std::endl;
            }
            else
            {
                std::cout << "Not an option, try again!" << std::endl << std::endl;
                displayDrinkList = true;
            }
            break;
            
        case SELECT:
            static bool displayMsg = true;
            
            if(displayMsg)
            {
                std::cout << "Please, Insert Coins" << std::endl;
                displayMsg = false;
            }
            
            std::cout << std::endl;
            std::cout << "Only Nickels (5), Dimes (10), and Quarters (25). Thank you!" << std::endl;
            cin >> coinInput;
            
            if(coinInput == 25 || coinInput == 10 || coinInput == 5)
            {
                totalInput += coinInput;
                changeManager->addCoin(coinInput);
                std::cout << totalInput << std::endl;
            }
            
            if(totalInput >= inventoryManager->productPrice(selectedDrink-1))
            {
                inventoryManager->checkProduct(selectedDrink-1);
                currentState = DISPENSE;
                waitForChange = true;
                displayMsg = true;
                
            }
            break;
            
        case DISPENSE:
            std::cout << "Dispensing..." << std::endl;
            usleep(200000);
            std::cout << "Please, Take your " << inventoryManager->productName(selectedDrink-1) << "." << std::endl;
            currentState = CHANGE;
            break;
            
        case CHANGE:
            changeManager->customerChange(totalInput, inventoryManager->productPrice(selectedDrink-1));
            currentState = IDLE;
            waitForChange = false;
            totalInput = 0;
            coinInput = 0;
            selectedDrink = 0;
            std::cout << std::endl;
            break;
            
        case QUIT:
            break;
            
        case ERROR:
            break;
    }
}

int chooseDrink(int input)
{
    switch(input)
    {
        case 1: return 1;
            break;
        case 2: return 2;
            break;
        case 3: return 3;
            break;
        case 4: return 4;
            break;
        case 5: return 5;
            break;
        case 6: return 6;
            break;
        case 7: return 7;
            break;
        case 8: return 8;
            break;
        case 9: return 9;
            break;
        case 10: return 10;
            break;
        case 100: return 100;
            break;
        default: return -9999;
            break;
    }
}