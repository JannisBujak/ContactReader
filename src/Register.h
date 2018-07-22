//
// Created by JannisB98 on 18.06.2018.
//

#ifndef TEST_REGISTER_H
#define TEST_REGISTER_H

#include "Contact.h"

class Register
    {

    private:
        Register* next;
        Contact* contact;
        int ID;

    public:
        Register(int ID);
        void printRegister();
        void add(Contact* contact, int ID);
        string toString();
        int giveSmallestID();

        void deleteID(int ID);

        void deleteByName(string fullName);
};


#endif //TEST_REGISTER_H
