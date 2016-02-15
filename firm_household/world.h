#pragma once

#include "firm.h"
#include "household.h"

#include "market.h"
#include "labormarket.h"

#include "macro.h"

#include <vector>
#include <map>
#include <fstream>

using namespace std;

class world
{
public:
	world(void);
	world(int number_firm, int number_household, float money_household);
	//world(int number_firm, int number_household, float money_household, float tax_rate);

	void step();
	void step(float pl, float pr);

	void change_tax(float new_tax);

	void init(float money, float labor_productivity, float salary_coefficient); 

	vector<firm*> get_firms();

	macro *stats;


private:

	float money;

	firm *foreign;

	vector<firm*> firms;
	vector<household*> households;

	labormarket *labor_market;

	market *good_market;

	float tax;
	float total_taxes;

	void get_profits();
	//void get_profits(string type);

	void taxation();
	
	void write_log();
	//void write_log(string type);

	void learn();
	void learn(float pl, float pr);

	void get_info();
	void get_money();
	//void learn(string type);
};


