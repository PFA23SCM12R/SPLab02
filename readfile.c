#include <stdio.h>
#include <string.h>
#include "readfile.h"

Employee employees[MAXEMPLOYEES];
int employee_count = 0;

// Load employee data from file
void load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    employee_count = 0;
    while (fscanf(file, "%d %s %s %f", &employees[employee_count].id, 
                  employees[employee_count].first_name, employees[employee_count].last_name, 
                  &employees[employee_count].salary) == 4) {
        employee_count++;
        if (employee_count >= MAXEMPLOYEES) {
            printf("Database full; cannot load more employees.\n");
            break;
        }
    }
    fclose(file);

    sort_employees_by_id(); // Sort after loading
    printf("Data loaded and sorted by ID.\n");
}

// Print the employee database
void printDB() {
    printf("ID        FIRST NAME       LAST NAME         SALARY\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%-10d %-15s %-15s $%.2f\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
    }
    printf("---------------------------------------------------\n");
    printf("Number of Employees = %d\n\n", employee_count);
}

// Lookup by ID
void lookUpID(int id) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("Found: %d %s %s %.2f\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Lookup by Last Name
void lookUpLastName(const char *last_name) {
    for (int i = 0; i < employee_count; i++) {
        if (strcmp(employees[i].last_name, last_name) == 0) {
            printf("Found: %d %s %s %.2f\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
            return;
        }
    }
    printf("Employee with last name %s not found.\n", last_name);
}

// Add a new employee
void addEmployee() {
    if (employee_count >= MAXEMPLOYEES) {
        printf("Database full; cannot add more employees.\n");
        return;
    }
    printf("Enter new employee details (ID Firstname Lastname Salary): ");
    Employee newEmp;
    scanf("%d %s %s %f", &newEmp.id, newEmp.first_name, newEmp.last_name, &newEmp.salary);
    employees[employee_count++] = newEmp;
    sort_employees_by_id();
    printf("New employee added.\n");
}

// Remove an employee by ID
void remove_employee(int id) {
    int index = -1;
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    for (int i = index; i < employee_count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employee_count--;
    printf("Employee with ID %d removed.\n", id);
}

// Update an employee’s information
void update_employee(int id) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("Updating employee with ID %d.\n", id);
            printf("Enter new first name (current: %s): ", employees[i].first_name);
            scanf("%s", employees[i].first_name);
            printf("Enter new last name (current: %s): ", employees[i].last_name);
            scanf("%s", employees[i].last_name);
            printf("Enter new salary (current: %.2f): ", employees[i].salary);
            scanf("%f", &employees[i].salary);
            printf("Employee information updated.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Print top M employees by salary
void print_top_salaries(int M) {
    if (M > employee_count) M = employee_count;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < employee_count; j++) {
            if (employees[j].salary > employees[i].salary) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
        printf("ID: %d, Name: %s %s, Salary: %.2f\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
    }
}

// Find employees within a salary range
void find_by_salary_range(float min, float max) {
    int found = 0;
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].salary >= min && employees[i].salary <= max) {
            printf("ID: %d, Name: %s %s, Salary: %.2f\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found in the salary range %.2f - %.2f\n", min, max);
    }
}

// Sort employees by ID
void sort_employees_by_id() {
    for (int i = 0; i < employee_count - 1; i++) {
        for (int j = i + 1; j < employee_count; j++) {
            if (employees[i].id > employees[j].id) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

