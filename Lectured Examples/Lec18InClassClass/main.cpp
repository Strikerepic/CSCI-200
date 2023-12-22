#include <iostream>
// Add includes for the collections being used in your 
#include <vector>
#include <string>
#include <string>
using namespace std;

#include "Course.h"

int main() {

vector<Course> directory;

directory.push_back( Course());
directory.push_back( Course("Calc-111"));


for(size_t i = 0; i < directory.size(); i++) {
    directory.at(i).registerStudent();
    directory.at(i).registerStudent();
}


for(size_t i = 0; i < directory.size(); i++) {
    cout << directory.at(i).getTitle() << "    " << directory.at(i).getEnrollment() << endl;
}

}