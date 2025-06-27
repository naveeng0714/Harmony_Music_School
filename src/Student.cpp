#include "Student.h"
#include <sstream>

namespace harmony
{

    Student::Student(int id, const std::string &name, const std::string &instr, const std::string &lvl, int year)
        : id(id), name(name), instrument(instr), level(lvl), admissionYear(year) {}

    void Student::input()
    {
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        std::cout << "Enter instrument (e.g. Guitar, Vocal): ";
        std::getline(std::cin, instrument);
        std::cout << "Enter level (Beginner/Intermediate/Advanced): ";
        std::getline(std::cin, level);
        std::cout << "Enter admission year: ";
        std::cin >> admissionYear;
        std::cin.ignore();
    }

    void Student::display() const
    {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Instrument: " << instrument << "\n"
                  << "Level: " << level << "\n"
                  << "Admission Year: " << admissionYear << "\n";
    }

    std::string Student::toCSV() const
    {
        return std::to_string(id) + "," + name + "," + instrument + "," + level + "," + std::to_string(admissionYear);
    }

    Student Student::fromCSV(const std::string &line)
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 5)
            throw std::runtime_error("Invalid student data");

        return Student(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]));
    }

}
