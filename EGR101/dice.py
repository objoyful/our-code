import random

dice_counters = [0, 0, 0, 0, 0, 0]
total_rolls = 0

while max(dice_counters) < 100:
    roll = random.randint(0, 5)
    dice_counters[roll] += 1
   
    total_rolls += 1

print("One was rolled", dice_counters[0], "times")
print("Two was rolled", dice_counters[1], "times")
print("Three was rolled", dice_counters[2], "times")
print("Four was rolled", dice_counters[3], "times")
print("Five was rolled", dice_counters[4], "times")
print("Six was rolled", dice_counters[5], "times")

print("Total rolls:", total_rolls)