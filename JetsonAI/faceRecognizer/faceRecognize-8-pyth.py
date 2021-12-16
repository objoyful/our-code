def RectCalc(w, l):
    area = w * l
    per = 2 * w + 2 * l

    return area, per

l1 = 3
w1 = 5
area1, per1 = RectCalc(l1, w1)
print('Results of Retcangle 1:', area1, per1)

l2 = 6
w2 = 4
area2, per2 = RectCalc(l2, w2)
print('Results of Retcangle 2:', area2, per2)