/*
	Nikola Trajanovski
	Lab 4 
	due Oct13 2021	
	
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	//Declaring and opening the files
	ifstream inData;
	ofstream outData;
	inData.open("C:/Users/nikol/Desktop/inTemp.dat");
	outData.open("C:/Users/nikol/Desktop/outTemp.dat");
	//error check in case the files dont open properly
	if (inData.fail()) {
		cerr << "error opening file 1";
		exit (1);
	}
	if (outData.fail()) {
		cerr << "error opening file 2";
		exit (1);
	}
	//declaring variables
	float theTemp = 0;
	float roundedTemps = 0;

	// Header scale 
	cout << setw(55)<<"|-30|-18|-6| 0 |20|30|40|50|60|70|80|90|100|110|120|" << endl;
	
	//while loop that runs through the inTemp.dat file
	while (!inData.eof()) {
		inData >> theTemp;
		// I added 30 to theTemp so the for loop can start from zero, whenever I need to get the actual temperature value i can subtract 30
		if (theTemp + 30 > 150) {
			roundedTemps = round(theTemp / 3);
			cout << theTemp << "|";
			for (int i = 0; i < roundedTemps; i++) {
				cout << "*";
			}
			cout << endl;
		}
		else{
			theTemp = theTemp + 30;
			roundedTemps = round(theTemp / 3);
			//if statement that formats the text in the console by separating single, two, three digit numbers
			if (theTemp -30 <10 && theTemp-30 > -10) {
				cout << theTemp -30 << setw(3) << "|";
			}
			else if (theTemp-30 < 120  && theTemp-30 > -10) {
				cout << theTemp - 30 << setw(2) << "|";
			}
			else if(theTemp-30 >=10 || theTemp-30 <= -10){
				cout << theTemp-30 << "|";
			}

			//if else statement that adds one star for the lowest temperature(-30)
			if (roundedTemps != 0) {
				for (int i = 0; i < roundedTemps; i++) {
					cout << "*";
				}
			}
			else {
				cout << "*";
			}
			cout << endl;
		}

	}

	return 0;
}