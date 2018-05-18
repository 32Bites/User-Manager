//
//  main.cpp
//  User Manager
//
//  Created by Noah Scott on 5/15/18.
//  Copyright © 2018 Noah Scott Digital. All rights reserved.
//

//C++ Libraries

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

//C libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

//Constants - ANSI COLORS

const string RED = "\x1b[31m";
const string GREEN = "\x1b[32m";
const string YELLOW = "\x1b[33m";
const string BLUE = "\x1b[34m";
const string MAGENTA = "\x1b[35m";
const string CYAN = "\x1b[36m";
const string RESET = "\x1b[0m";
const string BOLD = "\033[1m";


//Classes.

// - User Class.

class User {
public:
    
    //Class Variables.
    unsigned long userAge = 0;
    long hash = 0;
    string userFullName = "\0";
    
    //Constructor.
    User (){
        //Get User Full Name + Check If The Input Is Valid.
        cout << RESET << "User Full Name: " << BLUE;
        cin.ignore();
        getline(cin, userFullName);
        if (userFullName.length() == 0) {
            cout << RED << BOLD << "You have provided invalid input for the User\'s First Name." << endl << endl << RESET << "Exiting..." << endl << endl;
            exit(1);
        }
        
        //Get User Age + Check If The Input Is Valid.
        cout << RESET << "User Age: " << BLUE;
        if (!(cin >> userAge)) {
            cout << RED << BOLD << "You have provided invalid input for the User\'s Age." << endl << endl << RESET << "Exiting..." << endl << endl;
            exit(1);
        }
    }
};

//Functions.

// - Hashing Function.

long hashFunc(int input, unsigned int num1, unsigned int num2) {
    //Function Variables.
    long hash = 21; //Hash to return.
    //Does the maths.
    for (int counter = 0; counter < input; counter++) {
        hash = hash * input;
        hash = hash + counter;
        hash = hash + num1;
        hash = hash * num2;
        hash = hash ^ (num2 * input * num1);
    }


    
    return hash;
    
}



int main(int argc, const char * argv[]) {
    //Welcome Text.
    cout << GREEN << BOLD << "User Manager Welcomes You!" << RESET << endl << endl;
    
    //User Array Length.
    unsigned int userListLength = 0;
    cout << RESET << "Amount Of Users To Register: " << BLUE;
    cin >> userListLength;
    User userList[userListLength];
    
    //Displays the User Objects with a For Loop.
    for(int counter = 0; counter < userListLength; counter++) {
        int userListNumber = counter + 1; 
        long userHash = hashFunc(userList[counter].userFullName.length(), userList[counter].userAge, 0x4123efad234843); //Calculates the hash.
        userList[counter].hash = userHash; //Puts the hash into the "User" Class Array Object, used for displaying the Previous Hash.
        long lastHash = userList[counter - 1].hash; //The "Previous Hash".
        
        if (counter == 0) { lastHash = 0; } // Creates the "Genesis" Block.



        //The Output
        cout << RESET << '[' << CYAN << BOLD << dec << userListNumber << RESET << "] " << MAGENTA << "User Full Name: " << RESET << userList[counter].userFullName << endl;
        cout << RESET << '[' << CYAN << BOLD << dec << userListNumber << RESET << "] " << MAGENTA << "User Age: " << RESET << dec << userList[counter].userAge << endl;
        cout << RESET << '[' << CYAN << BOLD << userListNumber << RESET << "] " << MAGENTA <<  "User Hash: " << RESET << hex << userHash << " " << endl;
        cout << RESET << '[' << YELLOW << BOLD << counter << RESET << "] " << MAGENTA << "Previous Hash: " << RESET << hex << lastHash << endl << endl;
        
    }
    return 0;
}
