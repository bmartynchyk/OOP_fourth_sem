
#include "Depot.h"

bool CDepot::loadDataFromCSV(std::string path) {
	return false;
}

void CDepot::AddCar() {

}

void CDepot::AddTrain() {
}

void CDepot::RemoveVehicle(int id) {
}

void CDepot::ShowAll() {
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