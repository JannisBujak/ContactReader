//
// Created by JannisB98 on 18.06.2018.
//
#ifndef CONTACTS_H
#define CONTACTS_H

#define NUMBER_OF_ATRIBUTES 11
#include <iostream>
using namespace std;

class Contact {
    private:
        const int ID;
        string firstName;
        string secondName;
        string birthday;
        string street;
        string adress;
        string plz;
        string city;
        string gender;
        string phoneNumber;
        string mobileNumber;
        string emailAdress;
    public:
        Contact(int ID, string firstName, string secondName, string birthday, string street, string adress, string plz, string city, string gender, string phoneNumber, string mobileNumber, string emailAdress);
        Contact();

        void printContact();
        string toString();
        int getID();
        string getFullName();
};


#endif //TEST_CONTACTS_H
