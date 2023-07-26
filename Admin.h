#pragma once
#include "Person.h"
class Admin : public Person
{
public:
		 Admin();
	void addCustomer();
	     Admin(string user, string pass);
	void addCustomer(string user, string pass);
	void setUserName(string user);
	void setPassword(string pass);
};

