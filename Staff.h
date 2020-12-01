#ifndef STAFF_H
#define STAFF_H

#include<iostream>
#include<string>
#include "Address.h"
#include <vector>


using namespace std;


class Staff{

	friend void writeToFile(ostream&, Staff &);

public:
    Staff();
	Staff(int id, string name, int age, Address add, string role, double salary);
    ~Staff();

	//setters
	void setID(int id);
	void setName(string name);
	void setAge(int age);
	Address setAddress (const Address& other);
	void setRole(string role);
	void setSalary(double salary);

	// getters
	int getID() const;
	string	getName() const;
	int getAge() const;
	Address getAddress() const;
	string getRole() const;
	double getSalary() const;


	void input(void);
	void print();

	static int searchID(vector<Staff>& records, int keyID);
	static bool searchWage(const Staff& theObj, const double WAGE_LIMIT);

private:
    int m_id;
    string m_name;
    int m_age;
    Address m_address ;
    string m_role;
    double m_salary;
};
#endif

