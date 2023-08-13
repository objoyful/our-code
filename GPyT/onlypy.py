import os
from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
import time


d = os.path.join("GPyT", "repos_test")

for dirpath, dirnames, filenames in os.walk(d):
    for f in filenames:
        full_path = os.path.join(dirpath, f)

        if full_path.endswith('.py'):
            print(green(f"Keeping {full_path}"))
        else:
            print(red(f"Deleting {full_path}"))
            
            if d in full_path:
                os.remove(full_path)
            else:
                print(yellow("Somethings wrong"))
                time.sleep(60)
while True:
    empty_dirs = 0
    for dirpath, dirnames, filenames in os.walk(d):  
        if len(filenames) == 0 and len(dirnames) == 0:
            empty_dirs += 1
            print(red(f"Removing {dirpath}"))
            os.rmdir(dirpath)
    
    if empty_dirs == 0:
        break