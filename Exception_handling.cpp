#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

// int main() {
//    string inputName;
//    int age;
//    // Set exception mask for cin stream
//   //  cin.exceptions(ios::failbit);

//    cin >> inputName;
//    while(inputName != "-1") {
//       try{
//         if(cin.fail()){
//             throw runtime_error("invalid");
//             cout<< "working" << endl;
//         }
//         }
//       catch(runtime_error& excpt){
//          cout << excpt.what() << endl;
//         cin.clear();
//         // Throw away the rest of the failed input line from cin buffer
//         string garbage;
//         getline(cin, garbage);
//         cout << garbage << " garbage" << endl;
//         cin.clear();
//         cout << inputName << " input name " << endl;
//       }
//       cout << "hello";
//       cin >> age;
//       cout << inputName << " " << (age + 1) << endl;

//       cin >> inputName;
// }
   
//    return 0;
// }


int main() {
   int weightVal;       // User defined weight (lbs)
   int heightVal;       // User defined height (in)
   float bmiCalc;       // Resulting BMI
   char quitCmd;        // Indicates quit/continue

   quitCmd = 'a';
   
   while (quitCmd != 'q') {
      
      try {
         // Get user data
         cout << "Enter weight (in pounds): ";
         cin >> weightVal;
         
         // Error checking, non-negative weight
         if (weightVal < 0) {
            throw runtime_error("Invalid weight.");
         }
         
         cout << "Enter height (in inches): ";
         cin >> heightVal;
         
         // Error checking, non-negative height
         if (heightVal < 0) {
            throw runtime_error("Invalid height.");
         }
         
         // Calculate BMI and print user health info if no input error
         // Source: http://www.cdc.gov/
         bmiCalc = (static_cast<float>(weightVal) /
                    static_cast<float>(heightVal * heightVal)) * 703.0;
         
         cout << "BMI: " << bmiCalc << endl;
         cout << "(CDC: 18.6-24.9 normal)" << endl;
      }
      catch (runtime_error& excpt) {
         // Prints the error message passed by throw statement
         cout << excpt.what() << endl;
         cout << "Cannot compute health info." << endl;
      }
      
      // Prompt user to continue/quit
      cout << endl << "Enter any key ('q' to quit): ";
      cin >> quitCmd;
   }
   
   return 0;
}