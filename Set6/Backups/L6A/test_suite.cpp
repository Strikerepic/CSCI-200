#include "test_suite.h"

#include "Array.hpp"
#include "LinkedList.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MESSAGE_WIDTH = 40;

const string PASSED_MESSAGE = "    PASSED   \n";

void print_test_row(const int TEST_NUM, const string MESSAGE, const string RESULT) {
    cout << "Test #" << setw(3) << right << TEST_NUM;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    cout << RESULT;
}

int test_int(int &testNum, const string MESSAGE, const int LHS, const int RHS)  {
    string result;
    if (LHS == RHS) {
        result = PASSED_MESSAGE;
    } else {
        result = " !!>FAILED<!! Returned: \"";
        result += to_string(LHS);
        result += "\" != Expected: \"";
        result += to_string(RHS);
        result += "\"\n";
    }
    print_test_row(++testNum, MESSAGE, result);
    return LHS == RHS ? 1 : 0;
}

int test_exception(int& testNum, const std::string MESSAGE, const bool EXCEPTION_THROWN) {
    string result;
    if (EXCEPTION_THROWN)
        result = PASSED_MESSAGE;
    else
        result = " !!>FAILED<!! Exception thrown when it shouldn't\n";
    print_test_row(++testNum, MESSAGE, result);
    return EXCEPTION_THROWN ? 1 : 0;
}

int test_exception_not(int& testNum, const std::string MESSAGE, const bool EXCEPTION_NOT_THROWN) {
    string result;
    if (EXCEPTION_NOT_THROWN)
        result = " !!>FAILED<!! This should not occur, function was used incorrectly\n";
    else
        result = " !!>FAILED<!! Exception not thrown when it should\n";
    print_test_row(++testNum, MESSAGE, result);
    return 0;
}

void print_header_top() {
    cout << endl;
    cout << "/" << setw(MESSAGE_WIDTH*2) << setfill('-') << right << "\\" << endl;
    cout << setfill(' ');
}

void print_header_row(const std::string MESSAGE) {
    const int MSG_LEN = MESSAGE.length();
    const int BOX_WIDTH = MESSAGE_WIDTH*2 + 2;
    const int PADDING_LEFT = (BOX_WIDTH - MSG_LEN) / 2 ;
    const int PADDING_RIGHT = (BOX_WIDTH - MSG_LEN) / 2 + (MSG_LEN % 2 ? 1 : 0);
    cout << setw(PADDING_LEFT) << left << "|" << MESSAGE << setw(PADDING_RIGHT) << right << "|\n";
    
}

void print_header_bottom() {
    cout << "\\" << setw(MESSAGE_WIDTH*2) << setfill('-') << right << "/" << endl;
    cout << setfill(' ');
}

void print_header(const std::string SECTION_HEADER) {
    print_header_top();
    print_header_row(SECTION_HEADER);
    print_header_bottom();
}

bool run_all_tests(IList<int>* const P_list, const int NUM_TESTS_TO_RUN = 9999)  {
    int totalPassed = 0, totalNumTests = 0;

    // testing empty list
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) print_header("Testing new empty list - List is {}");

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(0)", P_list->get(0) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(0,0);
                totalPassed += test_exception_not(totalNumTests, "Testing set(0,0)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(0,0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(-1,-1);
                totalPassed += test_exception_not(totalNumTests, "Testing set(-1,-1)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(-1,-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(1,1);
                totalPassed += test_exception_not(totalNumTests, "Testing set(1,1)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(1,1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(0);
                totalPassed += test_exception_not(totalNumTests, "Testing remove(0)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing min()", P_list->min() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing max()", P_list->max() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
    }

    // testing insert value 3 at position 0
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {}");
            print_header_row("Inserting value 3 at position 0");
            print_header_row("List is now {3}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(0, 3);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(0, 3)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(0, 3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
    }

    // testing set position 0 to 5
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {3}");
            print_header_row("Setting position 0 to 5");
            print_header_row("List is now {5}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(0,5);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing set(0, 5)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(0,5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
    }

    // testing set position -1 to 7
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {5}");
            print_header_row("Setting position -1 to 7");
            print_header_row("List is now {5}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(-1,7);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing set(-1, 7)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(-1,7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
    }

    // testing set position 1 to 9
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {5}");
            print_header_row("Setting position 1 to 9");
            print_header_row("List is now {5}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(1,9);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing set(1, 9)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(1,1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
    }

    // testing remove position 0
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {5}");
            print_header_row("Removing position 0");
            print_header_row("List is now {}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(0);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(0)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(0)", P_list->get(0) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(0,0);
                totalPassed += test_exception_not(totalNumTests, "Testing set(0,0)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(0,0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(-1,-1);
                totalPassed += test_exception_not(totalNumTests, "Testing set(-1,-1)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(-1,-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(1,1);
                totalPassed += test_exception_not(totalNumTests, "Testing set(1,1)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(1,1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(0);
                totalPassed += test_exception_not(totalNumTests, "Testing remove(0)", false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing min()", P_list->min() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing max()", P_list->max() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
    }

    // testing insert at head
    // testing insert at head
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {}");
            print_header_row("Inserting value 5 at position 0");
            print_header_row("Inserting value 1 at position 0");        
            print_header_row("List is now {1,5}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(0, 5);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(0, 5)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(0, 5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(0, 1);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(0, 1)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(0, 1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(2)", P_list->get(2) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
    }

    // testing insert at tail
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {1,5}");
            print_header_row("Inserting value 9 at position 2");
            print_header_row("List is now {1,5,9}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(2, 9);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(2, 9)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(2, 9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(3)", P_list->get(3) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing insert after head
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {1,5,9}");
            print_header_row("Inserting value 3 at position 1");
            print_header_row("List is now {1,3,5,9}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(1, 3);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(1, 3)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(1, 3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing insert before tail
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {1,3,5,9}");
            print_header_row("Inserting value 7 at position 3");
            print_header_row("List is now {1,3,5,7,9}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(3, 7);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(3, 7)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(3, 7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing insert before head
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {1,3,5,7,9}");
            print_header_row("Inserting value 9 at position -10");
            print_header_row("List is now {9,1,3,5,7,9}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(-10, 9);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(-10, 9)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(-10, 9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 6);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(5)", P_list->get(5), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing insert after tail
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,3,5,7,9}");
            print_header_row("Inserting value 1 at position 10");
            print_header_row("List is now {9,1,3,5,7,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->insert(10, 1);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing insert(10, 1)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing insert(10, 1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(5)", P_list->get(5), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(6)", P_list->get(6), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing min in middle
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,3,5,7,9,1}");
            print_header_row("Setting position 2 to -100");
            print_header_row("List is now {9,1,-100,5,7,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(2, -100);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing set(2, -100)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(2, -100)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), -100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(5)", P_list->get(5), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(6)", P_list->get(6), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), -100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(-100)", P_list->find(-100), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(-100)", false );   
            }
        }
    }

    // testing max in middle
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,-100,5,7,9,1}");
            print_header_row("Setting position 4 to 100");
            print_header_row("List is now {9,1,-100,5,100,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->set(4, 100);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing set(4, 100)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing set(4, 100)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 7);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), -100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(5)", P_list->get(5), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(6)", P_list->get(6), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), -100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(-100)", P_list->find(-100), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(-100)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(100)", P_list->find(100), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(100)", false );   
            }
        }
    }

    // testing remove from middle
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,-100,5,100,9,1}");
            print_header_row("Removing position 2");
            print_header_row("List is now {9,1,5,100,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(2);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(2)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(2)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 6);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(5)", P_list->get(5), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove from middle
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,5,100,9,1}");
            print_header_row("Removing position 2");
            print_header_row("List is now {9,1,100,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(2);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(2)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(2)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 5);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(4)", P_list->get(4), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove from middle
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,1,100,9,1}");
            print_header_row("Removing position 1");
            print_header_row("List is now {9,100,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(1);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(1)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 4);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(3)", P_list->get(3), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove from before head
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {9,100,9,1}");
            print_header_row("Removing position -1");
            print_header_row("List is now {100,9,1}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(-1);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(-1)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(-1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 3);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(2)", P_list->get(2), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(3)", P_list->get(3) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove from after tail
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {100,9,1}");
            print_header_row("Removing position 3");
            print_header_row("List is now {100,9}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(3);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(3)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 2);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(1)", P_list->get(1), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(2)", P_list->get(2) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(3)", P_list->get(3) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 9);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove tail
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {100,9}");
            print_header_row("Removing position 1");
            print_header_row("List is now {100}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(1);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(1)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing get(0)", P_list->get(0), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(2)", P_list->get(2) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(3)", P_list->get(3) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing min()", P_list->min(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing max()", P_list->max(), 100);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    // testing remove head
    if(NUM_TESTS_TO_RUN > totalNumTests) {
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            print_header_top();
            print_header_row("List was {100}");
            print_header_row("Removing position 0");
            print_header_row("List is now {0}");
            print_header_bottom();
        }

        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                P_list->remove(0);
                totalPassed++;
                print_test_row(++totalNumTests, "Testing remove(0)", PASSED_MESSAGE);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing remove(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing size()", P_list->size(), 0);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing size()", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(0)", P_list->get(0) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(0)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(1)", P_list->get(1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(2)", P_list->get(2) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(2)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(3)", P_list->get(3) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(3)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(4)", P_list->get(4) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(4)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(5)", P_list->get(5) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(5)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(6)", P_list->get(6) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(6)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(-1)", P_list->get(-1) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(-1)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing get(7)", P_list->get(7) && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing get(7)", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing min()", P_list->min() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing min()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_exception_not(totalNumTests, "Testing max()", P_list->max() && false);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing max()", true );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(0)", P_list->find(0), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(0)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(3)", P_list->find(3), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(3)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(1)", P_list->find(1), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(1)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(5)", P_list->find(5), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(5)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(7)", P_list->find(7), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(7)", false );   
            }
        }
        if(totalNumTests < NUM_TESTS_TO_RUN) {
            try {
                totalPassed += test_int(          totalNumTests, "Testing find(9)", P_list->find(9), -1);
            } catch (...) {
                totalPassed += test_exception(    totalNumTests, "Testing find(9)", false );   
            }
        }
    }

    print_header("Sanity Check");

    cout << endl;
    cout << "Tests Passed: " << setw(3) << right << totalPassed << " / " << setw(3) << totalNumTests << " (" << setprecision(0) << fixed << totalPassed * 100.0f / totalNumTests << "%)" << endl << endl;

    return (totalPassed == totalNumTests);
}

class Timer {
public:
    Timer() { mClockState = CLOCK_UNSTARTED; }
    void startClock() { mStartTime = std::chrono::high_resolution_clock::now(); mClockState = CLOCK_RUNNING; }
    void stopClock() { mEndTime = std::chrono::high_resolution_clock::now(); mClockState = CLOCK_STOPPED; }
    double elapsedTime() { 
        if(mClockState == CLOCK_UNSTARTED) { return 0.f; }
        if(mClockState == CLOCK_RUNNING) {
            mEndTime = std::chrono::high_resolution_clock::now();
        }
        return std::chrono::duration<double>(mEndTime - mStartTime).count(); 
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> mEndTime;
    unsigned short mClockState;
    const short CLOCK_UNSTARTED = 0;
    const short CLOCK_RUNNING = 1;
    const short CLOCK_STOPPED = 2;
};

template<typename T>
void run_timed_tests(IList<T>* const P_list, const unsigned int SIZE, const string LABEL, const T VALUE, const int MANIPULATE_POS, const string COST_1, const string COST_2, const string COST_3, const string COST_4) {
    cout << setw(17) << left << LABEL << flush;

    Timer timer;
    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        P_list->insert(i+MANIPULATE_POS, VALUE);
    }
    timer.stopClock();
    cout << setw(16) << right << timer.elapsedTime() << "s " << COST_1 << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        P_list->get(i);
    }
    timer.stopClock();
    cout << setw(16) << right << timer.elapsedTime() << "s " << COST_2 << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        P_list->set(i, VALUE);
    }
    timer.stopClock();
    cout << setw(16) << right << timer.elapsedTime() << "s " << COST_3 << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        P_list->remove(P_list->size() - (i+MANIPULATE_POS));
    }
    timer.stopClock();
    cout << setw(16) << right << timer.elapsedTime() << "s " << COST_4 << endl;
}

void run_stress_tests() {
    const unsigned int TEST_SIZE = 100000;

    cout << setw(17) << left << "\tList Type";
    cout << setw(19) << right << "Insert";
    cout << setw(21) << right << "Read";
    cout << setw(23) << right << "Write";
    cout << setw(21) << right << "Delete" << endl;

    cout << fixed << setprecision(6);

    IList<int> *pList = new Array<int>();
    run_timed_tests(pList, TEST_SIZE, "\tArray Head", 0, -TEST_SIZE, "O(n)", "O(1)", "O(1)", "O(n)");
    delete pList;

    pList = new Array<int>();
    run_timed_tests(pList, TEST_SIZE, "\tArray Mid", 0, -1, "O(n)", "O(1)", "O(1)", "O(n)");
    delete pList;

    pList = new Array<int>();
    run_timed_tests(pList, TEST_SIZE, "\tArray Tail", 0, TEST_SIZE+1, "O(n)", "O(1)", "O(1)", "O(n)");
    delete pList;

    pList = new LinkedList<int>();
    run_timed_tests(pList, TEST_SIZE, "\tLinkedList Head", 0, -TEST_SIZE, "O(1)", "O(n)", "O(n)", "O(1)");
    delete pList;

    pList = new LinkedList<int>();
    run_timed_tests(pList, TEST_SIZE, "\tLinkedList Mid", 0, -1, "O(n)", "O(n)", "O(n)", "O(n)");
    delete pList;

    pList = new LinkedList<int>();
    run_timed_tests(pList, TEST_SIZE, "\tLinkedList Tail", 0, TEST_SIZE+1, "O(1)", "O(n)", "O(n)", "O(1)");
    delete pList;
}
