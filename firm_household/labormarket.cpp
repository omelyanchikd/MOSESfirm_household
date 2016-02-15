#include "StdAfx.h"
#include "labormarket.h"


labormarket::labormarket(void)
{
	type = "labor_market";
}

labormarket::labormarket(vector<firm*> _firms, vector<household*> _households)
{
	type = "labor_market";
	firms = _firms;
	households = _households;
}

void labormarket::activate()
{
	probabilities.clear();
	for (int i = 0; i < firms.size(); i++)
	{
		firms[i]->activate(type);
		if (firms[i]->get_needed_workers() > 0)
				probabilities[firms[i]] = firms[i]->get_salary();
	}
	probabilities = allocate<firm*>(probabilities);
}

void labormarket::match()
{
	for (int i = 0; i < households.size(); i++)
	{
		households[i]->activate();
		if (probabilities.empty())
			continue;
		firm *employer = households[i]->find_work(probabilities);
		if (employer != NULL)
			update(employer);
	}
}

void labormarket::update(firm *employer)
{
	if (employer->get_needed_workers() == 0)
	{
		probabilities.erase(employer);
		probabilities = allocate<firm*>(probabilities);
	}
}