import numpy as np

a=np.array([[1,2,3,4],
            [5,6,7,8],
            [9,10,11,12]])
print("a的形状：",a.shape) #(3,4)

row=np.array([100,200,300,400])
print(a+row) #[[101,102,103,104],[105,106,107,108],[109,110,111,112]]

col=np.array([[100],[200],[300]])
print(a+col) #成功

bad=np.array([1,2,3])
print(a+bad) #报错
