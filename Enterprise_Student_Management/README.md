# Enterprise Student Management System

A high-performance, menu-driven student record management system implemented in C using optimized doubly linked-list structures for efficient data retrieval and administrative operations. Features a colorful, user-friendly console interface with robust error handling and automatic data persistence.

## Features

### Core CRUD Operations
- **Add Student**: Insert new student records with ID, name, age, department, and GPA (with input validation)
- **Update Student**: Modify existing student information by ID
- **Delete Student**: Remove student records by ID with memory cleanup
- **Search Operations**:
  - Search by unique ID (O(n) traversal)
  - Search by name (displays all matches)
  - Search by department (lists all department members)
  - Search by GPA range (finds students within min/max GPA)

### Data Visualization & Analytics
- **Display All Students**: View all records in a tabular format, sorted by ID
- **Display Ranked by GPA**: Show students ranked by GPA (descending), handling ties correctly
- **Display Statistics**: View total students, average GPA, highest/lowest GPA

### Data Persistence
- **Auto-Save**: Data saved to `students.txt` after every add/update/delete operation
- **Load on Startup**: Automatically loads existing data from CSV file
- **CSV Format**: Human-readable storage (ID,Name,Age,Department,GPA)

### User Interface
- **Colorful Console UI**: ANSI-colored menus and outputs (green for success, red for errors, blue for headers)
- **Menu-Driven**: Intuitive 12-option menu with clear navigation
- **Input Validation**: Prevents invalid IDs, ages (15-30), GPAs (0.0-4.0), and duplicate IDs
- **Error Handling**: Graceful handling of file operations and invalid inputs

## Data Structure

The system uses a **doubly linked list** for optimal insertion, deletion, and bidirectional traversal. Students are maintained in ascending order by ID, enabling efficient operations. Each node includes `next` and `prev` pointers for flexible navigation.

- **Time Complexity**: O(n) for search/insert/delete (linear traversal)
- **Space Complexity**: O(n) for n students
- **Advantages**: Dynamic sizing, no contiguous memory required, fast for CRUD in sorted order

## Building and Running

### Prerequisites
- GCC compiler (MinGW on Windows, GCC on Linux/Mac)
- Make utility (optional, for Makefile)
- Terminal supporting ANSI colors (VS Code, Windows Terminal, etc.)

### Build
Using Make (if Makefile present):
```bash
make
```

Manual compilation:
```bash
gcc -fdiagnostics-color=always -g -Wall -Wextra -O2 -mconsole main.c student.c -o student_management.exe
```

### Run
```bash
./student_management
```

On Windows:
```bash
student_management.exe
```

## Usage

1. **Launch the Program**: Run the executable; data loads automatically from `students.txt`.
2. **Navigate the Menu**: Choose from 12 options using numbers 1-12.
3. **Add a Student**:
   - Enter unique positive ID
   - Enter name (supports spaces)
   - Enter age (15-30)
   - Enter department (e.g., CS, EE)
   - Enter GPA (0.0-4.0)
   - Data saves automatically
4. **Search Operations**:
   - By ID: Enter ID to view details
   - By Name/Department: Enter criteria to list matches
   - By GPA Range: Enter min/max to filter students
5. **Update/Delete**: Enter ID, then modify/remove (with confirmations)
6. **View Data**: Display all students, rankings, or statistics
7. **Exit**: Program saves data and terminates

### Example Session
```
========================================
   Enterprise Student Management System
========================================
1. Add Student
...
Enter your choice: 1
Enter ID (positive integer): 101
Enter Name: John Doe
Enter Age (15-30): 20
Enter Department: CS
Enter GPA (0.0-4.0): 3.8
Data saved to students.txt
```

## File Structure
```
Enterprise_Student_Management/
├── main.c              # Main program and menu logic
├── student.c           # Linked list operations and functions
├── student.h           # Header file with structs and prototypes
├── students.txt        # CSV data file (auto-generated)
├── Makefile            # Build script (optional)
├── .gitignore          # Git ignore rules
└── README.md           # This file
```

## Troubleshooting

- **Colors not showing**: Ensure terminal supports ANSI escape codes (enable in VS Code settings)
- **Compilation errors**: Check GCC installation and paths
- **Data not loading**: Verify `students.txt` exists and has correct CSV format
- **Invalid inputs**: Follow prompts; system validates and shows red error messages
- **Memory issues**: Program handles allocation failures gracefully
- **File permissions**: Ensure write access to the directory for saving data

## Performance Notes

- Suitable for thousands of records with O(n) operations
- Doubly linked list allows efficient deletions without full traversals
- Auto-save ensures no data loss, but may slow down for very large datasets
- Sorting creates temporary copies for rankings to avoid modifying main list

## Future Enhancements

- Hash table for O(1) ID lookups
- Binary file storage for faster I/O
- GUI interface (e.g., with GTK or Qt)
- Database integration (SQLite)
- Multi-threading for concurrent operations

---

Developed as an enterprise-grade C application demonstrating advanced data structures, file I/O, and user interface design.