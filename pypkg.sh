#Install packages for Drone Dojo
sudo apt install -y python3.9 python2 python-dev python3-dev python3-wxgtk4.0 python3-yaml vim git screen libffi-dev build-essential autoconf libtool pkg-config python3-opengl python-pil idle-python2.7 pyqt5-dev-tools libqscintilla2-qt5-designer python3-qtpy libgle3 python-dev libssl-dev python3.9-dev gstreamer1.0-plugins-bad gstreamer1.0-libav gstreamer1.0-gl
python2 ./Packages/get-pip-python2.py -U --user
python3.9 ./Packages/get-pip.py -U --user
sudo usermod -a -G dialout $USER

#Python 2
python2 -m pip install -r ./Packages/requirements-python2.txt -U --user
python2 -m pip install -r ./Packages/pip-python2.txt -U --user

#Python 3
python3.9 -m pip install -r ./Packages/requirements.txt -U --user
python3.9 -m pip install -r ./Packages/pip.txt -U --user