#ifndef ADDRESS_H
#define ADDRESS_H

#include<iostream>
#include<string>

using namespace std;
class Address {
public:
	Address();
	Address(int hN, string sN, string cN,int zC);
	Address(const Address& other);
	~Address();


	void setHouseNumber(int hN);
	void setStreetName(string sN) ;
	void setCityName(string cN) ;
	void setZipCode(int zC) ;


	int getHouseNumber() const;
	string getStreetName() const;
	string getCityName() const;
	int getZipCode() const;

	void input(void);
	void print(void);

private:
	int houseNumber;
	string streetName;
	string cityName;
	int zipCode;
};
#endif

