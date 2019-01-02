#include "RungeKutta.h"


/**
 * \brief Constructor inherited from the VectorialODE class
 * @param input : Input object containing all variables needed to solve the ODE.
 * @param solution : Output object where we will store the solution.
 */
RungeKutta::RungeKutta(Input &input, Solution &solution) : VectorialODE(input, solution) {
    assert(input.GetInitialConditionMatrix()[0].size() <= input.GetOrder());//Assert that the number of initial conditions (which is the number of columns of the matrix) is inferior or equal to the system order
}

