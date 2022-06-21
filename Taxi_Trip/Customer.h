#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>

using namespace std;


struct Customer {
	int customerId;
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


	Customer(int cid = 0, string n = "name", string pn = "000-0000-0000", string e = "email@email.com", string p = "password", string str = "street", string cit = "city", string sta = "state", string cou = "country", string pc = "000-0000", string pm = "credit", string ccn = "NA", string pl = "area1", string des = "area2", int ss = 1) {
		customerId = cid;
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
	int orderId;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int days;
	int week;
	string customerName;
	string driverName;
	string carType;
	int pickupArea;
	int destinationArea;
	string pickupLocation;
	string destination;
	float fare;
	int selectedService;

	Orders(int oid = 0, int y = 2022, int mon = 01, int h = 01, int min = 01, int d = 01, int ds = 01, int w = 01, int o = 1, string cn = "customer name", string dn = "driver name", string ct = "taxi", int pa = 1, int da = 1, string pl = "pickup location", string des = "destination", float fa = 10.00) {
		orderId = oid;
		year = y;
		month = mon;
		day = d;
		hour = h;
		min = min;
		days = ds;
		week = w;
		customerName = cn;
		driverName = dn;
		carType = ct;
		pickupArea = pa;
		destinationArea = da;
		pickupLocation = pl;
		destination = des;
		fare = fa;
		selectedService = o;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerMenu(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId);
void ride(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId);
void customerSignup(vector <Customer> &customer, int* sId);
int customerLogin(vector <Customer> &customer);
void customerPage(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId);
void customerInquiry(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId);
int calculateDays(int month, int day);
int calculateWeeks(int days);
bool isPhoneValid(string& phone);
bool isEmailValid(string& email);
bool isPasswordValid(string& password);
bool isIntegerValid(string& number);
bool isPostalCodeValid(string& postalCode);
bool isYesNoValid(string& answer);
bool isMultiDigitValid(string& number);
bool isNameValid(string& name);
bool isLicenseValid(string& number);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerMenu(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId) {
	// int option;
	string cusMenuOptS, accountOptS;
	int cusMenuOptI, accountOptI;

	cout << "************************************************\n";
	cout << "Welcome Yoobee Customers!\n";
	cout << "Please select a number from the menu\n";
	cout << "************************************************\n";
	cout << "Menu\n";
	cout << "  1.Ride*\n";
	cout << "  2.My Page\n";
	cout << "  3.Inquiry\n";
	cout << "  4.Exit\n";
	cout << "                   *Direct Call: 012-3456-7890\n";

	//integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "  Enter option: ";
		getline(cin, cusMenuOptS);                                                                    //integer validation
		if (isIntegerValid(cusMenuOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (cusMenuOptS == "1" || cusMenuOptS == "2" || cusMenuOptS == "3" || cusMenuOptS == "4") {   //option validation
			cout << "\n\n";
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	cusMenuOptI = stoi(cusMenuOptS);


	switch (cusMenuOptI) {
	case 1:
		ride(customer, orders, inquiries, sId);
		break;


	case 2:
		// int option;

		if (*sId == 0) {
			cout << " ------------------------------------------------\n";
			cout << " Do you have Yoobee Taxi Customer Account?: \n";
			cout << "  1. Login       (if you have our account)\n";
			cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
			cout << "  3. Go Back\n";

			//integer & option validation
			while (true) {
				cout << " ------------------------------------------------\n";
				cout << "  Enter option: ";
				getline(cin, accountOptS);
				if (isIntegerValid(accountOptS) == false) {
					cout << " ------------------------------------------------\n";
					cout << "\n ❗️Select a number from the menu. \n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3") {
					cout << "\n\n";
					break;
				}
				else {
					cout << " ------------------------------------------------\n";
					cout << "\n ❗️Select a number from the menu. \n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}

			int accountOptI = stoi(accountOptS);

			// cin >> option;
			switch (accountOptI) {
			case 1:
				*sId = customerLogin(customer);
				break;

			case 2:
				customerSignup(customer, sId);
				// *sId = customer.size() -1;
				break;

			case 3:
				customerMenu(customer, orders, inquiries, sId);
				break;
			}
			if (*sId != 0) {
				customerPage(customer, orders, inquiries, sId);
			}
			else {
				customerMenu(customer, orders, inquiries, sId);
			}

		}
		else {
			customerPage(customer, orders, inquiries, sId);
		}
		break;


	case 3:
		customerInquiry(customer, orders, inquiries, sId);
		break;

	case 4:
		break;
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void customerSignup(vector <Customer>& customer, int* sId) {
	struct Customer c;
	int option{};
	int i = customer.size();

	string payOptS, customerNameS;
	int payOptI;

	c.customerId = i;

	cout << "\n************************************************\n";
	cout << "Sign up\n";
	cout << "************************************************\n";
	cout << "Enter your information \n";

	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Name: ";
		getline(cin, customerNameS);
		if (isNameValid(customerNameS) == true) {
			c.name = customerNameS;
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Enter your name. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	while (true) {
		cout << " Phone number (e.g. 000-0000-0000): ";
		cin >> c.phone;

		if (isPhoneValid(c.phone) == true) {
			break;
		}
		else {
			cout << "\n  ❗️Please enter a valid phone number\n\n";
		}
	}

	while (true) {
		cout << " Email address (e.g. test@email.com): ";
		cin >> c.email;

		if (isEmailValid(c.email) == true) {
			break;
		}
		else {
			cout << "\n  ❗️Please enter a valid email address\n\n";
		}
	}

	cout << " Home address: \n";
	cout << "    Street: ";
	cin >> c.street;
	cout << "    City: ";
	cin >> c.city;
	cout << "    State: ";
	cin >> c.state;
	cout << "    Country: ";
	cin >> c.country;

	while (true) {
		cout << "    Postal Code(e.g. 000-0000): ";
		cin >> c.postalCode;

		if (isPostalCodeValid(c.postalCode) == true) {
			break;
		}
		else {
			cout << "\n  ❗️Please enter a valid postal code\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}


	// cout << "    Postal Code(e.g. 000-0000): ";
	// cin >> c.postalCode;

	cout << "\nEnter your password: \n";
	cout << "  -At least 8 characters\n";
	cout << "  -At least one upper case character\n";
	cout << "  -At least one lower case character\n";
	cout << "  -At least one special character (@, !, ?, #)\n";
	cout << "  -At least one number\n";

	while (true) {
		cout << "---------------------------------------------------------\n";
		cout << "   Your password is: ";
		cin >> c.password;
		cout << "\n";

		if (isPasswordValid(c.password) == true) {
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << "\nPlease enter a valid password.\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	cout << " Payment method: \n";
	cout << "  1. Cash \n";
	cout << "  2. Credit Card \n";
	cout << "  3. Online Payment \n";

	//integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "  Enter option: ";
		getline(cin, payOptS);
		if (isIntegerValid(payOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (payOptS == "1" || payOptS == "2" || payOptS == "3") {
			switch (option) {
			case 1:
				c.payment = "Cash";
				break;

			case 2:
				c.payment = "Credit Card";
				break;

			case 3:
				c.payment = "Online Payment";
				break;
			}
			// cin.clear();
			// cin.ignore(10000, '\n');
			cout << "\n\n";
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	payOptI = stoi(payOptS);

	customer.push_back(c);

	cout << "\n\n";


	cout << " ------------------------------------------------\n";
	cout << " Please check and confirm your information \n\n";
	cout << "  Name:\t\t\t" << c.name << "\n";
	cout << "  Phone:\t\t" << c.phone << "\n";
	cout << "  Email:\t\t" << c.email << "\n";
	cout << "  Street:\t\t" << c.street << "\n";
	cout << "  City:\t\t\t" << c.city << "\n";
	cout << "  State:\t\t" << c.state << "\n";
	cout << "  Country:\t\t" << c.country << "\n";
	cout << "  Postal Code:\t\t" << c.postalCode << "\n";
	switch (option) {
	case 1:
		cout << "  Payment Method:\t" << "Cash" << "\n";
		break;

	case 2:
		cout << "  Payment Method:\t" << "Credit Card" << "\n";
		break;

	case 3:
		cout << "  Payment Method:\t" << "Online Payment" << "\n";
		break;
	}


	//confirm order
	string confirm;
	ofstream customerList("CustomerList.csv", ios::app);

	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "Confirm sign up (y/n): ";
		cin >> confirm;

		if (isYesNoValid(confirm) == true) {
			if (confirm == "y") {
				cout << "------------------------------------------------\n";
				cout << "\n  Thank you!\n  Registred successfully!\n\n\n";
				customerList << customer[i].customerId << "," << customer[i].name << "," << customer[i].phone << "," << customer[i].email << "," << customer[i].street << "," << customer[i].city << "," << customer[i].state << "," << customer[i].country << "," << customer[i].postalCode << "," << customer[i].password << "," << customer[i].payment << ",\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				cout << "\n  Your register was canceled.\n\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			break;
		}
		else {
			cout << "\n  ❗️Please answer with y or n\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}


int customerLogin(vector <Customer>& customer) {
	string userEmail, userPassword;
	int attemptCounts = 3;          //limit of attempts
	int customerNo;

	cout << "\n************************************************\n";
	cout << "Customer Login\n";
	cout << "************************************************\n";
	cout << "Enter your information \n";

	while (attemptCounts > 0) {
		cout << " Email address: ";
		cin >> userEmail;
		cout << " Password: ";
		cin >> userPassword;

		int emailFlag = 0, passwordFlag = 0;                    //initialize flag

		for (int i = 1; i < customer.size(); i++) {
			if (customer[i].email == userEmail && customer[i].password == userPassword) {
				emailFlag = 1;
				passwordFlag = 1;

				customerNo = i;
				break;
			}
			if (customer[i].email == userEmail && customer[i].password != userPassword) {
				emailFlag = 1;
				passwordFlag = 0;
				break;
			}
			if (customer[i].email != userEmail) {
				emailFlag = 0;
				passwordFlag = 0;
			}
		}

		attemptCounts--;

		//check results
		if (emailFlag == 1 && passwordFlag == 1) {
			cout << "----------------------------------------------------------------\n";
			cout << "Logged in successfully\n\n";
			//Login successfully
			// customerMenu(customers, orders);
			break;

		}
		else if (attemptCounts == 0) {
			cout << "----------------------------------------------------------------\n";
			cout << "The number of login attempts has exceeded the limit.\n";
			cout << "Please wait a while and try again.\n";

			customerNo = 0;

		}
		else {
			if (emailFlag == 1 && passwordFlag == 0) {
				cout << "\n  ❗️Your password is wrong\n";
				cout << "    Please try again.\n\n";
			}
			else if (emailFlag == 0 && passwordFlag == 0) {
				// cout << "\n  ❗️Your email address and password are wrong (or you are not authorized)\n";
				cout << "\n  ❗️Your email address is not registered.\n";
				cout << "    Please try again.\n\n";
			}
		}
	}
	//reset user input
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\n";

	return customerNo;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (CustomerPage, Customer Inquiry)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerPage(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId) {
	int s = *sId;
	int option;
	string myPageOptS;
	int myPageOptI;

	cout << "************************************************\n";
	cout << "My Page \n";
	cout << "************************************************\n";
	cout << "Menu \n";
	cout << "  1. Account Info\n";
	cout << "  2. Trip History \n";
	cout << "  3. Coupons \n";
	cout << "  4. Go Back \n";

	//integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "  Enter option: ";
		getline(cin, myPageOptS);                                                //integer validation
		if (isIntegerValid(myPageOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (myPageOptS == "1" || myPageOptS == "2" || myPageOptS == "3" || myPageOptS == "4") {   //option validation
			cout << "\n\n";
			// cin.clear();
			// cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	myPageOptI = stoi(myPageOptS);


	// cout << " ------------------------------------------------\n";
	// cout << "  Enter option: ";
	// cin >> option;
	// cout << "\n";

	switch (myPageOptI) {
	case 1:
		cout << "************************************************\n";
		cout << "Account Information\n";
		cout << "************************************************\n";
		cout << "  Customer ID:\t\t" << customer[s].customerId << "\n";
		cout << "  Name:\t\t\t" << customer[s].name << "\n";
		cout << "  Phone number:\t\t" << customer[s].phone << "\n";
		cout << "  Email address:\t" << customer[s].email << "\n";
		cout << "  Street:\t\t" << customer[s].street << "\n";
		cout << "  City:\t\t\t" << customer[s].city << "\n";
		cout << "  State:\t\t" << customer[s].state << "\n";
		cout << "  Country:\t\t" << customer[s].country << "\n";
		cout << "  Postal Code:\t\t" << customer[s].postalCode << "\n\n";

		//go back to the My Page
		cout << "\nPress any key to go back to the My Page\n";
		system("read");
		customerPage(customer, orders, inquiries, sId);
		break;

	case 2:
		cout << "************************************************\n";
		cout << "Trip History\n";
		cout << "************************************************\n";
		cout << "Date\t\t Customer\tDriver\t\tCar Type\t\tPickup Location\t\tDestination\t\tFare\n";
		for (int i = 1; i < orders.size(); i++) {
			if (orders[i].customerName == customer[s].name) {
				cout << orders[i].year << "/" << orders[i].month << "/" << orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t\t" << orders[i].destination << "\t" << orders[i].fare << "   \n";
			}
		}

		//go back to the My Page
		cout << "\nPress any key to go back to the My Page\n";
		system("read");
		customerPage(customer, orders, inquiries, sId);
		break;

	case 3:
		cout << "************************************************\n";
		cout << "Coupons\n";
		cout << "************************************************\n";
		cout << " - 30% off coupon　🎁" << "\n";

		//go back to the My Page
		cout << "\nPress any key to go back to the My Page\n";
		system("read");
		customerPage(customer, orders, inquiries, sId);
		break;

	case 4:
		customerMenu(customer, orders, inquiries, sId);
		break;
	}
}

void customerInquiry(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId) {
	struct Customer c;
	struct Inquiries iq;
	string inquiryDetail;

	string inquiryOptS, accountOptS;
	int inquiryOptI, accountOptI;

	//int option1, option2{};
	size_t bufferSize = 10;
	int i = inquiries.size();
	time_t now = time(0);
	tm* ltm = localtime(&now);

	iq.year = 1900 + ltm->tm_year;
	iq.month = 1 + ltm->tm_mon;
	iq.day = ltm->tm_mday;

	//select service
	cout << " ------------------------------------------------\n";
	cout << " Please select a topic: \n";
	cout << "  1. Service \n";
	cout << "  2. Lost Item\n";
	cout << "  3. Others \n";

	//integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "  Enter option: ";
		getline(cin, inquiryOptS);                                                //integer validation
		if (isIntegerValid(inquiryOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (inquiryOptS == "1" || inquiryOptS == "2" || inquiryOptS == "3") {   //option validation
			cout << "\n\n";
			// cin.clear();
			// cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key to go back) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	inquiryOptI = stoi(inquiryOptS);



	// cout << " ------------------------------------------------\n";
	// cout << "  Enter option: ";
	// cin >> option1;
	// cout << "\n";

	cout << " ------------------------------------------------\n";
	cout << " Please tell me the details of your inquiry: \n  ";
	getline(cin, inquiryDetail);
	// getline (cin, inquiryDetail);
	iq.detail = inquiryDetail;

	if (*sId == 0) {
		cout << " ------------------------------------------------\n";
		cout << " Do you have Yoobee Taxi account?: \n";
		cout << "  1. Login       (if you have our account)\n";
		cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
		cout << "  3. Guest       (If you don't want to create our account)\n";


		while (true) {
			cout << " ------------------------------------------------\n";
			cout << "  Enter option: ";
			getline(cin, accountOptS);
			if (isIntegerValid(accountOptS) == false) {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Select a number from the menu. \n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3") {
				cout << "\n\n";
				break;
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Select a number from the menu. \n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		accountOptI = stoi(accountOptS);


		// cout << " ------------------------------------------------\n";
		// cout << "  Enter option: ";
		// cin >> option2;

		switch (accountOptI) {
		case 1:
			*sId = customerLogin(customer);
			break;

		case 2:
			customerSignup(customer, sId);
			*sId = customer.size() - 1;
			break;


		case 3:
			cout << " ------------------------------------------------\n";
			cout << "Enter your information \n";
			cout << " Name: ";
			cin >> iq.name;
			while (true) {
				cout << " Phone number (e.g. 000-0000-0000): ";
				cin >> iq.phone;

				if (isPhoneValid(iq.phone) == true) {
					break;
				}
				else {
					cout << "\n  ❗️Please enter a valid phone number\n\n";
				}
			}

			//email validation
			while (true) {
				cout << " Email address (e.g. test@email.com): ";
				cin >> iq.email;

				if (isEmailValid(iq.email) == true) {
					break;
				}
				else {
					cout << "\n  ❗️Please enter a valid email address\n\n";
				}
			}
		}
	}


	int s = *sId;


	cout << " ------------------------------------------------\n";
	cout << " Please check and confirm your inquiry \n\n";

	if (s != 0) {
		cout << "  Customer ID:\t\t" << customer[s].customerId << "\n";
		cout << "  Name:\t\t\t" << customer[s].name << "\n";
		cout << "  Phone Number:\t\t" << customer[s].phone << "\n";
		cout << "  Emainl Address:\t" << customer[s].email << "\n";
	}
	else {
		cout << "  Name:\t\t\t" << iq.name << "\n";
		cout << "  Phone Number:\t\t" << iq.phone << "\n";
		cout << "  Email Address:\t" << iq.email << "\n";
	}


	switch (inquiryOptI) {
	case 1:
		iq.topic = "Service";
		cout << "  Topic:\t\t" << iq.topic << "\n";
		break;

	case 2:
		iq.topic = "Lost Item";
		cout << "  Topic:\t\t" << iq.topic << "\n";
		break;

	case 3:
		iq.topic = "Others";
		cout << "  Topic:\t\t" << iq.topic << "\n";
		break;
	}

	cout << "  Detail:\t\t" << iq.detail << "\n";


	if (accountOptI != 3) {
		iq.name = customer[s].name;
		iq.phone = customer[s].phone;
		iq.email = customer[s].email;
	}
	iq.userType = "Customer";


	inquiries.push_back(iq);


	//confirm order
	string confirm;
	ofstream inquiryList("InquiryList.csv", ios::app);


	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "Confirm order (y/n): ";
		cin >> confirm;

		if (isYesNoValid(confirm) == true) {
			if (confirm == "y") {
				cout << "------------------------------------------------\n";
				cout << "\n  Thank you!\n  See you later!\n";
				inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				cout << "\n  Your inquiry was canceled.\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			break;
		}
		else {
			cout << "\n  ❗️Please answer with y or n\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	// cout << "------------------------------------------------\n";
	// cout << "Confirm order (y/n): ";
	// cin >> confirm;

	// if (confirm == 'y'){
	//     cout << "------------------------------------------------\n";
	//     cout << "\n  Thank you!\n  See you later!\n";
	//     inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n" ;

	// } else {
	//     cout << "\n  Your inquiry was canceled.\n";
	// }

	//go back to the admin menu
	cout << "\nPress any key to go back to the Customer Menu\n";
	system("read");
	customerMenu(customer, orders, inquiries, sId);

	cout << "\n\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Ride)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ride(vector <Customer>& customer, vector <Orders>& orders, vector <Inquiries>& inquiries, int* sId) {
	struct Customer c;
	struct Orders o;
	string requestNow;
	int option1{}, option2;

	// int j;
	int i = orders.size();
	o.orderId = i;

	bool isUserInfo = false;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	size_t bufferSize = 10;
	int currentYear, currentMonth, currentDay, currentHour, currentMin;
	int  pickupDay, pickupHour, pickupMin;

	string strOption1, strOption2, strOption3, strOption4;
	int intOption;

	string pickOptS, desOptS, serOptS, payOptS, accountOptS;
	int pickOptI, desOptI, serOptI, payOptI, accountOptI{};

	string userInputYearS, userInputMonthS, userInputDayS, userInputHourS, userInputMinuteS;
	int userInputYearI, userInputMonthI, userInputDayI, userInputHourI, userInputMinuteI;;

	string pickLocationS, destinationS;
	// string pickupLocation, destination;

	 //integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Choose pickup area number (1.Downtown 2.Suburb): ";
		getline(cin, pickOptS);
		if (isIntegerValid(pickOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (pickOptS == "1" || pickOptS == "2") {
			cout << "\n\n";
			// cin.clear();
			// cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	o.pickupArea = stoi(pickOptS);


	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Enter pickup location (address): ";
		getline(cin, pickLocationS);
		if (isNameValid(pickLocationS) == true) {
			o.pickupLocation = pickLocationS;
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Enter valid address. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	cout << "\n";


	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Choose destination area number(1.Downtown 2.Suburb): ";
		getline(cin, desOptS);
		if (isIntegerValid(desOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (desOptS == "1" || desOptS == "2") {
			cout << "\n\n";
			// cin.clear();
			// cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	o.destinationArea = stoi(desOptS);



	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Enter destination(address): ";
		getline(cin, destinationS);
		if (isNameValid(destinationS) == true) {
			o.destination = destinationS;
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Enter valid address. (Press any key) \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	cout << "\n";




	//Yes or No Validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << " Request Now? (y/n): ";
		cin >> requestNow;

		if (isYesNoValid(requestNow) == true) {
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else {
			cout << "\n  ❗️Please answer with y or n\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}


	//request now
	if (requestNow == "y") {
		// get current date
		currentYear = 1900 + ltm->tm_year;
		currentMonth = 1 + ltm->tm_mon;
		currentDay = ltm->tm_mday;
		currentHour = ltm->tm_hour;
		currentMin = ltm->tm_min;

		o.days = calculateDays(currentMonth, currentDay);
		o.week = calculateWeeks(o.days);

		pickupDay = currentDay;
		pickupHour = currentHour;
		pickupMin = currentMin + 20;        //pickup in 20min


		if (pickupMin > 60) {
			pickupMin = pickupMin - 60;
			pickupHour = pickupHour + 1;
		}


		o.year = currentYear;
		o.month = currentMonth;
		o.day = pickupDay;
		o.hour = pickupHour;
		o.min = pickupMin;
	}

	//request later (booking)
	if (requestNow == "n") {
		cout << "------------------------------------------------\n";
		cout << "When are you going to ride?\n";


		//integer & option validation
		while (true) {
			cout << "------------------------------------------------\n";
			cout << "  Year (e.g. 2022): ";
			getline(cin, userInputYearS);
			if (isMultiDigitValid(userInputYearS) == true) {
				userInputYearI = stoi(userInputYearS);

				if (userInputYearI >= 2022 && userInputYearI <= 2023) {
					o.year = userInputYearI;
					// cin.clear();
					// cin.ignore(10000, '\n');
					break;
				}
				else {
					cout << "\n ❗️Reservations are possible from 2022(Jan) to 2023(Dec) (Press any key)\n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		while (true) {
			cout << "------------------------------------------------\n";
			cout << "  Month (e.g. 01): ";
			getline(cin, userInputMonthS);
			if (isMultiDigitValid(userInputMonthS) == true) {
				userInputMonthI = stoi(userInputMonthS);

				if (userInputMonthI >= 1 && userInputMonthI <= 12) {
					o.month = userInputMonthI;
					// cin.clear();
					// cin.ignore(10000, '\n');
					break;
				}
				else {
					cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		while (true) {
			cout << "------------------------------------------------\n";
			cout << "  Day (e.g. 01): ";
			getline(cin, userInputDayS);
			if (isMultiDigitValid(userInputDayS) == true) {
				userInputDayI = stoi(userInputDayS);

				if (userInputDayI >= 1 && userInputDayI <= 31) {
					o.day = userInputDayI;
					// cin.clear();
					// cin.ignore(10000, '\n');
					break;
				}
				else {
					cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		while (true) {
			cout << "------------------------------------------------\n";
			cout << "  Hour (e.g. 01): ";
			getline(cin, userInputHourS);
			if (isMultiDigitValid(userInputHourS) == true) {
				userInputHourI = stoi(userInputHourS);

				if (userInputHourI >= 0 && userInputHourI <= 24) {
					o.hour = userInputHourI;
					// cin.clear();
					// cin.ignore(10000, '\n');
					break;
				}
				else {
					cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		while (true) {
			cout << "------------------------------------------------\n";
			cout << "  Minute (e.g. 01): ";
			getline(cin, userInputMinuteS);
			if (isMultiDigitValid(userInputMinuteS) == true) {
				userInputMinuteI = stoi(userInputMinuteS);

				if (userInputMinuteI >= 0 && userInputMinuteI <= 59) {
					o.min = userInputMinuteI;
					// cin.clear();
					// cin.ignore(10000, '\n');
					break;
				}
				else {
					cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Please enter a valid number. (Press any key)\n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}


		// cout << "------------------------------------------------\n";
		// cout << "When are you going to ride?\n";
		// cout << "  Year (e.g. 2022): ";
		// cin >> o.year;
		// cout << "  Month (e.g. 01): ";
		// cin >> o.month;
		// cout << "  Day (e.g. 01): ";
		// cin >> o.day;
		// cout << "  Hour (e.g. 01): ";
		// cin >> o.hour;
		// cout << "  Minute (e.g. 01): ";
		// cin >> o.min;

		o.days = calculateDays(o.month, o.day);
		o.week = calculateWeeks(o.days);

		// cin.clear();
		// cin.ignore(10000, '\n');
	}

	//calcurate the fare
	float basicCharge, areaCharge, taxiFare, vanFare, premiumVanFare;

	basicCharge = 10;
	areaCharge = abs(o.destinationArea - o.pickupArea) * 10;
	taxiFare = basicCharge + areaCharge;
	vanFare = (basicCharge + areaCharge) * 1.15;
	premiumVanFare = (basicCharge + areaCharge) * 1.30;



	cout << " ------------------------------------------------\n";
	cout << " Please select a service: \n";
	printf("  1. Taxi\t\t4 people\t$%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", taxiFare, o.year, o.month, o.day, o.hour, o.min);    //printf is for showing two digits
	printf("  2. Van\t\t5 people\t$%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", vanFare, o.year, o.month, o.day, o.hour, o.min);
	printf("  3. Premium Van\t6 people\t$%2.2f\t\t%d/%d/%d %02d:%02d(Pick up)\n", premiumVanFare, o.year, o.month, o.day, o.hour, o.min);

	//integer & option validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "  Enter option: ";
		getline(cin, serOptS);
		if (isIntegerValid(serOptS) == false) {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (serOptS == "1" || serOptS == "2" || serOptS == "3") {
			// cin.clear();
			// cin.ignore(10000, '\n');
			cout << "\n\n";
			break;
		}
		else {
			cout << " ------------------------------------------------\n";
			cout << "\n ❗️Select a number from the menu. \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	o.selectedService = stoi(serOptS);



	if (*sId == 0) {
		cout << " ------------------------------------------------\n";
		cout << " Do you have Yoobee Taxi account?: \n";
		cout << "  1. Login       (if you have our account)\n";
		cout << "  2. Sign up     (if you don't have our account and  want to create(free))\n";
		cout << "  3. Guest Order (If you don't want to create our account)\n";

		while (true) {
			cout << " ------------------------------------------------\n";
			cout << "  Enter option: ";
			getline(cin, accountOptS);
			if (isIntegerValid(accountOptS) == false) {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Select a number from the menu. \n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (accountOptS == "1" || accountOptS == "2" || accountOptS == "3") {
				// cin.clear();
				// cin.ignore(10000, '\n');
				cout << "\n\n";
				break;
			}
			else {
				cout << " ------------------------------------------------\n";
				cout << "\n ❗️Select a number from the menu. \n\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		accountOptI = stoi(accountOptS);


		// cout << " ------------------------------------------------\n";
		switch (accountOptI) {
		case 1:
			*sId = customerLogin(customer);
			break;

		case 2:
			customerSignup(customer, sId);
			*sId = customer.size() - 1;
			break;


		case 3:
			cout << " ------------------------------------------------\n";
			cout << "Enter your information \n";
			cout << " Name: ";
			cin >> c.name;
			while (true) {
				cout << " Phone number (e.g. 000-0000-0000): ";
				cin >> c.phone;

				if (isPhoneValid(c.phone) == true) {
					break;
				}
				else {
					cout << "\n  ❗️Please enter a valid phone number\n\n";
				}
			}

			//email validation
			while (true) {
				cout << " Email address (e.g. test@email.com): ";
				cin >> c.email;

				if (isEmailValid(c.email) == true) {
					break;
				}
				else {
					cout << "\n  ❗️Please enter a valid email address\n\n";
				}
			}
			cin.clear();
			cin.ignore(10000, '\n');
		}

		if (accountOptI != 1) {
			cout << " ------------------------------------------------\n";
			cout << " Payment method: \n";
			cout << "  1. Cash \n";
			cout << "  2. Credit Card \n";
			cout << "  3. Online Payment \n";


			//integer & option validation
			while (true) {
				cout << " ------------------------------------------------\n";
				cout << "  Enter option: ";
				getline(cin, payOptS);
				if (isIntegerValid(payOptS) == false) {
					cout << " ------------------------------------------------\n";
					cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (payOptS == "1" || payOptS == "2" || payOptS == "3") {
					cout << "\n\n";
					break;
				}
				else {
					cout << " ------------------------------------------------\n";
					cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			payOptI = stoi(payOptS);
			// cin.clear();
			// cin.ignore(10000, '\n');
		}

		switch (payOptI) {
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
			c.payment = "Online Payment";
			break;
		}
	}


	int s = *sId;

	cout << " ------------------------------------------------\n";
	cout << " Please check and confirm your order information \n\n";
	if (s != 0) {
		cout << "  Your Name:\t\t" << customer[s].name << "\n";
		cout << "  Your Phone number:\t" << customer[s].phone << "\n";
	}
	else {
		cout << "  Your Name:\t\t" << c.name << "\n";
		cout << "  Your Phone number:\t" << c.phone << "\n";
	}

	cout << "  Pickup location:\t" << o.pickupLocation << "\n";
	cout << "  Destination:\t\t" << o.destination << "\n";


	switch (o.selectedService) {
	case 1:
		o.carType = "Taxi(4 people)";

		cout << "  Car type:\t\tTaxi(4 people)\n";
		// cout << "  Fare:\t\t\t$10.00\n";
		printf("  Fare:\t\t\t$%2.2f\n", taxiFare);
		printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year, o.month, o.day, o.hour, o.min);
		o.fare = taxiFare;
		break;

	case 2:
		o.carType = "Van(5 people)";

		cout << "  Car type:\t\tVan(5 people)\n";
		printf("  Fare:\t\t\t$%2.2f\n", vanFare);
		printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year, o.month, o.day, o.hour, o.min);
		o.fare = vanFare;
		break;

	case 3:
		o.carType = "Premium Van(6 people)";

		cout << "  Car type:\t\tPremium Van(6 people)\n";
		printf("  Fare:\t\t\t$%2.2f\n", premiumVanFare);
		printf("  Pick up date:\t\t%d/%d/%d %02d:%02d\n", o.year, o.month, o.day, o.hour, o.min);
		o.fare = premiumVanFare;
		break;
	}



	if (accountOptI == 3) {
		o.customerName = c.name;
	}
	else {
		o.customerName = customer[s].name;
	}
	o.driverName = "Not assigned";

	orders.push_back(o);


	//confirm order
	string confirm;
	ofstream orderList("OrderList.csv", ios::app);




	//Yes or No Validation
	while (true) {
		cout << " ------------------------------------------------\n";
		cout << "Confirm order (y/n): ";
		cin >> confirm;

		if (isYesNoValid(confirm) == true) {
			if (confirm == "y") {
				cout << "------------------------------------------------\n";
				cout << "\n  Thank you!\n  See you later!\n";
				orderList << orders[i].orderId << "," << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].hour << "," << orders[i].min << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].driverName << "," << orders[i].carType << "," << orders[i].pickupArea << "," << orders[i].destinationArea << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				cout << "\n  Your order was canceled.\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			break;
		}
		else {
			cout << "\n  ❗️Please answer with y or n\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}


	// cout << "------------------------------------------------\n";
	// cout << "Confirm order (y/n): ";
	// cin >> confirm;

	// if (confirm == 'y'){
	//     cout << "------------------------------------------------\n";
	//     cout << "\n  Thank you!\n  See you later!\n";
	//     orderList << orders[i].orderId << "," << orders[i].year << "," << orders[i].month << "," << orders[i].day << "," << orders[i].hour << "," << orders[i].min << "," << orders[i].days << "," << orders[i].week << "," << orders[i].customerName << "," << orders[i].driverName << "," << orders[i].carType << "," << orders[i].pickupArea << "," << orders[i].destinationArea << "," << orders[i].pickupLocation << "," << orders[i].destination << "," << orders[i].fare << ",\n" ;

	// } else {
	//     cout << "\n  Your order was canceled.\n";
	// }

	//go back to the admin menu
	cout << "\nPress any key to go back to the Customer Menu\n";
	system("read");
	customerMenu(customer, orders, inquiries, sId);

	cout << "\n\n";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (calculate)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculateDays(int month, int day) {
	int days{};

	switch (month) {
	case 1:     //Jan
		days = day;
		break;

	case 2:     //Feb
		days = 31 + day;
		break;

	case 3:     //Mar
		days = 31 + 28 + day;
		break;

	case 4:     //Apr
		days = 31 + 28 + 31 + day;
		break;

	case 5:     //May
		days = 31 + 28 + 31 + 30 + day;
		break;

	case 6:     //Jun
		days = 31 + 28 + 31 + 30 + 31 + day;
		break;

	case 7:     //Jul
		days = 31 + 28 + 31 + 30 + 31 + 30 + day;
		break;

	case 8:     //Aug
		days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
		break;

	case 9:     //Sep
		days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
		break;

	case 10:    //Oct
		days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
		break;

	case 11:    //Nov
		days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
		break;

	case 12:    //Dec
		days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
		break;
	}

	return days;
}

int calculateWeeks(int days) {
	int week;

	if (days % 7 == 0) {             //ex) 7%7=0, 14%7=0,....
		week = days / 7;            //ex) 7/7=1 (-->week1), 14/7=2 (-->week2), ....
	}
	else {
		week = (days / 7) + 1;      //ex) 3/7=0(int) +1 =1 (week1)
	}

	return week;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Read Files)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readOrderList(vector <Orders>& orders) {
	ifstream orderList("OrderList.csv");
	string line, item;
	struct Orders o;

	while (getline(orderList, line)) {
		istringstream i_stream(line);

		//String to integer conversion
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
	ifstream customerList("CustomerList.csv");
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



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Validation)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isPhoneValid(string& phone) {
	regex pattern("(\\d+)(\\-)(\\d+)(\\-)(\\d+)");               // define a regular expression

	return regex_match(phone, pattern);                          // try to match the string with the regular expression
}

bool isPostalCodeValid(string& postalCode) {
	regex pattern("(\\d+)(\\-)(\\d+)");

	return regex_match(postalCode, pattern);
}

bool isEmailValid(string& email) {
	regex pattern("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");

	return regex_match(email, pattern);
}

bool isPasswordValid(string& password) {
	bool digit, upperCase, lowerCase, specialCharacter, number, result;
	int digitFlag = 0, upperFlag = 0, lowerFlag = 0, specialCharacterFlag = 0, numberFlag = 0;

	regex digitExpression(".{8,}");
	regex upperCaseExpression("[A-Z]+");
	regex lowerCaseExpression("[a-z]+");
	regex specialCharacterExpression("[@!?#]+");
	regex numberExpression("[0-9]+");

	digit = regex_match(password, digitExpression);                         //Determine if the password is 8 characters or more
	upperCase = regex_search(password, upperCaseExpression);                //Determine if there is a part that matches the upper case
	lowerCase = regex_search(password, lowerCaseExpression);                //Determine if there is a part that matches the lower case
	specialCharacter = regex_search(password, specialCharacterExpression);  //Determine if there is a part that matches the special character
	number = regex_search(password, numberExpression);                      //Determine if there is a part that matches the number

	if (digit == false) {
		cout << "  !At least 8 characters\n";
		digitFlag = 1;
	}
	if (upperCase == false) {
		cout << "  !At least one upper case character\n";
		upperFlag = 1;
	}
	if (lowerCase == false) {
		cout << "  !At least one lower case character\n";
		lowerFlag = 1;
	}
	if (specialCharacter == false) {
		cout << "  !At least one special character (@, !, ?, #)\n";
		specialCharacterFlag = 1;
	}
	if (number == false) {
		cout << "  !At least one number\n";
		numberFlag = 1;
	}

	int totalFlagNum = digitFlag + upperFlag + lowerFlag + numberFlag + specialCharacterFlag;

	if (totalFlagNum == 0) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool isIntegerValid(string& number) {
	regex pattern("[0-9]");                  //Determine if the number is integer

	return regex_match(number, pattern);
}

bool isMultiDigitValid(string& number) {
	regex pattern("[0-9]+");                  //Determine if the number is integer

	return regex_match(number, pattern);
}

bool isYesNoValid(string& answer) {
	regex pattern("[yn]");                  //Determine if the number is integer

	return regex_match(answer, pattern);
}

bool isNameValid(string& name) {
	regex pattern("(\\w+)(\\s+)?(\\w+)?(\\s+)?(\\w+)?");

	return regex_match(name, pattern);
}

bool isLicenseValid(string& number) {
	regex pattern("(\\w+)");

	return regex_match(number, pattern);
}