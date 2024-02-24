//#define ENABLE_PROJECT_TEST  // Uncomment this line to enable the Project tests

#include "gtest/gtest.h"
#include "../header/insertionsort.h"
#include "../../project/header/project.h"  // Adjust this include path based on your project structure

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
    int arr[5] = { 3, 1, 4, 5, 2 };
    int sortedArr[5] = { 1, 2, 3, 4, 5 };

    InsertionSort(arr);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }
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