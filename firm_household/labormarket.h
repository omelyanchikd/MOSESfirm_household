#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

#include <string>

using namespace std;

class labormarket
{
public:
	labormarket(void);
	labormarket(vector<firm*> _firms, vector<household*> _households);

	void activate();
	void match();

	void update(firm *employer);

private:

	vector<firm*> firms;
	vector<household*> households;

	map<firm*, float> probabilities;

	string type;
};

