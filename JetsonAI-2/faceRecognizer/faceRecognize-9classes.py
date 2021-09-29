class Rectangle:
    def __init__(self,c,w,l):
        self.width=w
        self.length=l
        self.color=c
    def area(self):
        self.area=self.width*self.length
    def per(self):
        self.per=2*self.width+2*self.length
c1='red'
w1=3
l1=4
rect1=Rectangle(c1,w1,l1)
areaRect1=rect1.area()
print(rect1.area)


c2='blue'
w2=4
l2=6.235424553667
rect2=Rectangle(c2,w2,l2)
areaRect2=rect2.area()
print(rect2.area)
per1=rect1.per()

print('Rectangle 1 is',rect1.color)

print('The ',rect1.color,'Retangle has the Perimeter of',rect1.per)