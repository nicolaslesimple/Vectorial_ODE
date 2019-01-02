#ifndef PCSC_VECTORIALODE_GROUP15_BASHFORTH_H
#define PCSC_VECTORIALODE_GROUP15_BASHFORTH_H

#include "VectorialODE.h"

/**
 * \brief Class allowing a more precise definition of one of the ODE solvers technics which is Adam-Bashforth method.
 * This is an abstract class as before because the method SolveVectorialODE is virtual and it will be defined in different ways in the inherited classes.
 * The different Adam-Bashforth method correspond to the different order we use to solve the system.
 */
class Bashforth : public VectorialODE {
public:
    Bashforth(Input &input, Solution& solution); // Constructor which completes the one of VectorialODE class.
    virtual void SolveVectorialODE() = 0; //Virtual method that will be defined in the inherited class to solve the system.

};

#endif //PCSC_VECTORIALODE_GROUP15_BASHFORTH_H