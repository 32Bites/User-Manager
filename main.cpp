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
    int userAge = 0;
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
    long result = (((strSize ^ powerOf) * strLength) / 0x45676543FFDEADF) ^ 0x45FECA34567654;
    
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
        int userListNumber = counter + 1;
        
        cout << '[' << userListNumber << "] " <<  "User Full Name: " << userList[counter].userFullName << endl;
        cout << '[' << userListNumber << "] " << "User Age: " << userList[counter].userAge << endl << endl;
        
        long userHash = hashFunc(sizeof(userList[counter].userFullName), long(userList[counter].userAge),userList[counter].userFullName.length() ^ 15);

        cout << '[' << userListNumber << "] " <<  "User Hash: " << hex << userHash << " " << endl << endl;
        
    }
    
    return 0;
}
