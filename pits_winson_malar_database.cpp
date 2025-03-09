#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define AADHAR 1
#define PAN 2
#define NAME 3
#define AGE 4
#define DOB 5
#define ERROR_STRING "-1"
#define NO_FILE "__none__"
#define _ERROR_ 0
#define _SUCCESS_ 1
#define MAXCITIZEN 100000

#define INSERT 0
#define DELETE_LAST 1
#define DELETE 2
#define STORE 3

#define EXIT -1

struct Date{
    int day;
    int month;
    int year;

    string string_format(){
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

class Citizen{
    private:
        string aadharNumber;
        string panNumber;

    public:
        string name;
        int age;
        Date dateOfBirth;

        Citizen(){}  /* Default Constructor DO NOT CHANGE ANYTHING */ 

        void set_details(string name_, int age_, string aadharNo, string panNo, Date dob){
            name = name_;
            age = age_;
            aadharNumber = aadharNo;
            panNumber = panNo;
            dateOfBirth = dob;
        } 
  
        string get_details(int type){
            if(type == AADHAR){
                return aadharNumber;
            }
            else if(type == PAN){
                return panNumber;
            }
            else{
                return ERROR_STRING;
            }
        }

        string make_data(){
            string combined_data = name + ", " + to_string(age) + ", " + aadharNumber + ", " + panNumber + ", " + dateOfBirth.string_format();
            return combined_data;  
        }
};

class Database{
    private:
        string hash_string(string &s){
            string hashed_string = s;
            for(int i = 0; i < hashed_string.size(); i++) hashed_string[i] += 1; // Simple encryption
            return hashed_string;
        }

        string unhash_string(string &s){
            string unhashed_string = s;
            for(int i = 0; i < unhashed_string.size(); i++) unhashed_string[i] -= 1; // Simple decryption
            return unhashed_string;
        }

        string adminUsername;
        string adminPin;
        Citizen citizenList[MAXCITIZEN];
        int currentSize;
    
    public:
        Database(string name_, string pin_){
            adminUsername = name_;
            adminPin = hash_string(pin_); // Encrypting password
            currentSize = 0;
        }

        bool verify(string name_, string pin_){
            string unhashed_string = unhash_string(adminPin);
            bool matched = false;
            if(unhashed_string == pin_ && adminUsername == name_){
                matched = true;
            }
            return matched;
        }

        void insertEntry(Citizen citizen, string name_, string pin_){
            if(verify(name_, pin_)){
                if(currentSize < MAXCITIZEN){
                    citizenList[currentSize++] = citizen;
                } else {
                    cout << "Database is full" << endl;
                }
            } else {
                cout << "Invalid credentials" << endl;
            }
        }

        void deleteLastEntry(string name_, string pin_){
            if(verify(name_, pin_)){
                if(currentSize > 0){
                    currentSize--;
                } else {
                    cout << "No entries to delete" << endl;
                }
            } else {
                cout << "Invalid credentials" << endl;
            }
        }

        void deleteEntry(Citizen citizen, string name_, string pin_){
            if(verify(name_, pin_)){
                bool found = false;
                for(int i = 0; i < currentSize; i++){
                    if(citizenList[i].get_details(AADHAR) == citizen.get_details(AADHAR)){
                        // Shift entries
                        for(int j = i; j < currentSize - 1; j++){
                            citizenList[j] = citizenList[j + 1];
                        }
                        currentSize--;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout << "Citizen not found" << endl;
                }
            } else {
                cout << "Invalid credentials" << endl;
            }
        }

        void writeDataBaseToFile(string name_, string pin_, string filename){
            if(filename == NO_FILE){
                for(int i = 0; i < currentSize; i++){
                    cout << citizenList[i].make_data() << endl;
                }
            } else {
                // IGNORE THIS FOR HACKERRANK
            }
        }
};

int main(){
    string userName = "NIT_Trichy";
    string userPassword = "Vortex2024";
    Database workshopDatabase(userName, userPassword);

    int command = 0;
    while(command != EXIT){
        cin >> command;
        if(command == INSERT){
            Citizen citizen;
            string name, aadhar, pan;
            int age;
            cin >> name >> age >> aadhar >> pan;
            Date dob;
            cin >> dob.day >> dob.month >> dob.year;
            citizen.set_details(name, age, aadhar, pan, dob);
            workshopDatabase.insertEntry(citizen, userName, userPassword);
        }
        else if(command == DELETE_LAST){
            workshopDatabase.deleteLastEntry(userName, userPassword);
        }
        else if(command == DELETE){
            Citizen citizen;
            string name, aadhar, pan;
            int age;
            cin >> name >> age >> aadhar >> pan;
            Date dob;
            cin >> dob.day >> dob.month >> dob.year;
            citizen.set_details(name, age, aadhar, pan, dob);
            workshopDatabase.deleteEntry(citizen, userName, userPassword);
        }
        else if(command == STORE){
            workshopDatabase.writeDataBaseToFile(userName, userPassword, NO_FILE);
        }
    }
}
