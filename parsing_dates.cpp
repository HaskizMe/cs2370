#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <chrono>
using namespace std;

int DateParser(string month) {
	int monthInt = 0;
	
	if (month == "January")
		monthInt = 1;
	else if (month == "February")
		monthInt = 2;
	else if (month == "March")
		monthInt = 3;
	else if (month == "April")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "June")
		monthInt = 6;
	else if (month == "July")
		monthInt = 7;
	else if (month == "August")
		monthInt = 8;
	else if (month == "September")
		monthInt = 9;
	else if (month == "October")
		monthInt = 10;
	else if (month == "November")
		monthInt = 11;
	else if (month == "December")
		monthInt = 12;
	return monthInt;
}

bool isDay(string day){
	//Takes in day and makes sure that it has a comma
	if (day.find(',') != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

//Making sure last argument is an int
bool isYear(string year){
	return stoi(year);
}

string deleteDayComma(string day){
	//Taking off the comma and storing it as a new string
	int pos;
	string sday = "";
	for(unsigned int i = 0; i < day.size(); i++){
		if(day[i] == ','){
			pos = i;
		}
	}
	sday = day.substr(0,pos);
	return sday;
}
int main () {
	string sday = "";
	string syear = "";
	int month;
	string smonth = "";
	string rawInput;
    vector<string> v;
	string outputStr = ""; 

	// loop that will keep going until user enters -1
	while(true){
		getline(cin, rawInput);
		if(rawInput == "-1"){
			break;
		}
		// Stores input in array by space
		istringstream iss(rawInput);
		vector<string> result;

		for(string s;iss>>s;){
			result.push_back(s);
		}
	// Checking to see if there is the right amount of arguments
	//if not don't print anything or break from while loop
	if(result.size() == 3){
		smonth = result[0];
		sday = result[1];
		syear = result[2];
		//Checking to see if first argument is able to be traced to a month
		if(DateParser(smonth) != 0){
			month = DateParser(smonth);
			smonth = to_string(month);
			//Now checking day
			if(isDay(sday)){
				sday = deleteDayComma(sday);
				// Now lastly checking year
				if(isYear(syear)){
					//Storing and formating values in string
					//Storing the string in a vector
					outputStr = smonth + "-" + sday + "-" + syear;
					v.push_back(outputStr);
				}
			}
		}
	}
}

	//Looping through vector and printing out the valid dates
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v.at(i) << endl;
	}

}