#ifndef _TECHINDUSTRY_
#define _TECHINDUSTRY_

#include "Industry.h"

//this class is used to make a technology stock. 

class TechIndustry: public Industry{


public:

    TechIndustry(string stockName, double initialStockPrice);
    
};

#endif