#pragma once
#include "LearningProgress.h"
#include <vector>
#include <filesystem>

namespace harmony
{

    class ProgressManager
    {
    private:
        std::vector<LearningProgress> progressList;

    public:
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;

        void addProgress(int studentId);
        void displayAllProgress() const;
    };

}
