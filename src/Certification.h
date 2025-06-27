#pragma once
#include <string>
#include <iostream>

namespace harmony
{
    
    class Certification
    {
    private:
        int studentId;
        std::string courseName;
        std::string certId;
        std::string date;

    public:
        Certification() = default;
        Certification(int id, const std::string &course, const std::string &cid, const std::string &dt);

        void input(int id);
        void display() const;

        std::string toCSV() const;
        static Certification fromCSV(const std::string &line);

        int getStudentId() const { return studentId; }
    };

}
