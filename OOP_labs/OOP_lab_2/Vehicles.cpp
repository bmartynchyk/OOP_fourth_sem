
#include "Vehicles.h"

// Base class implementation
CVehicle::CVehicle() : v_type(0), id(0), average_speed(0),
load_capacity(0), cost_per_mile(0) { }

int CVehicle::GetId() { return id; }


// Derived class implementation
// CCar class implementation

void CCar::Display() {

}

double CCar::CalculateCost(int weight, int dist) {
	return 0.0;
}

double CCar::CalculateTime(int dist) {
	return 0.0;
}

//!!
int CCar::GetId() { return 0; }

// CTrain class implementation

void CTrain::Display() {

}

double CTrain::CalculateCost(int weight, int dist) {
	return 0.0;
}

double CTrain::CalculateTime(int dist) {
	return 0.0;
}

//!!
int CTrain::GetId() { return 0; }