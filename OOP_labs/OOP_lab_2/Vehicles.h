
#ifndef _VEHICLES_H_
#define _VEHICLES_H_

#include <vector>
#include <string>

//
// Base class
//

//An abstract base class
class CVehicle {
public:

	// Constructors
	CVehicle();
	CVehicle(int _id, int _v_type, double _capacity, double _cost_per_mile, double _avr_speed);

	// Methods
	virtual void Display() = 0;

	// The cost of transporting 'weight'(kg) on 'dist'(km). If carriage is carried out by
	//car and parameter 'dist' > 'max_distance' this function returns -1.
	virtual double CalculateCost(int weight, int dist) = 0;

	// The time of transporting luggages. If carriage is carried out by car and parameter
	//'dist' > 'max_distance' this function returns -1.
	virtual double CalculateTime(int dist) = 0;
	virtual int GetId();

	virtual void SetCostPerMile(double newcost);

protected:
	int id;
	int v_type; // 0 - car, 1 - train
	double capacity;
	double cost_per_mile; // The cost weight(kg)/dist(km)
	double avr_speed;
};

//
// Derived classes
//

// Derived class from CVehicle class
class CCar : public CVehicle {
public:

	// Constructors
	CCar(int _id, std::string _make, double _capacity, double _cost_per_mile,
		double _avr_speed, int _max_dist);

	// Methods
	void Display();
	double CalculateCost(int weight, int dist);
	double CalculateTime(int dist);
	void SetCostPerMile(double newcost);
	int GetId();
	double GetAvrSpeed();
	int GetMaxDist();

protected:
	int max_dist; // Max distance without refueling
	std::string make; // Manufacturer
};

// Derived class from CVehicle class
class CTrain :public CVehicle {
public:

	// Constructors
	CTrain(int _id, std::string _type, double _capacity, double _cost_per_mile, double _avr_speed);

	// Methods
	void Display();
	double CalculateCost(int weight, int dist);
	double CalculateTime(int dist);
	void SetCostPerMile(double newcost);
	int GetId();
	double GetAvrSpeed();

protected:
	std::string type; //diesel / electrical
};

#endif // !_VEHICLES_H_