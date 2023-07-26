#include "Car.h"
Car::Car() :manufacturer("UNINTIALIZED"), color("UNINTIALIZED"), power_train_type("UNINTIALIZED"), transmission("UNINTIALIZED"), model_year(0), rent_fees(0), index(car_count), avilable(0)
{
	if (0 == car_count)
	{
		Car::intilize_list();
	}
	if(car_count < NUMBER_OF_CARS)
	{
		counter[index] = 1;
		car_count++;
	}
	else
	{
		cout << "MAXIMUM CAR NUMBER REATCHED!" << endl;
	}
}
int Car::rentCar()
{
	if (avilable > 0)
	{
		avilable--;
		return SUCCESS;
	}
	else
	{
		return FAILD;
	}
}
Car::Car(int manufacturer_index, int color_index, int power_train_index, int transmission_index, int mdl, int rntFeez):model_year(mdl), rent_fees(rntFeez)
{
	Car::setColor(color_index);
	Car::setManufacturer(manufacturer_index);
	Car::setTransmission(transmission_index);
	Car::setPowerTrainType(power_train_index);
	if (0 == car_count)
	{
		Car::intilize_list();
	}
	index = car_count;
	counter[index] = 1;
	car_count++;
}
void Car::editCar(int manufacturer_index, int color_index, int power_train_index, int transmission_index, int mdl, int rntFeez)
{
	Car::setColor(color_index);
	Car::setManufacturer(manufacturer_index);
	Car::setTransmission(transmission_index);
	Car::setPowerTrainType(power_train_index);
	avilable = 1;
	model_year = mdl;
	rent_fees = rntFeez;
}
int Car::counter[] = {-1};
string Car::arr_manufacturer[] = { "Tesla", "BMW", "Audi", "KIA", "Mercedes", "Ford", "Honda", "Nissan", "Chevrolet", "Volvo", "Skoda", "Hyundai", "Tata", "Jeep", "Lada", "Porche", "Aston Martin", "Ferrari", "Bentley", "Lamborgini"};
string Car::arr_color[] = { "Yellow","Black","Red","Brown","Blue","Silver","Balck","Grey","Red" };
string Car::arr_transmission[] = { "Automatic" , "Manual" };
string Car::arr_power_train_type[] = { "Electric","Hybird", "Gas", "Desiel"};
Car* Car::ptr_list[] = { NULL };
int Car::car_count = 0;
void Car::intilize_list()
{
	int i;
	for (i = 0; i < NUMBER_OF_CARS; i++)
	{
		counter[i] = -1;
	}
}

void Car::setManufacturer(int Manufacturer_index)
{

	manufacturer = arr_manufacturer[Manufacturer_index % NUMBER_OF_CARS];	
}
void Car::setColor(int color_index)
{
	color = arr_color[color_index % NUMBER_OF_COLORS];
}
void Car::setPowerTrainType(int power_train_index)
{
	power_train_type = arr_power_train_type[power_train_index % NUMBER_OF_POWER_TRAIN_TYPES];
}
void Car::setTransmission(int transmission_index)
{
	transmission = arr_transmission [transmission_index % NUMBER_OF_TRANSIMISSIONS];
}
void Car::setModelYear(int mdl)
{
	model_year = mdl;
}
string Car::getManufacturer()
{
	return manufacturer;
}
string Car::getColor()
{
	return color;
}
string Car::getPowerTrainType()
{
	return power_train_type;
}
string Car::getTransmission()
{
	return transmission;
}
int Car::getModelYear()
{
	return model_year;
}
int Car::getIndex()
{
	return index;
}
void Car::Display()
{
	cout<< "Car No." << index + 1 << " is a/an " << color << " " << manufacturer << " and it is a/an " << power_train_type << " car, Has a/an " << transmission << " Transmission, Model year is: " << model_year << " Rent fees is: " << rent_fees << " per day" << endl;
}
void Car::Display_Avilable_Cars(Car* ptr)
{
	int i;
	for (i = 0; i < NUMBER_OF_CARS; i++)
	{
		if ((ptr + i)->IsAvailable() == TRUE)
		{
			(ptr + i)->Display();
		}
	}
}
int Car::getCarCount()
{
	return car_count;
}

int Car::IsAvailable()
{
	return avilable;
}