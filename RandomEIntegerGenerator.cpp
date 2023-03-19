#include "RandomEIntegerGenerator.h"

Hist::EInteger RandomEintegerGenerator::operator()()
{
	srand((unsigned)time(NULL));
	int n = rand();
	n = n % 5;
	return ((Hist::EInteger)n);
}
