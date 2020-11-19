Write-Output "Download https://www.microsoft.com/en-us/download/details.aspx?id=44266 and https://visualstudio.microsoft.com/visual-cpp-build-tools/ select C++ Tools"
py -2 -m pip install -r requirements-python2.txt -U --user
py -2 -m pip install -r pip-python2.txt -U --user
py -3.8 -m pip install -r requirements.txt -U --user
py -3.8 -m pip install -r pip.txt -U --user
py -3 -m pip install -r requirements.txt -U --user
py -3 -m pip install -r pip-python3.9.txt -U --user