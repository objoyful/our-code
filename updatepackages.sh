#Install packages for Drone Dojo
sudo apt install python3.8 python3.9 python3-pip python2 python-dev python3-dev python3-wxgtk4.0 python3-yaml vim git screen
python2 ./Packages/get-pip.py --user
sudo usermod -a -G dialout $USER

#Python 2
python -m pip install -r requirements-python2.txt -U --user
python -m pip install -r pip-python2.txt -U --user

#Python 3
python3 -m pip install -r requirements.txt -U --user
python3 -m pip install -r pip.txt -U --user

#Python 3.9
python3.9 -m pip install -r requirements.txt -U --user
python3.9 -m pip install -r pip-python3.9.txt -U --user