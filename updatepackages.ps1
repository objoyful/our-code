Write-Output "Download https://www.microsoft.com/en-us/download/details.aspx?id=44266 and https://visualstudio.microsoft.com/visual-cpp-build-tools/ select C++ Tools"
py -2 -m pip install -r .\Packages\requirements-python2.txt -U --user
py -2 -m pip install -r .\Packages\pip-python2.txt -U --user
py -3.8 -m pip install -r .\Packages\requirements.txt -U --user
py -3.8 -m pip install -r .\Packages\pip.txt -U --user
py -3 -m pip install -r .\Packages\requirements.txt -U --user
py -3 -m pip install -r .\Packages\pip-python3.9.txt -U --user