
#include <iostream>
#include <fstream>
#include "Depot.h"

#include <algorithm>
#include <typeinfo>
#include <regex>

#define WSIZE 32


// C O N S T R U C T O R S
CDepot::CDepot(std::string file_path) {
	loadDataFromCSV(file_path);
}


// P R I V A T E   M E T H O D S

bool CDepot::DataIsCorrect(int id, std::string make_type, double capacity, double cost_per_mile,
	double avr_speed) {
	try {
		if (!IdIsUnique(id)) throw "vehicle with such id already exist!";
		if (0 >= capacity) throw "the value 'capacity' > 0 for all vehicles!";
		if (0 >= cost_per_mile) throw "the value 'cost_per_mile' > 0 for all vehicles!";
		if (0 >= avr_speed) throw "the value 'avr_speed' > 0 for all vehicles!";

		// Detecting whether the string 'make_type' has inappropriate expression by using
		//regular expressions
		std::regex reg("[A-z]{0,32}");
		if (!std::regex_match(make_type, reg))
			throw "'make'/'type' has inappropriate expression(sould be < 32 characters)!";

		return true;
	}
	catch (const char *mes){
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

// true - if id is unique, otherwise returns false
bool CDepot::IdIsUnique(int id){
	for (auto itr : vehicles)
		if (itr->GetId() == id) return false;

	return true;
}


// P U B L I C   M E T H O D S

//	Input file should has next structure in each row:
//<id>;<vehicle type>;<make/type>;<load capacity>;<cost per mile>;<everage speed>;<max distance/nope>
//	In case if we has truck so in this case in we look at third position as  make(manufacturer), 
//in last position - max distance. In case if we have train third position is type of train, and 
//last position - ebsent.
bool CDepot::loadDataFromCSV(std::string path) {
	try {
		if (path.empty()) throw "path string is empty!";
		
		std::ifstream file(path); // Checking the path string
		if (!file.is_open()) throw "seems like path string is incorrect!";

		// If call this function and list 'vehicles' contains data, If call this function and list 
		//'vehicles' contains data, so this function clears list and upload new data from file.
		if (!vehicles.empty()) {
			vehicles.clear();
			std::cout << "WARNING: list wasn't empty - old data removed and new uploaded from file!\n";
		}

		// Declaration variables
		int vehicle_type = 0, id = 0, max_dist = 0;
		double avr_speed = 0, capacity = 0, cost_per_mile = 0;
		std::string make_type; // Manufacturer or type of train
		char str[WSIZE]; // String for extracting content from input file
		CVehicle *new_vehicle = nullptr; // Pointer to base vehicle class

		while (!file.eof()) {
			file.getline(str, WSIZE, ';'); // Getting Id
			id = atoi(str);
			file.getline(str, WSIZE, ';'); // Getting vehicle type
			vehicle_type = atoi(str);
			file.getline(str, WSIZE, ';'); // Getting manufacturer of truck or type of train
			make_type = str;
			file.getline(str, WSIZE, ';'); // Getting average speed
			avr_speed = atof(str);
			file.getline(str, WSIZE, ';'); // Getting load capacity
			capacity = atof(str);

			if (1 == vehicle_type) { // Checking if it is the last one
				file.getline(str, WSIZE, '\n'); // Getting cost per mile
				cost_per_mile = atof(str);
			}
			else {
				file.getline(str, WSIZE, ';'); // Getting cost per mile
				cost_per_mile = atof(str);
				file.getline(str, WSIZE, '\n'); // Getting max distance for car
				max_dist = atoi(str);
			}

			if (!DataIsCorrect(id, make_type, avr_speed, capacity, cost_per_mile)) {
				std::cerr << "ERROR: object: [" << id << ";" << vehicle_type << ";" <<
					make_type << ";" << capacity << ";" << avr_speed << ";" << 
					cost_per_mile << "] is incorrect!\n";
				continue;
			}

			// If it is CCar call proper constructor
			if (0 == vehicle_type) new_vehicle = new CCar(id, vehicle_type, make_type, avr_speed,
				capacity, cost_per_mile, max_dist);
			else new_vehicle = new CTrain(id, vehicle_type, make_type, avr_speed,
				capacity, cost_per_mile);

			vehicles.push_back(new_vehicle);
		}
	}
	catch(const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

CVehicle* CDepot::AddCar(int id, std::string make, double capacity, double cost_per_mile, 
	double avr_speed, int max_dist) {
	try {
		CVehicle *vehicle = nullptr;

		if (!DataIsCorrect(id, make, capacity, cost_per_mile, avr_speed))
			throw "correct your inputting data please!";
		if (0 >= max_dist) throw "the value 'max_dist' should be > 0 for car!";
			
		vehicle = new CCar(id, 0, make, avr_speed, cost_per_mile, capacity, max_dist);
		if (nullptr == vehicle) throw "cannot creating the object 'CCar'!";

		vehicles.push_back(vehicle);
		return vehicle;
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return nullptr;
	}
}

CVehicle* CDepot::AddTrain(int id, std::string type, double capacity, double cost_per_mile,
	double avr_speed) {
	try {
		CVehicle *vehicle = nullptr;

		if (!DataIsCorrect(id, type, capacity, cost_per_mile, avr_speed))
			throw "correct your inputting data please!";

		vehicle = new CTrain(id, 0, type, avr_speed, cost_per_mile, capacity);
		if (nullptr == vehicle) throw "cannot creating the object 'CTrain'!";

		vehicles.push_back(vehicle);
		return vehicle;
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return nullptr;
	}
}

bool CDepot::RemoveVehicle(int id) {
	for (auto i = vehicles.begin(); i != vehicles.end(); ++i)
		if ((*i)->GetId() == id) {
			vehicles.erase(i);
			return true;
		}

	return false;
}

void CDepot::ShowAll() {
	for (auto itr : vehicles) itr->Display();
}

//
// Database methods
//

CVehicle *CDepot::FindCheapest(int weight, int dist) {
	try {
		std::list<CVehicle*>::iterator cheapest = vehicles.begin();

		for (auto itr : vehicles)
			if ((*cheapest)->CalculateCost(weight, dist) > itr->CalculateCost(weight, dist))
				*cheapest = itr;

		//std::list<CVehicle*> res;
		//res.push_back(*cheapest);

		//std::cout << "\n\nThe cheapest:\n";
		//ShowRecordSet(res);

		return *cheapest;
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return nullptr;
	}
}

// Returns a list of records matching the selection criteria. Variable 'field' can take:
//'average_speed', 'max_distance'. Variable 'cond' can take values: 'le'(less or equal), 'ge'
//(greater or equal). Variable 'value' - is value of corresponding field.
std::list<CVehicle*> CDepot::SQL(const char * field, const char * cond, const char * value) {
	try {
		std::list<CVehicle*> res;

		return res;
	} //!!
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return std::list<CVehicle*>();
	}
}

// Outputs rescords set 'rs'
void CDepot::ShowRecordSet(std::list<CVehicle*> rs) {
	for (auto itr : rs) itr->Display();
}

// Returns all available vehicles
CVehicle *CDepot::VehiclesAvailable(double weight, double dist, double cost) {
	try {
		// The trucs in which 'dist' > 'max_dist' should be excepted

		//1) Check in abs class if 'weight' and 'cost' approach
		//2) If not then go to next vehicle
		//3) If it approachs then
		//4) Make dynamic_cast to proper class
		//5) If it is CTrain then push it into result list
		//6) If it is CCar then compare 'dist' > 'max_dist'
		//7) If true - push into result list, false - go to next vehicle
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return nullptr;
	}
}

void CDepot::ChangeCostPerMile(int id, double newcost) {
	try {
		if (0 >= newcost) throw "the value 'newcost' > 0 for all vehicles!";
		if (IdIsUnique(id)) throw "the vehicle with such id is not exist!";

		for (auto itr : vehicles)
			if (itr->GetId() == id) {
				itr->SetCostPerMile(newcost);
				break;
			}
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
	}
}