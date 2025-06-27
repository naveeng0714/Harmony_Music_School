#include "CertificationManager.h"
#include <fstream>
#include <iostream>

namespace harmony
{

    void CertificationManager::loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        if (!fin.is_open())
            return;

        std::string line;
        while (std::getline(fin, line))
        {
            try
            {
                Certification c = Certification::fromCSV(line);
                certifications.push_back(c);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error loading certification: " << e.what() << "\n";
            }
        }
        fin.close();
    }

    void CertificationManager::saveToFile(const std::string &filename) const
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
        for (const auto &c : certifications)
        {
            fout << c.toCSV() << "\n";
        }
        fout.close();
    }

    void CertificationManager::addCertification(int studentId)
    {
        Certification c;
        c.input(studentId);
        certifications.push_back(c);
    }

    void CertificationManager::displayAllCertifications() const
    {
        for (const auto &c : certifications)
        {
            c.display();
            std::cout << "---------------------------\n";
        }
    }

}
