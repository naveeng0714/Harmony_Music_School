#include "ProgressManager.h"
#include <fstream>
#include <iostream>

namespace harmony
{

    void ProgressManager::loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        if (!fin.is_open())
            return;

        std::string line;
        while (std::getline(fin, line))
        {
            try
            {
                LearningProgress lp = LearningProgress::fromCSV(line);
                progressList.push_back(lp);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error loading progress record: " << e.what() << "\n";
            }
        }
        fin.close();
    }

    void ProgressManager::saveToFile(const std::string &filename) const
    {
        std::filesystem::path filePath(filename);

        // Create the directory if it doesn't exist
        std::filesystem::create_directories(filePath.parent_path());

        // Open the file for writing
        std::ofstream fout(filename);
        if (!fout.is_open())
        {
            std::cerr << "Error!!: Failed to open file: " << filename << std::endl;
            return;
        }

        // Write the data to the file
        for (const auto &lp : progressList)
        {
            fout << lp.toCSV() << "\n";
        }
        fout.close();
    }

    void ProgressManager::addProgress(int studentId)
    {
        LearningProgress lp;
        lp.input(studentId);
        progressList.push_back(lp);
    }

    void ProgressManager::displayAllProgress() const
    {
        for (const auto &lp : progressList)
        {
            lp.display();
            std::cout << "---------------------------\n";
        }
    }

}
