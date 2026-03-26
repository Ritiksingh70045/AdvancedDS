#include <bits/stdc++.h>
using namespace std;

// ---------------- Abstract Class ----------------
class Employee
{
public:
  virtual double calculateSalary() = 0;
  virtual string getRole() = 0;

  virtual ~Employee() {}
};

// ---------------- Full Time ----------------
class FullTimeEmployee : public Employee
{
  double salary;

public:
  FullTimeEmployee(double s) : salary(s) {}

  double calculateSalary() override
  {
    return salary;
  }

  string getRole() override
  {
    return "Full Time Employee";
  }
};

// ---------------- Part Time ----------------
class PartTimeEmployee : public Employee
{
  double hourlyRate;
  int hoursWorked;

public:
  PartTimeEmployee(double rate, int hours)
      : hourlyRate(rate), hoursWorked(hours) {}

  double calculateSalary() override
  {
    return hourlyRate * hoursWorked;
  }

  string getRole() override
  {
    return "Part Time Employee";
  }
};

// ---------------- Main ----------------
int main()
{
  vector<Employee *> employees;

  employees.push_back(new FullTimeEmployee(50000));
  employees.push_back(new PartTimeEmployee(200, 20));

  for (auto e : employees)
  {
    cout << e->getRole() << endl;
    cout << "Salary: " << e->calculateSalary() << endl;
  }

  // cleanup
  for (auto e : employees)
  {
    delete e;
  }
}