//#define ENABLE_PROJECT_TEST  // Uncomment this line to enable the Project tests

#include "gtest/gtest.h"
#include "../../project/header/project.h"
 // Adjust this include path based on your project structure

class ProjectTest : public ::testing::Test {
protected:
    std::ostringstream out;
    std::istringstream in;
    void SetUp() override {
        out.str("");
        out.clear();
    }
    void TearDown() override {

    }
    void simulateUserInput(const std::string& input) {
        in.str(input);
        in.clear();
    }
};

TEST_F(ProjectTest, InsertionSortTest) {
    int arr[5] = { 5, 4, 3, 1, 2 };
    int sortedArr[5] = { 1, 2, 3, 4, 5 };

    InsertionSort(out, arr);
    std::string expectedOutput = "1.step: 4 5 3 1 2 \n";
    expectedOutput += "2.step: 3 4 5 1 2 \n";
    expectedOutput += "3.step: 1 3 4 5 2 \n";
    expectedOutput += "4.step: 1 2 3 4 5 \n";
    EXPECT_EQ(expectedOutput, out.str());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }

}

TEST_F(ProjectTest, MergeFunctionTest) {
    int arr[5] = { 2, 4, 5, 1, 3 };
    Merge(out, arr, 0, 2, 4);
    std::string expectedOutput = "Merged array from 0 to 4: 1 2 3 4 5 \n";
    EXPECT_EQ(expectedOutput, out.str());
    int expectedArr[5] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST_F(ProjectTest, MergeSortFunctionTest) {
    int arr[5] = { 5, 4, 3, 1, 2 };
    MergeSort(arr, 0, 4);
    int expectedArr[5] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST_F(ProjectTest, MergeSortPrintArrayTest) {
    int arr[5] = { 1, 2, 3, 4, 5 };
    MergeSortPrintArray(out, arr, 5);
    std::string expectedOutput = "1 2 3 4 5 \n";
    EXPECT_EQ(expectedOutput, out.str());
}


TEST_F(ProjectTest, ValidInputTest) {
    simulateUserInput("8\n7\n3\n47\n96\n");
    menu(in, out);
    std::string expectedOutput = "Please enter 5 numbers: \n";
    expectedOutput += "Please enter 1. number: ";
    expectedOutput += "Please enter 2. number: ";
    expectedOutput += "Please enter 3. number: ";
    expectedOutput += "Please enter 4. number: ";
    expectedOutput += "Please enter 5. number: ";
    expectedOutput += "--------------------------------------------------\n";
    expectedOutput += "Sorting with Insertion Sort: \n";
    expectedOutput += "1.step: 7 8 3 47 96 \n";
    expectedOutput += "2.step: 3 7 8 47 96 \n";
    expectedOutput += "3.step: 3 7 8 47 96 \n";
    expectedOutput += "4.step: 3 7 8 47 96 \n";
    expectedOutput += "Insertion Sort Result: 3 7 8 47 96 \n";
    expectedOutput += "Sorting with Merge Sort: 3 7 8 47 96 \n";
    EXPECT_EQ(expectedOutput, out.str());
}

TEST_F(ProjectTest, NonNumberInputTest) {
    simulateUserInput("**\n8\n7\n3\n47\n96\n");
    menu(in, out);
    std::string expectedOutput = "Please enter 5 numbers: \n";
    expectedOutput += "Please enter 1. number: ";
    expectedOutput += "Error: Please enter a valid number.\n";
    expectedOutput += "Please enter 1. number: ";
    expectedOutput += "Please enter 2. number: ";
    expectedOutput += "Please enter 3. number: ";
    expectedOutput += "Please enter 4. number: ";
    expectedOutput += "Please enter 5. number: ";
    expectedOutput += "--------------------------------------------------\n";
    expectedOutput += "Sorting with Insertion Sort: \n";
    expectedOutput += "1.step: 7 8 3 47 96 \n";
    expectedOutput += "2.step: 3 7 8 47 96 \n";
    expectedOutput += "3.step: 3 7 8 47 96 \n";
    expectedOutput += "4.step: 3 7 8 47 96 \n";
    expectedOutput += "Insertion Sort Result: 3 7 8 47 96 \n";
    expectedOutput += "Sorting with Merge Sort: 3 7 8 47 96 \n";
    EXPECT_EQ(expectedOutput, out.str());
}
/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_PROJECT_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}