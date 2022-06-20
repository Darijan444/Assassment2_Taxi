// Taxi_Trip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Customer.h"
using namespace std;



int main() {
    
    vector <Customer> customer;
    vector <Orders> orders;
    vector <Inquiries> inquiries;


    readCustomerList(customer);
    readOrderList(orders);
    readInquiryList(inquiries);


    //store session user id
    int sessionId = 0;        //initial value is 0 (= no session)
    int* sId = &sessionId;


    
    customerMenu(customer, orders, inquiries, sId);
    
    
    return 0;
}






