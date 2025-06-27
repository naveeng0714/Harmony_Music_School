# Harmony Music School Management System

This is a command-line application written in **modern C++ (C++17)** that simulates a basic record management system for a music school. 
It showcases good software design practices using object-oriented principles, modular architecture, and file-based persistence.

---

##  Features

-  **Student Management** – Enroll students and view details.
-  **Tuition Fee Tracking** – Record and manage fee payments.
-  **Instrument & Accessory Purchase Records** – Log items purchased by students.
-  **Learning Progress Tracking** – Track learning levels, notes, and progression.
-  **Certifications** – Manage and record course completions and certificates.
-  **File Persistence (Pluggable)** – Data saving hooks implemented per module.
-  **CMake Build System** – Easily portable and buildable on Linux systems.

---

##  Build Instructions

###  Prerequisites
- C++17 or higher
- `cmake` and `g++` installed on your system

###  Build & Run
```bash
# Clone or extract the repo
cd HarmonyMusicSchool_CPP_Advanced

# Create a build directory
mkdir build && cd build

# Configure the project
cmake ..

# Build the executable
make

# Run the application
./HarmonyMusicSchool
