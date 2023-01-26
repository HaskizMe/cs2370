#include <iostream>
using namespace std;

int main() {
    bool valid;
    int x;
    int y;
    int z;
    cin >> x;
    cin >> y;
    do
    {

    cin >> z;
    if(z > y)
    {
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout << "*";
        }
        cout << endl;
        
    }

    for(int i = z; i > 0; i--)
    {
        for(int y = 0; y < i; y++)
        {
        cout << "*";

        }
        cout << endl;
    }

        valid = true;
    }

    else
    {
        valid = false;
    }
    }

    while(!valid);

   return 0;
}
