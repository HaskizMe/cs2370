#include <iostream>

using namespace std;

void PrintNumPattern(int num1, int num2){
    static int NUMBER = 12;
    int currentNumber = num1;
    int count = 0;

    //use a counter to count how many times 
    //it iterates to get to a negative and then 
    //use that variable to make a loop and base case 
    //to know how many times it needs to add again
    if(currentNumber < 0){
        if(currentNumber == num1){
            // cout << "hi " <<num1;        
            return;
        }
        else{
            currentNumber = currentNumber + num2;
            cout << currentNumber;
            PrintNumPattern(currentNumber, num2);
        }
    }
    else{
    cout << currentNumber << " ";
    currentNumber = num1 - num2;
    // count++;
    // cout<<count;
    PrintNumPattern(currentNumber, num2);

    }

    // if(currentNumber >= 0){
    //     cout << currentNumber << " ";
    //     currentNumber = currentNumber - num2;
    //     PrintNumPattern(currentNumber, num2);
    // }

    // else{
    //     cout << currentNumber << " ";
    //     currentNumber = currentNumber + num2;
    //     PrintNumPattern(currentNumber, num2);
    //     if(currentNumber == 12){
    //         cout << currentNumber;
    //         return;
    //     }
    // }


}

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   PrintNumPattern(num1, num2);
   
   return 0;
}