class Rectangle:
    def __init__(self, color, w, l):
        self.width = w
        self.length = l
        self.color = color
        
    def area(self):    
        self.area = self.width * self.length
        return self.area

    def per(self):
        self.perimeter = 2 * self.length + 2 * self.width
        return self.perimeter

c1 = 'red'
w1 = 3
l1 = 4

rect1 = Rectangle(c1, w1, l1)
areaRect1 = rect1.area()

print('Rectangle 1 is', rect1.color, 'with area', areaRect1)
print(areaRect1)

c2 = 'blue'
w2 = 7
l2 = 3.2

rect2 = Rectangle(c2, w2, l2)
areaRect2 = rect2.area()

print('Rectangle 2 is', rect2.color, 'with area', areaRect2)
print(areaRect2)

print('Rectangle 1 is:', rect1.color)

per1 = rect1.per()
print('The', rect1.color, 'rectangle has a perimeter of', per1)