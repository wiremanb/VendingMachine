vendingMachine: main.o InventoryManager.o ChangeManager.o Soda.o VendingLog.o
	g++  main.o InventoryManager.o ChangeManager.o Soda.o VendingLog.o -o vendingMachine

main.o: main.cpp
	g++ -c main.cpp

InventoryManager.o: InventoryManager.cpp InventoryManager.h
	g++ -c InventoryManager.cpp

ChangeManager.o: ChangeManager.cpp ChangeManager.h
	g++ -c ChangeManager.cpp

Soda.o: Soda.cpp Soda.h
	g++ -c Soda.cpp

VendingLog.o: VendingLog.cpp VendingLog.h
	g++ -c VendingLog.cpp

clean:
	rm *.o vendingMachine