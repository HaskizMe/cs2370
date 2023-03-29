#include <vector>
#include <iostream>
#include "split.h"
#include <fstream>
#include <string>
#include <iomanip>
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

bool item_found(vector<item> item, int num){
    for(int i = 0; i < item.size(); i++){
        if(item[i].itemid == num){
            return true;
        }
    }
    return false;
}

int find_item(vector<item> item, int num){
    int index;
    for(int i = 0; i < item.size(); i++){
        if(item[i].itemid == num){
            index = i;
        }
    }
    return index;
}

int find_customer(vector<customer> customer, int num){
    int index;
    for(int i = 0; i < customer.size(); i++){
        if(customer[i].customerid == num){
            index = i;
        }
    }
    return index;
}

void print_order(vector<string> customer_orders_description, vector<float> customer_orders_prices, int id, string name){
    // cout << name <<" Customer id " << id << "'s order" << endl;
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

void one_customer_order(){
    vector<customer> cust;
    vector<item> items;
    vector<string> raw_items_data;
    vector<string> customer_orders_description;
    vector<float> customer_orders_prices;

    int item_id;
        items = store_items();
    cust = store_customers();

    int custid;
    cout << "There are " << my_vector_customer_txt.size() << " customers." << endl;
    cout << "And there are " << my_vector_items_txt.size() << " items." << endl;
    cout << "Please enter a customer number:" << endl;
    cin >> custid;
    string name = cust.at(find_customer(cust, custid)).name;

    if(!custid_found(cust, custid)){
        cout << "Error: Customer id not found" << endl;
    }
    else{
    
    do{
        cout << "Please enter an item number to purchase or enter 0 to exit" << endl;
        cin >> item_id;
        if(item_found(items, item_id)){
            int index;
            index = find_item(items, item_id);
            string description = items.at(index).description;
            float price = items.at(index).price;
            cout << "description: " << setw(description.length() + 3) << left << description << "|";
            cout << setw(10) << right << " Price: $" << price << endl;
            customer_orders_description.push_back(items.at(index).description);
            customer_orders_prices.push_back(items.at(index).price);

        }
        else if(item_id == 0){
            cout << "Exiting program\n" << endl;
        }
        else{
            cout << "Item id not found!" << endl;
        }

    } while (item_id != 0);

        print_order(customer_orders_description, customer_orders_prices, custid, name);

    }
}


int main() {
    read_customers("customers.txt"); // Step 1 above
    read_items("items.txt"); // Step 2 above
    one_customer_order();
}

