# 🎵 Harmony Music School Management System (C++ Advanced Version)

Welcome to the **Harmony Music School Management System**, a modular C++ application designed for managing the day-to-day operations of a music school. This system tracks student admissions, tuition fee payments, instrument and accessory purchases, learning progress, and certifications.

---

## 📌 Features

✅ **Student Management**  
- Add and manage students  
- Assign unique IDs  
- Store admission details  

✅ **Tuition Fee Tracking**  
- Record total fee, amount paid  
- Calculate balance  
- Persisted in `fees.txt`

✅ **Instrument & Accessory Purchase**  
- Supports both instruments and accessories  
- Stores item name, type, price, date  
- Stored in `purchases.txt`

✅ **Learning Progress Tracking**  
- Tracks levels (Beginner, Intermediate, Advanced)  
- Progress notes and timestamps  
- Stored in `progress.txt`

✅ **Certification Records**  
- Stores certifications achieved  
- Includes course name, cert ID, and date  
- Stored in `certifications.txt`

---

## 💡 Technologies Used

- **C++17**
- **CMake** for build automation
- **OOP Principles**: Encapsulation, Modularity, Abstraction
- **Advanced C++**: `std::shared_ptr`, `std::map`, `std::vector`, RAII, const correctness

---

## 🛠️ Build Instructions

### 🔧 Requirements
- A C++17 compatible compiler (e.g., `g++ >= 9`)
- `cmake >= 3.10`

### 🔨 Build
```bash
mkdir build
cd build
cmake ..
make
