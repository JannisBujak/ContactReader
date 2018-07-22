#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;

string getLine(string s, int index)
{
    int line = 0;
    int start = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '\n'){
            line++;
            continue;
        }
        if(line == index && start == 0)
            start = i;
        if(start != 0 && line == index + 1)
            return s.substr(start, i - start);
    }
    if(start != 0)
        return s.substr(start, s.length() - start);

}

string getStringpart(string s, int index)
{
    int countWords = - 1;
    int start = 0;
    bool inWord = false;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ') {
            if(!inWord){
                countWords++;
                inWord = true;
            }
        } else
            inWord = false;

        if(countWords == index) {
            start = i;
            break;
        }
    }
    if(!(index == 0 && s[0] != ' ') && start == 0) {
        //cout << "Index is too high/ input too short";
        return "";
    }
    for(int i = start; i < s.length(); i++)
        if(s[i] == ' ')
            return s.substr(start, i - start);


    if(start != 0){
        return s.substr(start, s.length() - start);
    }
    return {    "Fuck"  };
}

bool isConvertibleToInt(string s){
    if(s.length() == 0) return false;
    for(int i = 0; i < s.length(); i++)
        if(!isdigit(s[i])) return false;
    return true;
}

Register* giveExistingRegister(string filename)
{
    Register* reg = new Register(1);

    ifstream reader;    reader.open(filename);
    string::size_type sz;
    while(reader.good()){
        string line;
        getline(reader, line);
        if(line == "") continue;

        reg->add(new Contact(reg->giveSmallestID(), getStringpart(line, 1),
                             getStringpart(line, 2), getStringpart(line, 3),
                             getStringpart(line, 4), getStringpart(line, 5),
                             getStringpart(line, 6),
                             getStringpart(line, 7), getStringpart(line, 8),
                             getStringpart(line, 9), getStringpart(line, 10),
                             getStringpart(line, 11)), 1);

    }
    reader.close();
    return reg;
}

void write(string s, string filename)
{
    ofstream writer;
    writer.open(filename);
    writer << s;
    writer.close();
}

int main()
{
    Register* reg = giveExistingRegister("text/text.txt");

    string::size_type sz;

    while(true)
    {

        string insert;

        //cin.get();
        getline(cin, insert);

        if(insert == "add") {
            cout << "Type in the data of the new Contact please.\n";
            string contact;

            while(true)
            {
                cout << "first name - second name - birthday - street - adress - plz - city - "
                        "gender - phoneNumber - mobileNumber - email-adress" << endl;
                //cin.get();
                getline(cin, contact);

                if (getStringpart(contact, 10) != "" && getStringpart(contact, 11) == "") {
                    reg->add(new Contact(reg->giveSmallestID(), getStringpart(contact, 0),
                                         getStringpart(contact, 1), getStringpart(contact, 2),
                                         getStringpart(contact, 3), getStringpart(contact, 4),
                                         getStringpart(contact, 5), getStringpart(contact, 6),
                                         getStringpart(contact, 7), getStringpart(contact, 8),
                                         getStringpart(contact, 9), getStringpart(contact, 10)), 1);
                    break;
                } else if (contact == "cancel"){
                    cout << "Canceled making new contact" << endl;
                    break;
                }else {
                    cout << "\nContact length does not fit!\nPlease insert the following:" << endl;
                }
            }
        }else if(insert == "delete ID") {
            cout << "Insert the ID" << endl;
            string deleteID;
            getline(cin, deleteID);

            if(isConvertibleToInt(deleteID)){
                reg->deleteID(stoi(deleteID));
            }

        }else if(insert == "delete"){
            string contact;
            getline(cin, contact);
            //cout << contact;
            reg->deleteByName(contact);
        }else if(insert == "print") {
            reg->printRegister();
        }else if(insert == "reread"){
            reg = giveExistingRegister("text/text.txt");
        }else {
            break;
        }
    }


    //cout << reg->toString();

    write(reg->toString(), "text/text.txt");


    return 0;
}