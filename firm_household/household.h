#pragma once

#include "macro.h"

#include "firm.h"
#include "generator.h"

#include <vector>
#include <string>

#include "math.h"

using namespace std;

class firm;

class household
{
public:
	household(void);
	household(float _money);

	void fire();

	void decide();

	void activate();

	float get(string s);

	firm* find_work(map<firm*, float> probabilities);

	firm* buy(map<firm*, float> probabilities);
	firm* buy(float &capacity, float &consumption, float &budget, map<firm*, float> probabilities);

	void learn(macro *world);


private:
	
	float money;

	firm *employer;
	float salary;

	bool employed;

	float consumption_budget;
	float consumption;
	float consumption_capacity;

	float budget;

	float price_growth;

	int time;

};

