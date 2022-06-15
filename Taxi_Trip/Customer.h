#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


struct Customer {
	string name;
	string phone;
	string email;
	string street;
	string city;
	string state;
	string country;
	string postalCode;
	string password;
	string payment;
	string creditCardNumber;
	string pickupLocation;
	string destination;
	int selectedService;


	Customer(string n = "name", string pn = "000-0000-0000", string e = "email@email.com", string p = "password", string str = "street", string cit = "city", string sta = "state", string cou = "country", string pc = "000-0000", string pm = "credit", string ccn = "NA", string pl = "area1", string des = "area2", int ss = 1) {
		name = n;
		phone = pn;
		email = e;
		street = str;
		city = cit;
		state = sta;
		country = cou;
		postalCode = pc;
		password = p;
		payment = pm;
		creditCardNumber = ccn;
		pickupLocation = pl;
		destination = des;
		selectedService = ss;
	}
};

struct Orders {
	int year;
	int month;
	int day;
	int days;
	int week;
	string customerName;
	string driverName;
	string carType;
	string pickupLocation;
	string destination;
	float fare;

	Orders(int y = 2022, int m = 01, int d = 01, int ds = 01, int w = 01, string cn = "customer name", string dn = "driver name", string ct = "taxi", string pl = "pickup location", string des = "destination", float fa = 10.00) {
		year = y;
		month = m;
		day = d;
		days = ds;
		week = w;
		customerName = cn;
		driverName = dn;
		carType = ct;
		pickupLocation = pl;
		destination = des;
		fare = fa;

	}
};


struct Inquiries {
	int year;
	int month;
	int day;
	string name;
	string userType;
	string phone;
	string email;
	string topic;
	string detail;

	Inquiries(int y = 2022, int m = 01, int d = 01, string n = "name", string ut = "user type", string p = "000-0000-0000", string e = "email@email.com", string t = "topic", string de = "detail") {
		year = y;
		month = m;
		day = d;
		name = n;
		userType = ut;
		phone = p;
		email = e;
		topic = t;
		detail = de;
	}
};


//Make an order list (create a structure for order)
//Make an inquiry list (creata a structure for inquiry)

//struct Ride{};
//struct guestOrder{};
//struct myPage{};
//struct customerMenu{};


void customerMenu(vector <Customer>& customer, vector <Orders> &orders, vector <Inquiries> &inquiries);
void customerSingup(vector <Customer> &customer, vector <Orders>& orders, vector <Inquiries>& inquiries);
void customerLogin(vector <Customer> &customer, vector <Orders>& orders, vector <Inquiries>& inquiries);
void ride(vector <Customer>& customer);
void myPage(vector <Customer>& customer);
void contact(vector <Customer>& customer);
void guestOrder(vector <Customer>& customer);
void readCustomerList(vector <Customer>& customer);
void readOrderList(vector <Orders>& orders);
void readInquiryList(vector <Inquiries>& inquiries);
void inquiryReport(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries);



void customerMenu(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	int option1, option2;

	cout << "\n************************************************\n";
	cout << "Welcome Yoobee Customer!\n";
	cout << "Please select a number from the menu\n";
	cout << "************************************************\n";
	cout << "Menu\n";
	cout << " 1.Ride\n";
	cout << " 2.My Page\n";
	cout << " 3.Contact\n";
	cout << " 4.Exit\n";
	cout << "-----------------------------\n";
	cout << " Select option: ";
	cin >> option1;
	cout << "\n\n";

	switch (option1) {
	case 1:
		ride(customer);
		break;

	case 2:
		myPage(customer);
		break;

	case 3:
		contact(customer);
		break;
		

		break;

	case 4:
		cout << "Thank you!\n\n";
		break;
	}
	
	
}


void ride(vector <Customer>& customer) {
	struct Customer c;
	int option;

	cout << "************************************************\n";
	cout << "Ride\n";
	cout << "************************************************\n";
	cout << "Enter pickup location: \n";
	cin >> c.pickupLocation;
	cout << "Enter destination: \n";
	cin >> c.destination;
	cout << "---------------------------------------------------------\n";
}

void customerSingup(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	struct Customer c;
	int option;
	int i = customer.size();
	

	cout << "************************************************\n";
	cout << "Sign up\n";
	cout << "************************************************\n";
	cout << "Enter your information \n";
	cout << " Name: \n";
	cin >> c.name;
	cout << " Phone number: \n";
	cin >> c.phone;
	cout << " Email address: \n";
	cin >> c.email;
	cout << " Home address: \n";
	cout << " Street: \n";
	cin >> c.street;
	cout << " City: \n";
	cin >> c.city;
	cout << " State: \n";
	cin >> c.state;
	cout << " Country: \n";
	cin >> c.country;
	cout << " Postal Code(e.g 000-0000): \n";
	cin >> c.postalCode;
	cout << " Password: \n";
	cin >> c.password;
	
	cout << " Payment method: \n";
	cout << "  1. Cash \n";
	cout << "  2. Credit Card \n";
	cout << "  3. Online Payment \n";
	cout << "  4. - \n";
	cout << " ------------------------------------------------\n";
	cin >> option;

	cout << "\n\n";

	switch (option) {

	case 1:

		c.payment = "Cash";

		break;

	case 2:

		c.payment = "Credit Card";

		// cout << "Enter your Credit Card Number(e.g. 0000-0000-0000) :";

		// cin >> c.creditCardNumber;

		break;

	case 3:

		// cout << "Choose your Online Payment Service :"

		c.payment = "Online payment";

		break;
	}

	customer.push_back(c);

	cout << "\n\n";

	ofstream customerList("CustomerList.csv", ios::app);

	customerList << customer[i].name << "," << customer[i].phone << "," << customer[i].email << "," << customer[i].street << "," << customer[i].city << "," << customer[i].state << "," << customer[i].country << "," << customer[i].postalCode << "," << customer[i].password << ",\n";
}


void guestOrder(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	struct Customer c;
	int option;
	int i = customer.size();

	cout << "************************************************\n";
	cout << "Guest order\n";
	cout << "************************************************\n";
	cout << "Enter your information \n";
	cout << " Name: \n";
	cin >> c.name;
	cout << " Phone number: \n";
	cin >> c.phone;


	cout << " Payment method: \n";
	cout << "  1. Cash \n";
	cout << "  2. Credit Card \n";
	cout << "  3. Online Payment \n";
	cout << " ------------------------------------------------\n";
	cin >> option;

	cout << "\n\n";

	switch (option) {

	case 1:

		c.payment = "Cash";

		break;

	case 2:

		c.payment = "Credit Card";

		// cout << "Enter your Credit Card Number(e.g. 0000-0000-0000) :";

		// cin >> c.creditCardNumber;

		break;

	case 3:

		// cout << "Choose your Online Payment Service :"

		c.payment = "Online payment";

		break;
	}

	customer.push_back(c);

	cout << "\n\n";

	ofstream customerList("CustomerList.csv", ios::app);

	customerList << customer[i].name << "," << customer[i].phone << "," << customer[i].payment << ",\n";


}

void customerLogin(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	string userEmail, userPassword;
	int attemptCounts = 3;

	cout << "************************************************\n";
	cout << "Log in\n";
	cout << "************************************************\n";
	cout << "Enter your information \n";

	bool isCustomer = false;

	while (isCustomer != true && attemptCounts > 0) {

		cout << "Email address: ";
		cin >> userEmail;
		cout << "Password: ";
		cin >> userPassword;

		for (int i = 1; i < customer.size(); i++) {
			if (customer[i].email == userEmail && customer[i].password == userPassword) {
				isCustomer = true;


			}
		}

		attemptCounts--;

		if (attemptCounts == 0) {
			cout << "---------------------------------------------------------------------\n";
			cout << "The number of login attempts has exceeded the limit. \n";
			cout << "Please wait a while and try again.\n";
		}
		else if (isCustomer != true) {
			cout << "----------------------------------------------------------------\n";
			cout << " Your email address or password is wrong.\n";
			cout << " Try again.\n";
			cout << "----------------------------------------------------------------\n";
		}
	}
	cout << "\n";
}

void customerInfo(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	cout << "************************************************\n";
	cout << "Customer Information\n";
	cout << "************************************************\n";

	cout << "Name\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tPayment Method\n";
	for (int i = 1; i < customer.size(); i++) {
		cout << customer[i].name << "  \t" << customer[i].phone << "  \t" << customer[i].email << "  \t" << customer[i].street << "   \t" << customer[i].city << "   \t" << customer[i].state << "   \t" << customer[i].country << "   \t" << customer[i].postalCode << "\t" << customer[i].payment << "   \n";
	}

	cout << "\nPress any key to go back to the Customer Menu\n";
	system("read");
	customerMenu(customer, orders, inquiries);
}

void inquiryReport(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries) {
	cout << "************************************************\n";
	cout << "Inquiry Report\n";
	cout << "************************************************\n";
	cout << "Date\t\tCustomer\tUser Type\tPhone\t\t\tEmail\t\t\tTopic\t\tDetail\n";
	for (int i = 1; i < inquiries.size(); i++) {
		cout << inquiries[i].year << "/" << inquiries[i].month << "/" << inquiries[i].day << "  \t" << inquiries[i].name << "   \t" << inquiries[i].userType << "   \t" << inquiries[i].phone << "   \t" << inquiries[i].email << "   \t" << inquiries[i].topic << "\t" << inquiries[i].detail << "   \n";
	}

	cout << "\nPress any key to go back to the Customer Menu\n";
	system("read");
	customerMenu(customer, orders, inquiries);
}

void readOrderList(vector <Orders>& orders) {
	ifstream orderlist("OrderList.csv");
	string line, item;
	struct Orders o;

	while (getline(orderlist, line)) {
		istringstream i_stream(line);

		getline(i_stream, item, ',');
		o.year = atoi(item.c_str());
		getline(i_stream, item, ',');
		o.month = atoi(item.c_str());
		getline(i_stream, item, ',');
		o.day = atoi(item.c_str());
		getline(i_stream, item, ',');
		o.days = atoi(item.c_str());
		getline(i_stream, item, ',');
		o.week = atoi(item.c_str());

		getline(i_stream, o.customerName, ',');
		getline(i_stream, o.driverName, ',');
		getline(i_stream, o.carType, ',');
		getline(i_stream, o.pickupLocation, ',');
		getline(i_stream, o.destination, ',');
		getline(i_stream, item, ',');
		o.fare = atoi(item.c_str());

		orders.push_back(o);
	}
}

void readInquiryList(vector <Inquiries>& inquiries) {
	ifstream inquiryList("InquiryList.csv");
	string line, item;
	struct Inquiries i;

	while (getline(inquiryList, line)) {
		istringstream i_stream(line);

		getline(i_stream, item, ',');
		i.year = atoi(item.c_str());
		getline(i_stream, item, ',');
		i.month = atoi(item.c_str());
		getline(i_stream, item, ',');
		i.day = atoi(item.c_str());

		getline(i_stream, i.name, ',');
		getline(i_stream, i.userType, ',');
		getline(i_stream, i.phone, ',');
		getline(i_stream, i.email, ',');
		getline(i_stream, i.topic, ',');
		getline(i_stream, i.detail, ',');

		inquiries.push_back(i);
	}
}

void readCustomerList(vector <Customer>& customer) {
	ifstream customerList("CustomerLis.csv");
	string line, item;
	struct Customer c;

	while (getline(customerList, line)) {
		istringstream i_stream(line);

		getline(i_stream, c.name, ',');
		getline(i_stream, c.phone, ',');
		getline(i_stream, c.email, ',');
		getline(i_stream, c.street, ',');
		getline(i_stream, c.city, ',');
		getline(i_stream, c.state, ',');
		getline(i_stream, c.country, ',');
		getline(i_stream, c.postalCode, ',');
		getline(i_stream, c.password, ',');
		getline(i_stream, c.payment, ',');

		customer.push_back(c);
	}
}