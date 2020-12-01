///////////////  UE20023617   //////////////
//////////////   BSC COMPUTER ENGINEERING  /////////////

#include<iostream>
#include "Staff.h"
#include<fstream>
#include <vector>
#include "Address.h"

using namespace std;

int menu();
void program(vector<Staff>& records, int choice);
void readFromFile(vector<Staff>& records, const string& filename);
void readLine(const string & line, char separator, string fields[], const int& numberOfFields);
string trim(string text);

const double WAGE_LIMIT = 20000;

int main(){

	cout << "\t\tWELCOME TO STAFF MANAGEMENT SYSTEM\t\t" << endl;
	cout<<endl;

	// When the program starts, it reads the records from the main file.
	vector<Staff> recordsOfSMS;
	string filename = "StaffManagementSystem.txt";
	readFromFile(recordsOfSMS, filename);


	int choice = menu();

	while (choice != 4) {
		program(recordsOfSMS, choice);
		cout << endl;
		choice = menu();
	}

return 0;
}


int menu(){
    int choice;
    bool valid = false;
    while (!valid){
        cout << "************************************************************" << endl;
        cout << "* 1. Insert an employee into the system                    *" << endl;
        cout << "* 2. Search for an employee via their id number            *" << endl;
        cout << "* 3. Search for all employees with a wage higher than 20k. *" << endl;
        cout << "* 4. Exit the program                                      *" << endl;
        cout << "************************************************************" << endl;
        cout << endl;
        cout << "Choose an option >> ";
        cin >> choice;

        if ( (choice >= 1) && (choice <= 4) )
            return choice;
        else
            cout <<endl<< "Invalid choice. Please enter a number between 1 and 4" << endl << endl;
    }
}


void program(vector<Staff>& records, int choice) {

    switch(choice){
        case 1:
            {
			Staff theObject;
			cout << endl;

			int indexFound = Staff::searchID(records, theObject.getID());

			while ( indexFound != -1 ) {
				int id;
				cout << "ID already taken, choose a new ID :" << endl;
				cout << "ID   : "; cin >> id;
				theObject.setID(id);
				indexFound = Staff::searchID(records, theObject.getID());
			}
			records.push_back(theObject);

			ofstream outFile;
			outFile.open("StaffManagementSystem.txt", ios::app);
			writeToFile(outFile,theObject);
			outFile.close();

			theObject.~Staff();  // calling destructor

            break;
            }

        case 2:
            {
				int keyID;
				cout << "Enter the ID to search for : ";
				cin >> keyID;
				int indexFound = Staff::searchID(records, keyID);
				if (indexFound != -1) {
					records[indexFound].print();
				}
				else {
					cout << "No record was found" << endl;
				}

                break;
            }

        case 3:
            {

			for (unsigned int i = 0; i < records.size(); i++) {
				bool found = Staff::searchWage(records[i], WAGE_LIMIT);
				if ( found )
					records[i].print();
			}

			break;

            }
        case 4:
            {
			// to clear the memory before exiting the program.
				for (int i = 0; i < records.size(); i++)
				{
					records[i].~Staff();
				}

                cout <<"Have a nice day! ..." << endl;
                break;
            }

        default:
            cout<<"Invalid Input"<<endl;

    }

}



/**
	This function reads the records from the database file
	@param records, records to be read from the file
	@param filename, the name of the database file.
	@return void
*/
void readFromFile(vector<Staff>& records, const string& filename) {

	const int NUMBEROFDATA = 10;

    cout<<endl;
	cout << "Loading from master file .... "<< endl;


	string line;
	ifstream inFile;
	inFile.open(filename);

	int id, age;
	string name, role;
	double salary;


	if (!inFile) {
		cout << "File not found !" << endl;
		exit(1);
	}

	while (!inFile.eof()) {
		getline(inFile, line);

		if (line.length() > 0) {
			string data[10];
			readLine(line, ',', data, NUMBEROFDATA);

			id  = atoi(data[0].c_str());
			name = data[1];
		    age = atoi(data[2].c_str());
			int houseNumber = atoi(data[3].c_str());
			int zipCode = atoi(data[7].c_str());
			Address addr(houseNumber, data[4], data[5], zipCode);
			role = data[8];
			salary = atof(data[9].c_str());

			Staff theObject(id, name, age, addr, role, salary);
			records.push_back(theObject);
			theObject.~Staff();  // calling the destructor
		}
	}
	cout << "Number of records loaded from the master file : " << (records.size()-1) << endl;
	inFile.close();
}


/**
This function reads a given string line and splits them into the fields and returns them in a string array.
@param line, the line that is to be read
@param separator, the char value that separates the fields. (eg. ',')
@param fields, the fields in the array
@param numberOfFields , the number of the fields in the line
@return void.
*/
void readLine(const string & line, char separator, string fields[], const int& numberOfFields) {
	int i = 0;
	int cnt = 0;
	int _from = 0;
	int _to = 0;
	int howMany = 0;
	while (line[i]) {
		if (line[i] == separator) {
			_to = i;
			 howMany = _to - _from;
			fields[cnt] = trim(line.substr(_from, howMany)).c_str();
			_from = _to + 1;
			cnt++;
		}
		i++;
	}
	howMany = line.size() - _from;
	fields[numberOfFields - 1] = trim(line.substr(_from, howMany)).c_str();
}


/**
This function leaves out the white spaces of the string input
@param text, string input to be trimmed.
@return string with no white spaces at the beginning or at the end of the text.
*/
string trim(string text) {
	int lastIndex = 0;
	for (int i = text.length() - 1; i >= 0; i--) {
		if (text[i] != ' ') {
			lastIndex = i;
			break;
		}
	}
	lastIndex++;

	int firstIndex = -1;
	for (int i = 0; i < lastIndex; i++) {
		firstIndex++;
		if (text[i] != ' ')
			break;
	}

	int howMany = (lastIndex - firstIndex);
	return  text.substr(firstIndex, howMany);
}
