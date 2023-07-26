#include "Admin.h"

Admin::Admin()
{
	Person::user_admin = "admin";
	Person::pass_admin = "admin";
}

Admin::Admin(string user, string pass)
{
	Person::user_admin = user;
	Person::pass_admin = pass;
}
void Admin::addCustomer()
{
	if (0 == customer_counter)
	{
		intilize_list();
		user_name = "user";
		password = "pass";
		user_list[customer_counter] = "user";
		pass_list[customer_counter] = "pass";
		customer_counter++;
	}
	else
	{
		cout << "default user already created!\nusername: user, password: pass";
	}
}

void Admin::addCustomer(string user, string pass)
{
	if (customer_counter < NUMBER_OF_USERS)
	{
		user_name = user;
		password = pass;
		user_list[customer_counter] = user_name;
		pass_list[customer_counter] = password;
		customer_counter++;
	}
	else
	{
		cout << "MAXIMUM NUMBER OF USERS REACHED!";
	}
}

void Admin::setUserName(string user)
{
	user_name = user;
	user_admin = user;
}

void Admin::setPassword(string pass)
{
	password = pass;
	pass_admin = pass;
}