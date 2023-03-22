#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"
#include <vector>

class Histogram: public Hist::HistogramBase{
	/*
	** Mahdollisesti HistogramBasen periytyessä, Funktiot toimi.
	** Nämä kyseiset funktiot ainakin toimivat kun Histogram ei peri HistogramBasea ja
	** kun Histogramista on muuttuja eikä osoitin. En Kyennyt testaamaan perinnän kanssa
	** sillä itsellä ei HistogramBasen rakentajia eikä Log.h:ta ole ja niitä ei pyydetty
	** toteuttamaan.
	*/
	private:
		std::vector<Hist::EInteger>	numbers;

	public:
	void			add(Hist::EInteger new_num);
	Hist::EInteger	getMinValue() const;
	Hist::EInteger	getMaxValue() const;
	Hist::EInteger	getMode() const;

};
#endif