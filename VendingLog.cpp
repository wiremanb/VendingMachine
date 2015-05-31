#include "VendingLog.h"

VendingLog::VendingLog()
{
}

VendingLog::~VendingLog()
{
    writeFile.close();
}

void VendingLog::init()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //std::cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << std::endl;
    fileName = "VendingLog_" + std::to_string(now->tm_year+1900) + "_" + std::to_string(now->tm_mon + 1) + "_" + std::to_string(now->tm_mday);
    fileNameExt = ".log";
    
    std::string openThis = fileName + fileNameExt;
    bool alreadyExist = true;
    int extraFileName = 1;
    while(alreadyExist)
    {
        ifstream readFile(openThis.c_str());
        if(readFile)
        {
            readFile.close();
            extraFileName++;
            openThis = fileName + "_" + std::to_string(extraFileName) + fileNameExt;
        }
        else
        {
            readFile.close();
            alreadyExist = false;
            writeFile.open((openThis.c_str()));
            break;
        }
    }
}

void VendingLog::output(string productName, int productPrice, int quantity)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    float timeNow = 60.0/(t/1000.0);
    writeFile << productName << ", " << productPrice << ", " << quantity << ", " << t << std::endl;
}

