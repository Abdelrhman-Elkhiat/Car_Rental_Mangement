#pragma once
#include<iostream>
using namespace std;
#define NUMBER_OF_CARS 20
#define NUMBER_OF_COLORS 9
#define NUMBER_OF_TRANSIMISSIONS 2
#define NUMBER_OF_POWER_TRAIN_TYPES 4
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILD 0
class Car
{
private:
	string manufacturer;
	string color;
	string power_train_type;
	string transmission;
	int model_year;
	int rent_fees;
	int index;
	int avilable;
	static int car_count;
	static Car* ptr_list[NUMBER_OF_CARS];
	static int counter[NUMBER_OF_CARS];
	static string arr_color[NUMBER_OF_COLORS];
	static string arr_manufacturer[NUMBER_OF_CARS];
	static string arr_transmission[NUMBER_OF_TRANSIMISSIONS];
	static string arr_power_train_type[NUMBER_OF_POWER_TRAIN_TYPES];
public:
			Car();
	int		rentCar();
	int		getIndex();
	void	Display();
	string	getColor();
	int		getModelYear();
	int		getCarCount();
	int		IsAvailable();
	void	intilize_list();
	string	getManufacturer();
	string	getTransmission();
	void	setModelYear(int mdl);
	string	getPowerTrainType();
	void	setColor(int color_index);
	void	Display_Avilable_Cars(Car* ptr);
	void	setTransmission(int transmission_index);
	void	setManufacturer(int Manufacturer_index);
	void	setPowerTrainType(int power_train_index);
			Car(int manufacturer_index, int color_index, int power_train_index, int transmission_index, int mdl, int rntFeez);
	void	editCar(int manufacturer_index, int color_index, int power_train_index, int transmission_index, int mdl, int rntFeez);
};

