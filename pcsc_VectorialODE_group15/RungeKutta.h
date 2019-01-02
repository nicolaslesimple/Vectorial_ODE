#ifndef PCSC_VECTORIALODE_GROUP15_RUNGEKUTTA_H
#define PCSC_VECTORIALODE_GROUP15_RUNGEKUTTA_H

#include "VectorialODE.h"


/**
 * \brief Class allowing a more precise definition of one of the ODE solvers technics which is Runge-Kutta method.
 * This is an abstract class as before because the method SolveVectorialODE is virtual and it will be defined in different ways in the inherited classes.
 * The different Runge-Kutta method correspond to the different order we use to solve the system.
 */
class RungeKutta : public VectorialODE {
public:
	RungeKutta(Input &input, Solution& solution); // Constructor
	virtual void SolveVectorialODE() = 0; //Virtual method that will be defined in the class to solve the system
};

#endif //PCSC_VECTORIALODE_GROUP15_RUNGEKUTTA_H
