#pragma once
class macro
{
public:

	float salary;
	float hsalary;
	float salary_growth;
	float price;
	float price_growth;
	float hprice;
	float sales;
	float sales_growth;
	float hsales;
	float profits;
	float sold;

	int workers;

	macro()
	{
		salary = 0; price = 0; sales = 0; profits = 0; sold = 0; sales_growth = 0; hsales = 0; hprice = 0; price_growth = 0;
	}

	macro(float s, float p, float sold, float prof, float sl, int w)
	{
		salary = s; hsalary = 0.95 * salary; price = p; sales = sold; profits = prof; sold = sl; workers = w; sales_growth = 0; hsales = 0.9 * sales; hprice = 0.95 * price; price_growth = 0;
	}

	void targeting(macro *m, double r, double e)
	{
		salary = (r * salary + (1 - r) * m->salary)* (1 + e);
		price = (r * price + (1 - r) * m->price)* (1 + e);
		sales = (r * sales + (1 - r) * m->sales)* (1 + e);
		sold = (r * sold + (1 - r) * m->sold)* (1 + e);
		profits = (r * profits + (1 - r) * m->profits)* (1 + e);
	}
};

