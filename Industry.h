#ifndef _INDUSTRY_
#define _INDUSTRY_

#include "common.h"

//declaration file for an industry class. theses classes are used to create stock objects
//this class is inherited by EVIndustry, AirlinesIndustry, VGIndustry, TechIndustry class

class Industry {


    private:
    double initialStockPrice;   //intitial stock price which is set for all stocks
    double currentStockPrice;   //the current price changes all the time as trading is carried out throughout the day
    string stockName;       
    double boughtPrice;         //the price you buy the stock at
    double soldPrice;           //the price yous sell the stock at
    int numShares;              //the number of shares you buy
    string description;            //holds the description of a stock and other stocks in the same industry/classification
    double netStockValue;       //net profit/loss on each stock

    

    public:
   
    double getCurrentPrice();                                       //returns current price at a particular instance of the trading day
    void setCurrentPrice(double currentStockPrice);

    void setInitialPrice(double initialStockPrice);
    double getInitialPrice();

    string getName();
    void setName(string stockName);

    void priceChange();             //price changing algorithm which changes the current price of the stock as trading day continues

    double getStockNetValue();      //gets the net profit/loss on each stock

    
     double getBoughtPrice();
     void setBoughtPrice(double boughtPrice);
     int getNumShares();
     void setNumShares(int numShares);

     double totalStockValue();      //returns the total market value of the stock at an instance i.e current price*number of shares

     void setDescription(string des);  
     string getDescription ();
     void printDescription();

     void setSoldPrice(double soldPrice);
     double getSoldPrice();

 



};


#endif