#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

using namespace std;

class market
{
public:
	market(void);
	market(string market_type, vector<firm*> _sellers, vector<household*> _buyers);

	void activate();
	void match();

	bool empty();
	void update(firm *seller);

	string get_type();

private:

	string type;

	vector<firm*> sellers;
	vector<household*> buyers;

	map<firm*, float> probabilities;

};

