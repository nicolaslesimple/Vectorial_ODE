#ifndef PCSC_VECTORIALODE_GROUP15_INPUT_H
#define PCSC_VECTORIALODE_GROUP15_INPUT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * \brief  Class allowing the saving of all the variables to define the system we want to solve.
 * In fact, it takes as input variable (integer or double): Timestep, Dimension, Order, NumberSteps, WriteOutputTimestep.
 * Moreover, Input object needs 3 matrix to define the system : InitialConditionMatrix, CoefficientMatrix, FunctionMatrix. Matrix are defined to be vector of vector of double.
 * Input variables are given to the input class by the constructor. The other methods are getter allowing the access to theses private attributes.
 */
class Input {
private:
    double*  Timestep;
    int* Dimension;
    int* Order;
    int* NumberSteps;
    int* WriteOutputTimestep;

    vector<vector<double>> InitialConditionMatrix;
    vector<vector<double>> CoefficientMatrix;
    vector<vector<double>> FunctionMatrix;

public:
    explicit Input();
    explicit Input(double time_step, int dimension, int order, int number_steps, int write_output_timestep,
          const  vector<vector<double>>& initial_condition_matrix,
          const vector<vector<double>>& changing_matrix,
          const  vector<vector<double>>& past_step_matrix); //Constructor defining the system

    int AskNumberToUser(); // Method allowing the asking of a number to the user.

    double& GetTimestep() const; //Getter for the double Timestep
    unsigned long GetDimension() const; //Getter for the integer Dimension
    int& GetOrder() const; //Getter for the integer Order
    int& GetNumberSteps() const; //Getter for the integer NumberSteps
    int& GetWriteOutputTimestep() const; //Getter for the integer WriteOutputTimestep

    vector<vector<double>> GetInitialConditionMatrix() const; //Getter for the matrix InitialConditionMatrix
    vector<vector<double>> GetCoefficientMatrix() const; //Getter for the matrix ChangingConditionMatrix
    vector<vector<double>> GetFunctionMatrix() const; //Getter for the matrix PastStepConditionMatrix

    ~Input(); //Destructor
};

#endif //PCSC_VECTORIALODE_GROUP15_INPUT_H
