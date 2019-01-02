#ifndef PCSC_VECTORIALODE_GROUP15_BASHFORTHFIRSTSTEP_H
#define PCSC_VECTORIALODE_GROUP15_BASHFORTHFIRSTSTEP_H

#include "Bashforth.h"

/**
 *\brief Class implementing the Adam-Bashforth 1 step (Forward Euler) to solve the ODE system.
 * Bashforth method allows the solving of the ODE system.
 * This class is implementing in such a way that it only writes the solution every WriteOutputTimestep.
 * This class is inherited from Bashforth class also inherited from VectorialODE.
 */
class BashforthFirstStep : public Bashforth {
public:
    BashforthFirstStep(Input &input, Solution &solution); //Constructor which completes the one of VectorialODE class and Bashforth class
    void SolveVectorialODE() override; //Precise definition of the virtual inherited method to solve the ODE using Bashforth one step method
};

#endif //PCSC_VECTORIALODE_GROUP15_BASHFORTHFIRSTSTEP_H
