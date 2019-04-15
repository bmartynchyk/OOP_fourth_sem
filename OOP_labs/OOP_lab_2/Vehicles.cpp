

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

//Constructors
CCar::CCar(int _id, int _v_type, std::string _make, double _avr_speed, double _cost_per_mile,
	double _capacity, int _max_dist) : CVehicle(_id, _v_type, _avr_speed, _capacity, _cost_per_mile),
	make(_make), max_dist(_max_dist) { }

// Methods
void CCar::Display() {
	std::cout << "[" << id << "] " << v_type << "; " << make << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << "; " << max_dist << ";\n";
}

double CCar::CalculateCost(int weight, int dist) {
	return 0.0;
}

double CCar::CalculateTime(int dist) {
	return 0.0;
}

//!!
int CCar::GetId() { return id; }

CTrain::CTrain(int _id, int _v_type, std::string _t_type, double _avr_speed, double _capacity, 
	double _cost_per_mile) : CVehicle(_id, _v_type, _avr_speed, _capacity, _cost_per_mile),
	type(_t_type) { }

// CTrain class implementation
void CTrain::Display() {
	std::cout << "[" << id << "] " << v_type << "; " << type << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << ";\n";
}

double CTrain::CalculateCost(int weight, int dist) {
	return 0.0;
}

double CTrain::CalculateTime(int dist) {
	return 0.0;
}

//!!
int CTrain::GetId() { return id; }