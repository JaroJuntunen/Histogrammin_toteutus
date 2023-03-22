#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"

class	RandomEintegerGenerator: public Hist::RandomEintegerGeneratorBase{
	private:
		int test;
	/*
	** int test on tehty sitä varten ettemme alusta srand:ia montaa kertaa,
	** jolloin arvot ovat paljon satunnaisempia.
	*/
	public:
		RandomEintegerGenerator(){
			test = 0;
		}
		Hist::EInteger operator()();
};
#endif