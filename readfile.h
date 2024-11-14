#ifndef READFILE_H
#define READFILE_H

#define MAXEMPLOYEES 100
#define MAXNAME 50

typedef struct {
    int id;
    char first_name[MAXNAME];
    char last_name[MAXNAME];
    float salary;
} Employee;

extern Employee employees[MAXEMPLOYEES];
extern int employee_count;

void load_data(const char *filename);
void printDB();
void lookUpID(int id);
void lookUpLastName(const char *last_name);
void addEmployee();
void remove_employee(int id);
void update_employee(int id);
void print_top_salaries(int M);
void find_by_salary_range(float min, float max);
void sort_employees_by_id();

#endif

