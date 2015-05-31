#ifndef VendingLogHeader

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include <ctime>


using namespace std;
#define VendingLogHeader

class VendingLog
{
private:
    fstream logFile;
    std::string fileName;
    std::string fileNameExt;
    ofstream writeFile;
public:
	VendingLog();
	~VendingLog();
    void init();
	void output(string, int, int);
};
#endif