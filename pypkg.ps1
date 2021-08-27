# Begining Prompt
Write-Output "Download https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi and https://visualstudio.microsoft.com/visual-cpp-build-tools/ select C++ Tools"
Read-Host -Prompt "Press Enter to Continue"

# Python 3
py -3 -m pip install -r .\Packages\requirements.txt --upgrade --user
py -3 -m pip install -r .\Packages\pip.txt --upgrade --user
py -3 -m pip install opencv-contrib-python --upgrade --user