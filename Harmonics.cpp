/**
 * This is the Harmonics.h implementation, it is the basis for PIMD
 * that creates an array of desired length of harmonic oscillators subject 
 * to langevin equation.   
 *
 * Joey Cendagorta 1/16/15
 */
#include "Harmonics.h"
#include "Harmonic.h"
#include "Random.h"


/**
 * This is the defualt constructor which makes ten beads. 
 */ 
Harmonics::Harmonics()
{
	p = 10;
	Populate(p);
	mass = 1.0;
}

/**
 * This is the explicit constructor which makes the desriec amount of beads. 
 */ 
 
Harmonics::Harmonics(int num)
{
	p = num;
	Populate(p);
	mass = 1.0;
}

/**
 * This populates each bead with a random mass, frequency, and friction
 * coefficient. 
 */ 

void Harmonics::Populate(int num)
{
	double o,m,f;
	for(int i=1; i<=num; i++) {
//		m = RandMass();
//		o = RandOmega();
//		f = RandFriction();
		m = 1.0;
		o = 1.0;
		if(i==1)
			f=0.5;
		else
			f=8.0;
		std::cout << i << " " << m << " " << o << " " << f << std::endl;
		h[i].Assignment(m,o,f);
	}
}

/**
 * This function returns a specific bead.
 */ 

Harmonic Harmonics::getHarmonic(int n)
{
	return h[n-1];
}

/**
 * This performs langevin dynamics for all beads. 
 */ 
void Harmonics::Run(double time, double k, double t)
{
	for(int i=0; i<p; i++) {
		h[i].Langevin(time,k,t);
	}
}

/**
 * This is the transformation function that transforms the staging variables
 * to the primitive variables (U-->X). It follows the recursive formula of 
 * x1 = u1; x(k) = u(k) + sum(k to p) {(k-1)/(l-1)u(l) for k = 2 to P.
 * This makes a decoupled system coupled
 */
void Harmonics::TransformUtoX()
{
	double sum, numer, denom;
	for(int k=1;k<=p;k++) {
		sum = 0.0;
		numer = k-1;
		if(k == 1) {
			tpos[0] = h[0].position;
			h[0].mass = mass;
		}
		else {
			for(int l=k;l<=p;l++) {
				denom = l - 1;
				sum = sum + numer/denom*h[l-1].position;
			}
			tpos[k-1] = tpos[0]+sum;
			h[k-1].mass = k/(k-1)*mass;
		}
	}
}

/**
 * This is the transformation function that transforms the primitive variables
 * to the staging variables (X-->U). It follows the recursive formula of 
 * u1 = x1; u(k) = x(k) - [(k-1)*x(k+1) + x1]/k
 * This makes a coupled system decoupled
 */

void Harmonics::TransformXtoU()
{
	h[0].position = tpos[0];
	for(int k=p;k>=2;k--) {
		if(k == p) {
			h[k-1].position = tpos[k-1] - tpos[0]/k;
		}
		else {
			h[k-1].position = tpos[k-1] - ((k-1)*tpos[k] + tpos[0])/k;
		}
	}
}

void Harmonics::ForceTransformXtoU() 
{
	double fsum, numer, denom;
	for(int k=1;k<=p;k++) {
		fsum = 0.0;
		if(k == 1) {
			for(int i=1;i<=p;i++)
				fsum = fsum + h[i-1].force;
			tforce[0] = fsum; // Check to see if should be divided by P.
		}
		else {
			tforce[k-1] = h[k-1].force + (k-2)/(k-1)*tforce[k-2];
		}
	}
}

double Harmonics::PrimitiveEnergy()
{

}

double Harmonics::VirialEnergy()
{
	double energy, extpot, harmpot;
}

Harmonics::~Harmonics()
{

}
