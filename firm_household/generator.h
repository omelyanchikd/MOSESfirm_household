#pragma once

#include <vector>
#include <map>

using namespace std;

float summarize(vector<float> values);

vector<float> allocate(vector<float> values);	

template <class T> map<T, float> allocate(map <T,float> values);	

vector<float> invert(vector<float> values);

template <class T> map<T,float> invert(map <T,float> values);

int get_random(vector<float> probabilities);

template <class T> T get_random(map<T,float> probabilities);

template <class T> float summarize(map<T, float> values)
{
	float sum = 0;
	for (map<T, float>::iterator i = values.begin(); i != values.end(); ++i)
		sum += i->second;
	return sum;
}

template <class T> map<T, float> allocate(map<T, float> values)
{
	map<T, float> allocation;
	float sum = summarize<T>(values);
	for (map<T, float>::iterator i = values.begin(); i != values.end(); ++i)
	{
		allocation[i->first] = (i->second/sum);
	}
	return allocation;
}

template <class T> map<T, float> invert(map<T, float> values)
{
	map<T, float> invert_vector;
	for (map<T, float>::iterator i = values.begin(); i != values.end(); ++i)
	{
		invert_vector[i->first] = (1.0/i->second);
	}
	return invert_vector;
}

template <class T> T get_random(map<T, float> probabilities)
{
	float rand_number = rand()/(float)RAND_MAX;
	if (rand_number == 1)
		return (probabilities.rbegin()->first);
	map<T, float>::iterator index = probabilities.begin();
	float first = 0;
	float last = index->second;
	while (index != probabilities.end()) 
	{
		if (first <= rand_number && rand_number < last)
			return index->first;
		first = last;
		index++;
		last = first + index->second;
	}
	return index->first;
}