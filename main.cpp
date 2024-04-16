#include <iostream>
#include <fstream>
#define rented 50

using namespace std;

class Car_Management{
private:
    int carID;
    string model;
    float rentalRate;
    bool available;

public:
    void menu();
    void login();
    void admin();
    void customer();
    void addCar();
    void modifyCar();
    void removeCar();
    void viewCar();
    void rentCar();
};
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
                customer();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid Input..";
                break;
        }
    } while (true);
}

void Car_Management :: login(){
	string username, password;

	     cout << "*-------------------------------*\n";
		 cout << "*                               *\n";
		 cout << "*             Login             *\n";
		 cout << "*                               *\n";
		 cout << "*-------------------------------*\n";
		 cout << "*                               *\n";
		 cout << "Enter Username: ";
		 cin  >> username;
		 cout << "Enter Password: ";
		 cin  >> password;

		 if(username == "Admin" && password == "Admin12345"){
         admin();
		 }
		 else{
		 	cout << "Invalid Username or Password \n";
		 }
}
void Car_Management::admin() {
    int choice;

    do {
        system("cls");
        // Display the menu options and get the user's choice
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
        cout << "* [ 5 ]   Exit                  *\n";
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
                menu(); // This should return to the main  menu
                break;
            default:
                cout << "Invalid Input..\n";
                // Add a prompt to continue
                cout << "Press any key to continue...\n";
                cin.ignore();
                cin.get(); // Wait for user input before continuing
        }
    } while (true); // Keep looping until explicitly exited
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
                rentCar();
                break;
            case 2:
                //returnCar();
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
    int id;
    string m;
    float r;
    char s;

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
    cout << "*   Rental Rate: ";
    cin >> rentalRate;
    cout << "*   Status (A/a for available, anything else for unavailable): ";
    cin >> s;

    bool available = (s == 'A' || s == 'a');

    carsData.open("database.txt", ios::in | ios::out);
    if (!carsData) {
        cerr << "Error opening file.";
        return;
    }

    bool carExists = false;
    while (carsData >> id >> m >> r >> s) {
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
        carsData << carID << " " << model << " " << rentalRate << " " << available << "\n";
        cout << "\nRecord has been added... \n";
        system("pause");
    }

    carsData.close();
}

void Car_Management::modifyCar() {
    fstream carsData, carsData1;
    int cId;
    int id;
    string m;
    float r;
    char s;
    int total = 0;

    cout << "Modify car" << endl;
    cout << "Enter car id: ";
    cin >> cId;

    carsData.open("database.txt", ios::in);
    carsData1.open("database1.txt", ios::out);

    if (!carsData) {
        cout << "File does not exist." << endl;
        return;
    }

    bool carFound = false;
    while (carsData >> id >> m >> r >> s) {
        if (cId == id) {
            carFound = true;
            cout << "New car id: ";
            cin >> id;
            cout << "New car model: ";
            cin >> m;
            cout << "New rental rate: ";
            cin >> r;
            cout << "New status (A or a for available, R or r for rented): ";
            cin >> s;

            bool available = (s == 'A' || s == 'a');

            carsData1 << id << " " << m << " " << r << " " << s << endl;
            cout << "Car data modified successfully." << endl;
            total++;
        } else {
            carsData1 << id << " " << m << " " << r << " " << s << endl;
        }
    }

    carsData.close();
    carsData1.close();

    if (!carFound) {
        cout << "Car not found." << endl;
        remove("database1.txt"); // Remove the temporary file
    } else {
        remove("database.txt");
        rename("database1.txt", "database.txt");
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
    while (carsData >> carID >> model >> rentalRate >> available) {
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
            tempData << carID << " " << model << " " << rentalRate << " " << available << endl;
        }
    }

    carsData.close();
    tempData.close();

    remove("database.txt");
    rename("tempdatabase.txt", "database.txt");
}
void Car_Management::viewCar(){
    fstream carsData;
    carsData.open("database.txt", ios::in);
    cout << "car id\t\t model\t\t rental rate\t\t available\n";

    if (!carsData) {
        cout << "File does not exist." << endl;
        system("pause");
        return;
    }
    while (carsData >> carID >> model >> rentalRate >> available) {
        cout << carID << "\t\t" << model << "\t\t" << rentalRate<< "\t\t" << available << endl;
    }
    system("pause");
    carsData.close();

}

void Car_Management::rentCar(){
        fstream carsData;
        int cId;

        carsData.open("database.txt",ios::in);

    if (!carsData) {
        cout << "File does not exist." << endl;
        system("pause");
    }

        viewCar();
    cout << "Enter car id you want to rent: ";
    cin >> cId;

    bool carFound = false;
    while (carsData >> carID >> model >> rentalRate >> available) {
        if(carID == cId) {
            carFound = true;
            available = false;
            cout << "Car rented successfully." << endl;
            system("pause");
        }

      }
    carsData.close();
    }
int main()
{
    Car_Management car;
    car.customer();
    return 0;
}
