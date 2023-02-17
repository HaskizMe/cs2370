#include <iostream>
#include <string>
using namespace std;
    //GetNumOfNonWSCharacters method
    int GetNumOfNonWSCharacters(const string str){
        return str.size();
    }
    //end of GetNumOfNonWSCharacters method

    //Start of GetNumofWords()
    int GetNumOfWords(const string str){    
    int Num = 0;      
    char prev = ' ';
    for(unsigned int i = 0; i < str.size(); i++) {

        if(str[i] != ' ' && prev == ' ') Num++;

        prev = str[i];
    }
    return Num;
    }
    //End of GetNumOfWords()

    int FindText(string WordToFind, string str){
        int numOfInstances = 0;
        
        return numOfInstances;
    }

    void ExecuteMenu(char input, string text){
    switch (input)
        {
        case 'c':
        //working
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(text) << endl;
            break;
        case 'w':
        cout<< "w";
        cout << "Number of words: " << GetNumOfWords(text) << endl;
            // remove_player();
            break;
        case 'f':
        cout<< "f";
        //working
            // update_rating();
            break;
        case 'r':
        cout << "r";
            //method
            // above_rating();
            break;
        case 's':
        cout << "s";
            // output_roster();
            break;
        case 'q':
        cout << "q";
            //method
            break;

        default:
            cout << "Please enter a valid letter" << endl;
            break;
        }

    }
    // PrintMenu Method
    void PrintMenu(){
    string str = "";
    char c;
    getline (cin,str);
    cout << "You entered: " << str;
    do{
        cout << "" << endl;
        cout << "MENU" << endl;
        cout << "c - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n" << endl;
        cout << "Choose an option:" << endl;
        cin >> c;
        ExecuteMenu(c,str);
    }
    while(c!='q');
    }

int main() {

   /* Type your code here. */
    // string str = "";
    // char c = 'a';
    // getline (cin,str);
    // cout << "You entered: " << str;
    // do{
    // cout << "" << endl;
    // cout << "MENU" << endl;
    // cout << "c - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n" << endl;
    // cout << "Choose an option:" << endl;
    // cin >> c;
    // ExecuteMenu(c,str);
    // }while(c!='q');
    PrintMenu();
   return 0;
}