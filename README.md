# personal-expense-tracker-c
A console-based Personal Expense Tracker developed in C using structures, arrays, functions, pointers, and file handling. It supports adding, viewing, searching, updating, and deleting expenses, along with total expense calculation, highest expense detection, and category-wise expense tracking.
# Personal Expense Tracker in C

## Project Overview

Personal Expense Tracker is a menu-driven, console-based application developed using the C programming language. It helps users manage and track their daily expenses through a simple interface.

The project allows users to add, display, search, update, and delete expense records. It also provides features for calculating total expenses, finding the highest expense, and analyzing expenses by category.

The application uses file handling to store expense records in a text file, allowing users to access previously saved data even after restarting the program.

I developed this project to improve my C programming skills, strengthen my problem-solving abilities, and gain practical experience with file handling and record management.

## Key Features

- **Add New Expense:** Store expense details including a unique ID, title, category, and amount.
- **Display All Expenses:** View all saved expense records.
- **Search Expense:** Find a specific expense using its ID.
- **Calculate Total Expenses:** Calculate the total amount spent across all records.
- **Find Highest Expense:** Identify the expense with the highest amount.
- **Category-wise Expenses:** Calculate total spending for a specific category using string comparison.
- **Update Expense:** Modify the amount of an existing expense.
- **Delete Expense:** Remove an expense by its ID and update the remaining records.
- **Persistent Storage:** Save and load expense records using a text file.
- **Duplicate ID Prevention:** Prevent adding records with duplicate IDs.

## Technologies Used

- **Programming Language:** C
- **Code Editor:** Visual Studio Code
- **Compiler:** GCC
- **Data Storage:** Text File (`personl.txt`)

## Programming Concepts Used

- Structures and arrays
- Functions and pointers
- File handling (`fopen`, `fclose`, `fprintf`, `fscanf`, `rewind`)
- String handling (`strcmp`, `strcpy`)
- Loops and conditional statements
- Linear searching
- Array element shifting
- Basic data validation

## How to Run

1. Clone or download this repository.
2. Open the project folder in Visual Studio Code.
3. Make sure GCC is installed.
4. Compile the source code:

```bash
gcc main.c -o expense_tracker
```

5. Run the program on Windows:

```bash
.\expense_tracker.exe
```

On Linux/macOS:

```bash
./expense_tracker
```

The application uses `personl.txt` to store expense records. This file is created when an expense is successfully saved.

## Future Improvements

- Improve input validation and file error handling.
- Add expense dates and monthly expense reports.
- Support expense titles containing spaces.
- Add category-based filtering and sorting.
- Improve the console interface and data management.

## Learning Outcomes

Through this project, I gained practical experience in managing structured data, reading and writing files, implementing record updates and deletion, and working with functions and pointers.

It helped me understand how different C programming concepts can be combined to build a practical application.

## Project Status

Core features implemented. Further improvements in input validation and error handling are planned.
