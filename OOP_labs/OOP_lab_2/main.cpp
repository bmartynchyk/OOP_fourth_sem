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
	
	// TEST 1
	/*CDepot depot("Input2.csv");
	CVehicle* car = depot.AddCar(5, "Renault", 9000, 32.5, 68, 450);
	depot.ShowAll();
	depot.loadDataFromCSV("Input.csv");
	depot.ShowAll();*/

	// TEST 2
	/*CDepot depot("Input.csv");
	depot.ShowAll();

	if (depot.AddCar(5, "Renault", 9000, 32.5, 68, 450)) cout << "\nAdding completed successfully!\n";
	else cout << "\nAdding failed!\n";
	depot.ShowAll();
	cout << "\n\n";

	if (depot.AddTrain(6, "Electrical", 18000, 33.5, 55)) cout << "Adding completed successfully!\n";
	else cout << "Adding failed!\n";
	depot.ShowAll();*/

	// TEST 3
	/*CDepot depot("Input.csv");
	cout << "Before deleting:\n";
	depot.ShowAll();
	cout << "\n\n";
	if (depot.RemoveVehicle(3)) cout << "Successfully removed!\n";
	cout << "\nAfter deleting:\n";
	depot.ShowAll();*/

	// TEST 4
	CDepot depot("Input.csv");
	std::list<CVehicle*> res;
	depot.ShowAll();
	CVehicle *veh = depot.FindCheapest(1, 8001);
	res.push_back(veh);
	cout << "\n\nCheapest:\n";
	depot.ShowRecordSet(res);

	//depot.ChangeCostPerMile(0, 12.12);
	//if (depot.AddTrain(4, "Diesel", 125000, 12, 75))
	//	cout << "Added succesfully!\n";

	system("pause");
}