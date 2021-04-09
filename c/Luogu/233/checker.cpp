#include "testlib.h"
#include<string>
int main()
{
	registerTestlibCmd(argc, argv);
    string pans = ouf.readDouble();
    if(pans.compare("AC")) quitf(_ac,"got it");
    else if(pans.compare("WA")) quitf(_wa,"got it");
    else if(pans.compare("RE")) quitf(_re,"got it");
    else if(pans.compare("UKE")) quitf(_uke,"got it");
    else if(pans.compare("TLE")) quitf(_tle,"got it");
    else if(pans.compare("CE")) quitf(_ce,"got it");
    else if(pans.compare("PE")) quitf(_pe,"got it");
    else quitf(_uke,"not found");
} 
