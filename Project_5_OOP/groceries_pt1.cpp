#include <vector>
#include <iostream>
#include "split.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
using namespace std;

// My global vectors
vector<string> my_vector_customer_txt;
vector<string> my_vector_items_txt;

// customer class
class Customer
{
public:
    int customerid;
    string name;
    string street_address;
    string city;
    string state;
    string zip_code;
    string phone_number;
    string email_address;

    string print_detail()
    {
        return "";
    };
};

// Item class
class Item
{
public:
    int itemid;
    string description;
    float price;   
};


// Reading and storing all customers in a global vector
void read_customers(string customers_file){
    ifstream read_file(customers_file);
    string text;

    // Checking if file exists
    if(read_file.is_open()){
        // Grabbing each line and putting them in a global customer vector
        while(getline (read_file, text)){
            my_vector_customer_txt.push_back(text);
        }
    }
    else{
        cout << "File not found!" << endl;
    }
}

// Same thing as read_customers but reads items
vector<string> read_items(string items_file){
    ifstream read_file(items_file);
    string text;

    // Checking if file exists
    if(read_file.is_open()){
        // Grabbing each item and putting it in its own global vector
        while(getline (read_file, text)){
            my_vector_items_txt.push_back(text);
        }
    }
    else{
        cout << "File not found!" << endl;
    }

    return my_vector_items_txt;
}

// Creating item objects and storing them to a new vector
vector<Item> store_items(){
    // Creating a vector
    vector<Item> it_vect;
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_items_txt.size(); i++){
        Item obj_item;
        // Filling out information of each object attribute
        // by calling the split function and splitting by comma
        obj_item.itemid = stoi(split(my_vector_items_txt[i],',').at(0));
        obj_item.description = split(my_vector_items_txt[i],',').at(1);
        obj_item.price = stof(split(my_vector_items_txt[i],',').at(2));
        // Storing in vector
        it_vect.push_back(obj_item);
    }

    return it_vect; 
}

// Same thing as store_items just doing it with customers
vector<Customer> store_customers(){
    // Creating a vector
    vector<Customer> c;
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_customer_txt.size(); i++){
        Customer obj;
        // Filling out information of each object attribute
        // by calling the split function and splitting by comma
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

// Returning true or false if custid is found
bool custid_found(vector<Customer> c, int num){
    for(int i = 0; i < c.size(); i++){
        if(c[i].customerid == num){
            return true;
        }
    }
    return false;
}

// Same thing as custid_found but with items
bool item_found(vector<Item> item, int num){
    for(int i = 0; i < item.size(); i++){
        if(item[i].itemid == num){
            return true;
        }
    }
    return false;
}

// Returns the index of the item searched
int find_item_idx(vector<Item> item, int num){
    int index;
    for(int i = 0; i < item.size(); i++){
        if(item[i].itemid == num){
            index = i;
        }
    }
    return index;
}

// Same thing as find_item just with customer
int find_customer_idx(vector<Customer> customer, int num){
    int index;
    for(int i = 0; i < customer.size(); i++){
        if(customer[i].customerid == num){
            index = i;
        }
    }
    return index;
}

// Print order function with spacing and formatting
void print_order(vector<string> customer_orders_description, vector<float> customer_orders_prices, int id, string name){
    cout << "id number " << id << " " << name << "'s order" << endl;
    cout << setfill('-') << setw(64) << "" << endl;
    float total_price;
    cout << setfill(' ');
    for(int i = 0; i < customer_orders_description.size(); i++){
        string description = customer_orders_description.at(i);
        float price = customer_orders_prices.at(i);
        total_price += customer_orders_prices.at(i);
        cout << "description: " << setw(35) << left << description << "|";
        cout << setw(10) << right << "Price: $" << price << endl;
    }
    cout << setfill('-') << setw(64) << "" << endl;

    cout << "total price: $" << total_price << endl;
}

// Printing and running for one customer's order
void one_customer_order(){
    // All my variables
    vector<Customer> cust;
    vector<Item> items;
    vector<string> customer_orders_description;
    vector<float> customer_orders_prices;
    int custid;
    int item_id;
    int index;
    string name;

    items = store_items();
    cust = store_customers();

    // Printing size of customers and size of items in file
    cout << "There are " << my_vector_customer_txt.size() << " customers." << endl;
    cout << "And there are " << my_vector_items_txt.size() << " items." << endl;
    cout << "Please enter a customer number:" << endl;
    // Asking for customer's id
    cin >> custid;

    // Storing name of customer's id
    name = cust.at(find_customer_idx(cust, custid)).name;

    // If custid is not found then exit program
    if(!custid_found(cust, custid)){
        cout << "Error: Customer id not found" << endl;
    }
    // Run a loop if custid is found
    else{
    
        do{
            cout << "Please enter an item number to purchase or enter 0 to exit" << endl;
            cin >> item_id;

            // If found then print out description and price with formatting
            // and store descriptions and price in seperate vectors
            if(item_found(items, item_id)){
                index = find_item_idx(items, item_id);
                string description = items.at(index).description;
                float price = items.at(index).price;
                cout << "description: " << setw(description.length() + 3) << left << description << "|";
                cout << setw(10) << right << " Price: $" << price << endl;
                customer_orders_description.push_back(items.at(index).description);
                customer_orders_prices.push_back(items.at(index).price);

            }
            // If input is 0 then exit loop
            else if(item_id == 0){
                cout << "Exiting program\n" << endl;
            }
            // If not found then print error
            else{
                cout << "Error: item id not found!" << endl;
            }

        } while (item_id != 0);

    // Call print order function
    print_order(customer_orders_description, customer_orders_prices, custid, name);

    }
}



int main() {
    read_customers("customers.txt");
    read_items("items.txt");
    one_customer_order();
}