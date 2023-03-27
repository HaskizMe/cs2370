#include <vector>
#include <iostream>
#include "split.h"
#include <fstream>
#include <string>
using namespace std;

// My global vector
vector<string> my_vector_customer_txt;
vector<string> my_vector_items_txt;
// customer class
struct customer{
    int customerid;
    string name;
    string street_address;
    string city;
    string state;
    string zip_code;
    string phone_number;
    string email_address;
}customers;

// Item class
struct item{
    int itemid;
    string description;
    float price;
}items;

void print_vector(){
    for(int i = 0; i < my_vector_customer_txt.size(); i++){
        cout << my_vector_customer_txt[i] << endl;
    }

}
void print_vector_size(){
    cout << my_vector_customer_txt.size() << endl;
}

int find_cust_idx(int cust_id);
int find_item_idx(int item_id);

void read_customers(string customers_file){
    ifstream read_file(customers_file);
    string text;
    if(read_file.is_open()){
        int j = 0;
        while(getline (read_file, text)){
            my_vector_customer_txt.push_back(text);
        }
    }
    else{
        cout << "File not found!" << endl;
    }
}

vector<string> read_items(string items_file){
    // vector<string> v;
    ifstream read_file(items_file);
    string text;
    if(read_file.is_open()){
        int j = 0;
        while(getline (read_file, text)){
            my_vector_items_txt.push_back(text);
        }
    }
    else{
        cout << "File not found!" << endl;
    }

    return my_vector_items_txt;
}


vector<item> store_items(){
    // Creating a vector
    vector<item> it_vect;
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_items_txt.size(); i++){
        item obj_item;
        // Filling out information of each object attribute
        obj_item.itemid = stoi(split(my_vector_items_txt[i],',').at(0));
        obj_item.description = split(my_vector_items_txt[i],',').at(1);
        obj_item.price = stof(split(my_vector_items_txt[i],',').at(2));
        // Storing in vector
        it_vect.push_back(obj_item);
    }

    return it_vect; 
}

vector<customer> store_customers(){
    // Creating a vector
    vector<customer> c;
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_customer_txt.size(); i++){
        customer obj;
        // Filling out information of each object attribute
        obj.customerid = stoi(split(my_vector_customer_txt[i],',').at(0));
        obj.name = split(my_vector_customer_txt[i],',').at(1);
        obj.street_address = split(my_vector_customer_txt[i],',').at(2);
        obj.city = split(my_vector_customer_txt[i],',').at(3);
        obj.state = split(my_vector_customer_txt[i],',').at(4);
        obj.zip_code = split(my_vector_customer_txt[i],',').at(5);
        obj.phone_number = split(my_vector_customer_txt[i],',').at(6);
        obj.email_address = split(my_vector_customer_txt[i],',').at(7);
        // Storing in vector
        c.push_back(obj);
    }

    return c;
}
bool custid_found(vector<customer> c, int num){
    for(int i = 0; i < c.size(); i++){
        if(c[i].customerid == num){
            return true;
        }
    }
    return false;
}

void find_item()



int main() {
    vector<customer> cust;
    vector<item> items;
    vector<string> raw_items_data;



    // customers.customerid = 50;
    // cout << customers.customerid << endl;
    read_customers("customers.txt"); // Step 1 above
    read_items("items.txt"); // Step 2 above
    items = store_items();
    cust = store_customers();

    int custid;
    cout << "There are " << my_vector_customer_txt.size() << " customers." << endl;
    cout << "And there are " << my_vector_items_txt.size() << " items." << endl;
    cout << "Please enter a customer number:" << endl;
    cin >> custid;


    if(!custid_found(cust, custid)){
        cout << "Error: Customer id not found" << endl;
    }
    else{
        do{
            int input;
            cout << "Please enter an item number to purchase" << endl;
            cin >> input;
            cout << 
        } while (input == 0);
        
    }
    // cout << cust[0].customerid;
    // cout << custid_found(cust, custid) << endl;

    // if()
    // items = store_items();
    // cust = store_customers();

    // cout << items.at(197).description << endl;
    // cout << store_customers().at(299).city << endl;

    // cout << custid;
    // cout<< read_items("items.txt").at(1) << endl;
    // one_customer_order(); // The rest of the step
    // print_vector();
    // print_vector_size();
}