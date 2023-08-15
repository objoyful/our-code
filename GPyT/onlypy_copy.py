import os
from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan

repos = os.path.join("GPyT", "repos_test")

for dirpath, dirnames, filenames in os.walk(repos):
    # print(dirpath, dirnames, filenames)

    for file in filenames:
        full_path = os.path.join(dirpath, file)
        
        if full_path.endswith('.py'):
            print(green(f"Keeping {full_path}"))
        else:
            if repos in full_path:
                print(red(f"Deleting {full_path}"))
                os.remove(full_path)
            else:
                print(yellow("Something went wrong"))

while True:
    empty_dirs = 0
    for dirpath, dirnames, filenames in os.walk(repos):
        if len(dirnames) == 0 and len(filenames) == 0:
            empty_dirs += 1
            os.rmdir(dirpath)
        
    if empty_dirs == 0:
        break
    print('==='*5)