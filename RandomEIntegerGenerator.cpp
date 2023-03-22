#include "RandomEIntegerGenerator.h"
/*
** RandomEIntegerGenerator luo niin sanottuja Random numeroita.
** kuseiset numerot ovat aluksi int muodossa jonka jälkeen otamme siitä
** modulo 5 jotta saamme sen Hist::EIntegerin rajoihin.
** Jonka jälkeen teemme Typecastin jotta muutamme intin EIntegeriksi.
*/
Hist::EInteger	RandomEintegerGenerator::operator()()
{
	int	n;

	if (test == 0){
		srand((unsigned)time(NULL));
		test = 1;
	}
	n = (rand() % 5);
	return ((Hist::EInteger)n);
}
