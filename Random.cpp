#include "Random.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

#define TWO_PI 6.2831853071795864769252866


double generateRand() {
//	static bool haveSpare = false;
	static double rand1, rand2;
	
/*	if(haveSpare)
	{
		haveSpare = false;
		return sqrt(rand2)*sin(rand1);
	}
	
	haveSpare = true;
*/	
	rand2 = rand()/ ((double) RAND_MAX);
	rand2 = 1.0-rand2;
	if(rand2 < 1e-100) rand2 = 1e-100;
	rand2 = -2*log(rand2);
	rand1 = (rand() / ((double) RAND_MAX)) * TWO_PI;
	return sqrt(rand2)*cos(rand1);
}

double RandMass() {
	double mR = rand()/((double) RAND_MAX);
	if(mR == 0)
		mR = 1.0;
	else
		mR = 10*mR;
	return mR;
}

double RandOmega() {
	double oR = rand()/((double) RAND_MAX);
	if(oR == 0)
		oR = 1.0;
	else
		oR = 20*oR;
	return oR;
}

double RandFriction() {
	double fR = rand()/((double) RAND_MAX);
	if(fR == 0)
		fR = 1.0;
	else
		fR = fR;
	return fR;
}

