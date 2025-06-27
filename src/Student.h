#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace harmony
{

    class Student
    {
    private:
        int id;
        std::string name;
        std::string instrument;
        std::string level;
        int admissionYear;

    public:
        Student() = default;
        Student(int id, const std::string &name, const std::string &instr, const std::string &lvl, int year);

        void input();
        void display() const;

        std::string toCSV() const;
        static Student fromCSV(const std::string &line);

        int getId() const { return id; }
    };

}
