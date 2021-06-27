#include "EVIndustry.h" 



EVIndustry::EVIndustry(string stockName, double initialStockPrice){
    this->setName(stockName);
    this->setInitialPrice(initialStockPrice);
    this->setCurrentPrice(0);
    
    this->setSoldPrice(0);
    this->priceChange();
    this->setBoughtPrice(0);
    this->setNumShares(0);
    this->setDescription("This class includes two electric vehicle stocks that you can buy. These are Nio and Tesla stock.");
}


 

