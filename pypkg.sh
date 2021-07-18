#Install packages for Drone Dojo
sudo apt install -y python-is-python3 python3.9 python3-dev python3-wxgtk4.0 python3-yaml vim git screen libffi-dev build-essential autoconf libtool pkg-config python3-opengl python-pil pyqt5-dev-tools libqscintilla2-qt5-designer python3-qtpy libgle3 libssl-dev python3.9-dev gstreamer1.0-plugins-bad gstreamer1.0-libav gstreamer1.0-gl
python3.9 ./Packages/get-pip.py -U --user
sudo usermod -a -G dialout $USER

#Python 3
python3.9 -m pip install -r ./Packages/requirements.txt -U --user
python3.9 -m pip install -r ./Packages/pip.txt -U --user
