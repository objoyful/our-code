import os
from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
import time

root_dir = os.path.abspath(os.sep)
d = os.path.join(root_dir, "mnt", "e", "repos")
days = os.listdir(d)

for dirpath, dirnames, filenames in os.walk(d):
    for f in filenames:
        full_path = os.path.join(dirpath, f)

        if full_path.endswith('.py'):
            # print(green(f"Keeping {full_path}"))
            pass
        else:
            print(red(f"Deleting {full_path}"))
            
            if d in full_path:
                os.remove(full_path)
            else:
                print(yellow("Somethinonlypy.pygs wrong"))
                time.sleep(60)
for day in days:
    d = os.path.join(d, day)
    while True:
        empty_dirs = 0
        for dirpath, dirnames, filenames in os.walk(d):  
            if len(filenames) == 0 and len(dirnames) == 0:
                empty_dirs += 1
                print(red(f"Removing {dirpath}"))
                os.rmdir(dirpath)
        
        if empty_dirs == 0:
            break
    print(green(f"Checked {day}"))