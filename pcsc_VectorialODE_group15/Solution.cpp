#include "Solution.h"

#include <fstream>
#include <cassert>
using namespace std;

/**
 * \brief Default constructor
 */
Solution::Solution() = default;

/**
 * \brief Constructor to initialized properly the size of the solution with the input object.
 * This overwritten constructor allows the declaration of the solution matrix with the corresponding size and the initialisation of all elements to 0.
 * @param rows : Integer defining the number of rows in the solution matrix.
 * @param columns : Integer defining the number of columns in the solution matrix.
 */
Solution::Solution(unsigned long rows, int columns) {
    number_of_rows = rows;
    assert(number_of_rows > 0); //Assert that the number of rows is positive
    number_of_columns = columns;
    assert(number_of_columns > 0); //Assert that the number of columns is negative
    vector<vector<double>> v (number_of_rows, vector<double>(number_of_columns,0)); //Declaration and initialisation of all the elements to 0
    solutionODE = v; //Declaration and initialisation of the solutionODE attribute
}

/**
 * \brief Constructor to initialized properly the size of the solution with the input object.
 * This overwritten constructor allows the declaration of the solution matrix with the corresponding size and the initialisation of all elements to 0.
 * @param input : Input object containing all information to define the system and thus allowing the access to theses variables thanks to getter to define our solution matrix
 */
Solution::Solution(const Input &input) {
    number_of_rows = input.GetDimension();;
    assert(number_of_rows > 0); //Assert that the number of rows is positive
    number_of_columns = (input.GetNumberSteps()/input.GetWriteOutputTimestep());
    assert(number_of_columns > 0); //Assert that the number of columns is negative
    vector<vector<double>> v (number_of_rows, vector<double>(number_of_columns,0)); //Declaration and initialisation of all the elements to 0
    solutionODE = v; //Declaration and initialisation of the solutionODE attribute
}

/**
 * \brief Getter allowing the access to one particular element of the matrix solution given two indexes
 * @param RowsIndex : Integer defining the rows where we want to get the value of the element
 * @param ColumnsIndex : Integer defining the columns where we want to get the value of the element
 * @return Double corresponding to the defined element of the solution matrix
 */
const double Solution::GetSolutionValueFromIndex(int rowsIndex, int columnsIndex) const {
    return solutionODE[rowsIndex][columnsIndex];
}

/**
 * \brief Method that modify the solution matrix by reference given a columns index.
 * This method only modify the solution by columns, which means that the selected columns is erase and replace by the vector of our choice
 * @param vector : Vector of double use to modify the solution matrix. The value of this vector will be put in the selected columns of the solution matrix
 * @param position : Integer defining the index of the columns of the matrix solution we want to modify
 */
void Solution::ModifySolutionByColumns(vector<double>& vector, int position) {
    assert(vector.size() == number_of_rows); //Assert that the dimension of the vector we use to modify the matrix is the same as the matrix solution
    assert((position < number_of_columns)&(position >= 0)); //Assert that the position where we want to modify the solution matrix is positive and smaller than the maximum size of the matrix
    for (int i = 0; i < number_of_rows; ++i) {
        solutionODE[i][position] = vector[i];
    }
    //Print the execution of the program in the terminal
    for (int i = 0 ; i < number_of_rows; ++i){
        for (int j = 0 ; j < number_of_columns; ++j){
            cout<<solutionODE[i][j]<<'|';
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * \brief Method allowing the writing of the solution in a output file.
 * This method write the solution matrix into the file corresponding to the given filename.
 * @param filename : String corresponding to the entire path and filename of the file of destination. The filename needs to have the extension.
*/
void Solution::SolutionToFile(const string& filename) const {
    ofstream output(filename); //Set the filename as the ofstream
    output.precision(10); //Set the precision of the number we will write in the output file
    output.setf(ios::scientific); //Set the way of writing the output numbers
    assert(output.is_open()); //Check if the file is open. Really important step to avoid errors
    if (output.is_open()) {
        for (int i = 0; i < number_of_rows; i++) {
            for (int j = 0; j < number_of_columns; j++) {
                output << GetSolutionValueFromIndex(i, j) << " | ";
            }
            output << endl;
        }
        output.flush();
        output.close();
    }
}

vector<vector<double>> Solution::GetSolutionODE(){
    return solutionODE;
}

///Destructor by default
Solution::~Solution() = default;


