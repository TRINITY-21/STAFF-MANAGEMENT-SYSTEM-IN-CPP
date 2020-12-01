#include "Staff.h"
#include <fstream>
#include<iomanip>
#include<string>

Staff::Staff(){
	input();
}

Staff::Staff(int id, string name, int age, Address add, string role, double salary) :
	m_id(id), m_name(name), m_age(age), m_address(add), m_role(role), m_salary(salary) {}

Staff::~Staff(){}

// setters
void Staff::setID(int id) {	m_id = id;}
void Staff::setName(string name) { m_name = name; }
void Staff::setAge(int age) { m_age = age; }
Address Staff::setAddress(const Address& other){
	Address temp(other);
	return temp;
}

void Staff::setRole(string role) { m_role = role; }
void Staff::setSalary(double salary) { m_salary = salary; }

// getters

int Staff::getID() const { return m_id; }
string	Staff::getName() const { return m_name; }
int Staff::getAge() const { return m_age; }
Address Staff::getAddress() const { return this->m_address;}

string Staff::getRole() const { return m_role; }
double Staff::getSalary() const { return m_salary; }

void Staff::input(void) {
	int id, age;
	string name, role;
	double salary;

	cout << "Data Input Screen" << endl;
	cout << "ID   : "; cin >> id; 	cin.ignore();  setID(id);
	cout << "Name : "; getline(cin, name); setName(name);
	cout << "Age  : "; cin >> age; cin.ignore();  setAge(age);
	m_address.input();
	cout << "Role : "; getline(cin, role); setRole(role);
	cout << "Salary(GHC):";	cin >> salary; setSalary(salary);

}

void Staff::print() {
	cout << "ID      : " << m_id << endl;
	cout << "Name    : " << m_name << endl;
	cout << "Age     : " << m_age << endl;
	m_address.print();
	cout << "Role    : " << m_role << endl;
	cout << "Salary  : GHC " << fixed << setprecision(2) << m_salary << endl;
	cout << endl;
}


 int Staff::searchID(vector<Staff>& records, int keyID) {
	for (unsigned int i = 0; i < records.size(); i++) {
		if (keyID == records[i].getID()) {
			return i; // if found the index will be return
		}
	}
	// if not found
	return -1;
}

 bool Staff::searchWage(const Staff& theObj, const double WAGE_LIMIT) {
	 if (theObj.getSalary() > WAGE_LIMIT)
		 return true;
	 else
		return false;
}


void writeToFile(ostream& out, Staff & theObject) {
	out << setw(5)<< theObject.m_id << left
		<< ", " << setw(15) << theObject.m_name
		<< "  "<< setw(15) << theObject.m_age
        << "  "<< setw(15) << theObject.m_address.getHouseNumber()
		<< "  "<< setw(15) << theObject.m_address.getStreetName()
        << "  "<< setw(15) << theObject.m_address.getCityName()
        << "  "<< setw(15) << theObject.m_address.getZipCode()
        << "  "<< setw(15) << theObject.m_role
		<< "  "<< setw(15) << fixed << setprecision(2) << theObject.m_salary
		<< endl;
}

