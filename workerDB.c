#include <stdio.h>
#include "readfile.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Load employee data from file
    load_data(argv[1]);
    
    // Main menu loop
    int choice;
    do {
        printf("Employee Database Menu:\n");
        printf("1. Print the Database\n");
        printf("2. Lookup by ID\n");
        printf("3. Lookup by Last Name\n");
        printf("4. Add an Employee\n");
        printf("5. Remove an Employee\n");
        printf("6. Update an Employee\n");
        printf("7. Print Top M Salaries\n");
        printf("8. Find Employees by Salary Range\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printDB();
                break;
            case 2: {
                int id;
                printf("Enter ID to lookup: ");
                scanf("%d", &id);
                lookUpID(id);
                break;
            }
            case 3: {
                char last_name[MAXNAME];
                printf("Enter Last Name to lookup: ");
                scanf("%s", last_name);
                lookUpLastName(last_name);
                break;
            }
            case 4:
                addEmployee();
                break;
            case 5: {
                int id;
                printf("Enter ID to remove: ");
                scanf("%d", &id);
                remove_employee(id);
                break;
            }
            case 6: {
                int id;
                printf("Enter ID to update: ");
                scanf("%d", &id);
                update_employee(id);
                break;
            }
            case 7: {
                int M;
                printf("Enter the number of top salaries to display: ");
                scanf("%d", &M);
                print_top_salaries(M);
                break;
            }
            case 8: {
                float min, max;
                printf("Enter salary range (min max): ");
                scanf("%f %f", &min, &max);
                find_by_salary_range(min, max);
                break;
            }
            case 9:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

