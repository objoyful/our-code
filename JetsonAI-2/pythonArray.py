def find_ending(num):
    end_number = [
        "st",
        "nd",
        "rd",
        "th"
    ]
    num = num % 100
    
    if num > 13 or num < 11:
        num = num % 10
    try:
        return end_number[num - 1]
    except:
        return "th"

grade_array = []
num_grades = int(input("How many grades do you have? "))
while num_grades < 1:
    num_grades = int(input("You need to have at least one grade. How many grades do you have? "))

for i in range(0, num_grades):
    grade = float(input("Input the grade: "))
    grade_array.append(grade)

print("==============================")

sum = 0
low = grade_array[0]
high = grade_array[0]

for i in range(0, num_grades):
    print(f"Your {i + 1}{find_ending(i + 1)} grade is {grade_array[i]}")
    
    sum = sum + grade_array[i]

    if (grade_array[i] < low):
        low = grade_array[i]
    if (grade_array[i] > high):
        high = grade_array[i]

print("==============================")

avg_grade = sum / num_grades
print(f"Your average grade is {avg_grade}")

print(f"Your lowset grade was {low}")
print(f"Your highest grade was {high}")

print("==============================")