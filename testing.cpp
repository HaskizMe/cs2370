#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
   set<string> groceries;
   string userInput;

   groceries.insert("bananas");
   groceries.insert("noodles");
   groceries.insert("soda");
   groceries.insert("apples");
   groceries.insert("ham");

   cin >> userInput;
   while (userInput != "done") {
      if (groceries.erase(userInput)) {
            cout << "e" << endl;
      }
      else {
            cout << "n" << endl;
      }
      cin >> userInput;
   }

   cout << "Size: " << groceries.size() << endl;

   return 0;
}