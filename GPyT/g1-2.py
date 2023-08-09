import time
from datetime import datetime

end_time = time.time()
start_time = end_time-86400

for i in range(5):
    start_time_string = datetime.utcfromtimestamp(start_time).strftime('%Y-%m-%d')
    end_time_string = datetime.utcfromtimestamp(end_time).strftime('%Y-%m-%d')

    query = f"pyopengl language:python created:{start_time_string}..{end_time_string}"
    print(query)
    
    end_time -= 86400
    start_time -= 86400