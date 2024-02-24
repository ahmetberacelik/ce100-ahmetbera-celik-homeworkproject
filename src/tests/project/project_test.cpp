//#define ENABLE_PROJECT_TEST  // Uncomment this line to enable the Project tests

#include "gtest/gtest.h"
#include "../../project/header/project.h"  // Adjust this include path based on your project structure



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