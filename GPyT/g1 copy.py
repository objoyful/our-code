from github import Github
import os
import time
from datetime import datetime

end_time = time.time()
start_time = end_time - 86400

ACCESS_TOKEN = open(os.path.join("GPyT", "token.txt"), 'r').read()
g = Github(ACCESS_TOKEN)

for i in range(5):
    start_time_string = datetime.utcfromtimestamp(start_time).strftime('%Y-%m-%d')
    end_time_string = datetime.utcfromtimestamp(end_time).strftime('%Y-%m-%d')

    query = f"language:python created:{start_time_string}..{end_time_string}"
    print(query)

    result = g.search_repositories(query)

    for repositories in result:
        url = repositories.clone_url
        path = os.path.join("GPyT", "repos", repositories.owner.login, repositories.name)
        os.system(f"git clone {url} {path}")
        break

    end_time -= 86400
    start_time -= 86400