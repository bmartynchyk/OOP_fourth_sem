
#ifndef _DEPOT_H_
#define _DEPOT_H_

#include <list>
#include "Vehicles.h"

//The class which contains vehicles
class CDepot {

public:
	bool loadDataFromCSV(std::string path);
	void AddCar();
	void AddTrain();
	void RemoveVehicle(int id);
	void ShowAll();

	// Database functions
	CVehicle* FindCheapest(int weight, int dist);
	std::list< CVehicle*> SQL(const char *field, const char * cond, const char* value);
	void ShowRecordSet(std::list<CVehicle*> rs);
	CVehicle* VehiclesAvailable(double weight, double dist, double cost);
	void ChangeCostPerMile(int id, double newcost);

private:
	std::list< CVehicle *> vehicles;
};

#endif // !_DEPOT_H_