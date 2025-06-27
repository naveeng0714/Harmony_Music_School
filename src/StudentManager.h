#pragma once
#include "Student.h"
#include <map>
#include <memory>
#include <string>
#include <filesystem> 

namespace harmony
{

    class StudentManager
    {
    private:
        std::map<int, std::shared_ptr<Student>> students;
        int nextId = 1;

    public:
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;

        void addStudent();
        void displayAllStudents() const;

        std::shared_ptr<Student> getStudentById(int id) const;
    };

}
