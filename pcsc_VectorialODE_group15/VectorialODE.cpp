#include <cassert>
#include "VectorialODE.h"

///Constructor by default which is empty.
VectorialODE::VectorialODE() = default;

/**
 * Constructor which overridden the default one.
 * @param input_object : Object of Input class containing all the input informations we need to define and solve the problem.
 * @param output_object : Object of Solution class containing the initialised solution matrix where we will write the results.
 */
VectorialODE::VectorialODE(Input& input_object, Solution& solution_object) {
    input = &input_object;
    solution = &solution_object;
    assert(input->GetFunctionMatrix()[0].size()==input->GetNumberSteps());//Assert that the number of point of the function matrix is the same as number of step we will do to solve the system
    assert(GetColumnsOfMatrix(input->GetFunctionMatrix(),0).size()==input->GetDimension());//Assert that the number of line of the function matrix is the same as the dimension of the system
    assert(input->GetCoefficientMatrix()[0].size()==GetColumnsOfMatrix(input->GetInitialConditionMatrix(),0).size());//Assert that the number of columns in the matrix is the same as the number of line of the input matrix
    assert(GetColumnsOfMatrix(input->GetInitialConditionMatrix(),0).size()==input->GetDimension());//Assert that the number of lines in the input matrix is the same as the dimension of the system
}

/**
 * \brief Method allowing the access to one columns of one matrix.
 * The chosen columns is define by the index. This method we be accessible in the inherited classes.
 * @param matrix : Vector of vector of double representing the matrix we want to access.
 * @param position : Integer corresponding to the index of the columns of the matrix we will return.
 * @return Vector of double corresponding to one columns of the matrix given by the index
 */
vector<double> VectorialODE::GetColumnsOfMatrix(vector<vector<double>> matrix, int position) {
    vector<double> column (matrix.size()); //Declaration of the returned vector
    for (int i = 0; i < matrix.size(); ++i) {
        column[i] = matrix[i][position];
    }
    return column;
}

/**
 * \brief Method allowing the multiplication of a matrix with a scalar.
 * This method we be accessible in the inherited classes.
 * @param matrix : Vector of vector of double representing the matrix we want to multiply.
 * @param scalar : Integer corresponding to the scalar we want to multiply.
 * @return Vector of vector of double (which is a matrix) corresponding to the output of the multiplication.
 */
vector<vector<double>> VectorialODE::Multiply(const vector<vector<double>>& matrix, const double scalar ) {
    unsigned long number_of_rows = matrix.size(); //Definition of one dimension of the return matrix
    unsigned long number_of_columns = matrix[0].size(); //Definition of the second dimension of the return matrix
    vector<vector<double>> matrix_to_return (number_of_rows, vector<double>(number_of_columns,0)); //Declaration of the returned matrix and initialisation of all elements to 0
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            matrix_to_return[i][j] = matrix[i][j]*scalar;
        }
    }
    return matrix_to_return;
}

/**
 * \brief Method allowing the addition of a matrix with a scalar.
 * This method we be accessible in the inherited classes.
 * @param matrix : Vector of vector of double representing the matrix we want to add.
 * @param scalar : Integer corresponding to the scalar we want to add.
 * @return Vector of vector of double (which is a matrix) corresponding to the output of the addition.
 */
vector<vector<double>> VectorialODE::Addition(const vector<vector<double>>& matrix, const double scalar ) {
    unsigned long number_of_rows = matrix.size(); //Definition of one dimension of the return matrix
    unsigned long number_of_columns = matrix[0].size(); //Definition of the second dimension of the return matrix
    vector<vector<double>> matrix_to_return (number_of_rows, vector<double>(number_of_columns,0)); //Declaration of the returned matrix and initialisation of all elements to 0
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            matrix_to_return[i][j] = matrix[i][j]+scalar;
        }
    }
    return matrix_to_return;
}

/**
 * \brief Method allowing the multiplication of a matrix with a vector coming from the right side of the matrix.
 * This method we be accessible in the inherited classes.
 * @param matrix : Vector of vector of double representing the matrix we want to multiply.
 * @param matrix_columns : Vector of double corresponding to the vector we want to multiply.
 * @return Vector of double (which is a vector) corresponding to the output of the multiplication.
 */
vector<double> VectorialODE::MultiplyWithVectorByRight(const vector<vector<double>>& matrix, const vector<double>& matrix_columns ) {
    unsigned long vector_size = matrix_columns.size(); //Define and save the size of the input vector
    assert(matrix[0].size() == vector_size); //Assert if the number of columns of the matrix is the same as the number of lines of the vector which is the rule for this kind of operation.
    unsigned long output_vector_size = matrix.size(); //Define and save the size of the returned vector
    vector<double> output_vector(output_vector_size, 0); //Declaration of the returned vector and initialisation of all elements to 0
    for (int i = 0; i < output_vector_size; ++i) {
        for (int j = 0; j < vector_size; ++j) {
            output_vector[i] += (matrix[i][j]*matrix_columns[j]);
        }
    }
    return output_vector;
}

/**
 * \brief Method allowing the multiplication of a vector with a scalar.
 * This method we be accessible in the inherited classes.
 * @param vector_to_multiply : Vector of double representing the vector we want to multiply.
 * @param scalar : Integer corresponding to the scalar we want to multiply.
 * @return Vector of double (which is a vector) corresponding to the output of the multiplication.
 */
vector<double> VectorialODE::MultiplyVectorAndScalar(const vector<double>& vector_to_multiply, double scalar) {
    vector<double> vector_to_return(vector_to_multiply.size(),0); //Declaration of the returned vector and initialisation of all elements to 0
    for (int i = 0; i < vector_to_multiply.size(); ++i) {
        vector_to_return[i] = scalar*vector_to_multiply[i];
    }
    return vector_to_return;
}

/**
 * \brief Method allowing the addition of two vectors.
 * This method we be accessible in the inherited classes.
 * @param vector_1 : Vector of double representing the first vector we want to add.
 * @param vector_2 : Vector of double representing the second vector we want to add.
 * @return Vector of double (which is a vector) corresponding to the output of the addition.
 */
vector<double> VectorialODE::AddTwoVector(const vector<double>& vector_1,  const vector<double>& vector_2){
    assert(vector_1.size() == vector_2.size()); //Assert that the two vector have the same size. Otherwise the addition is impossible.
    vector<double> vector_to_return (vector_1.size(),0); //Declaration of the returned vector and initialisation of all elements to 0
    for (int i = 0; i < vector_1.size(); ++i) {
        vector_to_return[i] = vector_1[i] + vector_2[i];
    }
    return vector_to_return;
}

/**
 * \brief Method allowing the subtraction of two vectors.
 * This method we be accessible in the inherited classes.
 * @param vector_1 : Vector of double representing the first vector we want to subtract.
 * @param vector_2 : Vector of double representing the second vector we want to subtract.
 * @return Vector of double (which is a vector) corresponding to the output of the subtraction.
 */
vector<double> VectorialODE::SubtractTwoVector(const vector<double>& vector_1,  const vector<double>& vector_2){
    assert(vector_1.size() == vector_2.size()); //Assert that the two vector have the same size. Otherwise the addition is impossible.
    vector<double> vector_to_return (vector_1.size(),0); //Declaration of the returned vector and initialisation of all elements to 0
    for (int i = 0; i < vector_1.size(); ++i) {
        vector_to_return[i] = vector_1[i] - vector_2[i];
    }
    return vector_to_return;
}

///Destructor by default
VectorialODE::~VectorialODE() = default;
