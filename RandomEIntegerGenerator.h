#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"
#include <stdlib.h>

class	RandomEintegerGenerator: public Hist::RandomEintegerGeneratorBase{
	private:
		int test;
	public:
		RandomEintegerGenerator(){
			test = 0;
		}
		Hist::EInteger operator()();
};
#endif