//
// Created by JannisB98 on 18.06.2018.
//

#include "Register.h"

Register::Register(int ID){
    this->ID = ID;
    contact = nullptr;
    next = nullptr;
}

void Register::add(Contact* contact, int ID)
{
    if(this->contact == NULL)
    {
        //cout << "Rar";
        this->contact = contact;
        if(next == nullptr) next = new Register(this->ID + 1);
        return;
    }
    //cout << "Fif";
    next->add(contact, ID + 1);
}

void Register::printRegister() {
    if(this== nullptr)  return;
    if(contact != NULL){
        contact->printContact();
        cout << "\n";
    }
    next->printRegister();


}

string Register::toString() {
    if(this == nullptr)    return "";
    if(contact != NULL){
        string text = contact->toString();
        text += "\n";
        text += next->toString();
        return text;
    }
    return "";
}

int Register::giveSmallestID() {
    if(contact == nullptr) return this->ID;
    if(next == nullptr) return  this->ID + 1;
    return next->giveSmallestID();
}

void Register::deleteID(int ID) {
    if(this == nullptr || contact == nullptr){
        cout << "ID " << ID << " not found" << endl;
        return;
    }
    cout << contact->getID() << endl;
    if(contact->getID() == ID){
        cout << "Deleted " << contact->toString() << endl;
        delete(contact);
        this->contact = nullptr;
    }else{
        next->deleteID(ID);
    }
}

void Register::deleteByName(string fullName) {
    if(this == nullptr || contact == nullptr){
        cout << "Name " << fullName << " not found" << endl;
        return;
    }
    cout << contact->getFullName() << endl;
    if(contact->getFullName() == fullName){
        cout << "Deleted " << contact->toString() << endl;
        delete(contact);
        this->contact = nullptr;
    }else{
        next->deleteByName(fullName);
    }
}
