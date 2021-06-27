#include "Industry.h"

//implementation file for the industry class


double Industry::getCurrentPrice(){
    return currentStockPrice;

}

void Industry::setCurrentPrice(double currentStockPrice){
    this->currentStockPrice=currentStockPrice;
}

void Industry::setInitialPrice(double initialStockPrice){
    this->initialStockPrice=initialStockPrice;
}

double Industry::getInitialPrice(){
    return initialStockPrice;
}

string Industry:: getName(){
    return stockName;
}

void Industry:: setName(string stockName){
    this->stockName=stockName;
}
 
//this is the price changing algorithm which changes the value of the current price of the stock as the program is run
//this randomly increases/decreases the price of a stock.
//a stock's current price can change upto 10% in each iteration/call of the function
//depending on how much the stock price changes, this application can reflect a stock market where the maximum change of a stock can be upto 10% 

void Industry::priceChange(){

   
    int choice=rand()%2+1;
    

    if (choice==1){
       
        double x = this->initialStockPrice * ((rand()%10+1)+100)/ (double) 100;

        this->currentStockPrice = x;

        return;
    }
    
    double x =this->initialStockPrice*(100-(rand()%10+1))/ (double) 100;

    this->currentStockPrice = x;

}

void Industry::setDescription(string des){
    this->description = des;
}

void Industry::printDescription(){
    cout << this->description << endl;
}


double Industry::getBoughtPrice(){
    return this->boughtPrice;
 }
void Industry::setBoughtPrice(double boughtPrice){
    this->boughtPrice = boughtPrice;
}
int Industry::getNumShares(){
    return this->numShares;
}
void Industry::setNumShares(int numShares){
    this->numShares= numShares;
}
double Industry::totalStockValue(){
    return getCurrentPrice()*numShares;
}

double Industry::getStockNetValue(){
    return totalStockValue()-getBoughtPrice()*numShares;
}

void Industry::setSoldPrice(double soldPrice){
    this->soldPrice=soldPrice;
}

double Industry::getSoldPrice(){
    return this->soldPrice;
}

string Industry::getDescription (){
    return this->description;
}