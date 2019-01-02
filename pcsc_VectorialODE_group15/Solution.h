#ifndef PCSC_VECTORIALODE_GROUP15_SOLUTION_H
#define PCSC_VECTORIALODE_GROUP15_SOLUTION_H

#include "Input.h"

#include <vector>
using namespace std;

/**
 * \brief This class allows the saving in the memory and the writing in a output file of the solution of the ODE system.
 * The constructor need the input object defining the system to create a consistent format for the solution.
 * In this class, method allowing the retrieve, the modification and the writing of the solution are implemented.
 * The attributes of this class are the the solution matrix and two integer defining the size of this solution.
 */
class Solution {
private:
    unsigned long number_of_rows;
    int number_of_columns;
    vector<vector<double>> solutionODE;

public :
    Solution(); //Default constructor
    explicit Solution(unsigned long rows, int columns); //Overwritten constructor allowing the declaration of the solution matrix and the initialisation to 0
    explicit Solution(const Input &input); //Overwritten constructor allowing the declaration of the solution matrix taking input object as argument

    const double GetSolutionValueFromIndex(int rowsIndex, int columnsIndex) const; //Getter allowing the access to one particular element of the matrix solution
    void ModifySolutionByColumns(vector<double>& vector, int position); //Method that modify the solution matrix by reference
    void SolutionToFile(const string& filename) const; //Method allowing the writing of the solution in a output file
    vector<vector<double>> GetSolutionODE();

    ~Solution(); //Destructor
};

#endif //PCSC_VECTORIALODE_GROUP15_SOLUTION_H

