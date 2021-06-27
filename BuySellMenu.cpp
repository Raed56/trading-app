#include "BuySellMenu.h"




string BuySellMenu::menuType="\nWelcome to the Buy-Sell Menu!";


BuySellMenu::BuySellMenu(User user):
Nio("Nio", 30),
Tesla("Tesla",600),
AmericanAirlines("American Airlines", 20),
UnitedAirlines("United Airlines", 15),
Gamestop("Gamestop", 70),
EA("Electronic Arts", 50),
Facebook("Facebook", 250),
Apple("Apple", 120)

{
    this->user=user;

}

void BuySellMenu::showMenu(){
   
    cout<<menuType<<endl<<endl;
    while(true){
        
        cout<<"Select an option from the list below."<<endl<<endl;
        cout<<"1. Buy Stocks"<<endl<<"2. Sell Stocks"<<endl<<"3. Continue Trading and View Portfolio Stats"<<endl<<"4. End Trading Day, Save Portfolio and Exit Program"<<endl<<endl;
        this->userInput=getUserInput();

        if(this->userInput==4){
            cout<<"PRINTING PORTFOLIO INFORMATION AND ENDING TRADING DAY"<<endl<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
            user.priceChangeAllPurchasedStocks();
            showUserStats(user);
            cout<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
            user.printPurchasedStockList();
            user.printSoldStockList();
        
            
            cout<< "Exiting Program. Your portfolio is saved in an output file \"Portfolio.txt\". BYE!!"<<endl<<endl;

            writeandSavePortfolio(user);    //writing for displaying to user later
                

            return;
        }


        if(this->userInput<1 ||this->userInput>4){
            cout<<"Please select a valid option from the menu."<<endl<<endl;
            continue;
        }
        

        if(this->userInput==1){
            this->userInputBuyHandler();
        }

        if(this->userInput==2){

           this->userInputSellHandler();     

        } 

        if(this->userInput==3){
            user.priceChangeAllPurchasedStocks();       //everytime the user wishes to see the updated portfolio the profit/loss on all stocks change
            showUserStats(user);
            cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
            user.printPurchasedStockList();
            user.printSoldStockList();
        }
        
      
    }  
    
}

int BuySellMenu::getUserInput(){
    int menuChoice=0;

    cout<<"Enter your menu choice number: ";
    cin>>menuChoice;

    cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
   
    return menuChoice;

}

void BuySellMenu::userInputBuyHandler(){
    int stockBuyChoice=0;
    int numShares=0;

   
    this->printStockList();
    cout<<"\nEnter the stock number you want to buy: ";
    cin>>stockBuyChoice;
    cout<<endl;

    if (stockBuyChoice<1||stockBuyChoice>8) {
        cout<<"Invalid option! Returning to main menu."<<endl<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
        
        return;
    }

    cout<<"Please enter the number of shares you want to buy: ";
    cin>>numShares;

    cout<<endl;

    cout<<"Congratulations you have bought the chosen stock!"<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
   

    if(stockBuyChoice==1){
        
        this->Nio.setNumShares(numShares);
        this->user = addStock(this->user, this->Nio);

        this->user.printPurchasedStockList();
        this->Nio.setNumShares(0);
        
    }
    else if (stockBuyChoice==2){
        this->Tesla.setNumShares(numShares);
        this->user = addStock(this->user, this->Tesla);

        this->user.printPurchasedStockList();
        this->Tesla.setNumShares(0);
    }
    else if (stockBuyChoice==3){
        this->AmericanAirlines.setNumShares(numShares);
        this->user = addStock(this->user, this->AmericanAirlines);

        this->user.printPurchasedStockList();
        this->AmericanAirlines.setNumShares(0);
    }
    else if (stockBuyChoice==4){
        this->UnitedAirlines.setNumShares(numShares);
        this->user = addStock(this->user, this->UnitedAirlines);

        this->user.printPurchasedStockList();
        this->UnitedAirlines.setNumShares(0);
    }
    else if (stockBuyChoice==5){
        this->Gamestop.setNumShares(numShares);
        this->user = addStock(this->user, this->Gamestop);

        this->user.printPurchasedStockList();
        this->Gamestop.setNumShares(0);
    }
    else if (stockBuyChoice==6){
        this->EA.setNumShares(numShares);
        this->user = addStock(this->user, this->EA);

        this->user.printPurchasedStockList();
        this->EA.setNumShares(0);
    }
    else if (stockBuyChoice==7){
        this->Facebook.setNumShares(numShares);
        this->user = addStock(this->user, this->Facebook);

        this->user.printPurchasedStockList();
        this->Facebook.setNumShares(0);
    }
    else if (stockBuyChoice==8){
        this->Apple.setNumShares(numShares);
        this->user = addStock(this->user, this->Apple);

        this->user.printPurchasedStockList();
        this->Apple.setNumShares(0);
    }
    

   
}

void BuySellMenu::userInputSellHandler(){
    string stockSellChoice="";

    if(user.getPurchasedStocks().empty()){
        cout<<"You have not bought any stocks that can be sold! Returning to main menu."<<endl<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
        return;
    }

    
    cout<<"Please enter the name of the stock you want to sell: ";
    
    getline(cin >> ws, stockSellChoice);


    cout<<endl;

    if(stockSellChoice.compare("Nio")==0){
        
        this->user = sellStock(this->user, this->Nio);
        
    }
    else if(stockSellChoice.compare("Tesla")==0){
        
        this->user = sellStock(this->user, this->Tesla);
        
    }
    else if(stockSellChoice.compare("American Airlines")==0){
        
        this->user = sellStock(this->user, this->AmericanAirlines);
        
    }
    else if(stockSellChoice.compare("United Airlines")==0){
        
        this->user = sellStock(this->user, this->UnitedAirlines);
        
    }
    else if(stockSellChoice.compare("Gamestop")==0){
        
        this->user = sellStock(this->user, this->Gamestop);
        
    }
    else if(stockSellChoice.compare("Electronic Arts")==0){
        
        this->user = sellStock(this->user, this->EA);
        
    }
    else if(stockSellChoice.compare("Facebook")==0){
        
        this->user = sellStock(this->user, this->Facebook);
        
    }
    else if(stockSellChoice.compare("Apple")==0){
        
        this->user = sellStock(this->user, this->Apple);
        
    }
    else{
        cout<<"Invalid stock name! Please try again from the main menu."<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
        return;

    }

    cout<<"Congratulations you have sold the desired stock!"<<endl<<endl;
    
    cout<<"UPDATED LISTS"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
    user.printPurchasedStockList();
    user.printSoldStockList();
    
    
    
}


void BuySellMenu:: printStockList(){
    cout<<"The stocks below, listed with their starting prices, are available for purchase:"<<endl<<endl;
    cout<<"1. Nio - "<<Nio.getInitialPrice()<<endl;
    cout<<"2. Tesla - "<<Tesla.getInitialPrice()<<endl;
    cout<<"3. American Airlines - "<<AmericanAirlines.getInitialPrice()<<endl;
    cout<<"4. United Airlines - "<<UnitedAirlines.getInitialPrice()<<endl;
    cout<<"5. Gamestop - "<<Gamestop.getInitialPrice()<<endl;
    cout<<"6. Electronic Arts - "<<EA.getInitialPrice()<<endl;
    cout<<"7. Facebook - "<<Facebook.getInitialPrice()<<endl;
    cout<<"8. Apple - "<<Apple.getInitialPrice()<<endl;
    
}

User addStock(User u, Industry stock){
    u+=stock;
    u.priceChangeAllPurchasedStocks();        //enable to allow day trading
    return u;
}

User sellStock(User u, Industry stock){
    u-=stock;
    u.priceChangeAllPurchasedStocks();        //enable to allow day trading
    return u;
}

void BuySellMenu::writeandSavePortfolio(User user){
    ofstream output;

    output.open("Portfolio.txt"); // opens the file

   if( !output ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
   
   output<<"-----------------------------------------------------------------------------"<<endl;

   output <<"Name of user: "<<user.getName()<<endl;
   output<<"Email of user: "<<user.getEmail()<<endl;
   output<<"Total value of portfolio: "<<user.getTotalValue()<<endl;
   output<<"Net Profit/Loss in portfolio: "<<user.getNetValue()<<endl;

   output<<"-----------------------------------------------------------------------------"<<endl<<endl;

   //print purchased stocks

   output<< "The purchased stocks are : "<<endl<<endl;


   for(int i=0; i < (int) user.getPurchasedStocks().size(); i++){

       
       output<< "STOCK NUMBER-"<<i+1<<endl<<endl;

        
        output<<"Description of all stocks in the same industry: "<< user.getPurchasedStocks().at(i).getDescription()<<endl;
       
        output<<"Stock Name: "<<user.getPurchasedStocks().at(i).getName()<<endl;
        output<<"Today's Starting Price: "<<user.getPurchasedStocks().at(i).getInitialPrice()<<endl;
        output<<"Current Price: "<<user.getPurchasedStocks().at(i).getCurrentPrice()<<endl;

        output<<"Bought Price: "<<user.getPurchasedStocks().at(i).getBoughtPrice()<<endl;
        output<<"Number of Shares: "<<user.getPurchasedStocks().at(i).getNumShares()<<endl;
        output<<"Total Value of Stocks: "<<user.getPurchasedStocks().at(i).totalStockValue()<<endl;
        output<<"Net Profit/Loss on this Stock: "<<user.getPurchasedStocks().at(i).getStockNetValue()<<endl<<endl;
        
   }
   
   output<<"-----------------------------------------------------------------------------"<<endl<<endl;
   
   
   //print sold stocks

    output<<"The list of sold stocks contain: "<<endl<<endl;

    for(int i=0; i<(int)user.getSoldStocks().size();i++){
        output<< "STOCK NUMBER-"<<i+1<<endl<<endl;
       
        output<<"Stock Name: "<<user.getSoldStocks().at(i).getName()<<endl;
        output<<"Today's Starting Price: "<<user.getSoldStocks().at(i).getInitialPrice()<<endl;
        output<<"Current Price: "<<user.getSoldStocks().at(i).getCurrentPrice()<<endl;
        output<<"Bought Price: "<<user.getSoldStocks().at(i).getBoughtPrice()<<endl;
        output<<"Sold Price: "<<user.getSoldStocks().at(i).getSoldPrice()<<endl;
        
        output<<"Number of Shares: "<<user.getSoldStocks().at(i).getNumShares()<<endl;
        output<<"Total Value of Stocks: "<<user.getSoldStocks().at(i).totalStockValue()<<endl;
        output<<"Net Profit/Loss on this Stock: "<<user.getSoldStocks().at(i).getStockNetValue()<<endl<<endl;
        
    }

   output<<"-----------------------------------------------------------------------------"<<endl<<endl;

   output.close();
    

}

