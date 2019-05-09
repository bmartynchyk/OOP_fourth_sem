
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
		std::regex reg("[A-z ]{0,32}");
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
//<id>;<vehicle type>;<make/type>;<load capacity>;<cost per mile>;<average speed>;<max distance/nope>
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

		while (!file.eof()) {
			file.getline(str, WSIZE, ';'); // Getting Id
			id = atoi(str);
			file.getline(str, WSIZE, ';'); // Getting vehicle type
			vehicle_type = atoi(str);
			file.getline(str, WSIZE, ';'); // Getting manufacturer for truck or type for train
			make_type = str;
			file.getline(str, WSIZE, ';'); // Getting load capacity
			capacity = atof(str);
			file.getline(str, WSIZE, ';'); // Getting cost per mile
			cost_per_mile = atof(str);

			if (1 == vehicle_type) { // Checking if this record is the last one
				file.getline(str, WSIZE, '\n'); // Getting average speed
				avr_speed = atof(str);
			}
			else {
				file.getline(str, WSIZE, ';'); // Getting average speed
				avr_speed = atof(str);
				file.getline(str, WSIZE, '\n'); // Getting max distance for car
				max_dist = atoi(str);
			}

			// Perform errors
			if (!DataIsCorrect(id, make_type, capacity, cost_per_mile, avr_speed)) {
				std::cerr << "ERROR: object: [" << id << "; " << vehicle_type << "; " <<
					make_type << "; " << capacity << "; " << cost_per_mile << "; " <<
					avr_speed << "] is incorrect!\n";
				continue;
			}
			else if (0 >= max_dist) {
				std::cerr << "ERROR: the value 'max_dist' for car should be > 0!\n";
				std::cerr << "ERROR: object: [" << id << "; " << vehicle_type << "; " <<
					make_type << "; " << capacity << "; " << cost_per_mile << "; " <<
					avr_speed << "] is incorrect!\n";
				continue;
			}

			if (0 == vehicle_type) vehicles.push_back(new CCar(id, make_type, capacity, 
				cost_per_mile, avr_speed, max_dist));
			else vehicles.push_back(new CTrain(id, make_type, capacity,
				cost_per_mile, avr_speed));
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
			
		vehicle = new CCar(id, make, capacity, cost_per_mile, avr_speed, max_dist);
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

		vehicle = new CTrain(id, type, capacity, cost_per_mile, avr_speed);
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
	// auto - std::list<CVehicle*>::iterator
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

CVehicle *CDepot::FindCheapest(int weight, int dist) {
	try {
		std::list<CVehicle*>::iterator cheapest = vehicles.begin();
		int cost = 0;

		// Initialization of cheapest vehicle
		for (auto itr : vehicles)
			// 'CalculateCost' will check the validity of such weight and distance for 
			//vehicles. In bad case 'CalculateCost' returns -1.
			if (itr->CalculateCost(weight, dist) != -1) {
				*cheapest = itr; // Initialization
				break;
			}

		// If cheapest vehicle is not initialized with the correct value, then there is
		//no point in continuing to search for the chepest vehicle.
		if ((*cheapest)->CalculateCost(weight, dist) == -1) return nullptr;

		// Trying to find cheapest vehicle
		for (auto itr = cheapest; itr != vehicles.end(); ++itr) {
			if ((cost = (*itr)->CalculateCost(weight, dist)) == -1) continue;
			if ((*cheapest)->CalculateCost(weight, dist) > cost) cheapest = itr;
		}

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
std::list<CVehicle*> CDepot::SQL(const char * field, const char * cond , const char * value) {
	try {
		std::list<CVehicle*> res;
		std::regex reg("(\\d+)|(\\d+\\.\\d+)"); // Regular expression for checking number format

		//Check if parameter 'value' in format <digits>.<at least one digit>
		if (!std::regex_match(value, reg))
			throw "'value' is not integer or float number(examples: 10.21, 43, 97.0)!";
		if (!strstr(cond, "ge") && !strstr(cond, "le"))
			throw "incorect parameter 'cond'(should be 'ge' or 'le')!";
		if (strstr(field, "average_speed")) comparator = &CDepot::CmpByAvrSpeed;
		else if (strstr(field, "max_distance")) comparator = &CDepot::CmpByMaxDist;
		else throw "incorect parameter 'field'(should be 'average_speed' or 'max_distance')!";

		for (auto obj : vehicles)
			// If function 'strstr' finds a substring "ge"(>=) in 'cond' it means
			//true(>=) by default, else - false(<=) or selected "le"(<=).
			if ((this->*comparator)(obj, value, strstr(cond, "ge"))) res.push_back(obj);

		return res;
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return std::list<CVehicle*>();
	}
}

// Outputs rescords set 'rs'
void CDepot::ShowRecordSet(std::list<CVehicle*> rs) {
	if (rs.empty()) return;
	for (auto itr : rs) itr->Display();
}

// Returns all available vehicles
std::list<CVehicle*> CDepot::VehiclesAvailable(double weight, double dist, double cost) {
	try {
		std::list<CVehicle*> res;

		for (auto obj : vehicles)
			if (cost >= obj->CalculateCost(weight, dist)) res.push_back(obj);

		return res;
	}
	catch (char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return std::list<CVehicle*>();
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


// P R I V A T E   M E T H O D S

// Compares object by 'average_speed' with '_val'. If 'obj' is CTrain or
//CCar - comparing.
bool CDepot::CmpByAvrSpeed(CVehicle *obj, const char *_val, bool cond) {
	double val = atof(_val);

	if (CTrain *train = dynamic_cast<CTrain*>(obj)) {
		if (train->GetAvrSpeed() >= val && cond) return true;
		if (train->GetAvrSpeed() <= val && !cond) return true;
	}
	else if (CCar *car = dynamic_cast<CCar*>(obj)) {
		if (car->GetAvrSpeed() >= val && cond) return true;
		if (car->GetAvrSpeed() <= val && !cond) return true;
	}

	return false;
}

// Compares object by 'max_distance' with '_val'. If 'obj' is CCar - comparing,
//if 'obj' is CTrain - return false because CTrain has no field 'max_distance'.
bool CDepot::CmpByMaxDist(CVehicle *obj, const char *_val, bool cond) {
	double val = atoi(_val);

	if (dynamic_cast<CTrain*>(obj)) return false;
	else if (CCar *car = dynamic_cast<CCar*>(obj)) {
		if (car->GetMaxDist() >= val && cond) return true;
		if (car->GetMaxDist() <= val && !cond) return true;
	}

	return false;
}