#include "Address.h"

Address::Address() :houseNumber(0), streetName("Unknown"), cityName("Unknown"),zipCode(0) {}

Address::Address(int hN, string sN, string cN,int zC)
	: houseNumber(hN), streetName(sN), cityName(cN), zipCode(zC) {}

Address::Address(const Address& other)
	: houseNumber(other.houseNumber), streetName(other.streetName), cityName(other.cityName), zipCode(other.zipCode) {}

Address::~Address() {}

void Address::setHouseNumber(int hN) { this->houseNumber = hN; }
void Address::setStreetName(string sN) { this->streetName = sN; }
void Address::setCityName(string cN) { this->cityName = cN; }
void Address::setZipCode(int zC) { this->zipCode = zC; }


int Address::getHouseNumber() const { return houseNumber; }
string Address::getStreetName() const { return streetName; }
string Address::getCityName() const { return cityName; }
int Address::getZipCode() const { return zipCode; }

void Address::input() {
	cout << "House Number(Numbers Only) : ";  cin >> houseNumber;	cin.ignore();
	cout << "Street     : ";	getline(cin, streetName);
	cout << "City       : ";	getline(cin, cityName);
	cout << "Zip Code   : ";	cin >> zipCode; cin.ignore();
}


void Address::print() {
	cout << "Address : " << houseNumber << " " << streetName << " " << cityName << " " << zipCode << endl;
}

