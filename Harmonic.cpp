/**
 * This is the Harmonic.h implementation, it includes the Langevin
 * equation to solve for equations of motion.  
 *
 * Joey Cendagorta 1/16/15
 */

#include "Harmonic.h"
#include "Random.h"
#include <cmath>
#include <iostream>

/**
 * This initializes the harmonic bead and assigns all values to unity.
 */
Harmonic::Harmonic()
{
	Assignment(1.0,1.0,1.0);	
}

/**
 * This initializes the harmonic bead and assigns all values to the desired
 * quantities.
 */
Harmonic::Harmonic(double m, double o, double f) 
{
	Assignment(m,o,f);
}

/**
 * This is the assignment function that sets the values of the bead to the
 * desired values. 
 */
void Harmonic::Assignment(double m, double o, double f)
{
	mass = m;
	omega = o;
	friction = f;
	position = 0.0;
	momentum = 0.0;
	ForceCalc();
	EnergyCalc();
}

/**
 * This calculates the energy of the current state. E = 1/2*k*x^2
 */
void Harmonic::EnergyCalc()
{
	double k = omega*omega*mass;
	energy = 0.5*k*position*position;
}

/**
 * This calculates the force associated with a harmonic potential.
 */

void Harmonic::ForceCalc() 
{
	double k = omega*omega*mass;
	force = -k*position;
}

/**
 * This solves Langevin dynamics associated with the BAOAB method. 
 */
void Harmonic::Langevin(double time_step, double boltz, double Temp)
{
	double dt = time_step;
	double kb = boltz;
	double T = Temp;
	double R = generateRand();
	momentum = momentum + 0.5*dt*force;
	position = position + 0.5*dt*momentum/mass;
//	momentum = exp(-friction*dt)*momentum+sqrt(1-exp(-2.0*friction*dt)/(2.0*friction))*R/mass;
	momentum = exp(-friction*dt)*momentum+sqrt(kb*T*(1.0-exp(-2.0*friction*dt)))*R*sqrt(mass);
	position = position + 0.5*dt*momentum/mass;
	ForceCalc();
	momentum = momentum + 0.5*dt*force;
}

Harmonic::~Harmonic()
{
}
		
