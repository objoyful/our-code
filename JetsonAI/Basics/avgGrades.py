def find_ending(num):
    end_number = [
        "st",
        "nd",
        "rd",
        "th"
    ]
    
    if num == 1:
        return ''
    else:
        num = num % 100
        
        if num > 13 or num < 11:
            num = num % 10
        try:
            return end_number[num - 1]
        except:
            return "th"

def find_number(num):
    if num == 1:
        return ''
    else:
        numString = str(num)
        return ' ' + numString

gradeArray = []
numGrades = int(input('How many grades do you have? '))

for i in range(0, numGrades, 1):
    newGrade = float(input('Enter your next grade: '))
    gradeArray.append(newGrade)

print(' ')
print('Your grades are:')
for i in range(0, numGrades, 1):
    print(gradeArray[i])

bucket = 0
for i in range (0, numGrades, 1):
    bucket = bucket + gradeArray[i]

av = bucket / numGrades
print(' ')
print('Your average is:', '{:.2f}'.format(av))

print(' ')
highGrade = 0
lowGrade = 100
for i in range(0, numGrades, 1):
    if highGrade < gradeArray[i]:
        highGrade = gradeArray[i]
    
    if lowGrade > gradeArray[i]:
        lowGrade = gradeArray[i]

print('Your high grade is', highGrade)
print('Your low grade is', lowGrade)

print(' ')
listChanged = True
while listChanged:
    listChanged = False
    for i in range(0, numGrades - 1, 1):
        firstNumber = gradeArray[i]
        secondNumber = gradeArray[i + 1]

        if firstNumber > secondNumber:
            gradeArray[i + 1] = firstNumber
            gradeArray[i] = secondNumber

            listChanged = True

for i in range(0, numGrades, 1):
    print('Your', end = '')
    print(find_number(i + 1), end = '')
    print(find_ending(i + 1), 'lowest grade is:', gradeArray[i])