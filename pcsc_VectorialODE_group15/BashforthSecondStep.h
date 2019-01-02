#ifndef PCSC_VECTORIALODE_GROUP15_BASHFORTHSECONDSTEP_H
#define PCSC_VECTORIALODE_GROUP15_BASHFORTHSECONDSTEP_H

#include "Bashforth.h"

/**
 *\brief Class implementing the Adam-Bashforth 2 steps to solve the ODE system.
 * Bashforth method allows the solving of the ODE system.
 * This class is implementing in such a way that it only writes the solution every WriteOutputTimestep.
 * This class is inherited from Bashforth class also inherited from VectorialODE.
 */
class BashforthSecondStep : public Bashforth {
public:
    BashforthSecondStep(Input &input, Solution &solution); //Constructor which completes the one of VectorialODE class and Bashforth class
    void SolveVectorialODE() override; //Precise definition of the virtual inherited method to solve the ODE using Bashforth 2 steps method
};

#endif //PCSC_VECTORIALODE_GROUP15_BASHFORTHSECONDSTEP_H
