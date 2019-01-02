#ifndef PCSC_VECTORIALODE_GROUP15_VECTORIALODESOLVE_H
#define PCSC_VECTORIALODE_GROUP15_VECTORIALODESOLVE_H

#include "Input.h"
#include "Solution.h"

#include <string>

/**
 * \brief Class allowing the definition ODE solvers. This is an abstract class.
 * The method SolveVectorialODE is virtual and it will be defined in different ways in the inherited classes.
 */

class VectorialODE
{
protected:
    Input *input; //Object where all the necessary input variables are stored.
    Solution *solution; //Object where we will put the solution of the solver for each step.

public:
    VectorialODE(); //Default constructor for class which is empty
    VectorialODE(Input& input_object, Solution& solution_object); //Constructor which is the overridden version of the default one.

    virtual void SolveVectorialODE() = 0; //Virtual method that will be defined in the class to solve the system using different technics.

    vector<double> GetColumnsOfMatrix(vector<vector<double>> matrix, int position); //Method allowing the access to one columns of the matrix put as argument.

    vector<vector<double>> Multiply(const vector<vector<double>>& matrix, double number); //Method defining the multiplication of a matrix by a scalar
    vector<vector<double>> Addition(const vector<vector<double>>& matrix, double number); //Method defining the addition of a matrix with a scalar
    vector<double> MultiplyWithVectorByRight(const vector<vector<double>>& matrix, const vector<double> &matrix_columns );//Method defining the multiplication of a matrix by a vector coming from the right.
    vector<double> MultiplyVectorAndScalar(const vector<double>& vector_to_multiply,  double scalar);//Method defining the multiplication between a vector and a scalar
    vector<double> AddTwoVector(const vector<double>& vector_1,  const vector<double>& vector_2);//Method defining the addition of two vector
    vector<double> SubtractTwoVector(const vector<double>& vector_1,  const vector<double>& vector_2);//Method defining the substraction of two vectors


    ~VectorialODE(); //Overridden destructor for Solver class
};


#endif //PCSC_VECTORIALODE_GROUP15_VECTORIALODESOLVE_H