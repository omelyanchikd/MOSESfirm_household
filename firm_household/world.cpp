#include "StdAfx.h"
#include "world.h"


world::world(void)
{
	tax = 0.2;
	firms.clear();
	households.clear();
	for (int i = 0; i < 5; i++)
		firms.push_back(new firm());
	for (int i = 0; i < 100; i++)
		households.push_back(new household());
	labor_market = new labormarket(firms, households);
	good_market = new market("good_market", firms, households);
	ofstream fout;
	fout.open("taxes.txt", ios::out | ios::trunc);	
	fout.close();	
}

world::world(int number_firm, int number_household, float money_household)
{
	tax = 0.2;
	firms.clear();
	households.clear();
	for (int i = 0; i < number_firm; i++)
	{
		firms.push_back(new firm());
		firms[i]->set("share", 1.0/number_firm);
		firms[i]->id = i;
	}
	for (int i = 0; i < number_household; i++)
		households.push_back(new household(money_household));
	labor_market = new labormarket(firms, households);	
	vector<firm*> good_firms = firms;
	foreign = new firm("foreign");
	foreign->set("price", 2);
	foreign->id = number_firm;
	good_firms.push_back(foreign);	
	good_market = new market("good_market", good_firms, households);
	ofstream fout;
	fout.open("taxes.txt", ios::out | ios::trunc);	
	fout.close();	
	stats = new macro(9, 2, 2200, 0, 0, 0);
}

void world::init(float money, float labor_productivity, float salary_coefficient)
{
	for (int i = 0; i < firms.size(); i++)
	{
		firms[i]->init(money, labor_productivity, salary_coefficient, salary_coefficient * money);	
	}
	get_money();
}


void world::step()
{
	get_money();
	labor_market->activate();
	labor_market->match();	
	good_market->activate();
	good_market->match();
	get_profits();
	get_info();
	write_log();
	learn();
	foreign->learn(stats);
//	taxation();
}

void world::step(float pl, float pr)
{
	learn(pl, pr);
	labor_market->activate();
	labor_market->match();	
	good_market->activate();
	good_market->match();
	get_profits();
	write_log();
	get_money();
//	taxation();
}

void world::change_tax(float new_tax)
{
	tax = new_tax;
}

void world::taxation()
{
	total_taxes = 0;
	for (int i = 0; i < firms.size(); i++)
		total_taxes += firms[i]->get_tax(tax);
	ofstream fout;
	fout.open("taxes.txt", ios_base::app);
	fout<<total_taxes<<endl;
	fout.close();	
}

void world::get_profits()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->get_profits();
}

void world::get_money()
{
	money = 0;
	for (int i = 0; i < firms.size(); i++)
		money += firms[i]->get("money");
	for (int j = 0; j < households.size(); j++)
		money += households[j]->get("money");
}

void world::get_info()
{
	stats->hprice = stats->price;
	stats->hsales = stats->sales;
	stats->hsales = stats->salary;
	stats->salary = 0;
	stats->workers = 0;
	stats->price = 0;
	stats->sales = 0;
	stats->profits = 0;
	stats->sold = 0;
	for (int i = 0; i < firms.size(); i++)
	{
		stats->salary += firms[i]->get("salary") * firms[i]->get("workers");
		stats->workers += firms[i]->get("workers");
		stats->price += firms[i]->get("price") * firms[i]->get("sold");
		stats->sold += firms[i]->get("sold");
		stats->sales += firms[i]->get("sales");
		stats->profits += firms[i]->get("profit");			
	}
	//stats->price += foreign->get("price") * foreign->get("sold");
	stats->sold += foreign->get("sold");
	stats->price += foreign->get("price") * foreign->get("sold");
	stats->price /= stats->sold;
	stats->salary /= stats->workers;	
	stats->sales = foreign->get("sales") + stats->sales;	
	stats->sales_growth = (stats->sales - stats->hsales)/stats->hsales;
	stats->price_growth = (stats->price - stats->hprice)/stats->hprice;
	stats->salary_growth = (stats->salary - stats->hsalary)/stats->hsalary;
}

void world::write_log()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->write_log();
}

void world::learn()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn(stats);
	for (int i = 0; i < households.size(); i++)
		households[i]->learn(stats);
}

void world::learn(float pl, float pr)
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn(pl, pr);
}

vector<firm*> world::get_firms()
{
	return firms;
}