#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"
#include <stdlib.h>

class Histogram: public Hist::HistogramBase{
	
	private:
		Hist::EInteger		*numbers;
		int					elem_size;
	public:
	virtual void			add(Hist::EInteger new_num);
	virtual Hist::EInteger	getMinValue();
	virtual Hist::EInteger	getMaxValue();
	virtual Hist::EInteger	getMode();
	virtual void			destroy();
};
#endif
