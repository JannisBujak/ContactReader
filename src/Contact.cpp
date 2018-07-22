//
// Created by JannisB98 on 18.06.2018.
//

#include "Contact.h"

Contact::Contact(int ID, string firstName, string secondName, string birthday, string street, string adress, string plz, string city, string gender, string phoneNumber, string mobileNumber, string emailAdress)
        : ID(ID) {
    //this->ID = ID;
    this->firstName = firstName;
    this->secondName = secondName;
    this->birthday = birthday;
    this->street = street;
    this->adress = adress;
    this->plz = plz;
    this->city = city;
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->mobileNumber = mobileNumber;
    this->emailAdress = emailAdress;
}

Contact::Contact() : ID(ID) {}


void Contact::printContact() {
    cout << "ID: " << ID << "\n"
            << "First name: " << firstName << "\n"
            << "Second name: " << secondName << "\n"
            << "Birthday: " << birthday << "\n"
            << "Street: " << street << "\n"
            << "Adress: " << adress << "\n"
            << "Plz: " << plz << "\n"
            << "City: " << city << "\n"
            << "Gender: " << gender << "\n"
            << "PhoneNumber: " << phoneNumber << "\n"
            << "MobileNumber: " << mobileNumber << "\n"
            << "EmailAdress: " << emailAdress << "\n";
}

string Contact::toString() {
    return (to_string(ID) + " " + firstName + " " + secondName + " " + birthday + " " + street + " "
                    + adress + " " + plz + " " + city + " " + gender + " " + phoneNumber + " " + mobileNumber + " " + emailAdress);
}

int Contact::getID() {
    return this->ID;
}

string Contact::getFullName() {
    return firstName + " " + secondName;
}