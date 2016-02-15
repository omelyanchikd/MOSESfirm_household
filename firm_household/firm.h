#pragma once

#include "household.h"

#include "macro.h"

#include "generator.h"

#include <vector>
#include <map>

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class household;


class firm
{
public:
	
	int id;
	firm(void);
	firm(string type);

	void set(string param, float value);

	void init(float _money, float _labor_productivity, float _salary_coefficient, float _salary_budget);

	void activate(string market_type);

	bool check(string market_type);
	float get_value(string market_type);

	void fire();
	void hire(household* worker);
	void quit(household* worker);

	void set_vacancies();

	float pricing();
	float get_tax(float tax);

	void produce();
	
	void sell(float quantity);

	void get_profits();

	void write_log();

	void learn(macro *world);
	void learn(float pl, float pr);

	float get(string parameter);

	float get_salary();
	float get_needed_workers();
	float get_price();
	float get_storage();


private:

	string type;

	macro *state;
//	macro *world;

	float share;
	
	float money;

	float salary;
	float price;
	float plan;
	
	float salary_budget;

	float labor_capacity;

	float labor_productivity;

	float elasticity;

	float production;
	float storage;

	float time;
	vector<float> history;

	float price_coefficient;

	float salary_coefficient;

	float plan_coefficient;

	vector<household*> workers;
	float sold;

	float prev_sold;
	float prev_plan;
	float prev_price;
	float prev_profit;

	float sales;
	float expected;

	float exp_price;
	float exp_sales;

	float exp_price_growth;

	float exp_salary;
	float exp_salary_growth;
	float exp_world_salary_growth;

	float profit_growth;

	float profit;
	float margin;

	float target;

	string parse(float a, float b);	
	double trial(double expected, double wage, int capacity);

	float prev_sales;

	float exp_world_price_growth;
	float exp_world_growth;


};

