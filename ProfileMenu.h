#ifndef _PROFILEMENU_
#define _PROFILEMENU_

#include "common.h"
#include "Menu.h"
#include "User.h"


//child class of Menu class

class ProfileMenu:public Menu {

    private:
    User& user;
    static  string menuIntro;       //static variable which is displayed when program starts

    public:
    ProfileMenu(User &user);
    
    void showMenu();            //this function and the next one is overriding the one in the parent Menu class
    int getUserInput();         //hence polymorphism

    void createProfile();          //creates a porftolio 
    bool loadProfile();         //reading from text files implemented here
    

};

#endif