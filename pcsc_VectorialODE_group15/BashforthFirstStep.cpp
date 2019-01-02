#include "BashforthFirstStep.h"

/**
 * \brief Constructor inherited from the Bashforth class (also inherited from VectorialODE)
 * @param input : Input object containing all variables needed to solve the ODE.
 * @param solution : Output object where we will store the solution.
 */
BashforthFirstStep::BashforthFirstStep(Input &input, Solution& solution) : Bashforth(input, solution) {}

/**
 * \brief Method allowing the implementation of Adam-Bashforth method 1 step.
 * This method is one of the several definition of the virtual inherited method.
 * There are no arguments as all information needed are stored and are accessible in the input object.
 * @return Void return as the solution is stored in the solution object.
 */
void BashforthFirstStep::SolveVectorialODE() {
    vector<double> tmp = GetColumnsOfMatrix(input->GetInitialConditionMatrix(), 0); //Set the initial condition to 0 and tmp_solution is the vector where the solution will be stored for each iteration.
    vector<double> tmp_solution = tmp; //Definition of the temporary vector storing for each step the solution
    solution->ModifySolutionByColumns(tmp, 0); //Definition of the initial solution with the initial condition
    vector<double> past_solution = GetColumnsOfMatrix(input->GetFunctionMatrix(),0); //Vector (i-1) at each iteration storing the function defining the system
    const double timestep = input->GetTimestep(); //Get the timestep and store it
    const double overall_timestep = input->GetNumberSteps(); //Get the overall number of timestep we will do and store it
    int position_to_write = 1; //Integer defining the position of the column of solution matrix where output is written

    for (int i = 1; i < overall_timestep; i++) { // Solve the system for a fixed number of time steps.
        tmp_solution = AddTwoVector(AddTwoVector(MultiplyWithVectorByRight(Multiply(input->GetCoefficientMatrix(), timestep),tmp),(MultiplyVectorAndScalar(tmp,1.0))), MultiplyVectorAndScalar(past_solution,timestep)); //Apply the definition of the Adam-Bashforth method 1 step : https://en.wikipedia.org/wiki/Linear_multistep_method#Adams%E2%80%93Bashforth_methods
        if (i%input->GetWriteOutputTimestep()==0.0) { // write output for each print time step.
            solution->ModifySolutionByColumns(tmp_solution, position_to_write);
            position_to_write++;
        }
        // Update the several variables to do a new step
        tmp = tmp_solution;
        past_solution = GetColumnsOfMatrix(input->GetFunctionMatrix(),i);
    }
}