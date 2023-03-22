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

int main () {
	string rawInput;
	getline(cin, rawInput);

	istringstream iss(rawInput);
    vector<string> result;

    for(string s;iss>>s;){
        result.push_back(s);
	}
    int n=result.size();

    for(int i=0;i<n;i++){
        cout<<result[i]<<endl;
	}
	int date;
	int num;
	string a = " ";
	string c = " ";
	// if(typeid(a).name() == typeid(result.at(0)).name()){
    try 
    {
          num = stoi(result.at(1));
		  cout << num << endl;
		  cout << typeid(num).name() << endl;
		//   date = DateParser(result.at(0));

		//   cout << date << endl;
    }
    catch (exception e) { 
	}
	cout << date << endl;
	// if(num = stoi(result.at(0))){
	// 	cout << "True" << endl;
	// 	date = DateParser(result.at(0));
	// 	// if (result.at(1).find(',') != std::string::npos){
	// 	// 	cout << "found" << endl;
	// 	// }
	// }

	// else{
	// 	cout << "not found" << endl;
	// 	return 0;
	// }
// int main()
// {
//     std::string date_time_format = "%m/%d/%Y";
//     std::istringstream ss{ "4/28/2022" };
//     std::chrono::year_month_day date;

//     ss >> std::chrono::parse(date_time_format, date);

//     if (!ss) {
//         /* failed to parse date */
        
//     }

//     std::cout << "Year: "  << date.year()  << '\n';
//     std::cout << "Month: " << date.month() << '\n';
//     std::cout << "Day: "   << date.day()   << '\n';
// }

	// TODO: Read dates from input, parse the dates to find the ones
	//       in the correct format, and output in m-d-yyyy format

}