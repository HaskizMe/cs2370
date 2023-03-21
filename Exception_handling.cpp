// #include <string>
// #include <iostream>
// #include <stdexcept>
// using namespace std;

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

#include <string>
#include <iostream>
#include <limits>
using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      try{
            cin >> age;
            cout << inputName << " " << age + 1 << endl;
        }
      catch(ios_base::failure){
        cin.clear();
        cout << inputName << " " << 0 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

      }


      cin >> inputName;
}
   
   return 0;
}