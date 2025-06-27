#include "StudentManager.h"
#include <fstream>
#include <iostream>

namespace harmony
{

    void StudentManager::loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        if (!fin.is_open())
            return;

        std::string line;
        while (std::getline(fin, line))
        {
            try
            {
                Student s = Student::fromCSV(line);
                auto ptr = std::make_shared<Student>(s);
                students[s.getId()] = ptr;
                if (s.getId() >= nextId)
                    nextId = s.getId() + 1;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error loading student: " << e.what() << "\n";
            }
        }
        fin.close();
    }

    void StudentManager::saveToFile(const std::string &filename) const
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
        for (const auto &[id, student] : students)
        {
            fout << student->toCSV() << "\n";
        }
        fout.close();
    }

    void StudentManager::addStudent()
    {
        auto newStudent = std::make_shared<Student>();
        std::cout << "Assigning Student ID: " << nextId << "\n";
        *newStudent = Student(nextId, "", "", "", 0);
        newStudent->input();
        students[nextId] = newStudent;
        ++nextId;
    }

    void StudentManager::displayAllStudents() const
    {
        for (const auto &[id, student] : students)
        {
            student->display();
            std::cout << "---------------------------\n";
        }
    }

    std::shared_ptr<Student> StudentManager::getStudentById(int id) const
    {
        auto it = students.find(id);
        return (it != students.end()) ? it->second : nullptr;
    }

}
