#include "RungeKuttaOrder2.h"

/**
 * \brief Constructor inherited from the RungeKutta class (also inherited from VectorialODE)
 * @param input : Input object containing all variables needed to solve the ODE.
 * @param solution : Output object where we will store the solution.
 */
RungeKuttaOrder2::RungeKuttaOrder2(Input &input, Solution& solution) : RungeKutta(input, solution) {}

/**
 * \brief Method allowing the implementation of Runge-Kutta method 2 step.
 * This method is one of the several definition of the virtual inherited method.
 * There are no arguments as all information needed are stored and are accessible in the input object.
 * @return Void return as the solution is stored in the solution object.
 */
void RungeKuttaOrder2::SolveVectorialODE() {
    //Declaration and initialisation to 0 for all vector we need to solve the system
    vector<double> tmp1 = GetColumnsOfMatrix(input->GetInitialConditionMatrix(),
                                             0); //Set the initial condition to 0 and tmp_solution is the vector where the solution will be stored for each iteration.
    vector<double> tmp2(input->GetDimension(), 0);
    vector<double> kutta1(input->GetDimension(), 0);
    vector<double> kutta2(input->GetDimension(), 0);
    vector<double> store(input->GetDimension(), 0);

    solution->ModifySolutionByColumns(tmp1, 0); //Definition of the initial solution with the initial condition
    int position_to_write = 1; //Integer defining the position of the column of solution matrix where output is written
    const double timestep = input->GetTimestep(); //Get the timestep and store it
    const double overall_timestep = input->GetNumberSteps(); //Get the overall number of timestep we will do and store it

    for (int i = 1; i <
                    overall_timestep; ++i) { // Solve the system for a fixed number of time steps. Runge-Kutta method needs the timestep i-1 to interpolate so this method will integrate it
        kutta1 = AddTwoVector(MultiplyWithVectorByRight(input->GetCoefficientMatrix(), tmp1),
                              GetColumnsOfMatrix(input->GetFunctionMatrix(), i));
        tmp2 = GetColumnsOfMatrix(input->GetFunctionMatrix(), 1 + i);
        store = MultiplyVectorAndScalar(AddTwoVector(tmp2, GetColumnsOfMatrix(input->GetFunctionMatrix(), i)),
                                        0.5); //Interpolating
        kutta2 = AddTwoVector(MultiplyWithVectorByRight((input->GetCoefficientMatrix()), AddTwoVector(tmp1,
                                                                                                   MultiplyVectorAndScalar(
                                                                                                           kutta1,
                                                                                                           (timestep /
                                                                                                            2)))),
                              store);
        tmp1 = AddTwoVector(tmp1, MultiplyVectorAndScalar(kutta2,
                                                          (timestep))); //Apply the definition of the Runge-Kutta method 1 step : https://fr.wikipedia.org/wiki/M%C3%A9thodes_de_Runge-Kutta
        if (i % input->GetWriteOutputTimestep() == 0.0) { // write output for each print time step.
            solution->ModifySolutionByColumns(tmp1, position_to_write);
            position_to_write++;
        }
    }
}