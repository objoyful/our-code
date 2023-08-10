from github import Github
import os
import time
from datetime import datetime
# from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan

end_time = 1691379494.951034
start_time = end_time-86400

BILL_TOKEN = open(os.path.join("GPyT", "token.txt"), 'r').read()
BOB_TOKEN = open(os.path.join("GPyT", "bob-token.txt"), 'r').read()

g = Github(BOB_TOKEN)
print(g.get_user())

for i in range(50):
    try:
        start_time_string = datetime.utcfromtimestamp(start_time).strftime('%Y-%m-%d')
        end_time_string = datetime.utcfromtimestamp(end_time).strftime('%Y-%m-%d')

        query = f"language:python created:{start_time_string}..{end_time_string}"
        
        result = g.search_repositories(query)

        print(result.totalCount)

        for repository in result:
            print(f"{repository.clone_url}")
            os.system(f"git clone {repository.clone_url} {os.path.join('GPyT', 'repos', repository.owner.login, repository.name)}")

            print(f"current system time {start_time}")
    except Exception as e:
        print(str(e))
        print("Broke for some reason")
        
        end_time -= 86400
        start_time -= 86400