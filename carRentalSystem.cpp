#include <iostream>
using namespace std;

class Car{
    private:
        string brand;
        string model;
        int year;
        double pricePerday;
        bool isAvailable;
    public:
        Car(string b, string m, int y, double ppd, bool isAvail = false){
            brand = b;
            model = m;
            year = y;
            pricePerday = ppd;
            isAvailable = isAvail;
        }
        void displayDetails(){
            cout << "Car: " << brand << " " << model << " " << year << endl;
            cout << "Price: Php " << pricePerday << " per day" << endl;
            cout << "Available Status: " << (isAvailable ? " Rented" : " Available") << endl;
            cout << "==============================================" << endl;
        }
        void payment(int day, double userPayment){
            double totalPrice = pricePerday * day;
            cout << "Total amount: Php " << totalPrice << endl;
            cout << "Cash: Php " << userPayment << endl;
                if (userPayment == totalPrice)
                {
                    cout << "Thank you for renting have a safe trip." << endl;
                    cout << "==============================================" << endl;
                }
                else if (userPayment > totalPrice)
                {
                    double change = userPayment - totalPrice;
                    cout << "Your change: Php " << change << endl;
                    cout << "Thank you for renting have a safe trip." << endl;
                    cout << "==============================================" << endl;
                }
                else
                {
                    cout << "INVALID PAYMENT" << endl;
                    isAvailable = false;
                    cout << "==============================================" << endl;
                }
        }
        /*void rentCar(){
            if (isAvailable)
            {
                isAvailable = false;
                cout << "Available" << endl;
            }
            else
            {
                cout << "Sorry the Car your Choice is rented." << endl;
                exit(0);
            }
        }*/
        bool rentCar(){
            if (isAvailable)
            {
                return false; // Available the Car
            }
            else
            {
                isAvailable = true;
                return true; // Rented
            }
        }
        void returnCar(string returnCar){
            isAvailable = false;
            cout << "The car " << brand << " has been returned." << endl;
            cout << "==============================================" << endl;
        }
};

int main(){
    cout << "============== Car Rental System =============" << endl;
    Car car1("Toyota", "Vios", 2025, 1000);
    Car car2("Honda", "Civic", 2025, 1500);
    Car car3("Ford", "Everest", 2025, 2000);

    int menu;
    int day;
    string returnCar;
    double userPayment;
    do
    {
        cout << "1. Rent a car" << endl;
        cout << "2. Return a car" << endl;
        cout << "3. View the car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> menu;
        cout << "==============================================" << endl;

    switch (menu)
    {
    case 1:
        cout << "1. Toyota Vios " << '\n' << "2. Honda Civic " << '\n' << "3. Ford Everest" << endl;
        cout << "What car do you like: ";
        cin >> menu;
            if (menu == 1)
            {
                /*car1.rentCar();
                cout << "How many days: ";
                cin >> day;
                cout << "Cash: Php ";
                cin >> userPayment;
                car1.payment(day, userPayment);*/
                if (car1.rentCar())
                {
                    cout << "How many days: ";
                    cin >> day;
                    cout << "Cash: Php ";
                    cin >> userPayment;
                    car1.payment(day, userPayment);
                }
                else
                {
                    cout << "Sorry the Car your Choice is rented." << endl;
                    cout << "==============================================" << endl;
                }
            }
            else if (menu == 2)
            {
                if (car2.rentCar())
                {
                    cout << "How many days: ";
                    cin >> day;
                    cout << "Cash: Php ";
                    cin >> userPayment;
                    car2.payment(day, userPayment);
                }
                else
                {
                    cout << "Sorry the Car your Choice is rented." << endl;
                    cout << "==============================================" << endl;
                }
            }
            else if (menu == 3)
            {
                if (car3.rentCar())
                {
                    cout << "How many days: ";
                    cin >> day;
                    cout << "Cash: Php ";
                    cin >> userPayment;
                    car3.payment(day, userPayment);
                }
                else
                {
                    cout << "Sorry the Car your Choice is rented." << endl;
                    cout << "==============================================" << endl;
                }
            }
            else
            {
                cout << "INVALID" << endl;
                cout << "==============================================" << endl;
            }
        break;
    case 2:
        cout << "Enter the Car you want to return: ";
        cin >> returnCar;
            if (returnCar == "Toyota" || returnCar == "toyota")
            {
                car1.returnCar(returnCar);
            }
            else if (returnCar == "Honda" || returnCar == "honda")
            {
                car2.returnCar(returnCar);
            }
            else if (returnCar == "Ford" || returnCar == "ford")
            {
                car3.returnCar(returnCar);
            }
            else
            {
                cout << "INVALID" << endl;
                cout << "==============================================" << endl;
            }
        break;
    case 3:
        car1.displayDetails();
        car2.displayDetails();
        car3.displayDetails();
        break;
    case 4:
        cout << "EXIT" << endl;
        break;
    default:
        cout << "INVALID" << endl;
        cout << "==============================================" << endl;
        break;
    }
    } while (menu != 4);
    
    return 0;
}
