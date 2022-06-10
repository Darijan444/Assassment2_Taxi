#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream

using namespace std;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare structures
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Customers{
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
    // string creditCardNumber;
    string pickupLocation;
    string destination;
    int selectedService;

    //constructor
    Customers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit", string ccn="NA", string pl="area1",string des="area2",int ss=1){
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
        // creditCardNumber = ccn;
        pickupLocation = pl;
        destination = des;
        selectedService = ss;
    }
};


struct Drivers{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string license;
    string area;

    //constructor
    Drivers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string li="0000-0000", string a="area"){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        license = li;
        area = a;
    }
};


struct Admins{
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

    //constructor
    Admins(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit"){
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
    }
};

struct Orders{
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

    Orders(int y=2022, int m=01, int d=01, int ds=01, int w=01, string cn="customer name", string dn="driver name", string ct="taxi", string pl="pickup location", string des="destination", float fa=10.00){
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

struct Inquiries{
    int year;
    int month;
    int day;
    string name;
    string userType;
    string phone;
    string email;
    string topic;
    string detail;

    Inquiries(int y=2022, int m=01, int d=01, string n="name", string ut="user type", string p="000-0000-0000", string e="email@email.com", string t="topic", string de="detail"){
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






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Admin//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
//show info
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
//show report
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
//read files
void readCustomerList(vector <Customers> &customers);
void readDriverList(vector <Drivers> &drivers);
void readAdminList(vector <Admins> &admins);
void readOrderList(vector <Orders> &orders);
void readInquiryList(vector <Inquiries> &inquiries);
//sign up
void adminSignup(vector <Admins> &admins);
void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);










/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    int option1, option2;

    cout << "\n************************************************\n";
    cout << "Welcome Yoobee Admin!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer Information\n";
    cout << "  2.Driver Information\n";
    cout << "  3.Admin Information\n";
    cout << "  4.Report\n";
    cout << "  5.Exit\n";
    cout << "------------------------\n";
    cout << "  Enter option: ";
    cin >> option1;
    cout << "\n\n";

    switch(option1){
        case 1:
        customerInfo(customers, drivers, admins, orders, inquiries);
        break;

        case 2:
        driverInfo(customers, drivers, admins, orders, inquiries);
        break;

        case 3:
        adminInfo(customers, drivers, admins, orders, inquiries);
        break;


        case 4:
        cout << "Please choose report type\n";
        cout << "  1.Daily\n";
        cout << "  2.Weekly\n";
        cout << "  3.Monthly\n";
        cout << "  4.All Data\n";
        cout << "  5.Inquiry\n";
        cout << "------------------------\n";
        cout << "  Enter option: ";
        cin >> option2;
        cout << "\n\n";

        switch(option2){
            case 1:
            dailyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 2:
            weeklyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 3:
            monthlyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 4:
            allDataReport(customers, drivers, admins, orders, inquiries);
            break;

            case 5:
            inquiryReport(customers, drivers, admins, orders, inquiries);
            break;
        }
        break;

        case 5:
        cout << "Thank you!\n\n";
        break;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminSignup(vector <Admins> &admins){
    struct Admins a;
    int option;
    int i = admins.size();      //List Size

    cout << "************************************************\n";
    cout << "Admin Sign Up\n";
    cout << "************************************************\n";
    cout << "Enter addmin information \n";
    cout << " Name: ";
    cin >> a.name;
    cout << " Phone number (e.g. 000-0000-0000): ";
    cin >> a.phone;
    cout << " Email address: ";
    cin >> a.email;
    cout << " Home address: \n";
    cout << "    Street: ";
    cin >> a.street;
    cout << "    City: ";
    cin >> a.city;
    cout << "    State: ";
    cin >> a.state;
    cout << "    Country: ";
    cin >> a.country;
    cout << "    Postal Code(e.g. 000-0000): ";
    cin >> a.postalCode;
    cout << " Password: ";
    cin >> a.password;

    admins.push_back(a);

    cout << "\n\n";

    ofstream adminList("AdminList.csv", ios::app);

    adminList << admins[i].name << "," << admins[i].phone << "," << admins[i].email << "," << admins[i].street << "," << admins[i].city << "," << admins[i].state << "," << admins[i].country << "," << admins[i].postalCode << "," << admins[i].password << ",\n" ;
}



void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    string userEmail, userPassword;
    int attemptCounts = 3;

    cout << "************************************************\n";
    cout << "Admin Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    // cout << " Email address: \n";
    // cin >> userEmail;
    // cout << " Password: \n";
    // cin >> userPassword;
    
    bool isAdmin = false;

    while (isAdmin != true && attemptCounts > 0){
    // for (int i= 0; i < 3; i++){
        cout << " Email address: ";
        cin >> userEmail;
        cout << " Password: ";
        cin >> userPassword;

        for (int i = 1; i < admins.size(); i++){
            if (admins[i].email == userEmail && admins[i].password == userPassword){
                isAdmin = true;
                
                adminMenu(customers, drivers, admins, orders, inquiries);
            }
        }

        attemptCounts--;
        
        if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "The number of login attempts has exceeded the limit.\n";
            cout << "Please wait a while and try again.\n";
        } else if (isAdmin != true) {
            cout << "----------------------------------------------------------------\n";
            cout << " Your email address or password is wrong.\n";
            cout << " Try again.\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
    cout << "\n";
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Information)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    cout << "************************************************\n";
    cout << "Customer Information\n";
    cout << "************************************************\n";

    cout << "Name\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tPayment Method\n";
    for (int i = 1; i < customers.size(); i++){
        cout << customers[i].name << "  \t" << customers[i].phone << "  \t"<< customers[i].email << "  \t" << customers[i].street << "   \t" << customers[i].city << "   \t" << customers[i].state << "   \t" << customers[i].country << "   \t" << customers[i].postalCode << "\t" << customers[i].payment <<"   \n";
    }
    

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    cout << "************************************************\n";
    cout << "Driver Information\n";
    cout << "************************************************\n";

    cout << "Name\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tLicense\t\tArea\n";
    for (int i = 1; i < drivers.size(); i++){
        cout << drivers[i].name << "  \t" << drivers[i].phone << "  \t"<< drivers[i].email << "  \t" << drivers[i].street << "   \t" << drivers[i].city << "   \t" << drivers[i].state << "   \t" << drivers[i].country << "   \t" << drivers[i].postalCode << "\t" << drivers[i].license << "\t" << drivers[i].area <<"   \n";
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    string option;

    cout << "************************************************\n";
    cout << "Admin Information\n";
    cout << "************************************************\n";

    cout << "Name\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\n";
    for (int i = 1; i < admins.size(); i++){
        cout << admins[i].name << "  \t" << admins[i].phone << "  \t"<< admins[i].email << "  \t" << admins[i].street << "   \t" << admins[i].city << "   \t" << admins[i].state << "   \t" << admins[i].country << "   \t" << admins[i].postalCode <<"   \n";
    }

    cout << "\nDo you want to add Admin?(y/n): ";
    cin >> option;

    if (option == "y"){
        adminSignup(admins);
    } 
    adminMenu(customers, drivers, admins, orders, inquiries);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Report)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    cout << "************************************************\n";
    cout << "All Data\n";
    cout << "************************************************\n";

    cout << "Date\t\t Customer\tDriver\t\tCar Type\tPickup Location\t\tDestination\t\tFare\n";
    for (int i = 1; i < orders.size(); i++){
        cout << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    float totalDayCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Daily Report\n";
    cout << "************************************************\n";
    cout << "Day\tFare(NZD)\n";

    for (int i = 0; i < 365; i++){   //1 year = 365 days
        totalDayCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].days){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalDayCost += orders[j].fare;
            }
        }
        if (totalDayCost > 0){
            cout << i + 1 << "\t" << totalDayCost << "\n";
            totalYearCost += totalDayCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);

}

void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    float totalWeekCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Weekly Report\n";
    cout << "************************************************\n";
    cout << "Week\tFare(NZD)\n";

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        totalWeekCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].week){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalWeekCost += orders[j].fare;
            }
        }
        if (totalWeekCost > 0){
            cout << i + 1 << "\t" << totalWeekCost << "\n";
            totalYearCost += totalWeekCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";

    
    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    float totalMonthCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Monthly Report\n";
    cout << "************************************************\n";
    cout << "Month\tFare(NZD)\n";

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        totalMonthCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].month){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalMonthCost += orders[j].fare;
            }
        }
        if (totalMonthCost > 0){
            cout << i + 1 << "\t" << totalMonthCost << "\n";
            totalYearCost += totalMonthCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    cout << "************************************************\n";
    cout << "Inquiry Report\n";
    cout << "************************************************\n";
    cout << "Date\t\tCustomer\tUser Type\tPhone\t\t\tEmail\t\t\tTopic\t\tDetail\n";
    for (int i = 1; i < inquiries.size(); i++){
        cout << inquiries[i].year << "/" << inquiries[i].month << "/"<< inquiries[i].day << "  \t" << inquiries[i].name << "   \t" << inquiries[i].userType << "   \t" << inquiries[i].phone << "   \t" << inquiries[i].email << "   \t" << inquiries[i].topic << "\t" << inquiries[i].detail <<"   \n";
    }

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Read Files)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readOrderList(vector <Orders> &orders){
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

void readInquiryList(vector <Inquiries> &inquiries){
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

void readCustomerList(vector <Customers> &customers){
    ifstream customerList("CustomerList.csv");
    string line, item;
    struct Customers c;

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

        customers.push_back(c);  
    }
}

void readDriverList(vector <Drivers> &drivers){
    ifstream driverList("DriverList.csv");
    string line, item;
    struct Drivers d;

    while (getline(driverList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, d.name, ',');
        getline(i_stream, d.phone, ',');
        getline(i_stream, d.email, ',');
        getline(i_stream, d.street, ',');
        getline(i_stream, d.city, ',');
        getline(i_stream, d.state, ',');
        getline(i_stream, d.country, ',');
        getline(i_stream, d.postalCode, ',');
        getline(i_stream, d.password, ',');
        getline(i_stream, d.license, ',');
        getline(i_stream, d.area, ',');

        drivers.push_back(d); 
    }
}

void readAdminList(vector <Admins> &admins){
    ifstream adminList("AdminList.csv");
    string line, item;
    struct Admins a;

    while (getline(adminList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, a.name, ',');
        getline(i_stream, a.phone, ',');
        getline(i_stream, a.email, ',');
        getline(i_stream, a.street, ',');
        getline(i_stream, a.city, ',');
        getline(i_stream, a.state, ',');
        getline(i_stream, a.country, ',');
        getline(i_stream, a.postalCode, ',');
        getline(i_stream, a.password, ',');

        admins.push_back(a); 
    }
}
