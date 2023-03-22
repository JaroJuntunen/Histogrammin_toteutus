#include "Histogram.h"

/*
** add lisää Histogrammin sisällä olevaan EInteger vectoriin uuden EIntegerin elementin.
*/
void	Histogram::add(Hist::EInteger new_num)
{
	numbers.push_back(new_num);
}

/*
** Lukee EInteger vectorin läpi ja palauttaa pienimmän arvon joka havaittiin.
*/
Hist::EInteger	Histogram::getMinValue() const
{
	int	min_num = numbers[0];
	int	elem_size = numbers.size();

	for (int i = 1; i < elem_size; i++)
	{
		if (numbers[i] < min_num)
		{
			min_num = numbers[i];
		}
	}
	return ((Hist::EInteger)min_num);
}

/*
** Lukee EInteger vectorin läpi ja palauttaa suurimman arvon joka havaittiin.
*/
Hist::EInteger	Histogram::getMaxValue() const
{
	int	max_num = numbers[0];
	int	elem_size = numbers.size();

	for (int i = 1; i < elem_size; i++)
	{
		if (numbers[i] > max_num)
		{
			max_num = numbers[i];
		}
	}
	return ((Hist::EInteger)max_num);
}

/*
** Etsii useimmin esiintyvän arvon pienimmän ja suurimman arvon väliltä.
*/
Hist::EInteger	Histogram::getMode(void) const
{
	int	most;
	int	test_number;
	int	elem_size = numbers.size();
	int	most_count = 0;
	int	test_number_couont;
	int	min_num = getMinValue();
	int	max_num = getMaxValue();

	for (int i = 0; i < max_num - min_num; i++)
	{
		test_number = (min_num + i);
		test_number_couont = 0;
		for (int j = 0; j < elem_size; j++)
		{
			if (numbers[j] == test_number)
			{
				test_number_couont++;
			}
		}
		if (test_number_couont > most_count)
		{
			most = test_number;
			most_count = test_number_couont;
		}
	}
	return ((Hist::EInteger)most);
}
