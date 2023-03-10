import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2 * np.pi, 100)

y = np.sin(x)
y2 = np.cos(x)

# x = np.linspace(-4, 4, 25)

#y = np.square(x)
#y2 = np.square(x) + 2
#y3 = np.square(x) + 4

#y = np.square(x)
#y2 = np.square(x - 2)
#y3 = np.square(x - 4)

#x = np.arange(-4, 4, 0.1)

#y = np.square(x)
#y2 = np.square(x - 2)
#y3 = np.square(x - 4)

#y = np.square(x)
#y2 = np.square(x) + 2
#y3 = np.square(x) - 2

#x = [1, 2, 3, 4]
#y = [3, 5, 7, 9]
#z = [10, 8, 6, 4]

plt.grid(True)

plt.xlabel('My X Values')
plt.ylabel('My Y Values')
plt.title('My First Graph')

#plt.axis([0, 5, 2, 11])

plt.plot(x, y, 'b-^', lineWidth = 3, markerSize = 7, label = 'Blue Line')
plt.plot(x, y2, 'r-^', lineWidth = 3, markerSize = 7, label = 'Red Line')
#plt.plot(x, y3, 'g-^', lineWidth = 3, markerSize = 7, label = 'Green Line')
#plt.plot(x, z, 'r:o', lineWidth = 3, markerSize = 7, label = 'Red Line')

plt.legend(loc = 'upper center')
plt.show()