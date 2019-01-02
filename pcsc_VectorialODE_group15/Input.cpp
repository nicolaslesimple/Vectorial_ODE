#include "Input.h"

#include <cassert>

/**
 * \brief Constructor allowing the definition of the system we want to solve.
 * In this class, the three input matrix were hardcode with the order of the system.
 */
Input::Input(){
    Timestep = new double;
    NumberSteps = new int;
    Order = new int;
    Dimension = new int;
    WriteOutputTimestep = new int;
    cout << "Please, enter the size of the timestep. It can be a double :" << endl;
    *Timestep = AskNumberToUser();
    cout << "Please, enter the overall number of timesteps. It should be a integer : " << endl;
    *NumberSteps = AskNumberToUser();
    cout << "Please, enter the order of the system. It should be a integer : " << endl;
    *Order = AskNumberToUser();
    cout << "Please, enter the dimension of the system. It should be a integer." << endl;
    *Dimension = AskNumberToUser();
    cout << "Please, enter the size of interval of timestep defining two saving points. It should be a integer : " << endl;
    *WriteOutputTimestep = AskNumberToUser();

    assert(*NumberSteps % *WriteOutputTimestep == 0);//Assert that the rest of the division between the overall number of steps to solve the system and the time step defining when we write the solution is 0

    vector<vector<double>> initial_condition_matrix = {{6},{4}};
    vector<vector<double>> coefficient_matrix = {{1, -1}, {-1, 1}};
    vector<vector<double>> function_matrix (2, vector<double>(10,0));

    InitialConditionMatrix = initial_condition_matrix;
    CoefficientMatrix = coefficient_matrix;
    FunctionMatrix = function_matrix;
}

/**
 * \brief Constructor of the class allowing the definition of the system.
 * @param time_step : Double representing the time step we will use in the ODE solver.
 * @param dimension : Integer representing the dimension of the system.
 * @param order : Integer representing the order of the system.
 * @param number_steps : Integer representing the overall number of steps we will do to solve the system.
 * @param write_output_timestep : Integer representing the steps when we write the solutions
 * @param initial_condition_matrix : Matrix (which is a vector of vector of double) representing the initial conditions of the system.
 * @param coefficient_matrix : Matrix (which is a vector of vector of double) containing the value of the function defining the system for all the step we want to compute.
 * @param function_matrix :  Matrix (which is a vector of vector of double) allowing the definition of the RHS of the ODE.
 */
Input::Input(double time_step, int dimension, int order, int number_steps, int write_output_timestep,
             const vector<vector<double>>& initial_condition_matrix ,
             const vector<vector<double>>& coefficient_matrix,
             const vector<vector<double>>& function_matrix) {

    assert(number_steps % write_output_timestep == 0);//Assert that the rest of the division between the overall number of steps to solve the system and the time step defining when we write the solution is 0
    Timestep = new double;
    NumberSteps = new int;
    Order = new int;
    Dimension = new int;
    WriteOutputTimestep = new int;
    *Timestep = time_step;
    *NumberSteps = number_steps;
    *Order = order;
    *Dimension = dimension;
    *WriteOutputTimestep = write_output_timestep;

    InitialConditionMatrix = initial_condition_matrix;
    CoefficientMatrix = coefficient_matrix;
    FunctionMatrix = function_matrix;
}

/**
 * \brief Method allowing the asking of a number to the user.
 * The user will enter this input number thank to the keyboard.
 * @return : Returns the integer number given by the user.
 */
int Input::AskNumberToUser() {
    int enter_number;
    cin >> enter_number;
    while (enter_number <= 0) {
        cerr << "The value is negative. It must be superior to 0." << endl;
        cout << "Enter a new number" << endl;
        cin >> enter_number;
    }
    cout << "Input received" << endl;
    return enter_number;
}

/**
 * \brief Return the time step attribute
 */
double& Input::GetTimestep() const {
    return *Timestep;
}

/**
 * \brief Return the dimension attribute
 */
unsigned long Input::GetDimension() const {
    return *Dimension;
}

/**
 * \brief Return the solver attribute
 */
int& Input::GetOrder() const {
    return *Order;
}

/**
 * \brief Return the overall number of steps attribute
 */
int& Input::GetNumberSteps() const {
    return *NumberSteps;
}

/**
 * \brief Return the Timestep defining when we write the output solution
 */
int& Input::GetWriteOutputTimestep() const {
    return *WriteOutputTimestep;
}

/**
 * \brief Return the initial condition matrix
 */
vector<vector<double>> Input::GetInitialConditionMatrix() const {
    return InitialConditionMatrix;
}

/**
 * \brief Return the changing matrix corresponding to several states when the program run
 */
vector<vector<double>> Input::GetCoefficientMatrix() const {
    return CoefficientMatrix;
}

/**
 * \brief Return the past step corresponding to i-1 for the function defining the problem
 */
vector<vector<double>> Input::GetFunctionMatrix() const {
    return FunctionMatrix;
}

/**
 * \brief Destructor allowing the liberation of memory
 */
Input::~Input(){
    delete Timestep;
    delete NumberSteps;
    delete Order;
    delete Dimension;
    delete WriteOutputTimestep;
}