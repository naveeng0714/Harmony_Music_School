#pragma once
#include "Certification.h"
#include <vector>

namespace harmony
{

    class CertificationManager
    {
    private:
        std::vector<Certification> certifications;

    public:
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;

        void addCertification(int studentId);
        void displayAllCertifications() const;
    };

}
