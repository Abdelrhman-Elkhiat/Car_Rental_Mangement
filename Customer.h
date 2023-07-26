#pragma once
#include "Person.h"
class Customer :public Person
{
private:
public:
		 Customer();
	void addCustomer();
	void setUserName(string user);
	void setPassword(string pass);
	void addCustomer(string user, string pass);
};

