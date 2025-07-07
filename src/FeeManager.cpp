#include "FeeManager.h"
#include <fstream>
#include <iostream>

namespace harmony
{

    void FeeManager::loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        if (!fin.is_open())
            return;

        std::string line;
        while (std::getline(fin, line))
        {
            try
            {
                FeeRecord f = FeeRecord::fromCSV(line);
                fees[f.getStudentId()] = f;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error loading fee record: " << e.what() << "\n";
            }
        }
        fin.close();
    }

    void FeeManager::saveToFile(const std::string &filename) const
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
        for (const auto &[id, fee] : fees)
        {
            fout << fee.toCSV() << "\n";
        }
        fout.close();
    }

    void FeeManager::addFee(int studentId)
    {
        FeeRecord f;
        f.input(studentId);
        fees[studentId] = f;
    }

    void FeeManager::displayAllFees() const
    {
        for (const auto &[id, fee] : fees)
        {
            fee.display();
            std::cout << "---------------------------\n";
        }
    }

    const FeeRecord *FeeManager::getFee(int studentId) const
    {
        auto it = fees.find(studentId);
        return (it != fees.end()) ? &it->second : nullptr;
    }

}
