#ifndef HARMONICS_H
#define HARMONICS_H

/* This code is the header file for the Harmonics class, which is
 * an array of harmonic oscillator systems of one particle each
 * in one dimension. 
 *
 * Joey Cendagorta 1/16/15
*/

#include <iostream>
#include "Harmonic.h"

class Harmonics
{
	public:
		Harmonics();
		Harmonics(int num);
		void Populate(int num);
		Harmonic getHarmonic(int n);
		void Run(double time, double k, double t);
		void TransformXtoU();
		void TransformUtoX();
		void ForceTransformXtoU();
		double PrimitiveEnergy();
		double VirialEnergy();
		~Harmonics();
	private:
		Harmonic h [200];
		int p; //Number of oscillators
		double tpos [200];
		double mass;
		double tforce[200];
		
};

#endif //HARMONIC_H
