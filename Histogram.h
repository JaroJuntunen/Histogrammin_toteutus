#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"
#include <stdlib.h>

class Histogram: public Hist::HistogramBase{
	
	private:
		Hist::EInteger		*numbers;
		int					elem_size;
	/*
	**Muuttujat jotka tulevat sisältämään
	** nubers osoitin tulee olemaan arrey EIntegereistä.
	** elem_size on ( numbers muistin koko / sizeof(EInteger)) numberssin pituus.
	*/
	public:
		void			add(Hist::EInteger new_num);
		Hist::EInteger	getMinValue(void);
		Hist::EInteger	getMaxValue(void);
		Hist::EInteger	getMode(void);
		/*
		** Lisäsin oman funktion destroy jotta muisti voitaisiin vapauttaa,
		** kun kyseistä histogrammia ei enää tarvita.
		*/
		void	destroy();
};
#endif
