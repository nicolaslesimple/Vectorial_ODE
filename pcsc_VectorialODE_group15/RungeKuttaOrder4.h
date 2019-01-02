#ifndef PCSC_VECTORIALODE_GROUP15_RUNGEKUTTAORDER4_H
#define PCSC_VECTORIALODE_GROUP15_RUNGEKUTTAORDER4_H

#include "RungeKutta.h"

/**
 *\brief Class implementing the Runge-Kutta 4 steps to solve the ODE system.
 * Runge-Kutta method allows the solving of the ODE system.
 * This class is implementing in such a way that it only writes the solution every WriteOutputTimestep.
 * This class is inherited from RungeKutta class also inherited from VectorialODE.
 */
class RungeKuttaOrder4 : public RungeKutta {
public:
    RungeKuttaOrder4(Input &input, Solution &solution); //Constructor which completes the one of VectorialODE class and RungeKutta class
    void SolveVectorialODE() override; //Precise definition of the virtual inherited method to solve the ODE using Runge Kutta 4 steps method
};

#endif //PCSC_VECTORIALODE_GROUP15_RUNGEKUTTAORDER4_H
