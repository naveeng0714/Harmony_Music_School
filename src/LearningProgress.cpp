#include "LearningProgress.h"
#include <sstream>
#include <vector>

namespace harmony
{

    LearningProgress::LearningProgress(int id, const std::string &lvl, const std::string &note, const std::string &dt)
        : studentId(id), level(lvl), progressNote(note), date(dt) {}

    void LearningProgress::input(int id)
    {
        studentId = id;
        std::cout << "Enter current level (Beginner/Intermediate/Advanced): ";
        std::getline(std::cin, level);
        std::cout << "Enter progress note: ";
        std::getline(std::cin, progressNote);
        std::cout << "Enter date (YYYY-MM-DD): ";
        std::getline(std::cin, date);
    }

    void LearningProgress::display() const
    {
        std::cout << "Student ID: " << studentId
                  << "\nLevel: " << level
                  << "\nProgress Note: " << progressNote
                  << "\nDate: " << date << "\n";
    }

    std::string LearningProgress::toCSV() const
    {
        return std::to_string(studentId) + "," + level + "," + progressNote + "," + date;
    }

    LearningProgress LearningProgress::fromCSV(const std::string &line)
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 4)
            throw std::runtime_error("Invalid learning progress record");

        return LearningProgress(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3]);
    }

}
