//
//  main.cpp
//  User Manager
//
//  Created by Noah Scott on 5/15/18.
//  Copyright © 2018 Noah Scott Digital. All rights reserved.
//

#include <iostream>
#include <string>
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
    string userFirstName = "John\0";
    string userLastName = "Doe\0";
    
    //Constructor
    User (){
        cout << "User First Name: ";
        cin >> userFirstName;
        cout << "User Last Name: ";
        cin >> userLastName;
        cout << "User Age: ";
        cin >> userAge;
    }
};

//Functions

int hashFunc(int strSize, int powerOf, int strLength) {
    int result = ((strSize ^ powerOf) * strLength) ^ powerOf;
    
    
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
        
        cout << '[' << userListNumber << "] " << "User First Name: " << userList[counter].userFirstName << endl;
        cout << '[' << userListNumber << "] " << "User Last Name: " << userList[counter].userLastName << endl;
        cout << '[' << userListNumber << "] " << "User Age: " << userList[counter].userAge << endl << endl;
        
        string fullName = userList[counter].userFirstName + " " + userList[counter].userLastName;
        
        int userHash = hashFunc(sizeof(fullName), userList[counter].userAge, fullName.length());
        
        cout << '[' << userListNumber << "] " <<  "User Full Name: " << fullName << endl;
        cout << '[' << userListNumber << "] " <<  "User Hash: " /*<< hex*/ << userHash << " " << endl << endl;
        
    }
    
    return 0;
}
