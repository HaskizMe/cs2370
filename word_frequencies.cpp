#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

 int GetWordFrequency(vector<string> wordsList, string currWord){
    
     for(unsigned int i = 0; i<wordsList.size();i++){
        transform(wordsList[i].begin(), wordsList[i].end(), wordsList[i].begin(), ::tolower);
    }
    int count = 0;
    //outer loop will loop through number of elements in the list
    // int j = 1;
        //Inner loop comparing words
        // if(wordsList[0] == currWord){

        for(unsigned int j = 0; j < wordsList.size(); j++){
            //comparing two strings
            if(currWord == wordsList[j]){
                count++;
            }
           
        }
        // }
        // else{
        //     count = 0;
        //     for(int k = 1; k < wordsList.size(); k++){
        //     //comparing two strings
        //     if(currWord == wordsList[j]){
        //         count++;
        //     }
        // }
        // }
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
    //changing all letters to lower case
    // for(int i = 0; i<input_words.size();i++){
    //     transform(input_words_lower_case[i].begin(), input_words_lower_case[i].end(), input_words_lower_case[i].begin(), ::tolower);
    // }

    for(int k = 0; k < number_of_words; k++)
    {
        string currWord = input_words[k];
        cout << currWord << " " << GetWordFrequency(input_words,currWord) << endl;
        // cout<< GetWordFrequency(input_words, currWord) << endl;
    }

   return 0;
}