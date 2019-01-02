#include "BashforthThirdStep.h"

#include <cassert>

/**
 *\brief  Constructor inherited from the Bashforth class (also inherited from VectorialODE)
 * @param input : Input object containing all variables needed to solve the ODE.
 * @param solution : Output object where we will store the solution.
 */
BashforthThirdStep::BashforthThirdStep(Input &input, Solution& solution) : Bashforth(input, solution) {
    //Assertions
    assert(GetColumnsOfMatrix(input.GetInitialConditionMatrix(), 1).size()==input.GetDimension()); //Assert that the dimension of the initial conditions is the same as the system dimension
    assert(GetColumnsOfMatrix(input.GetInitialConditionMatrix(), 2).size()==input.GetDimension()); //Assert that the dimension of the initial conditions is the same as the system dimension
    assert(GetColumnsOfMatrix(input.GetFunctionMatrix(),1).size()==input.GetDimension()); //Assert that the dimension of the matrix containing the function defining the system is the same as the system dimension
}

/**
 * \brief Method allowing the implementation of Adam-Bashforth method 3 steps.
 * This method is one of the several definition of the virtual inherited method.
 * There are no arguments as all information needed are stored and are accessible in the input object.
 * @return Void return as the solution is stored in the solution object.
 */
void BashforthThirdStep::SolveVectorialODE() {
    vector<double> tmp1 = GetColumnsOfMatrix(input->GetInitialConditionMatrix(), 0); //tmp1 is a temporary vector that takes the solution vector (i-1) at each iteration.
    vector<double> tmp2 = GetColumnsOfMatrix(input->GetInitialConditionMatrix(), 1); //tmp2 is a temporary vector that takes the solution vector (i-2) at each iteration.
    vector<double> tmp3 = GetColumnsOfMatrix(input->GetInitialConditionMatrix(), 2); //tmp3 is a temporary vector that takes the solution vector (i-3) at each iteration.
    vector<double> tmp_solution = tmp1; //Definition of the temporary vector storing for each step the solution
    solution->ModifySolutionByColumns(tmp3, 0); //Definition of the initial solution with the initial condition
    if(1%input->GetWriteOutputTimestep()==0.0) solution->ModifySolutionByColumns(tmp2, 1); //Write output every WriteOutputTimestep.
    if(2%input->GetWriteOutputTimestep()==0.0) solution->ModifySolutionByColumns(tmp1, 2); //Write output every WriteOutputTimestep.
    vector<double> past_solution1 = GetColumnsOfMatrix(input->GetFunctionMatrix(),1); //Vector (i-1) at each iteration storing the function defining the system
    vector<double> past_solution2 = GetColumnsOfMatrix(input->GetFunctionMatrix(),0); //Vector (i-2) at each iteration storing the function defining the system
    const double timestep = input->GetTimestep(); //Get the timestep and store it
    const double overall_timestep = input->GetNumberSteps(); //Get the overall number of timestep we will do and store it
    int position_to_write = 3; //Integer defining the position of the column of solution matrix where output is written.

    for (int i = 3; i < overall_timestep; ++i) { //Solve the system for a fixed number of time steps.
        const vector<double> &past_solution3 = past_solution2; //Past_solution3 takes the value (i-3) at each iteration of the vector containing the function defining the system.
        past_solution2 = past_solution1; //Past_solution2 takes the value (i-2) at each iteration of the vector containing the function defining the system.
        past_solution1 = GetColumnsOfMatrix(input->GetFunctionMatrix(), i-1); //Past_solution1 takes the value (i-1) at each iteration of the vector containing the function defining the system.
        tmp_solution = AddTwoVector(SubtractTwoVector(SubtractTwoVector(AddTwoVector(AddTwoVector(MultiplyWithVectorByRight(Multiply(input->GetCoefficientMatrix(), timestep*23/12),tmp1),(MultiplyVectorAndScalar(tmp1,1.0))),MultiplyVectorAndScalar(past_solution1,(23/12*timestep))),MultiplyWithVectorByRight(input->GetCoefficientMatrix(),MultiplyVectorAndScalar(tmp2,(4/3*timestep)))),MultiplyVectorAndScalar(past_solution2,(timestep*4/3))),AddTwoVector(MultiplyVectorAndScalar(MultiplyWithVectorByRight(input->GetCoefficientMatrix(),tmp3),(timestep*5/12)),MultiplyVectorAndScalar(past_solution3,(timestep*5/12)))); //Apply the definition of the Adam-Bashforth method 1 step : https://en.wikipedia.org/wiki/Linear_multistep_method#Adams%E2%80%93Bashforth_methods
        if (i%input->GetWriteOutputTimestep()==0.0){ //Write output for each print time step
            solution->ModifySolutionByColumns(tmp_solution, position_to_write);
            position_to_write++;
        }
        // Update the several variables to do a new step
        tmp3 = tmp2;
        tmp2 = tmp1;
        tmp1 = tmp_solution;
    }
}
