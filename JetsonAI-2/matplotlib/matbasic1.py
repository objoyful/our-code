import matplotlib.pyplot as plt
import numpy as np
x=np.arange(4,-4,.1)
y=np.sin(x)
y2=np.square(x)
y3=np.square(x-2)
plt.plot(x,y,'r-*')
plt.title('My Cool Graph')
plt.legend(loc = 'lower center')
plt.show()
