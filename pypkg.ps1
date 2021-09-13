# Begining Prompt
Write-Output "Download https://visualstudio.microsoft.com/visual-cpp-build-tools/ select C++ Tools"
Read-Host -Prompt "Press Enter to Continue"

# Python 3
py -3 -m pip install -r .\Packages\requirements.txt --upgrade --user
py -3 -m pip install -r .\Packages\pip.txt --upgrade --user
py -3 -m pip install opencv-contrib-python --upgrade --user