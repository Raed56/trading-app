#include "VGIndustry.h" 



VGIndustry::VGIndustry(string stockName, double initialStockPrice){
    this->setName(stockName);
    this->setInitialPrice(initialStockPrice);
    this->setCurrentPrice(0);
    
    this->setSoldPrice(0);
    this->priceChange();
    this->setBoughtPrice(0);
    this->setNumShares(0);
    this->setDescription("This class includes two video game stocks that you can buy. These are GameStop and Electronic Arts stock.");
}




