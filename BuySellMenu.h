#ifndef _BUYSELLMENU_
#define _BUYSELLMENU_
#include "Menu.h"
#include "User.h"
#include "Industry.h"
#include "EVIndustry.h"
#include "AirlinesIndustry.h"
#include "VGIndustry.h"
#include "TechIndustry.h"


User addStock(User u, Industry stock);          //function for adding a stock to purchasedStock list

User sellStock(User u, Industry stock);         //function for selling a stock 

//child class of Menu class

class BuySellMenu:public Menu{
    
    private:
    int userInput;                  //takes user Input 
    static  string menuType;        //static member which is dispalyed when the buy-sell menu is entered first
    User user;

    EVIndustry Nio;
    EVIndustry Tesla;

    AirlinesIndustry AmericanAirlines;
    AirlinesIndustry UnitedAirlines;
    
    VGIndustry Gamestop;
    VGIndustry EA;

    TechIndustry Facebook;
    TechIndustry Apple;

    public:
    BuySellMenu(User user);

    void showMenu();                                //this function and the next three are overriding the functions in the parent Menu, polymorphism
    void userInputBuyHandler();                     //handles the user Input and uses it to buy stocks
    void userInputSellHandler();                    //handles user input and uses it to sell stocks
    int getUserInput();                             //returns the user input

    void printStockList();                            //prints the list of 8 stocks that can be bought/sold
    void writeandSavePortfolio(User user);          //writing to text files implemented here
    

};




#endif