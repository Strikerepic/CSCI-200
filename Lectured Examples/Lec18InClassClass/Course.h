#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>


class Course {
    public:

        Course();
        Course(string name);
        int getEnrollment();
        void registerStudent();
        string getTitle();
        void withdrawStudent();
    private:
        int _enrollment;
        string _title;

};

#endif