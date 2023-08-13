import os

repos = os.path.join("GPyT", "repos")

for dirpath, dirnames, filenames in os.walk(repos):
    # print(dirpath, dirnames, filenames)

    for file in filenames:
        full_path = os.path.join(dirpath, file)
        
        if full_path.endswith('.py'):
            print(f"Keeping {full_path}")
        else:
            try:
                print(f"Deleting {full_path}")
                os.remove(full_path)
                print("Done!")
            except Exception as e:
                print(e)

