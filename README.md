# SPLab02


# Employee Database Program

This program is an employee database that allows you to view, add, and search employees by their ID or last name. Follow the steps below to compile and run the program.

## How to Run the Program

1. Ensure You Have GCC Installed  
   Make sure GCC (GNU Compiler Collection) is installed on your system. You can check this by running:

   bash:  “gcc –version”

   If not installed, install GCC according to your operating system's instructions.

2. Open a Terminal and Navigate to the Project Directory  
   In your terminal, navigate to the directory where you saved the program files (e.g., `workerDB.c`, `readfile.c`, `readfile.h`, and `input.txt`).
   
bash:  “cd /Users/premswaroop/Desktop/402”

3. Compile the Program  
   Use the following GCC command to compile the source files. This will generate an executable named `workerDB`.
bash: “gcc -o workerDB workerDB.c readfile.c”

4. Check for Compilation Errors  
   If there are any errors, review the error messages, make necessary code adjustments, and recompile.

5. Prepare the Input File  
   Ensure there is an `input.txt` file in the same directory. This file should contain employee data in the format:
  
“<ID> <First Name> <Last Name> <Salary>”

   Example:
   165417 Cathryn Danner 72000
   273225 Matt Meeden 69000

6. Run the Program with the Input File  
   Execute the program by passing the `input.txt` file as an argument:
   Bash:  “  ./workerDB input.txt “

7. Use the Program Menu  
   The program will display a menu with options:
   
   1. Print the Database
   2. Lookup by ID
   3. Lookup by Last Name
   4. Add an Employee
   5. Quit
 
   Enter a number (1-5) to choose an option.

8. Look Up Employees by ID or Last Name  
   To look up an employee, select options 2 or 3 and enter the ID or last name as prompted. The program will display matching records if found.

9. Add a New Employee  
   Choose option 4 to add a new employee. The program will ask for the first name, last name, and salary, then automatically assign a new ID and add the employee to the database.

10. Exit the Program  
   To quit, select option 5 from the menu. The program will display a goodbye message and terminate.


#This README should provide all the steps you need to compile, run, and interact with the Employee Database program.
