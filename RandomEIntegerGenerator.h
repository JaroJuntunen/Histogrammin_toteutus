#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"
#include <stdlib.h>

class	RandomEintegerGenerator: public Hist::RandomEintegerGeneratorBase{
	public:
		virtual Hist::EInteger operator()();
};
#endif