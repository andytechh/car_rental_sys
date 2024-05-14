#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Car_Management{
private:
    int carID;
    string model, custName;
    float rentalRate;
    bool available;
    string color;
    int yearmodel, rentdays;
    

public:
	void frontPage();
    void menu();
    void login();
    void admin();
    void customer();
    void addCar();
    void modifyCar();
    void removeCar();
    void viewCar();
    void rentCar();
    void returnCar();
    void userlogin();
    void registration();
    void customerMenu();
    void viewRented();
};
void Car_Management::frontPage(){
	
 		cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*       Car Rental System       *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*_______________________________*\n";
        system("pause");
        
        system("cls");
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*            Members            *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*   Lazarte, Andy               *\n";
        cout << "*   Marcelo, Jerick             *\n";
        cout << "*   Fernandez, Louis Chanler    *\n";
        cout << "*   Lomerio, Aira Mae           *\n";
        cout << "*   Narito, Aries Daniel        *\n";
        cout << "*                               *\n";
        cout << "*_______________________________*\n";
        system("pause");
        menu();
	
}
void Car_Management::menu() {
    int choice;

    do {
    		system("cls");
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*             Menu              *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "* [ 1 ]   Admin                 *\n";
        cout << "* [ 2 ]   Customer              *\n";
        cout << "* [ 3 ]   Exit                  *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "* Select Options (1-3):         *\n";
        cin >> choice;
        cout << "*_______________________________*\n";

        switch (choice) {
            case 1:
            	system("cls");
                login();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid Input..";
                break;
        }
    } while (true);
}
void Car_Management :: registration(){
	 ofstream logindata;
    string user;

start:
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*         Registration          *\n";
    cout << "*                               *\n";
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "Create Username: ";
    cin >> user;

    string pass;
    cout << "\nCreate Password: ";
    char ch = _getch();
    while (ch != 13) {
        if (ch == '\b') { // Check for backspace
            if (!pass.empty()) {
                pass.erase(pass.size() - 1);
                cout << "\b \b";
            }
        } else {
            pass.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }

    logindata.open("logindatabase.txt", ios::app); // Open file in append mode
    if (!logindata) {
        cerr << "Error opening file.";
        return;
    }

  
    logindata << user << " " << pass << "\n";
    logindata.close();

    cout << "\nRegistration successful.\n";
}
void Car_Management :: userlogin(){
 ifstream logindata;
    string user;
	system("cls");
start:
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*        Customer Login         *\n";
    cout << "*                               *\n";
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "Enter Username: ";
    cin >> user;

    string pass;
    cout << "\nEnter Password: ";
    char ch = _getch();
    while (ch != 13) {
        if (ch == '\b') { // Check for backspace
            if (!pass.empty()) {
                pass.erase(pass.size() - 1);
                cout << "\b \b";
            }
        } else {
            pass.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    
    logindata.open("logindatabase.txt", ios::in);
    if (!logindata) {
        cerr << "Error opening file.";
        return;
    }

    bool loggedIn = false;
    string storedUser, storedPass;
    while (logindata >> storedUser >> storedPass) {
        if (user == storedUser && pass == storedPass) {
            loggedIn = true;
            break;
        }
    }

    logindata.close();

    if (loggedIn) {
    	customer();
        cout << "\nLogin successful.\n";
    } else {
        cout << "\n\n Wrong Password or Username, Try Again \n";
        system("pause");
        system("cls");
        goto start;
    }
}
void Car_Management :: login(){
	
string user;

    start:
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*             Login             *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "Enter Username: ";
        cin >> user;
        string pass;

        cout << "\nEnter Password: ";
        char ch = _getch();
        while (ch != 13) {
            if (ch == '\b') { // Check for backspace
                if (!pass.empty()) {
                    pass.erase(pass.size() - 1);
                    cout << "\b \b";
                }
            } else {
                pass.push_back(ch);
                cout << '*';
            }
            ch = _getch();
        }

        if (user == "Admin" && pass == "Admin12345") {
            admin();
        } else {
            cout << "\n\n Wrong Password or Username, Try Again \n";
            system("pause");
            system("cls");
            goto start;
        }

}

void Car_Management::admin() {
    int choice;

    do {
        system("cls");
     
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*         Administrator         *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "* [ 1 ]   Add Car               *\n";
        cout << "* [ 2 ]   Modify a Car          *\n";
        cout << "* [ 3 ]   Remove a Car          *\n";
        cout << "* [ 4 ]   View Cars             *\n";
        cout << "* [ 5 ]   View Rented Cars      *\n";
        cout << "* [ 6 ]   Exit                  *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "* Select Options (1-5):         *\n";
        cin >> choice;
        cout << "*_______________________________*\n";

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                modifyCar();
                break;
            case 3:
                removeCar();
                break;
            case 4:
                viewCar();
                break;
            case 5:
                viewRented(); 
                break;
            case 6: 
             	menu();
             	break;
            default:
                cout << "Invalid Input..\n";

                cout << "Press any key to continue...\n";
                cin.ignore();
                cin.get(); 
        }
    } while (true); 
}
void Car_Management::customerMenu(){
	int choice;
    bool exitCustomer = false;

    while (!exitCustomer) {
    		system("cls");
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*           Customer            *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "* [ 1 ]   Login                 *\n";
        cout << "* [ 2 ]   Register              *\n";
        cout << "* [ 3 ]   Exit                  *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "* Select Options (1-3):         *\n";
        cin >> choice;
        cout << "*_______________________________*\n";
 		switch(choice){
 			case 1: {
 				userlogin();
				break;
			 }
			case 2: {
				registration();
				break;
			}
			case 3: {
				menu();
				break;
			}
			default: {
				cout << "Invalid input\n";
				break;
			}
		 }       
}
}
void Car_Management::customer() {
	
    int choice;
    bool exitCustomer = false;

    while (!exitCustomer) {
    		system("cls");
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "*           Customer            *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "*                               *\n";
        cout << "* [ 1 ]   Rent Car              *\n";
        cout << "* [ 2 ]   Return Car            *\n";
        cout << "* [ 3 ]   Exit                  *\n";
        cout << "*                               *\n";
        cout << "*-------------------------------*\n";
        cout << "* Select Options (1-3):         *\n";
        cin >> choice;
        cout << "*_______________________________*\n";

        switch (choice) {
            case 1:
            	system("cls");
                rentCar();
                break;
            case 2:
                returnCar();
                break;
            case 3:
                menu();
                break;
            default:
                cout << "Invalid Input..";
                break;
        }
    }
}

void Car_Management::addCar(){
  fstream carsData;
    int id, ym;
    string m, c;
    float r;
    char s;
	system("cls");
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*           Add Car             *\n";
    cout << "*                               *\n";
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*   Car Id: ";
    cin >> carID; 
    cout << "*   Car Model: ";
    cin.ignore();
    getline(cin, model);
    cout << "*   Year Model: ";
    cin >> yearmodel; 
    cout << "*   Color: ";
    cin >> color; 
    cout << "*   Rental Rate: ";
    cin >> rentalRate;
    cout << "*   Status (A/a for available, U for unavailable): ";
    cin >> s;

    bool available = (s == 'A' || s == 'a');

    carsData.open("database.txt", ios::in | ios::out);
    if (!carsData) {
        cerr << "Error opening file.";
        return;
    }

    bool carExists = false;
    while (carsData >> id >> m >> ym >> c >> r >> s) {
        if (id == carID) {
            carExists = true;
            break;
        }
    }

    carsData.clear();
    carsData.seekg(0, ios::beg);
    if (carExists) {
        cout << "Car with the same ID already exists.\n";
        system("pause");
    } else {
        carsData.seekp(0, ios::end);
        carsData << carID << " " << model << " " << yearmodel << " " << color << " " << rentalRate << " " << available << "\n";
        cout << "\nRecord has been added... \n";
        system("pause");
    }

    carsData.close();
}

void Car_Management::modifyCar() {
    fstream carsData, carsData1;
    int cId,id,ym;
    string m, c;
    float r;
    char s;
    int choice;
	
	system("cls");
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*          Modify Car           *\n";
    cout << "*                               *\n";
    cout << "*-------------------------------*\n";
    cout << "*                               *\n";
    viewCar();
    cout << "Enter id of car: ";
    cin >> cId;

    carsData.open("database.txt", ios::in);
    carsData1.open("tempdatabase.txt", ios::out);

    if (!carsData) {
        cout << "File does not exist." << endl;
    }

    bool carFound = false;
    while (carsData >> id >> m >> ym >> c >> r >> s) {
        if (cId == id) {
            carFound = true;

            cout << "*-------------------------------*\n";
            cout << "*                               *\n";
            cout << "*          Modify Car           *\n";
            cout << "*                               *\n";
            cout << "*-------------------------------*\n";
            cout << "*                               *\n";
            cout << "* [ 1 ]   New Car Model         *\n";
            cout << "* [ 2 ]   New Year Model        *\n";
            cout << "* [ 3 ]   New Color             *\n";
            cout << "* [ 4 ]   New Rental Rate       *\n";
            cout << "* [ 5 ]   New Status            *\n";
            cout << "* [ 6 ]   Exit                  *\n";
            cout << "*                               *\n";
            cout << "*-------------------------------*\n";
            cout << "* Select Options (1-6):         *\n";
            cin >> choice;
            cout << "*_______________________________*\n";

            switch (choice) {
                case 1:
                    cout << "New car model: ";
                    cin >> m;
                    break;
                case 2:
                    cout << "New year model: ";
                    cin >> ym;
                    break;
                case 3:
                    cout << "New color: ";
                    cin >> c;
                    break;
                case 4:
                    cout << "New Rental Rate: ";
                    cin >> r;
                    break;
                case 5:
                    cout << "New status (A/a for available, U/u for not available): ";
                    cin >> s;
                    break;
                case 6:
                    exit(0);
                    break;
                default:
                    cout << "Invalid Input..";
                    break;
            }
        }

        // Write the modified or unmodified record to the new file
        carsData1 << id << " " << m << " " << ym << " " << c << " " << r << " " << s << endl;
    }

    carsData.close();
    carsData1.close();

    if (!carFound) {
        cout << "Car not found." << endl;
        remove("tempdatabase.txt");
    } else {
        remove("database.txt");
        rename("tempdatabase.txt", "database.txt");
    }
}



void Car_Management::removeCar() {
    int cId;
    int total = 0;

    cout << "Remove car" << endl;
    cout << "Enter car id: ";
    cin >> cId;

    ifstream carsData("database.txt");
    ofstream tempData("tempdatabase.txt");

    if (!carsData.is_open()) {
        cout << "Error: Unable to open database file." << endl;
        return;
    }

    bool carFound = false;
    while (carsData >> carID >> model >> yearmodel >> color >> rentalRate >> available) {
        if(carID == cId) {
            carFound = true;
            cout << "Car deleted successfully." << endl;
            system("pause");
            total++;


     }else if(!carFound) {
        cout << "Error: Car with ID " << cId << " not found." << endl;
        system("pause");
        return;


        } else {
            tempData << carID << " " << model << " " << yearmodel << " " << color << " " << rentalRate << " " << available << endl;
        }
    }

    carsData.close();
    tempData.close();

    remove("database.txt");
    rename("tempdatabase.txt", "database.txt");
}
void Car_Management::viewCar() {
    ifstream carsData("database.txt");
    cout << "car id|\tmodel |\tyear_model|\tcolor|\trental rate |\tavailable\n";
    if (!carsData) {
        cout << "File does not exist." << endl;
        system("pause");
        return;
    }

    int carID, yearmodel;
    string model, color;
    float rentalRate;
    char available;

    while (carsData >> carID >> model >> yearmodel >> color>> rentalRate >> available) {
        cout << carID << "\t" << model << "\t" << yearmodel << "\t\t" << color << "\t\t" << rentalRate << "\t\t" << available << endl;
    }

    system("pause");
    carsData.close();
}

void Car_Management::viewRented(){
	 ifstream carsData("database.txt");

    if (!carsData) {
        cerr << "Error: Could not open database file." << endl;
        return;
    }
	system("cls");
    bool anyRentedCars = false;
    cout << "\n*-------------------------------*\n";
    cout << "*                               *\n";
    cout << "*         Rented Cars            *\n";
    cout << "*                               *\n";
    cout << "*-------------------------------*\n";

    while (carsData >> carID >> model >> yearmodel >> color >> rentalRate >> available >> custName >> rentdays) {
        if (!available) {
            anyRentedCars = true;
            
            cout << "Customer : " << custName << endl;
            cout << "Reanted Days: " << rentdays << endl;
            cout << "Car ID: " << carID << endl;
            cout << "Car Model: " << model << endl;
            cout << "Year Model: " << yearmodel << endl;
            cout << "Color: " << color << endl;
            cout << "Rental Rate: Php " << rentalRate<< " per day\n";
            cout << "-----------------------------\n";
            cout << "Total: Php " << rentalRate * rentdays<< "\n\n";
            system("pause");
        }
    }

    if (!anyRentedCars) {
        cout << "No cars are currently rented." << endl;
    }
	 system("pause");
    carsData.close();
}

void Car_Management::rentCar() {
    int cId, rentDays;
    string customerName;

    ifstream carsData("database.txt");
    ofstream tempData("tempdatabase.txt");

    if (!carsData || !tempData) {
        cerr << "Error: Could not open files." << endl;
        return;
    }

    viewCar();

    cout << "Enter car id you want to rent: ";
    cin >> cId;

    bool carFound = false;
    while (carsData >> carID >> model >> yearmodel >> color >> rentalRate >> available) {
        if (carID == cId && available) {
            carFound = true;

            cout << "Enter your name (name only): ";
            cin.ignore();
            getline(cin, customerName);

            cout << "Enter the number of days you want to rent the car: ";
            cin >> rentDays;

            // Update rental rate in the database
            float updatedRentalRate = rentalRate * rentDays;
            tempData << carID << " " << model << " " << yearmodel << " " << color << " " << rentalRate << " " << false << " " << customerName << " " << rentDays << endl;

            cout << "Car rented successfully. Here is your receipt:" << endl;

            cout << "*-------------------------------*\n";
            cout << "*                               *\n";
            cout << "*          Rental Receipt       *\n";
            cout << "*                               *\n";
            cout << "*-------------------------------*\n";
            cout << "Name: " << customerName << endl;
            cout << "Car ID: " << carID << endl;
            cout << "Car Model: " << model << endl;
            cout << "Year Model: " << yearmodel << endl;
            cout << "Color: " << color << endl;
            cout << "Rental Rate: Php" << rentalRate << " per day\n";
            cout << "Number of days rented: " << rentDays << endl;
            cout << "-------------------------------\n";
            cout << "Total Rental Fee: Php" << updatedRentalRate << endl;

            break; 
        }
        tempData << carID << " " << model << " " << yearmodel << " " << color << " " << rentalRate << " " << available << " " << customerName << " " << rentDays << endl;
    }

    if (!carFound) {
        cout << "Car not found or already rented." << endl;
    }

    carsData.close();
    tempData.close();

  
    remove("database.txt");
    rename("tempdatabase.txt", "database.txt");

    system("pause");
}

void Car_Management::returnCar() {
	
        int cId;
        string customerName;

        ifstream carsData("database.txt");
        ofstream tempData("tempdatabase.txt");

        if (!carsData || !tempData) {
            cerr << "Error: Could not open files." << endl;
            return;
        }

        cout << "Enter car id you want to return: ";
        cin >> cId;

        bool carFound = false;
        while (carsData >> carID >> model >> yearmodel >> color >> rentalRate >> available >> custName >> rentdays) {
            if (carID == cId) {
                carFound = true;
                if (!available) {
                    available = true;
                    cout << "Car returned successfully." << endl;

                    // Calculate the rental fee based on the rental rate and the rental duration
                    float totalFee = rentalRate * rentdays; 
                    cout << "*-------------------------------*\n";
		            cout << "*                               *\n";
		            cout << "*          Rental Receipt       *\n";
		            cout << "*                               *\n";
		            cout << "*-------------------------------*\n";
					cout << "*                               *\n";
                    cout << "Customer : " << custName << endl;
                    cout << "Rented Days: " << rentdays << endl; 
                    cout << "Car ID: " << carID << endl;
                    cout << "Car Model: " << model << endl;
                    cout << "Year Model: " << yearmodel << endl;
                    cout << "Color: " << color << endl;
                    cout << "Rental Rate: Php " << rentalRate << " per day\n";
                    cout << "-----------------------------\n";
                    cout << "Total: Php " << totalFee << "\n\n"; 
                } else {
                    cout << "Car is already available." << endl;
                }
            }
            // Write the car data to the temporary file
         tempData << carID << " " << model << " " << yearmodel << " " << color << " " << rentalRate << " " << available << " " << custName << " " << rentdays << endl;
        }

        if (!carFound) {
            cout << "Car not found." << endl;
        }

        carsData.close();
        tempData.close();

       
        remove("database.txt");
        rename("tempdatabase.txt", "database.txt");

        system("pause");
    }


int main()
{
    Car_Management car;
    car.frontPage();
    return 0;
}
