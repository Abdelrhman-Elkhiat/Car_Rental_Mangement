#include<iostream>
using namespace std;
#include"Car.h"
#include"Admin.h"
#include"Person.h"
#include"Customer.h"
#include <conio.h>
#include<cstdlib>
void Random_Car_Generation(Car* ptr);
void Random_Car_Generation(Car* ptr)
{
	int i, Rand_num, mdel_year, rent_feez;
	for (i = 0; i < 9; i++)
	{
		Rand_num = rand();
		mdel_year = 2000 + (Rand_num % 23);
		rent_feez = 1000 + (Rand_num % 1500);
		(ptr+i)->editCar(i, Rand_num, Rand_num, Rand_num, mdel_year, rent_feez);
	}
}
void Menu(Car* Ptr_Car, Customer* Ptr_Customer)
{
	int Login_status;
	string name, Password,decision = "yes";
	int selection;
	do
	{
		Login_status = Ptr_Customer->login(&name);
		if (IS_USER == Login_status)
		{
			cout << "Car Rental System Car Selection\n";
			cout << "Please Choose The Car You Want to Rent \n";
			Ptr_Car->Display_Avilable_Cars(Ptr_Car);
			cout << "Enter Car Number: ";
			cin >> selection;
			while (!((Ptr_Car+selection - 1)->IsAvailable()))
			{
				cout << "PLEASE SELECT A VALID CAR NUMBER\n";
				cout << "Enter Car Number: ";
				cin >> selection;
			}

			Ptr_Customer->rent_car(name, selection - 1);
			(Ptr_Car + selection - 1)->rentCar();
			cout << "Car is Rented Successfuly!" << endl;
			system("PAUSE");
			system("CLS");
			cout << "Jump to main menu?" << endl;
			cout << "Enter yes to Continue" << endl;
			cout << "Enter Exit to End Program" << endl;
			cout << "Your Choice is: ";
			cin >> decision;
		}
		else if (IS_ADMIN == Login_status)
		{
			cout << "Car Rental System Admin Menu\n";
			cout << "1) Display Available Cars\n";
			cout << "2) Display Rented Cars\n";
			cout << "3) Add New Customer\n";
			cout << "Your Choice is: ";
			cin >> selection;
			if (1 == selection)
			{
				Ptr_Car->Display_Avilable_Cars(Ptr_Car);
			}
			else if (2 == selection)
			{
				Ptr_Customer->DisplayRentedCars(Ptr_Car);
			}
			else if (3 == selection)
			{
				cout << "Enter User Name:";
				cin >> name;
				cout << "Enter Password: ";
				cin >> Password;
				Ptr_Customer->addCustomer(name, Password);
				cout << "Added Succesfuly!";
				system("PAUSE");
				system("CLS"); 
				cout << "Jump to main menu?" << endl;
				cout << "Enter yes to Continue" << endl;
				cout << "Enter Exit to End Program" << endl;
				cout << "Your Choice is: ";
				cin >> decision;
			}
		}
		else if (WRONG_PASSWORD == Login_status)
		{
			system("CLS");
			cout << "Jump to main menu?" << endl;
			cout << "Enter yes to Continue" << endl;
			cout << "Enter Exit to End Program" << endl;
			cout << "Your Choice is: ";
			cin >> decision;
		}
		else if (NOT_FOUND == Login_status)
		{
			cout << "User name is not used! \n";
			cout << "Do You Want to Create New account ? \n";
			cout << "Enter 1 to Create New \n";
			cout << "Enter 2 to Try Again\n";
			cout << "Your Choice is: ";
			cin >> selection;
			if (1 == selection)
			{
				system("CLS");
				cout << "Enter New Password: ";
				cin >> Password;
				Ptr_Customer->addCustomer(name, Password);
				cout << "Added Succesfuly!";
				system("PAUSE");
				system("CLS");
				cout << "Jump to main menu?" << endl;
				cout << "Enter yes to Continue" << endl;
				cout << "Enter Exit to End Program" << endl;
				cout << "Your Choice is: ";
				cin >> decision;
			}
		}
	} while (decision != "Exit");
}
int main()
{
	Car array_Cars[NUMBER_OF_CARS];
	
	Admin Admin_1;
	Customer customer_1;
	customer_1.addCustomer("Abdelrhman", "1234");
	Random_Car_Generation(array_Cars);
	Menu(array_Cars, &customer_1);
	return 0;
}
