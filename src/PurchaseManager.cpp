#include "PurchaseManager.h"
#include <fstream>
#include <iostream>

namespace harmony
{

    void PurchaseManager::loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        if (!fin.is_open())
            return;

        std::string line;
        while (std::getline(fin, line))
        {
            try
            {
                PurchaseRecord p = PurchaseRecord::fromCSV(line);
                purchases.push_back(p);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error loading purchase record: " << e.what() << "\n";
            }
        }
        fin.close();
    }

    void PurchaseManager::saveToFile(const std::string &filename) const
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
        std::ofstream fout(filename);
        for (const auto &p : purchases)
        {
            fout << p.toCSV() << "\n";
        }
        fout.close();
    }

    void PurchaseManager::addPurchase(int studentId)
    {
        PurchaseRecord p;
        p.input(studentId);
        purchases.push_back(p);
    }

    void PurchaseManager::displayAllPurchases() const
    {
        for (const auto &p : purchases)
        {
            p.display();
            std::cout << "--------------------------\n";
        }
    }

}
