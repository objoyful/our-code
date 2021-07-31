import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [3, 5, 7, 9]
z = [10, 8, 6, 4]

plt.grid(True)

plt.xlabel('My X Values')
plt.ylabel('My Y Values')
plt.title('My First Graph')

plt.axis([0, 5, 2, 11])

plt.plot(x, y, 'b-^', lineWidth = 3, markerSize = 7, label = 'Blue Line')
plt.plot(x, z, 'r:o', lineWidth = 3, markerSize = 7, label = 'Red Line')

plt.legend(loc = 'lower center')
plt.show()