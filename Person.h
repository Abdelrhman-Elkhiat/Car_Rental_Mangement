#pragma once
#include<iostream>
#include <conio.h>
#include<cstdlib>
#include"Car.h"
using namespace std;
#define NUMBER_OF_USERS 10
#define NOT_INITIALIZED "UNINITILIZED" 
#define UNINTILAZED -1
#define TRUE 1
#define FALSE 0
#define IS_ADMIN 20
#define IS_USER 1
#define NOT_FOUND -1
#define WRONG_PASSWORD -2
#define NUMBER_OF_TRIALS 3
class Person
{
protected:
	string user_name;
	string password;
	int customer_index;
	static int customer_counter;
	static string user_list[NUMBER_OF_USERS];
	static string pass_list[NUMBER_OF_USERS];
	static int Rental_list[NUMBER_OF_USERS];
	static string user_admin;
	static string pass_admin;
	void			intilize_list();
public:
					Person();
	string			getPassword();
	string			getUserName();
	int				getIndex(string name);
	virtual void	addCustomer() = 0;
	int				login(string* Ptr_name);
	void			DisplayRentedCars(Car* Ptr_Car);
	int				isUser(string user, string pass);
	int				isAdmin(string user, string pass);
	virtual void	setUserName(string user) = 0;
	virtual void	setPassword(string pass) = 0;
	void			rent_car(string user, int car_index);
	virtual void	addCustomer(string user, string pass) = 0;
};

