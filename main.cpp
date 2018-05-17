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
    unsigned int userAge = 0;
    long hash = 0;
    string userFullName = "\0";
    
    //Constructor
    User (){
        cout << "User Full Name: ";
        cin.ignore();
        getline(cin, userFullName);
        cout << "User Age: ";
        cin >> userAge;
    }
};

//Functions

long hashFunc(long strSize, long powerOf, long strLength) {
    long result = (((strSize ^ powerOf) * strLength) * 0x45676543FFDEADF) ^ 0x45FECA34567654;
    
    return result;
}



int main(int argc, const char * argv[]) {
    //Welcome Text
    cout << "User Manager Welcomes You!" << endl << endl;
    
    //User Array Length
    unsigned int userListLength = 3;
    cout << "Amount Of Users To Register: ";
    cin >> userListLength;
    User userList[userListLength];
    
    for(int counter = 0; counter < userListLength; counter++) {
        unsigned int userListNumber = counter + 1;
        
        
        cout << '[' << dec << userListNumber << "] " <<  "User Full Name: " << userList[counter].userFullName << endl;
        cout << '[' << dec << userListNumber << "] " << "User Age: " << dec << userList[counter].userAge << endl;
        
        long userHash = hashFunc(sizeof(userList[counter].userFullName), long(userList[counter].userAge),userList[counter].userFullName.length() ^ 15);
        
        userList[counter].hash = userHash;

        cout << '[' << userListNumber << "] " <<  "User Hash: " << hex << userHash << " " << endl;
        cout << '[' << counter << "](Last Block/User)'s Hash: " << hex << userList[counter - 1].hash << endl << endl;
        
    }
    
    return 0;
}
