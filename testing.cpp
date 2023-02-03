#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

 int GetWordFrequency(vector<string> wordsList, string currWord){
    int count=1;
    //outer loop will loop through number of elements in the list
    int j = 1;
        //Inner loop comparing words
        if(wordsList[0] == currWord){

        for(j; j < wordsList.size(); j++){
            //comparing two strings
            if(currWord == wordsList[j]){
                count++;
            }
           
        }
        }
        else{
            count = 0;
            for(j; j < wordsList.size(); j++){
            //comparing two strings
            if(currWord == wordsList[j]){
                count++;
            }
        }
        }
    return count;
 }

int main() {

    vector<string> input_words;

    string input;
    int number_of_words;

    cin >> number_of_words;

    getline(cin,input);

    istringstream ss(input);
    string word;

    //Seperating words by spaces
    while (ss >> word)
    {
        input_words.push_back(word);
        
    }
        vector<string> input_words_lower_case(input_words);

    //changing all letters to lower case
    for(int i = 0; i<input_words.size();i++){
        transform(input_words_lower_case[i].begin(), input_words_lower_case[i].end(), input_words_lower_case[i].begin(), ::tolower);
    }

    for(int k = 0; k < number_of_words; k++ )
    {
        string currWord = input_words_lower_case[k];
        string show_word = input_words[k];
        cout << show_word << " " << GetWordFrequency(input_words_lower_case,currWord) << endl;
    }

   return 0;
}