#include <iostream>
#include "Depot.h"

// Menu captions
const char *menu[10] = {
	"bool loadDataFromCSV(std::string path);",
	"void AddCar();",
	"void AddTrain();",
	"void RemoveVehicle(int id);",
	"void ShowAll();",

	// Database menus
	"CVehicle* FindCheapest(int weight, int dist);",
	"std::list< CVehicle*> SQL(const char *field, const char * cond, const char* value);",
	"void ShowRecordSet(std::list<CVehicle*> rs);",
	"CVehicle* VehiclesAvailable(double weight, double dist, double cost);",
	"void ChangeCostPerMile(int id, double newcost);"
};

void main() {
	CDepot depot("Input.csv");

	depot.ShowAll();


	system("pause");
}