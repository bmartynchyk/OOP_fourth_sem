#include <iostream>
#include "Depot.h"

using namespace std;


void main() {
	
	// TEST 1
	/*CDepot depot("Input.csv");
	cout << "We reseive warning about non-empty list!\n";
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
	/*CDepot depot("Input.csv");
	std::list<CVehicle*> res;
	depot.ShowAll();
	CVehicle *veh = depot.FindCheapest(7001, 44);
	if (nullptr != veh) res.push_back(veh);
	cout << "\n\nCheapest:\n";
	depot.ShowRecordSet(res);*/

	// TEST 5
	/*CDepot depot("Input.csv");
	depot.ChangeCostPerMile(2, 11.11);
	depot.ShowAll();*/

	// TEST 6
	// If selected field 'max_distance' all 'CTtain' objects will be skipped because of they
	//have no such field
	/*CDepot depot("Input.csv");
	string field = "average_speed", cond = "ge", value = "55";
	depot.ShowAll();
	cout << "\n\nSELECT vehicles with params: [" << field << ", " << cond << ", "  << value << "]:\n";
	depot.ShowRecordSet(depot.SQL(field.c_str(), cond.c_str(), value.c_str()));*/

	//TEST 7
	/*CDepot depot("Input.csv");
	double weight = 8, distance = 45, cost = 4000;
	depot.ShowAll();
	cout << "\n\nAvailable Vehicles:\n";
	depot.ShowRecordSet(depot.VehiclesAvailable(weight, distance, cost));*/

	system("pause");
}