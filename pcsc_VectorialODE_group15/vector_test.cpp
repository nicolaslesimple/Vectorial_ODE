#include "BashforthFirstStep.h"
#include "VectorialODE.h"
#include "BashforthSecondStep.h"
#include "BashforthThirdStep.h"
#include "BashforthFourthStep.h"
#include "RungeKuttaOrder2.h"
#include "RungeKuttaOrder4.h"

#include <gtest/gtest.h>

/**
 * \brief Test the function MultiplyMatrixScalar() defined in the VectorialODE class
 */
TEST(VectorTest, MultiplyMatrixScalar) 
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<vector<double>> matrix = { {1, 2, 3},{4, 5, 6} };
	vector<vector<double>> m = vectorialODE->Multiply(matrix, 2);
	vector<vector<double>> comp = { {2, 4, 6}, { 8,10,12 } };

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i;
        }
    }
}

/**
 * \brief Test the function Addition() defined in the VectorialODE class
 */
TEST(VectorTest, Addition)
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<vector<double>> matrix = { {1, 2, 3},{4, 5, 6} };
	vector<vector<double>> m = vectorialODE->Addition(matrix, 2);
	vector<vector<double>> comp = { {3, 4, 5}, { 6,7,8 } };

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i;
        }
    }
}

/**
 * \brief Test the function MultiplyWithVectorByRight() defined in the VectorialODE class
 */
TEST(VectorTest, MultiplyMatrixVector)
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<vector<double>> matrix = { {1, 2, 3},{4, 5, 6} };
	vector<double> vect = { 1, 2, 1 };
	vector<double> v = vectorialODE->MultiplyWithVectorByRight(matrix, vect);
	vector<double> comp = { 8, 20 };

    ASSERT_EQ(v.size(), comp.size()) << "Vectors v and comp are of unequal length";

    for (int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], comp[i]) << "Vectors v and comp differ at index " << i;
    }

}

/**
 * \brief Test the function MultiplyVectorAndScalar() defined in the VectorialODE class
 */
TEST(VectorTest, MultiplyVectorAndScalar)
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<double> vect = { 1, 2, 3 };
	double scalar = 2;
	vector<double> v = vectorialODE->MultiplyVectorAndScalar(vect, scalar);
	vector<double> comp = { 2, 4, 6 };

    ASSERT_EQ(v.size(), comp.size()) << "Vectors v and comp are of unequal length";

    for (int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], comp[i]) << "Vectors v and comp differ at index " << i;
    }

}

/**
 * \brief Test the function AddTwoVector() defined in the VectorialODE class
 */
TEST(VectorTest, AddTwoVector)
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<double> v1 = { 1, 2, 3 };
	vector<double> v2 = { 1, 3, 1 };
	vector<double> v = vectorialODE->AddTwoVector(v1, v2);
	vector<double> comp = { 2, 5, 4 };

    ASSERT_EQ(v.size(), comp.size()) << "Vectors v and comp are of unequal length";

    for (int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], comp[i]) << "Vectors v and comp differ at index " << i;
    }
}

/**
 * \brief Test the function SubtractTwoVector() defined in the VectorialODE class
 */
TEST(VectorTest, SubtractTwoVector)
{
    // Declaration of variables we need
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
    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.
    Solution solution(input);
    VectorialODE *vectorialODE = nullptr;
    vectorialODE = new BashforthFirstStep(input, solution);

	vector<double> v1 = { 1, 2, 3 };
	vector<double> v2 = { 1, 3, 1 };
	vector<double> v = vectorialODE->SubtractTwoVector(v1, v2);
	vector<double> comp = { 0, -1, 2 };

    ASSERT_EQ(v.size(), comp.size()) << "Vectors v and comp are of unequal length";

    for (int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], comp[i]) << "Vectors v and comp differ at index " << i;
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the BashforthFirstStep class
 */
TEST(VectorTest, BashforthFirstStep){
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
    vectorialODE = new BashforthFirstStep(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i<<','<< j;
        }
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the BashforthSecondStep class
 */
TEST(VectorTest, BashforthSecondStep){
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
    vectorialODE = new BashforthSecondStep(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 4; j < m[0].size(); ++j) { //We began to check equlity at the third step as it can takes two step to converge to the solution.
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i<<','<< j;
        }
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the BashforthThirdStep class
 */
TEST(VectorTest, BashforthThirdStep) {
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
    vectorialODE = new BashforthThirdStep(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 4; j < m[0].size(); ++j) { //We began to check equlity at the third step as it can takes two step to converge to the solution.
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i<<','<< j;
        }
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the BashforthFourthStep class
 */
TEST(VectorTest, BashforthFourthStep) {
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
    vectorialODE = new BashforthFourthStep(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 4; j < m[0].size(); ++j) { //We began to check equality at the third step as it can takes two step to converge to the solution.
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i<<','<< j;
        }
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the RungeKuttaOrder2 class
 */
TEST(VectorTest, RungeKuttaOrder2){
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
    vectorialODE = new RungeKuttaOrder2(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size()-1; ++j) {
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors v and comp differ at index " << i<<','<< j;
        }
    }
}

/**
 * \brief Test the function SolveVectorialODE() defined in the RungeKuttaOrder4 class
 */
TEST(VectorTest, RungeKuttaOrder4){
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
    vectorialODE = new RungeKuttaOrder4(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<vector<double>> m = solution.GetSolutionODE();
    vector<vector<double>> comp  (4, vector<double>(10,2));

    ASSERT_EQ(m.size(), comp.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), comp[0].size()) << "Vectors m and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size()-1; ++j) {
            EXPECT_EQ(m[i][j], comp[i][j]) << "Vectors m and comp differ at index " << i <<','<< j;
        }
    }
}

/**
 * \brief Test the function GetColumnsOfMatrix() defined in the vectorialODE class
 */
TEST(VectorTest, GetColumnsOfMatrix){
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
    vectorialODE = new RungeKuttaOrder4(input, solution);

    vector<double> v = vectorialODE->GetColumnsOfMatrix(coefficient_matrix,0);
    vector<double> comp  (4,0);

    ASSERT_EQ(v.size(), comp.size()) << "Vectors v and comp are of unequal shape";

    for (int i = 0; i < v.size(); ++i) {
            EXPECT_EQ(v[i], comp[i]) << "Vectors v and comp differ at index " << i;
    }
}

/**
 * \brief Test the function GetSolutionValueFromIndex() defined in the Solution class
 */
TEST(VectorTest, GetSolutionValueFromIndex){
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
    vectorialODE = new RungeKuttaOrder4(input, solution);
    vectorialODE->SolveVectorialODE();

    EXPECT_EQ(solution.GetSolutionValueFromIndex(0,0), 2);

}

/**
 * \brief Test the function ModifySolutionByColumns() defined in the Solution class
 */
TEST(VectorTest, ModifySolutionByColumns){
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
    vectorialODE = new RungeKuttaOrder4(input, solution);
    vectorialODE->SolveVectorialODE();

    vector<double> tmp = {10, 10, 10, 10};

    solution.ModifySolutionByColumns(tmp , 0);
    vector<vector<double>> m = solution.GetSolutionODE();
    vector<double> comp  (4,10);

    ASSERT_EQ(m.size(), comp.size()) << "Vectors v and comp are of unequal shape";

    for (int i = 0; i < m.size(); ++i) {
        EXPECT_EQ(m[i][0], comp[i]) << "Vectors v and comp differ at index " << i;
    }

}

/**
 * \brief Test the class Input by testing all the getter in teh same test
 */
TEST(VectorTest, Input){
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

    Input input(time_step, dimension, order, number_steps, write_output_timestep, initial_condition_matrix, coefficient_matrix, function_matrix); //Declaration of an input object.

    ASSERT_EQ(1, input.GetTimestep());
    ASSERT_EQ(4, input.GetDimension());
    ASSERT_EQ(1, input.GetOrder());
    ASSERT_EQ(10, input.GetNumberSteps());
    ASSERT_EQ(1, input.GetWriteOutputTimestep());

    vector<vector<double>> m = input.GetInitialConditionMatrix();
    ASSERT_EQ(m.size(), initial_condition_matrix.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(m[0].size(), initial_condition_matrix[0].size()) << "Vectors m and comp are of unequal shape";
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size()-1; ++j) {
            EXPECT_EQ(m[i][j], initial_condition_matrix[i][j]) << "Vectors m and comp differ at index " << i <<','<< j;
        }
    }

    vector<vector<double>> l = input.GetFunctionMatrix();
    ASSERT_EQ(l.size(), function_matrix.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(l[0].size(), function_matrix[0].size()) << "Vectors m and comp are of unequal shape";
    for (int i = 0; i < l.size(); ++i) {
        for (int j = 0; j < l[0].size()-1; ++j) {
            EXPECT_EQ(l[i][j], function_matrix[i][j]) << "Vectors m and comp differ at index " << i <<','<< j;
        }
    }

    vector<vector<double>> k = input.GetCoefficientMatrix();
    ASSERT_EQ(k.size(), coefficient_matrix.size()) << "Vectors m and comp are of unequal shape";
    ASSERT_EQ(k[0].size(), coefficient_matrix[0].size()) << "Vectors m and comp are of unequal shape";
    for (int i = 0; i < k.size(); ++i) {
        for (int j = 0; j < k[0].size()-1; ++j) {
            EXPECT_EQ(k[i][j], coefficient_matrix[i][j]) << "Vectors m and comp differ at index " << i <<','<< j;
        }
    }

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}