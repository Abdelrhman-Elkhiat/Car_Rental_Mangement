#include "Person.h"
string Person:: user_list[] = {""};
string Person::pass_list[] =   {""};
string Person::user_admin = "";
string Person::pass_admin = "";
int Person::Rental_list[] = { -1};
int Person::customer_counter = 0;
void Person::intilize_list()
{
	int i;
	for (i = 0; i < NUMBER_OF_USERS; i++)
	{
		user_list[i] = NOT_INITIALIZED;
		pass_list[i] = NOT_INITIALIZED;
		Rental_list[i] = UNINTILAZED;
	}
}
int Person::isUser(string user, string pass)
{
	int i = 0;
	while (i < NUMBER_OF_USERS && user_list[i] != NOT_INITIALIZED && user != user_list[i])
	{
		i++;
	}
	if (user_list[i] == user)
	{
		if (pass_list[i] == pass)
		{
			return IS_USER;
		}
		else
		{
			return WRONG_PASSWORD;
		}
	}
	else
	{
		return NOT_FOUND;
	}
}
int Person::login(string* Ptr_name)
{
	int i = 0;
	string pass = "", name = "";
	char ch;
	system("CLS");
	cout << "Car Rental System Login\n";
	cout << "Please Provide Your Personal Details   \n";
	cout << "Enter Your Name : ";
	ch = _getch();
	while (ch != 13) {//character 13 is enter
		name.push_back(ch);
		cout << ch;
		ch = _getch();
	}
	cout << "\nEnter Password: ";
	ch = _getch();
	while (ch != 13) {//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (TRUE == Person::isAdmin(name, pass))
	{
		cout << "\nAccess Granted! Welcome " << name << " To Our System \n\n";
		system("PAUSE");
		system("CLS");
		*Ptr_name = name;
		return IS_ADMIN;
	}
	else if(WRONG_PASSWORD == Person::isUser(name, pass))
	{
		while (TRUE != Person::isUser(name, pass) && i < NUMBER_OF_TRIALS)
		{
			pass = "";
			cout << "\nWRONG PASSWORD" ;
			cout << "\nEnter Password: ";
			ch = _getch();
			while (ch != 13) {//character 13 is enter
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			i++;
		}
		if (IS_USER == Person::isUser(name, pass))
		{
			
			cout << "\ntAccess Granted! Welcome " << name << " To Our System \n\n";
			system("PAUSE");
			system("CLS");
			*Ptr_name = name;
			return IS_USER;
		}
		else
		{
			*Ptr_name = name;
			cout << "\nAccess Denied!...Please Try Again!!\n";
			system("PAUSE");
			system("CLS");
			return WRONG_PASSWORD;
		}
	}
	else if (IS_USER == Person::isUser(name, pass))
	{
		*Ptr_name = name;
		cout << "\nAccess Granted! Welcome  " << name << " To Our System \n\n";
		system("PAUSE");
		system("CLS");
		return IS_USER;
	}
	else if (NOT_FOUND == Person::isUser(name, pass))
	{
		*Ptr_name = name;
		cout << "\nWorng user name\nAccess Aborted...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
	}
	return NOT_FOUND;
}
string Person::getUserName()
{
	return user_name;
}
int Person::getIndex(string name)
{
	int i = 0;
	while (i < NUMBER_OF_USERS && user_list[i] != NOT_INITIALIZED && name != user_list[i])
	{
		i++;
	}
	if (user_list[i] == name)
	{
		return i;
	}
	else
	{
		return NOT_FOUND;
	}
}
string Person::getPassword()
{
	return password;
}
void Person::DisplayRentedCars(Car* Ptr_Car)
{
	int i, flag = 0;
	for (i = 0; i < NUMBER_OF_USERS; i++)
	{
		if (Rental_list[i] != UNINTILAZED)
		{
			if (0 == flag)
			{
				cout << "List of Rented Cars:\n";
				flag = 1;
			}
			cout << "User: " << user_list[i] << " Rented " << endl;
			(Ptr_Car + Rental_list[i])->Display();
		}
	}
	if (0 == flag)
	{
		cout << "All Cars Are Avialble There is No Rented Cars" << endl;
	}
}
int Person::isAdmin(string user, string pass)
{
	if (user == user_admin && pass == pass_admin)
	{
		return TRUE;
	}
	return FALSE;
}
void Person::rent_car(string user, int car_index)
{
	int i = 0;
	while (i < NUMBER_OF_USERS && user_list[i] != NOT_INITIALIZED && user != user_list[i])
	{
		i++;
	}
	if (user_list[i] == user)
	{
		Rental_list[i] = car_index;
	}
	else
	{
		cout << "USER NAME NOT FOUND!" << endl;
	}
}
Person::Person():customer_index(customer_counter)
{
}