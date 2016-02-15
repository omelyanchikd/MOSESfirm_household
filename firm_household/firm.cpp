#include "StdAfx.h"
#include "firm.h"



firm::firm(void)
{
	ofstream fout;
	fout.open("log.csv", ios::out | ios::trunc);
	fout<<"pointer"<<", "<<"money"<<", "<<"price"<<", "<<"salary"<<", "<<"sales"<<", "<<"production"<<", "<<"storage"<<", "<<"workers"<<", "<<"labor_capacity"<<", "<<"plan"<<", "<<"profit"<<", "<<"time"<<endl; 
	fout.close();	
	sales = 0;
	sold = 0;
	storage = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	money = 10000;
	elasticity = -1.5;
	prev_sold = 0;
	plan_coefficient = 1;
	labor_productivity = 10;
	salary_budget = 50;
	plan = 50;
	price_coefficient = 1;
	prev_price = 0;
	prev_sales = 0;
}

firm::firm(string t)
{
	sales = 0;
	sold = 0;
	storage = 0;
	salary = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	money = 0;
	profit = 0;
	type = t;

}

void firm::init(float _money, float _labor_productivity, float _salary_coefficient, float _salary_budget)
{
//	world = new macro;
	state = new macro;
	margin = 0.1;
	sales = 0;
	expected = 200;
	money = 100;
	salary = 10;
	labor_capacity = 20;
	sold = 0;
	storage = 0;
	price = 2;
	production = 0;
	workers.clear();
	time = 0;
	labor_productivity = _labor_productivity;	
	exp_price = 0;
	exp_sales = 0;
	exp_price_growth = 0.1;
	//growth = 0;
	prev_sales = 190;//(1 + exp_sales) * labor_capacity * labor_productivity;
	prev_price = 2;
	exp_world_price_growth = 0;
	exp_world_growth = 0;
	share = 0.2;
	prev_profit = 0;
	plan = 200;
	exp_world_salary_growth = 0.05;
	//exp_salary = 
}

void firm::activate(string market_type)
{
	if (market_type == "labor_market")
	{
		set_vacancies();
	}
	else
	{	
		if (type == "foreign")
		{
			storage = 500000;
			sold = 0;
		}
		else
		{
			produce();
			storage += production;
			prev_price = price;
			price = pricing();
			sold = 0;
		}
	}
}

bool firm::check(string market_type)
{
	if (market_type != "labor_market")
		return (storage >= 0.001);
	return (labor_capacity - workers.size() > 0.001);
}

float firm::get_value(string market_type)
{
	if (market_type != "labor_market")
		return price;
	else
		return salary;
}

void firm::fire()
{
	while (workers.size() > labor_capacity && workers.size())
	{
		int index = rand()/RAND_MAX * (workers.size() - 1);
		workers[index]->fire();
		workers.erase(workers.begin() + index);
	}
}

void firm::hire(household* worker)
{
	workers.push_back(worker);	
}

void firm::quit(household* worker)
{
	int index = -1;
	for (int i = 0; i < workers.size(); i++)
	{
		if (workers[i] == worker)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
		workers.erase(workers.begin() + index);
}

void firm::set_vacancies()
{
	if (labor_capacity < workers.size())
		fire();
}

void firm::sell(float quantity)
{
	storage -= quantity;
	sales += quantity * price;
	sold += quantity;	
}

void firm::produce()
{
	production = labor_productivity * workers.size();
}

float firm::pricing()
{
	return (storage > 0.001 && expected > 0.001? expected/storage : price);
}

void firm::get_profits()
{
	profit = sales - workers.size() * salary;
}

float firm::get_tax(float tax)
{
	if (profit > 0)
	{
		sales -= tax * sales;
		return tax * sales;
	}
	return 0;
}

void firm::write_log()
{
	ofstream fout;
	fout.open("log.csv", ios_base::app);
	fout<<this<<", "<<money<<", "<<price<<", "<<salary<<", "<<sales<<", "<<production<<", "<<storage<<", "<<workers.size()<<", "<<labor_capacity<<", "<<plan<<", "<<profit<<", "<<time<<endl; 
	fout.close();
}

void firm::learn(float pl, float pr)
{
	plan = pl;
	price = pr;
	salary_budget = (sales > 0)? salary_coefficient * sales : salary_budget;
	time++;
	money += profit;
	sold = 0;
	sales = 0;

	if (plan - storage > 0)
	{
		plan -= storage;
	}
	else
	{
		plan = 0;
	}//*/
}

float sign(float x) {
    return (x > 0) - (x < 0);
}

void firm::learn(macro *world)
{
	if (type == "foreign")
	{
		price = world->price;//time < 100 && time >= 200 ? 5 * world->price : world->price;
		sold = 0;
		sales = 0;
		time++;
	}
	else
	{
		money += profit;
		exp_world_price_growth = 0.5 * world->price_growth + 0.5 * exp_world_price_growth;
		exp_price_growth = 0.5 * (price - prev_price)/prev_price + 0.5 * exp_price_growth;
		//exp_price = price;
		exp_price = (1 + 0.5 * exp_price_growth + 0.5 * exp_world_price_growth) * price;
		if (exp_price < 0.001) exp_price = 0.001;
		margin = 0.05;
		//margin = 0.5 *margin  + 0.5 *profit/(price * sold); 
		target = margin > 0? 1.01 * margin: 0.001;
		exp_world_growth = 0.5 * world->sales_growth + 0.5 * exp_world_growth;
		if (prev_sales > 0.001)
			exp_sales = 0.5 * exp_sales  + 0.5 * (sales - prev_sales)/prev_sales;
		else
			exp_sales = 0.5 * exp_sales  + 0.5;
		//share = 0.5 * sales/world->sales + 0.5 * share;
		expected = 0.5 * (1 + 0.5 * exp_sales + 0.5 * exp_world_growth) * sales * (1 + exp_world_price_growth - exp_price_growth);
		//expected = (1 + 0.5 * exp_sales + 0.5 * exp_world_growth) * sales;
		//exp_world_salary_growth = 0.5 * world->salary_growth + 0.5 * exp_world_salary_growth;
		profit_growth = (prev_profit == 0)? sign(profit)*0.1: (profit - prev_profit)/prev_profit;
		plan = 0.5 * plan + 0.5 * sold * (1 + profit_growth);
		labor_capacity = floor(plan/labor_productivity + 0.5);
		if (labor_capacity <= 0) labor_capacity = 1;
		int workers_n = workers.size();
		if (workers.size() == 0) workers_n = 1;
		exp_world_salary_growth = 0.5 * exp_world_salary_growth + 0.5 * world->salary_growth;
		exp_salary_growth = (float(labor_capacity)/workers_n - 1)/10.0 + exp_world_salary_growth;
		salary = salary * (1 + exp_salary_growth);
		if (salary <= 0.001) salary = 0.01;
		while (!trial(expected, salary, labor_capacity))
		{
			salary *= 0.99;
		}
		



	}
	time++;
	sold = 0;
	prev_sales = sales;
	sales = 0;
}

double firm::trial(double expected, double wage, int capacity)
{
	return (1 - wage * capacity/expected);
}
string firm::parse(float a, float b)
{
	ostringstream buffer;
	buffer << a;
	buffer << " ";
	buffer << b;
	return buffer.str();
}

float firm::get(string parameter)
{
	if (parameter == "price")
		return price;
	if (parameter == "salary")
		return salary;
	if (parameter == "workers")
		return workers.size();
	if (parameter == "sales")
		return sales;
	if (parameter == "profit")
		return profit;
	if (parameter == "labor_capacity")
		return labor_capacity;
	if (parameter == "sold")
		return sold;
	if (parameter == "production")
		return production;
	if (parameter == "plan")
		return plan;
	if (parameter == "money")
		return money;
	if (parameter == "storage")
		return storage;
	if (parameter == "margin")
		return margin;
	if (parameter == "share")
		return share;
	if (parameter == "expected")
		return expected;
	if (parameter == "exp_price")
		return exp_price;
	if (parameter == "exp_sales")
		return exp_sales;
	if (parameter == "exp_price_growth")
		return exp_price_growth;
}

float firm::get_salary()
{
	return salary;
}

float firm::get_needed_workers()
{
	return (labor_capacity - workers.size());
}

float firm::get_price()
{
	return price;
}

float firm::get_storage()
{
	return storage;
}

void firm::set(string param, float value)
{
	if (param == "price")
		price = value;
	if (param == "share")
		share = value;
}