#ifndef _USER_
#define _USER_

#include "common.h"
#include "Industry.h"

class User{

private:
    string name;                             //holds name of user
    string email;                           //holds user email
    double boughtPrice;
    double totalValue;                      //portfolio total value
    double netValue;                        //hold the profit or loss of the entire portfolio
    vector<Industry> purchasedStocks;       //vector of all purchased stocks    
    vector <Industry> soldStocks;           //vector of all sold stocks
  

public:

    void setName(string name);
    string getName();

    void setEmail(string email);
    string getEmail();

    friend void showUserStats(User user);           //** friend function used here which returns portfolio information

    void adjustTotalValue();                        //calculates the total value of the portfolio as transactions are made
    void adjustNetValue();                          //calculates the net profit in the portfolio as transactions are made

    double getTotalValue();
    void setTotalValue(double totalValue);
    void setNetValue(double netValue);

    double getNetValue();

    void priceChangeAllPurchasedStocks();                       //applies the price changing algorithm to all purchased stocks

    friend User& operator += (User& user,Industry st);          //**overloaded operators and friend functions used here to 
                                                                //add a stock to the portfolio when it is bought

    friend User& operator -= (User& user,Industry st);          //**overloaded operators and friend functions used here
                                                                //sell a stock and remove from portfolio

    void printPurchasedStockList();                             //prints stocks that are still in the portfolio

    void printSoldStockList();                                  //prints list of sold stocks

    vector<Industry> getPurchasedStocks();              
    vector<Industry> getSoldStocks();

};

#endif