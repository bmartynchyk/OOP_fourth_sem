
#ifndef _DEPOT_H_
#define _DEPOT_H_

#include <list>
#include "Vehicles.h"

//The class which contains vehicles
class CDepot {
public:

	// Constructors
	CDepot(std:: string file_path);

	// Methods
	bool loadDataFromCSV(std::string path);
	void AddCar();
	void AddTrain();
	void RemoveVehicle(int id);
	void ShowAll();

	// Database methods
	CVehicle* FindCheapest(int weight, int dist);

	// Returns list of records that satisfy the specified conditions. 
	//'field' - can take value 'average_speed' or  'max_distance';
	//'cond' - can take value 'le'(less or equal) or 'ge'(greater or equal)
	//'value' - the value of required field
	std::list< CVehicle*> SQL(const char *field, const char * cond, const char* value);

	// Prints list, which returns method 'SQL'. For example:
	//list<CVehicle*> rs = depot.SQL(“max_distance”, “ge”, “500”);
	//depot.ShowRecordSet(rs);
	void ShowRecordSet(std::list<CVehicle*> rs);
	CVehicle* VehiclesAvailable(double weight, double dist, double cost);
	void ChangeCostPerMile(int id, double newcost);

private:
	std::list< CVehicle *> vehicles;
};

#endif // !_DEPOT_H_