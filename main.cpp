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


//Classes

class User {
public:
    
    //Class Variables
    unsigned long userAge = 0;
    long hash = 0;
    string userFullName = "\0";
    
    //Constructor
    User (){
        //Get User Full Name + Check If The Input Is Valid
        cout << "User Full Name: ";
        cin.ignore();
        getline(cin, userFullName);
        if (userFullName.length() == 0) {
            cout << "You have provided invalid input for the User\'s First Name." << endl << endl << "Exiting..." << endl;
            exit(1);
        }
        
        //Get User Age + Check If The Input Is Valid
        cout << "User Age: ";
        if (!(cin >> userAge)) {
            cout << "You have provided invalid input for the User\'s Age." << endl << endl << "Exiting..." << endl;
            exit(1);
        }
    }
};

//Functions

// - Old Hashing Function
/*
long hashFunc(long strSize, long powerOf, long strLength) {
    long result = (((strSize ^ powerOf) * strLength) * 0x45676543FFDEADF) ^ 0x45FECA34567654;
    
    return result;
}
*/


// - New Hashing Function

long hashFunc(int input, unsigned int num1, unsigned int num2) {
    //Function Variables
    long hash = 21; //Hash to return
    
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
    //Welcome Text
    cout << "User Manager Welcomes You!" << endl << endl;
    
    //User Array Length
    unsigned int userListLength = 0;
    cout << "Amount Of Users To Register: ";
    cin >> userListLength;
    User userList[userListLength];
    
    for(int counter = 0; counter < userListLength; counter++) {
        int userListNumber = counter + 1;
        
        
        cout << '[' << dec << userListNumber << "] " <<  "User Full Name: " << userList[counter].userFullName << endl;
        cout << '[' << dec << userListNumber << "] " << "User Age: " << dec << userList[counter].userAge << endl;
        
        long userHash = hashFunc(userList[counter].userFullName.length(), userList[counter].userAge, 0x4123efad234843);
        
        
        userList[counter].hash = userHash;

        cout << '[' << userListNumber << "] " <<  "User Hash: " << hex << userHash << " " << endl;
        cout << '[' << counter << "](Last Block/User)'s Hash: " << hex << userList[counter - 1].hash << endl << endl;
        
    }
    
    return 0;
}
