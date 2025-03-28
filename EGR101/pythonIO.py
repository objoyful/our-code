# William Carden pythonIO script
# EGR 101-02
# Due Date: 03/20/2025

# Gather inputs.
name = input("Enter Employee's name: ")
id = input("Employee's 4-digit ID: ")
wage = float(input("Employee's Hourly Wage: "))
hours = float(input("Hours worked last week: "))

# Calculate pay.
pay = wage * hours

# Print statements.
# print("")
print('\n', name, "is an hourly employee.\t", "ID:", id)
print(name, "worked", hours, "hours last week")
print("and", name, "earned $", pay)