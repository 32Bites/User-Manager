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

int hashFunc(int strSize, int powerOf, int strLength) {
    int result = ((strSize ^ powerOf) * strLength) ^ powerOf;
    result = result * 0x2423FEA3;
    result = result ^ (powerOf /(strSize / strLength));
    result = result * 0x74FE234AB67D;

    int argsAdded = (strSize + powerOf + strLength) + 0x74FE234AB67D;

    for (int counter = 0; counter > argsAdded; counter + 0x74FE234AB67D) {
        result = result + (0x74FE234AB67D + 0x2423FEA3);
    }

    
    
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
        
        int userHash = hashFunc(sizeof(userList[counter].userFullName), userList[counter].userAge, userList[counter].userFullName.length());

        cout << '[' << userListNumber << "] " <<  "User Hash: " << hex << userHash << " " << endl << endl;
        
    }
    
    return 0;
}
