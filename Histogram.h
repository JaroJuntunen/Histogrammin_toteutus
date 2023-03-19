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
		Histogram(){
			elem_size = 0;
		}
		virtual void			add(Hist::EInteger new_num);
		virtual Hist::EInteger	getMinValue();
		virtual Hist::EInteger	getMaxValue();
		virtual Hist::EInteger	getMode();
		/*
		** Lisäsin oman funktion destroy jotta muisti voitaisiin vapauttaa,
		** kun kyseistä histogrammia ei enää tarvita.
		*/
		virtual void			destroy();
};
#endif
