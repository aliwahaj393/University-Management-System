# `University-Management-System` Object-Oriented University Modeling

The **University-Management-System** is an Object-Oriented Programming (OOP) project built in C++ that models a university's core academic operations. It effectively manages the relationships between Students, Teachers, Courses, Degrees, and the University itself, utilizing concepts like inheritance, composition, and aggregation.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Notes](#notes)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

Representing real-world relationships in code is a core principle of OOP. The **University-Management-System** demonstrates this by modeling academic entities and their interactions. It serves as an educational simulation of a university where students enroll in degree programs, teachers manage courses, and the university oversees all administrative links.

## Features

- **Class Interactions**: Implements robust interactions between `University`, `Degree`, `Course`, `Student`, and `Teacher` classes.
- **File I/O**: Reads university and student data dynamically from text files (e.g., `uniInfo.txt`, `a4TaskOneData.txt`).
- **Memory Management**: Uses dynamic memory allocation, pointers, and custom string classes (`MyString`) for efficient memory handling.
- **OOP Concepts**: Heavily utilizes inheritance, composition, dynamic polymorphism, and encapsulation.
- **Reporting**: Generates output summarizing university operations, faculty allocations, and student enrollments.

## Getting Started

To run the **University-Management-System** locally, follow these steps:

1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler. Due to the multi-file architecture, compiling all `.cpp` files together is necessary:
   ```bash
   g++ *.cpp -o UniversitySystem
   ```
3. Run the compiled executable in your command-line interface:
   ```bash
   ./UniversitySystem
   ```

Make sure you have a C++ compiler installed on your system to compile and run the application.

## Usage

1. Launch the compiled executable.
2. Ensure that the required data files (`uniInfo.txt`, `a4TaskOneData.txt`) are located in the same directory as the executable.
3. The system will parse the input text files, initialize the objects in memory, and simulate the university environment.
4. Output will be displayed on the console detailing the relationships, enrollments, and teaching assignments.

## Notes

- This project is separated into multiple tasks/parts inside the repository (`Task_2_Part_2`, `Task_3_Part_One`). Navigate to those directories to compile specific parts of the assignment.
- Ensure that memory leaks are monitored if making modifications to the custom `MyString` class or any dynamically allocated arrays.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for architectural improvements, feel free to create a pull request.

## License

*This project is licensed under the [MIT License](https://choosealicense.com/licenses/mit/)*.

## Contact

For any questions or inquiries, please contact [aliwahaj393](https://github.com/aliwahaj393).
