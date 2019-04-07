
#include <iostream>
#include <fstream>
#include "Depot.h"

#include <algorithm>
#include <typeinfo>

#define WSIZE 32

// C O N S T R U C T O R S
CDepot::CDepot(std::string file_path) {
	loadDataFromCSV(file_path);
}


// M E T H O D S

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

		// Declaration variables
		int vehicle_type = 0, id = 0, max_dist = 0;
		double avr_speed = 0, capacity = 0, cost_per_mile = 0;
		std::string make_type; // Manufacturer or type of train
		char str[WSIZE]; // String for extracting content from input file
		CVehicle *new_vehicle; // Pointer to base vehicle class

		while (!file.eof()) {
			file.getline(str, WSIZE, ';'); // Getting Id
			id = atoi(str);
			//std::cout << "1) " << str << "\n";

			file.getline(str, WSIZE, ';'); // Getting vehicle type
			vehicle_type = atoi(str);
			//std::cout << "2) " << str << "\n";

			file.getline(str, WSIZE, ';'); // Getting manufacturer of truck or type of train
			make_type = str;
			//std::cout << "3) " << str << "\n";

			file.getline(str, WSIZE, ';'); // Getting average speed
			avr_speed = atof(str);
			//std::cout << "4) " << str << "\n";

			file.getline(str, WSIZE, ';'); // Getting load capacity
			capacity = atof(str);
			//std::cout << "5) " << str << "\n";

			if (1 == vehicle_type) { // Checking if it is the last one
				file.getline(str, WSIZE, '\n'); // Getting cost per mile
				cost_per_mile = atof(str);

				//std::cout << "6) " << str << "\n";
				new_vehicle = new CTrain(id, vehicle_type, make_type, avr_speed, capacity,
					cost_per_mile);
			}
			else {
				file.getline(str, WSIZE, ';'); // Getting cost per mile
				cost_per_mile = atof(str);
				//std::cout << "6) " << str << "\n";
				file.getline(str, WSIZE, '\n'); // Getting max distance for car
				max_dist = atoi(str);
				//std::cout << "7) " << str << "\n";

				new_vehicle = new CCar(id, vehicle_type, make_type, avr_speed, capacity,
					cost_per_mile, max_dist);
			}

			//new_vehicle = new CTrain(id, vehicle_type, str, avr_speed, capacity, cost_per_mile);
			vehicles.push_back(new_vehicle);

			//std::cout << std::endl;
		}
	}
	catch(const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

void CDepot::AddCar() {

}

void CDepot::AddTrain() {
}

void CDepot::RemoveVehicle(int id) {
}

void CDepot::ShowAll() {

	for (auto itr : vehicles) {
		itr->Display();
	}

}

//
// Database methods
//

CVehicle *CDepot::FindCheapest(int weight, int dist) {
	return nullptr;
}

std::list<CVehicle*> CDepot::SQL(const char * field, const char * cond, const char * value) {

	return std::list<CVehicle*>();
}

void CDepot::ShowRecordSet(std::list<CVehicle*> rs) {

}

CVehicle *CDepot::VehiclesAvailable(double weight, double dist, double cost) {

	return nullptr;
}

void CDepot::ChangeCostPerMile(int id, double newcost) {

}


//CVehicle *civ;
//CCar *car = new CCar();
//CTrain *train = new CTrain();
//CCar *cr = nullptr;

//civ = car;

//vehicles.push_back(civ);
//vehicles.push_back(train);
//vehicles.push_back(car);


//civ = vehicles.pop_back();

//CVehicle *ci = vehicles.pop_back();

//CCar *crr = dynamic_cast<CCar *>(vehicles.pop_back());


//civ = dynamic_cast vehicles.pop_back();
//return true;