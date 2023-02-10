#include <iostream>

using namespace std;

// Made global variable
int count = 1;
void PrintNumPattern(int num1, int num2){

//Checking to see how many times it loops to get to a negative number
    if(num1 >= 0){
        cout << num1 << " ";
        num1 = num1 - num2;
        count++;
        PrintNumPattern(num1, num2);

    }

    else{
//Loops the same amount of iterations but adding this time
        for(int i = 0; i<count; i++){
        cout << num1 << " ";
        num1 = num1 + num2;
        }
    }
}

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   PrintNumPattern(num1, num2);
   
   return 0;
}