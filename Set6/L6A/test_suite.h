#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "List.hpp"

#include <string>

/** 
 * @brief Test suite. Runs all tests.
 * @param P_list constant pointer list to test
 * @param NUM_TESTS_TO_RUN number of tests to run (default run all)
 * @return true if all tests pass, false otherwise
 */
bool run_all_tests(IList<int>* const P_list, const int NUM_TESTS_TO_RUN);

/**
 * @brief runs time tests to perform insert, read, write, remove operations
 * 
 */
void run_stress_tests();

#endif