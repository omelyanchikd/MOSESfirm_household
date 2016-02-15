#include "StdAfx.h"
#include "generator.h"

float summarize(vector<float> values)
{
	float sum = 0;
	for (int i = 0; i < values.size(); i++)
		sum += values[i];
	return sum;
}

vector<float> allocate(vector<float> values)
{
	vector<float> allocation;
	float sum = summarize(values);
	for (int i = 0; i < values.size(); i++)
	{
		allocation.push_back(values[i]/sum);
	}
	return allocation;
}

vector<float> invert(vector<float> values)
{
	vector<float> invert_vector;
	for (int i = 0; i < values.size(); i++)
	{
		if (values[i])
			invert_vector.push_back(1/values[i]);
		else
			invert_vector.push_back(0);
	}
	return invert_vector;
}

int get_random(vector<float> probabilities)
{
	vector<float> allocation;
	allocation.push_back(0);
	for (int i = 0; i < probabilities.size(); i++)
	{
		allocation.push_back(allocation[i] + probabilities[i]);
	}
	float rand_number = rand()/(float)RAND_MAX;
	if (rand_number == 1)
		return (allocation.size() - 1);
	for (int i = 1; i < allocation.size(); i++)
	{
		if (allocation[i-1] <= rand_number && rand_number < allocation[i])
			return i;
	}	
}

