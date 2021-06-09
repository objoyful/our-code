Write-Output "Download https://www.microsoft.com/en-us/download/details.aspx?id=44266 and https://visualstudio.microsoft.com/visual-cpp-build-tools/ select C++ Tools"
Read-Host -Prompt "Press Enter to Continue"
py -2 -m pip install -r .\Packages\requirements-python2.txt --upgrade --user
py -2 -m pip install -r .\Packages\pip-python2.txt --upgrade --user
py -3.8 -m pip install -r .\Packages\requirements.txt --upgrade --user
py -3.8 -m pip install -r .\Packages\pip.txt --upgrade --user
py -3 -m pip install -r .\Packages\requirements.txt --upgrade --user
py -3 -m pip install -r .\Packages\pip.txt --upgrade --user