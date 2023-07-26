#include "Customer.h"
Customer::Customer()
{
Customer:addCustomer();
}
void Customer::addCustomer(string user, string pass)
{
	if (customer_counter < NUMBER_OF_USERS)
	{
		customer_index = customer_counter;
		customer_counter++;
		user_name = user;
		password = pass;
		user_list[customer_index] = user_name;
		pass_list[customer_index] = password;
	}
	else
	{
		cout << "MAXIMUM NUMBER OF USERS REACHED!";
	}
}
void Customer::addCustomer()
{
	if (0 == customer_counter)
	{
		intilize_list();
		user_name = "user";
		password = "pass";
		customer_index = customer_counter;
		customer_counter++;
		user_list[customer_index] = "user";
		pass_list[customer_index] = "pass";
	}
	else
	{
		cout << "default user already created!\nusername: user, password: pass";
	}
}
void Customer::setUserName(string user)
{
	user_name = user;
	user_list[customer_index] = user;
}

void Customer::setPassword(string pass)
{
	password = pass;
	pass_list[customer_index] = pass;
}


