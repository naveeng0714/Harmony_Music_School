#pragma once
#include <string>
#include <iostream>

namespace harmony
{

    class LearningProgress
    {
    private:
        int studentId;
        std::string level;
        std::string progressNote;
        std::string date;

    public:
        LearningProgress() = default;
        LearningProgress(int id, const std::string &level, const std::string &note, const std::string &date);

        void input(int id);
        void display() const;

        std::string toCSV() const;
        static LearningProgress fromCSV(const std::string &line);

        int getStudentId() const { return studentId; }
    };

}
