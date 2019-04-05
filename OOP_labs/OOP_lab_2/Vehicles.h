
#ifndef _VEHICLES_H_
#define _VEHICLES_H_

#include <vector>
#include <string>


//An abstract base class
class CVehicle {
public:
	CVehicle();
	CVehicle(int _id, int _v_type, double _average_speed, double _load_capacity, double _cost_per_mile) : 
		average_speed(_average_speed), load_capacity(_load_capacity), cost_per_mile(_cost_per_mile), 
		id(_id), v_type(_v_type) { };

	virtual void Display() = 0;

	// The cost of transporting calculated like weight(kg)/dist(km). If carriage is carried out by
	//car and parameter 'dist' > 'max_distance' this function returns -1.
	virtual double CalculateCost(int weight, int dist) = 0;

	// The time of transporting luggages. If carriage is carried out by car and parameter
	//'dist' > 'max_distance' this function returns -1.
	virtual double CalculateTime(int dist) = 0;
	virtual int GetId() { return id; }

protected:
	int v_type; //0 - car, 1 - train
	int id;
	double average_speed;
	double load_capacity;
	double cost_per_mile; // The cost weight(kg)/dist(km)
};

//
// Derived classes
//

// Derived class from CVehicle class
class CCar : public CVehicle {
public:
	void Display();
	double CalculateCost(int weight, int dist);
	double CalculateTime(int dist);
	int GetId();

protected:
	int max_distance; // max distance without refueling
	std::string make; //manufactorer
};

// Derived class from CVehicle class
class CTrain :public CVehicle {
public:
	void Display();
	double CalculateCost(int weight, int dist);
	double CalculateTime(int dist);
	int GetId();

protected:
	std::string type; //diesel / electrical
};

#endif // !_VEHICLES_H_