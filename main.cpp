/**
* This is the main file to run Path Integral Molecular Dynamics (PIMD).
*
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "Harmonic.h"
#include "Harmonics.h"
#include "Random.h"

#define TWO_PI 6.2831853071795864769252866
using namespace std;

int main() {
	ofstream phase_space;
	phase_space.open("phase.dat");
	ofstream phase_space_2;
	phase_space_2.open("phase_2.dat");
	ofstream histo;
	histo.open("hist.dat");
	double j;
	double dt;
	double Et,R, kb, Temp;
	Harmonics h(2);

//	double xmin, xmax, dx;
//	int Nbins, o;
	
//	Nbins = 50;
//	kb = 8.61e-5;
//	Temp = 300.0;
	kb = 1.0;
	Temp = 1.0;
//	xmax = 5.0;
//	xmin = -xmax;
//	dx = (xmax - xmin)/float(Nbins);
//	int hist[Nbins];
	int steps;
	steps = 1000000;
	dt = 0.01;
//	h.getHarmonic(1).Assignment(1.0,1.0,0.5);
//	h.getHarmonic(2).Assignment(1.0,1.0,8.0);
	cout << h.getHarmonic(1).mass << endl;
	cout << h.getHarmonic(2).mass << endl;
//	for(int i = 0; i< Nbins; i++)
//		hist[i] = 0;
	
	for(int i = 1; i <= steps; i++) {
		h.Run(dt,kb,Temp);
//		h1.Langevin(dt,kb,Temp);
//		R = generateRand();
//		h2.Langevin(dt,kb,Temp);
		if(i % 100 == 0) {
			h.getHarmonic(1).EnergyCalc();
			h.getHarmonic(2).EnergyCalc(); 
			phase_space << i*dt/TWO_PI << ' ' << h.getHarmonic(1).position << ' ' 
			            << h.getHarmonic(1).momentum << ' ' << h.getHarmonic(1).energy << endl;
			phase_space_2 << i*dt/TWO_PI << ' ' << h.getHarmonic(2).position 
			              << ' ' << h.getHarmonic(2).momentum << ' ' << h.getHarmonic(2).energy << endl;
		}
//		o = int((xt - xmin)/dx);
//		hist[o] = hist[o]+1;

	}
//	for(int i = 0; i < Nbins; i++) {
//		if(i < 25)
//			j = 0.2*(i)-5.0;
//		else
//			j = 0.2*(i)-4.8;
//		histo << j << " " << float(hist[i])/(steps*0.2) << endl;
//	}
	phase_space.close();
	phase_space_2.close();
	histo.close();
		
	return 0;	
}
