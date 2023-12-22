#include "Course.h"
#include <string>

using namespace std;


Course::Course() {
    _enrollment = 0;
    _title = "CSCI-200";
}
Course::Course(string name){
    _enrollment = 0;
    _title = name;
} 
std::string Course::getTitle() {
    return _title;
}

int Course::getEnrollment() {
    return _enrollment;
}

void Course::registerStudent() {
    _enrollment += 1;
}

void Course::withdrawStudent() {
    _enrollment -= 1;
}

