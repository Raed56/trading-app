/*
Name-Raed Idris Seraj
U72350822


This is a trading/brokerage application where you are able to trade from a list of 8 stocks. 
My main goal here was to create a practical trading application which can help beginner inestors learn how to trade stocks.
This is particularly useful to them as they can see their profit/loss on the their investment.

*/

#include "Industry.h"
#include "EVIndustry.h"
#include "VGIndustry.h"
#include "AirlinesIndustry.h"
#include "TechIndustry.h"
#include "User.h"
#include "BuySellMenu.h"
#include "ProfileMenu.h"

int main() {
   

    srand(time(NULL));
 

    User u1=User();
    
    ProfileMenu m1= ProfileMenu(u1);
    
    m1.showMenu();

    BuySellMenu bsm = BuySellMenu(u1);

    bsm.showMenu();

    return 0;
}



/*LIST OF RULES FOR THE PROGRAM :

1. When stocks are sold, all of them are sold. In the case of duplicates, all stocks in the intitial/first purchase is sold. 
2. Day trading can be toggled on/off. Day trading is currently allowed. Price of stocks and total value of portfolio, net profit/loss always changes as a transaction (buying/selling) is made.
3. Duplicate stocks can be bought. However when selling, this will remove the the first batch of stocks bought. The latest batch is not sold.
4. All buying of stocks are assumed to be done at once. If day trading is allowed, however, the price of stocks changes after each transaction.
5. No fractional buying/selling of stocks.
6. Everytime the user runs the view statistic button, the profit/loss on the stock changes. So they can view their stats and decide to sell the stock only when they are at a profit.
7. When the program is terminated, the price change algorithm is applied to all pruchased stock one last time before closing and saving the portfolio.
    This can be thought of as the effect fo after-hours trading on stocks. 


CONCEPTs of OOP :

1. Encapsulation-done in many classes through private and public members. ex: BuySellMenu, ProfileMenu, User and Industry class

2. Inheritance-done in EVIndustry, VGIndustry, TechIndusrty, AirlinesIndustry classes and also ProfileMenu, BuySellMenu class

3. Polymorphism- done in child ProfileMenu and BuySellMenu class

4. Static members/functions- done in ProfileMenu class with "menuIntro" and BuySellMenu class with "menuType"

5. Friend functions- done in User class for showing user stats and to add/remove a stock as they are bought/sold

6. Overloaded operators -done in User class for adding and removing stocks

7. Text files - writing to text files implemented in BuySellMenu class, reading from text files implemented in ProfileMenu class

*/

