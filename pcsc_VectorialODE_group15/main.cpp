#include "VectorialODE.h"
#include "Bashforth.h"
#include "BashforthFirstStep.h"
#include "BashforthSecondStep.h"
#include "BashforthThirdStep.h"
#include "BashforthFourthStep.h"
#include "RungeKuttaOrder2.h"
#include "RungeKuttaOrder4.h"

/**
 * \brief This function is the main executable of the project.
 * This main function use the VectorialODE package.
 * In this method 3 different hard code example of the VectorialODE process are implemented.
 * The user has to enter his choices. Some printings are done to show the running steps.
 * @return 0
 */
int main() {


    cout << "If you want to choose the parameters of the simulation, enter 'keyboard'"<<endl;
    cout << "If you want to run SimpleTest, enter 'simple'"<<endl;
    cout << "If you want to run the ComplexTest, enter 'complex'"<<endl;
    string user_choice;
    cin >> user_choice; //User has to make a choice

    if (user_choice=="keyboard"){

        VectorialODE *vectorialODE = nullptr;
        Input input;
        Solution solution(input); //Declaration of an solution object using the input object

        string filename;
        cout <<"Please write the path to the output file. Here is a example : C:/Users/nicol/Desktop/Group15/pcsc_VectorialODE_group15/Output/solution.csv"<<endl;
        cin >> filename;

        string method;
        cout << "Please, enter the symbol to define the solver : " << endl;
        cout << "   - B1, for Adam-Bashforth 1 step. " << endl;
        cout << "   - B2, for Adam-Bashforth 2 step. " << endl;
        cout << "   - B3, for Adam-Bashforth 3 step. " << endl;
        cout << "   - B4, for Adam-Bashforth 4 step. " << endl;
        cout << "   - RK2, for Runge-Kutta 2 step. " << endl;
        cout << "   - RK4, for Runge-Kutta 4 step. " << endl;
        cin >> method;
        //Declaration of the solver method we will use
        if (method == "B1"){vectorialODE = new BashforthFirstStep(input, solution);}
        else if (method == "B2"){vectorialODE = new BashforthSecondStep(input, solution);}
        else if (method == "B3"){vectorialODE = new BashforthThirdStep(input, solution);}
        else if (method == "B4"){vectorialODE = new BashforthFourthStep(input, solution);}
        else if (method == "RK2"){vectorialODE = new RungeKuttaOrder2(input, solution);}
        else if (method == "RK4"){vectorialODE = new RungeKuttaOrder4(input, solution);}
        else {cout << "You did not enter a correct symbol. The program fails. Try again to run the program." << endl;}

        vectorialODE->SolveVectorialODE(); //Apply the method to solve the problem
        solution.SolutionToFile(filename); //Write the solution in an output file

    } else if(user_choice == "simple"){

        //Declaration of all the variables used to define the input object
        const double time_step = 1;
        const int dimension = 4;
        const int order = 1;
        const int number_steps = 10;
        const int write_output_timestep = 1;
        vector<vector<double>> initial_condition_matrix = {{2},{2},{2},{2}};
        vector<vector<double>> coefficient_matrix = {{0, 0, 0, 0},
                                                  {0, 0, 0, 0},
                                                  {0, 0, 0, 0},
                                                  {0, 0, 0, 0}};

        vector<vector<double>> function_matrix (4, vector<double>(10,0));

        VectorialODE *vectorialODE = nullptr;
        Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
        Solution solution(input); //Declaration of an solution object using the input object

        string method;
        cout << "Please, enter the symbol to define the solver : " << endl;
        cout << "   - B1, for Adam-Bashforth 1 step. " << endl;
        cout << "   - B2, for Adam-Bashforth 2 step. " << endl;
        cout << "   - B3, for Adam-Bashforth 3 step. " << endl;
        cout << "   - B4, for Adam-Bashforth 4 step. " << endl;
        cout << "   - RK2, for Runge-Kutta 2 step. " << endl;
        cout << "   - RK4, for Runge-Kutta 4 step. " << endl;
        cin >> method;
        //Declaration of the solver method we will use
        if (method == "B1"){vectorialODE = new BashforthFirstStep(input, solution);}
        else if (method == "B2"){vectorialODE = new BashforthSecondStep(input, solution);}
        else if (method == "B3"){vectorialODE = new BashforthThirdStep(input, solution);}
        else if (method == "B4"){vectorialODE = new BashforthFourthStep(input, solution);}
        else if (method == "RK2"){vectorialODE = new RungeKuttaOrder2(input, solution);}
        else if (method == "RK4"){vectorialODE = new RungeKuttaOrder4(input, solution);}
        else {cout << "You did not enter a correct symbol. Try again to run the program." << endl;}

        vectorialODE->SolveVectorialODE(); //Apply the method to solve the problem

    } else if (user_choice=="complex"){
        //Declaration of all the variables used to define the input object
        const double time_step = 1;
        const int dimension = 2;
        const int order = 1;
        const int number_steps = 10;
        const int write_output_timestep = 1;
        vector<vector<double>> initial_condition_matrix = {{0},{0}};
        vector<vector<double>> coefficient_matrix = {{0, 0},
                                                  {0, 0}};
        vector<vector<double>> function_matrix = {{1,0.54,-0.41,-0.99,-0.66,0.28,0.96,0.75,-0.14,-0.91},
                                                   {1,0.54,-0.41,-0.99,-0.66,0.28,0.96,0.75,-0.14,-0.91}};

        VectorialODE *vectorialODE = nullptr;
        Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
        Solution solution(input); //Declaration of an solution object using the input object

        string method;
        cout << "Please, enter the symbol to define the solver : " << endl;
        cout << "   - B1, for Adam-Bashforth 1 step. " << endl;
        cout << "   - B2, for Adam-Bashforth 2 step. " << endl;
        cout << "   - B3, for Adam-Bashforth 3 step. " << endl;
        cout << "   - B4, for Adam-Bashforth 4 step. " << endl;
        cout << "   - RK2, for Runge-Kutta 2 step. " << endl;
        cout << "   - RK4, for Runge-Kutta 4 step. " << endl;
        cin >> method;
        //Declaration of the solver method we will use
        if (method == "B1"){vectorialODE = new BashforthFirstStep(input, solution);}
        else if (method == "B2"){vectorialODE = new BashforthSecondStep(input, solution);}
        else if (method == "B3"){vectorialODE = new BashforthThirdStep(input, solution);}
        else if (method == "B4"){vectorialODE = new BashforthFourthStep(input, solution);}
        else if (method == "RK2"){vectorialODE = new RungeKuttaOrder2(input, solution);}
        else if (method == "RK4"){vectorialODE = new RungeKuttaOrder4(input, solution);}
        else {cout << "You did not enter a correct symbol. Try again to run the program." << endl;}

        vectorialODE->SolveVectorialODE(); //Apply the method to solve the problem
    } else {
        cout << "You did not put a correct input. The program stops. Try to re run it."<<endl;
    }
    return 0;
}