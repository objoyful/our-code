import os
# from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
import time

for dirpath, dirnames, filenames in os.walk(os.path.join("GPyT", "repos_test")):
    # print(dirpath)
    # print(dirnames)
    # print(filenames)

    for f in filenames:
        full_path = os.path.join(dirpath, f)

        if full_path.endswith('.py'):
            print(f"Keeping {full_path}")
        else:
            print(f"Deleting {full_path}")
    
    # time.sleep(0.5)
    # break