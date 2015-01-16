#ifndef HARMONIC_H
#define HARMONIC_H

/* This code is the header file for the Harmonic class, which is
 * a harmonic oscillator system of one particle in one dimension. 
 *
 * Joey Cendagorta 1/16/15
*/

class Harmonic
{
	public:
		Harmonic();
		Harmonic(double m, double o, double f);
		void Assignment(double m, double o, double f);
		void Langevin(double time_step, double boltz, double Temp);
		void EnergyCalc();
		void ForceCalc();	
		~Harmonic();
		double mass, friction, omega;
		double position, momentum, energy, force;
		
};

#endif //HARMONIC_H
