from github import Github
import os
import time
from datetime import datetime

end_time = time.time()
start_time = end_time-86400

ACCESS_TOKEN = open(os.path.join("GPyT", "token.txt"), 'r').read()
g = Github(ACCESS_TOKEN)
print(g.get_user())

for i in range(5):
    start_time_string = datetime.utcfromtimestamp(start_time).strftime('%Y-%m-%d')
    end_time_string = datetime.utcfromtimestamp(end_time).strftime('%Y-%m-%d')

    query = f"language:python created:{start_time_string}..{end_time_string}"
    
    result = g.search_repositories(query)

    print(result.totalCount)

    for repository in result:
        print(f"{repository.clone_url}")
        os.system(f"git clone {repository.clone_url} {os.path.join('GPyT', 'repos', repository.owner.login, repository.name)}")

    end_time -= 86400
    start_time -= 86400