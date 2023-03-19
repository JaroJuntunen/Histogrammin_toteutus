#include "Histogram.h"

/*
** add lisää Histogrammin sisällä olevaan EInteger arreyhin uuden EIntegerin.
*/
void Histogram::add(Hist::EInteger new_num)
{
	Hist::EInteger *temp = numbers;
	/*
	**Luomme väliaikais osoittimen osoittamaan aijempaan muistialueeseen
	*/
	numbers = (Hist::EInteger *)malloc(sizeof(Hist::EInteger) * (elem_size + 1));
	/*
	** Allokoimme uuden muistialueen numbersiin jotta on tilaa ja juuri oikea
	** määrä uistia.
	*/
	if (numbers != NULL)
	{
		/*
		** Siirrämme vanhat tiedon uuteen muisti alueeseen
		*/
		for (int i = 0; i < elem_size; i++)
			numbers[i] = temp[i];
		/*
		** Lisäämme uuden EIntegerin uuden muistialueen loppuun
		*/
		numbers[elem_size++] = new_num;
		/*
		** Vapautamme vanhan muisti alueen väliaikais osoittimen kautta
		*/
		if (elem_size != 1)
			free(temp);
	}
	else
		numbers = temp;
	/*
	** Jos muistin määritys epäonnistuu asetamme asetamme numbersin takaisin
	** aijempaan tilaansa.
	*/
}

/*
** getMinValue etsii pienimmän arvon Histogrammin sisäisestä arreysta.
*/
Hist::EInteger Histogram::getMinValue(void)
{
	Hist::EInteger min = numbers[0];
	/*
	** Otamme numbers arreyn ensimmäisen arvon oletetuksi minimi arvoksi, jonka
	** jälkeen menemme arreyn läpi ja katsomme esiintyykö arreyssä pienempää
	** EInteger arvoa.
	*/
	for (int i = 0; i < elem_size; i++)
		if (numbers[i] < min)
			min = numbers[i];
	return (min);
}
/*
** getMaxValue toimii samalla periaatteella kuin getMinValue mutta se etsiikin 
** suurinta arvoa eikä pienintä.
*/
Hist::EInteger Histogram::getMaxValue(void)
{
	Hist::EInteger	max = numbers[0];
	for (int i = 0; i < elem_size; i++)
		if (numbers[i] > max)
			max = numbers[i];
	return (max);
}

/*
** getMode etsii Histogramin sisällä olevan numbers arryn sisältä arvon,
** joka esiintyy kaikista useimmin. Jos useampaa arvoa on saman verran
** funktio oletuksena ottaa numeraalisesti pienemmän EInteger arvon.
*/
Hist::EInteger Histogram::getMode(void)
{
	/*
	** Ensin haemme min ja max arvot jotta meidän ei tarvitse hakea kaikkia
	** arvoja joita ei välttämättä ole numbers arreystä.
	*/
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
		/*
		** Tallennamme arreyssa esiintyvät arvot test_numberiin,
		** jonka jälkeen käymme laskemassa montako kertaa sitä arvoa esiintyy
		** arreyssa.
		*/
		for (int j = 0; j < elem_size; j++)
		{
			if (numbers[j] == test_number)
				test_number_couont++;
		}
		/*
		** Vertaamme mikäli meidän testaamaa arvoa esiintyy enemmän,
		** kuin testattuja.
		*/
		if (test_number_couont > most_count)
		{
			most = test_number;
			most_count = test_number_couont;
		}
	}
	return (most);
}
/*
** Lisäsin oman extra funktion muisti vuotojen poistamiseksi.
** Tätä funktiota tulisi käyttää aina kun kyseistä Histogrammi objektia ei enää
** tarvita.
*/
void Histogram::destroy(void)
{
	free(numbers);
}
