


//close to working
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



    void add_player(vector<int> new_rating, vector<int> new_jersey){
        int num;
        int rating;
        cout << "Enter a new player's jersey number:" << endl;
        cin >> num;
        new_jersey.push_back(num);
        cout << "Enter the player's rating:" << endl;
        cin >> rating;
        new_rating.push_back(rating);

    return;
    }
    void output_roster(vector<int> ratings, vector<int> jersey_numbers){
        cout << "ROSTER" << endl;
        int j = 0;
        for(int i = 0; i < jersey_numbers.size(); i++){
            cout << "Player " << j+1 << " -- Jersey number: " << jersey_numbers[i] << ", Rating: " << ratings[i] << endl; 
            j++;
        }
        return;
    }
    void remove_player(vector<int> ratings, vector<int> jersey_numbers){
        int match;
        int index = 0;
        vector<int>::iterator it;
        cout << "Enter a jersey number:" << endl;
        cin >> match;
        for(int i = 0; i < ratings.size(); i++){
            cout << ratings[i] << endl;
            if(match == jersey_numbers[i]){
                index = i;
                cout<<"hello" << endl;
                ratings.erase(ratings.begin()+index);
                jersey_numbers.erase(jersey_numbers.begin()+index);
            }
        }
        return;

    }
    void update_rating(vector<int> ratings, vector<int> jersey_numbers){
        int jersey;
        int rating;
        int index;
        cout << "Enter a jersey number:" << endl;
        cin >> jersey;
        cout << "Enter a new rating for player:" << endl;
        cin >> rating;
        for(int i = 0; i<ratings.size(); i++){
            if(jersey_numbers[i] == jersey){
                index = i;
            }
        }
        replace(ratings.begin(),ratings.end(),ratings[index],rating );
            for (int x : ratings){
        cout << x << " ";

    }
    }

    void above_rating(vector<int> ratings, vector<int> jersey_numbers){
        int input;
        int j = 0;
        cout << "Enter a rating:" << endl;
        cin >> input;
        for(int i = 0; i < ratings.size(); i++){
            if(ratings[i] > input){
                cout << "ABOVE " << input << endl;
                cout << "Player " << j+1 << " -- Jersey number: " << jersey_numbers[i] << ", Rating: " << ratings[i] << endl;
                j++;
            }
        }

        return;
    }


    void menu(vector<int> ratings, vector<int> jersey_numbers){
        char input;
        do {
        cout << "" << endl;
        cout << "MENU" << endl;
        cout << "a - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n" << endl;
        cout << "Choose an option:" << endl;
        cin >> input;

        
        switch (input)
        {
        case 'a':
        //working
            add_player(ratings, jersey_numbers);
            break;
        case 'd':
        //working
            remove_player(ratings, jersey_numbers);
            break;
        case 'u':
        //working
            update_rating(ratings, jersey_numbers);
            break;
        case 'r':
            //method
            above_rating(ratings, jersey_numbers);
            break;
        case 'o':
            output_roster(ratings, jersey_numbers);
            break;
        case 'q':
            //method
            break;

        default:
            cout << "Please enter a valid letter" << endl;
            break;
        }
        } while(input != 'q');
    }
int main() {

    vector<int> ratings;
    vector<int> jersey_numbers;
    int jersey;
    int rating;
    int j = 0;
    // int k = 0;
    for(int i = 0; i < 5; i++){
        cout << "Enter player " << j+1 << "'s jersey number:" << endl;
        cin >> jersey;
        jersey_numbers.push_back(jersey);
        cout << "Enter player " << j+1 << "'s rating:" << endl;
        cin >> rating;
        cout << "" << endl;
        ratings.push_back(rating);
        j++;
    }
    output_roster(ratings, jersey_numbers);
    menu(ratings, jersey_numbers);
   return 0;
}
