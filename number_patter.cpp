#include <iostream>

using namespace std;

void PrintNumPattern(int num1, int num2){
    static int NUMBER = 12;
    int currentNumber = num1;
    // if(currentNumber < 0 - num2){
    //     if(currentNumber == 12){
    //         cout << "hi " <<num1;

            
    //         return;
    //     }
    //     else{
    //         currentNumber = currentNumber + num2;
    //         cout << currentNumber;
    //         PrintNumPattern(currentNumber, num2);
    //     }
    // }
    // else{
    // cout << currentNumber << " ";
    // currentNumber = num1 - num2;
    // PrintNumPattern(currentNumber, num2);
    // }

    if(currentNumber >= -3){
        cout << currentNumber << " ";
        currentNumber = currentNumber - num2;
        PrintNumPattern(currentNumber, num2);
    }

    else{
        cout << currentNumber << " ";
        currentNumber = currentNumber + num2;
        PrintNumPattern(currentNumber, num2);
        if(currentNumber == 12){
            cout << currentNumber;
            return;
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