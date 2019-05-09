/***************************************************************************************************
* File:          Depot.h
* Synopsis:      declaration of methods, constructors of class CDepot. Forms module with file 
* Depot.cpp.
* Related files: Depot.cpp
* Author:        Bohdan Martynchyk KV-74
* Written:       12/04/2019
* Last modified: 08/05/2019
* Source:        https://github.com/bmartynchyk/OOP_fourth_sem
***************************************************************************************************/

#ifndef _DEPOT_H_
#define _DEPOT_H_

#include <list>
#include "Vehicles.h"

//The class which contains vehicles
class CDepot {
private:
	bool IdIsUnique(int id);
	bool DataIsCorrect(int id, std::string make_type, double capacity, double cost_per_mile,
		double avr_speed);

	// Two methods for comparing values in 'SQL' method
	bool CmpByAvrSpeed(CVehicle *obj, const char *_val, bool cond);
	bool CmpByMaxDist(CVehicle *obj, const char *_val, bool cond);
	
	// Pointer to class member function for 'SQL' method
	bool(CDepot::*comparator)(CVehicle *obj, const char *_val, bool cond);

public:

	// Constructors
	CDepot(std:: string file_path);

	// Methods
	bool loadDataFromCSV(std::string path);
	CVehicle* AddCar(int id, std::string make, double capacity, double cost_per_mile, double avr_speed,
		int max_dist);
	CVehicle* AddTrain(int id, std::string type, double capacity, double cost_per_mile,
		double avr_speed);
	bool RemoveVehicle(int id);
	void ShowAll();

	// Database methods
	CVehicle* FindCheapest(int weight, int dist);

	// Returns list of records that satisfy the specified conditions.
	//'field' - can take value 'average_speed' or  'max_distance';
	//'cond' - can take value 'le'(less or equal) or 'ge'(greater or equal)
	//'value' - the value of required field
	std::list<CVehicle*> SQL(const char *field, const char * cond, const char* value);

	// Prints list, which returns method 'SQL'. For example:
	//list<CVehicle*> rs = depot.SQL(“max_distance”, “ge”, “500”);
	//depot.ShowRecordSet(rs);
	void ShowRecordSet(std::list<CVehicle*> rs);
	std::list<CVehicle*> VehiclesAvailable(double weight, double dist, double cost);
	void ChangeCostPerMile(int id, double newcost);

private:
	std::list<CVehicle *> vehicles;
};

#endif // !_DEPOT_H_