#include "ProfileMenu.h"
#include "common.h"

string ProfileMenu::menuIntro="Welcome to Raed's Brokerage Application!";


ProfileMenu::ProfileMenu(User& user):user(user) {
}

void ProfileMenu::showMenu(){
    
    cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
    cout<< menuIntro<<endl<<endl;
    int userInput=0;

    while(true){
        
        cout<< "Please select from the following options: "<<endl;
        cout<<"1. Create a new portfolio."<<endl<<"2. Display an existing portfolio."<<endl<<endl;
        userInput=getUserInput();

        if(userInput==1){
             createProfile();
             return;
        }
        else if (userInput==2){

            bool readStatus;

           

            //include error handling for if there is no existing profile


            readStatus=loadProfile();    

            if(readStatus==true){

                cout<<"Closing Portfolio and Exiting program."<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;  
                exit(1);
            }
            
            cout<<"There is no existing portfolio. Please create one first."<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
            
            
        }
        else{
            cout<<"Invalid option! Try again."<<endl<<endl;

        }
       
    }
}



int ProfileMenu::getUserInput(){
    int command;

    cout<<"Command: ";
    cin>>command;
    cout<<endl;
   
   
    return command;
}

void ProfileMenu::createProfile(){

    string name;
    string email;

    cout<<"Please enter your name: ";
    getline(cin >> ws, name);
    
   
    cout<<"Please enter your email: ";
    getline(cin >> ws, email);
    
    
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;

    this->user.setName(name);
    this->user.setEmail(email);
   
}

//this function is to read the portfolio file to display to the user in a proper format
bool ProfileMenu::loadProfile(){


    string text;
    bool read=false;
    

    ifstream readFile("Portfolio.txt");

    
    
    while (getline (readFile, text)) {
    // Output the text from the file
        if(read==false){
            cout<<"Here is your existing portfolio information: "<<endl<<endl;
            read=true;
        }
    
        cout << text<<endl;

    }

   

    readFile.close();

    return read;
}

