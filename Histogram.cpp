#include "Histogram.h"

void Histogram::add(Hist::EInteger new_num)
{
	Hist::EInteger *temp = numbers;
	numbers = (Hist::EInteger *)malloc(sizeof(Hist::EInteger) * (elem_size + 1));
	for (int i = 0; i < elem_size; i++)
		numbers[i] = temp[i];
	numbers[elem_size++] = new_num;
	if (elem_size != 1)
		free(temp);
}

Hist::EInteger Histogram::getMinValue(void)
{
	Hist::EInteger min = numbers[0];
	for (int i = 0; i < elem_size; i++)
		if (numbers[i] < min)
			min = numbers[i];
	return (min);
}

Hist::EInteger Histogram::getMaxValue(void)
{
	Hist::EInteger	max = numbers[0];
	for (int i = 0; i < elem_size; i++)
		if (numbers[i] > max)
			max = numbers[i];
	return (max);
}

Hist::EInteger Histogram::getMode(void)
{
	Hist::EInteger max = getMaxValue();
	Hist::EInteger min = getMinValue();
	Hist::EInteger most;
	Hist::EInteger test_number;
	int most_count = 0;
	int test_number_couont;
	for (int i = 0; i < max - min; i++)
	{
		test_number = (Hist::EInteger)((int)min + i);
		test_number_couont = 0;
		for (int j = 0; j < elem_size; j++)
		{
			if (numbers[j] == test_number)
				test_number_couont++;
		}
		if (test_number_couont > most_count)
		{
			most = test_number;
			most_count = test_number_couont;
		}
	}
	return (most);
}

void Histogram::destroy(void)
{
	free(numbers);
}
