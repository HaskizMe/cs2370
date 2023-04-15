#include <vector>
#include <iostream>
#include "split.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// My global vectors
vector<string> my_vector_customer_txt;
vector<string> my_vector_items_txt;
int starting_index = 0;

string dollar_to_string(double dollar);
int find_item_idx(int num);
void store_customers();
// customer class
class Customer
{
private:
    int customerid;
    string name;
    string street_address;
    string city;
    string state;
    string zip_code;
    string phone_number;
    string email_address;
public:
    Customer(int c_id, string n, string street, string c, string s, string z, string phone, string email)
    {
        customerid = c_id;
        name = n;
        street_address = street;
        city = c;
        state = s;
        zip_code = z;
        phone_number = phone;
        email_address = email;
    }
    int get_id()
    {
        return customerid;
    }
    string get_name()
    {
        return name;
    }
    string print_detail()
    {
        return "Customer ID #" + to_string(customerid) + 
        ":\n" + name + ", ph. " + phone_number + ", email: " + email_address + 
        "\n" + street_address + 
        "\n" + city + ", " + state + " " + zip_code + "\n\n";
    };
};

vector<Customer> customers;


// Item class
class Item
{
private:
    int itemid;
    string description;
    float price;
public:
    Item(int id, string des, float p)
    {
        itemid = id;
        description = des;
        price = p;
    }

    int get_id()
    {
        return itemid;
    }
    string get_description()
    {
        return description;
    }
    double get_price()
    {

        return price;
    }
};
vector<Item> items;

class Lineitem
{
private:
    int item_id;
    int qty;
public:
    Lineitem(int id, int q)
    {
        item_id = id;
        qty = q;
    }
    double sub_total() const
    {
        int item_indx = find_item_idx(item_id);
        double item_price = items[item_indx].get_price();
        return qty * item_price;
    }

    int get_id()
    {
        return item_id;
    }
    friend bool operator<(const Lineitem& item1, const Lineitem& item2)
    {
        return item1.item_id < item2.item_id;
    }
    friend class Order;
};

// Returns the index of the item searched
int find_item_idx(int num){
    int index;
    for(int i = 0; i < items.size(); i++){
        if(items[i].get_id() == num){
            index = i;
        }
    }
    return index;
}

// Same thing as find_item just with customer
int find_customer_idx(int num){
    int index;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].get_id() == num){
            index = i;
        }
    }
    return index;
}
class Payment
{
private:
   double amount;
public:
    virtual string print_detail() const = 0;

    friend class Order;
};

// Children class of payment
class Credit: public Payment
{
private:
    string card_number;
    string expiration;
public:
    Credit(string cn, string exp)
    {
        card_number = cn;
        expiration = exp;
    }
    string print_detail() const
    { 
        return "Paid by Credit Card " + card_number + ", exp. " + expiration; 
    };
};

// Order class
class Order
{
private:
    int order_id;
    string order_date;
    int cust_id;
    vector<Lineitem> line_items;
    Payment* payment;
public:
    Order(int ord_id, string ord_date, int id, vector<Lineitem> li, Payment* p)
    {
        order_id = ord_id;
        order_date = ord_date;
        cust_id = id;
        line_items = li;
        payment = p;
    }

    int get_orderid()
    {
        return order_id;
    }
    int get_custid()
    {
        return cust_id;
    }
    string get_order_date()
    {
        return order_date;
    }
    Payment* get_payment()
    {
        return payment;
    }
    double total() const
    {
        double total = 0;
        for(int i = starting_index; i < line_items.size(); i++)
        {
            total += line_items[i].sub_total();
        }
        return total;
    };
    string print_order() const
    {
        string itemsStr;
        stringstream ss;
        string total1;
        itemsStr = "Order Detail:\n";

        for(int i = starting_index; i < line_items.size(); i++)
        {
            int item_id = line_items.at(i).item_id;
            int item_index = find_item_idx(item_id);
            string item_name = items.at(item_index).get_description();
            double item_price = items.at(item_index).get_price();
            itemsStr += "     Item " + to_string(item_id) + ": " + item_name + ", "+ to_string(line_items.at(i).qty) + " @ " + dollar_to_string(item_price)+"\n";
            total1 = dollar_to_string(total());
        }
        starting_index = line_items.size();
        int customer_index = find_customer_idx(cust_id);

        ss << "==================================" << "\nOrder #" << to_string(order_id) << ", Date: " << order_date << 
        "\nAmount: $"  << total1 << ", " << payment->print_detail() << "\n\n" << customers.at(customer_index).print_detail() << itemsStr;
        return ss.str();
    }
};

vector<Order*> orders;


// Children class of payment
class Paypal: public Payment
{
private:
    string paypal_id;
public:
    Paypal(string id)
    {
        paypal_id = id;
    }
    string print_detail() const
    {
        return "Paid by Paypal ID: " + paypal_id; 
    };
};

// Children class of payment
class WireTransfer: public Payment
{
private:
    string bank_id;
    string account_id;
public:
    WireTransfer(string b_id, string acc)
    {
        bank_id = b_id;
        account_id = acc;
    }
    string print_detail() const
    {
        return "Paid by Wire transfer from Bank ID " + bank_id + ", Account # " + account_id;
    };
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
        store_customers();
    }
    else{
        cout << "File not found!" << endl;
    }
}

// Same thing as read_customers but reads items
void read_items(string items_file){
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
}

// Creating item objects and storing them to a new vector
void store_items(){
    // Creating a vector
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_items_txt.size(); i++){
        // Filling out information of each object attribute
        // by calling the split function and splitting by comma
        int itemid = stoi(split(my_vector_items_txt[i],',').at(0));
        string description = split(my_vector_items_txt[i],',').at(1);
        float price = stof(split(my_vector_items_txt[i],',').at(2));
        // Storing in vector
        Item obj_item(itemid, description, price);

        items.push_back(obj_item);
    }
}

// Same thing as store_items just doing it with customers
void store_customers(){
    // Creating a vector
    // Looping through global vector and making new object
    for(int i = 0; i < my_vector_customer_txt.size(); i++){
        // Filling out information of each object attribute
        // by calling the split function and splitting by comma
        int cid = stoi(split(my_vector_customer_txt[i],',').at(0));
        string n = split(my_vector_customer_txt[i],',').at(1);
        string street = split(my_vector_customer_txt[i],',').at(2);
        string city = split(my_vector_customer_txt[i],',').at(3);
        string state = split(my_vector_customer_txt[i],',').at(4);
        string zip = split(my_vector_customer_txt[i],',').at(5);
        string phone = split(my_vector_customer_txt[i],',').at(6);
        string email = split(my_vector_customer_txt[i],',').at(7);
        // Storing in vector
        Customer obj(cid, n, street, city, state, zip, phone, email);
        customers.push_back(obj);
    }
}

// Returning true or false if custid is found
bool custid_found(int num){
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].get_id() == num){
            return true;
        }
    }
    return false;
}

// Same thing as custid_found but with items
bool item_found(int item){
    for(int i = 0; i < items.size(); i++){
        if(items[i].get_id() == item){
            return true;
        }
    }
    return false;
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

void read_orders(string filename){
    vector<string> my_orders_txt;
    ifstream file(filename);
    vector<Lineitem> line_items;
    vector<string> v;
    string my_text;
    int order_number;
    int cust_id;
    string order_date;
    Payment* payment;
    while(getline(file, my_text))
    {
        my_orders_txt.push_back(my_text);
    }
    for(int i = 0; i < my_orders_txt.size(); i++)
    {
        v = split(my_orders_txt[i], ',');
        for(int j = 3; j < v.size(); j++)
        {
            string item = split(my_orders_txt[i],',').at(j);


            line_items.push_back(Lineitem(stoi(split(item,'-').at(0)), stoi(split(item,'-').at(1))));

        }

        cust_id = stoi(split(my_orders_txt[i], ',').at(0));
        order_number = stoi(split(my_orders_txt[i], ',').at(1));
        order_date = split(my_orders_txt[i], ',').at(2);
        sort(line_items.begin(), line_items.end());


            i++;
            if(split(my_orders_txt[i], ',').at(0) == "1")
            {
                string card_number = split(my_orders_txt[i], ',').at(1);
                string exp_date = split(my_orders_txt[i], ',').at(2);
                payment = new Credit(card_number, exp_date);
            }
            else if(split(my_orders_txt[i], ',').at(0) == "2")
            {
                string paypal = split(my_orders_txt[i], ',').at(1);
                payment = new Paypal(paypal);  
            }
            else if(split(my_orders_txt[i], ',').at(0) == "3")
            {
                string bank_id = split(my_orders_txt[i], ',').at(1);
                string account_id = split(my_orders_txt[i], ',').at(1);
                payment = new WireTransfer(bank_id, account_id);
            }
            orders.push_back(new Order(order_number, order_date, cust_id, line_items, payment));
    }
    store_items();
};


string dollar_to_string(double dollar)
{
    string dollarStr = to_string(dollar);
    int decimal = dollarStr.find('.');
    if(decimal == string::npos)
    {
        dollarStr += ".00";
    }
    else
    {
        int missing = 3 - (dollarStr.size() - decimal);
        if(missing < 0)
        {
            dollarStr = to_string(dollar + .005);
            dollarStr = dollarStr.substr(0, dollarStr.size() + missing);
        }
        else
        {
            for(int i = 0; i < missing; i++)
            {
                dollarStr += "0";
            }
        }
    }
    return dollarStr;
}



vector<string> split(string str,   char* delimiter)
{
    vector<string> v;
     char *token = strtok(const_cast<char*>(str.c_str()), delimiter);
    while (token != nullptr)
    {
        v.push_back(string(token));
        token = strtok(nullptr, delimiter);
    }
   
  return v;
}
int main() {
    read_customers("customers.txt");
    read_items("items.txt");
    read_orders("orders.txt");

    ofstream ofs("order_report.txt");
    for (const auto& order: orders)
        ofs << order->print_order() << endl;
}