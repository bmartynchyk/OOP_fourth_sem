

#include <iostream>
#include <cstring>
#include "Vehicles.h"


//
// B A S E   C L A S S   I M P L E M E N T A T I O N
//


// Constructors
CVehicle::CVehicle() : id(0), v_type(0), avr_speed(0), capacity(0), cost_per_mile(0) { }

CVehicle::CVehicle(int _id, int _v_type, double _avr_speed, double _capacity, double _cost_per_mile) :
	avr_speed(_avr_speed), capacity(_capacity), cost_per_mile(_cost_per_mile),
	id(_id), v_type(_v_type) { };


// Methods
int CVehicle::GetId() { return id; }

//
// D E R I V E D   C L A S S E S   I M P L E M E N T A T I O N
//

// CCar class implementation
void CCar::Display() {
	std::cout << id << ") " << v_type << "; " << make << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << "; " << max_dist << ";\n";
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
	std::cout << id << ") " << v_type << "; " << type << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << ";\n";
}

double CTrain::CalculateCost(int weight, int dist) {
	return 0.0;
}

double CTrain::CalculateTime(int dist) {
	return 0.0;
}

//!!
int CTrain::GetId() { return 0; }