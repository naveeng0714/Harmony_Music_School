#include "Certification.h"
#include <sstream>
#include <vector>

namespace harmony
{

    Certification::Certification(int id, const std::string &course, const std::string &cid, const std::string &dt)
        : studentId(id), courseName(course), certId(cid), date(dt) {}

    void Certification::input(int id)
    {
        studentId = id;
        std::cout << "Enter course/instrument name: ";
        std::getline(std::cin, courseName);
        std::cout << "Enter certification ID: ";
        std::getline(std::cin, certId);
        std::cout << "Enter date (YYYY-MM-DD): ";
        std::getline(std::cin, date);
    }

    void Certification::display() const
    {
        std::cout << "Student ID: " << studentId
                  << "\nCourse: " << courseName
                  << "\nCert ID: " << certId
                  << "\nDate: " << date << "\n";
    }

    std::string Certification::toCSV() const
    {
        return std::to_string(studentId) + "," + courseName + "," + certId + "," + date;
    }

    Certification Certification::fromCSV(const std::string &line)
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 4)
            throw std::runtime_error("Invalid certification record");

        return Certification(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3]);
    }

}
