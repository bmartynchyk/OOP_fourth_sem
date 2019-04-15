#include <iostream>
#include "Depot.h"

using namespace std;

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

	depot.RemoveVehicle(1);
	depot.ShowAll();
	system("pause");

	cout << "\n\n";
	CVehicle* car = depot.AddCar(1, "Renault", 9000, 32.5, 68, 450);
	//depot.AddTrain(4, "Opel", 12, 12, 14);

	if (depot.AddTrain(4, "Diesel", 125000, 12, 75))
		cout << "Added succesfully!\n";

	depot.ShowAll();
	system("pause");
}