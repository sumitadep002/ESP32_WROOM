#This is setup for Command Line based Interface


#Install some prerequistiqes like: git, make, cmake, ninja etc....
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0



#Install SDK and setup environment
mkdir -p Toolchain/esp/
cd Toolchain/esp/
git clone --recursive https://github.com/espressif/esp-idf.git

cd Toolchain/esp/esp-idf/
./install.sh


#Below line so that you can use idf based commands in your local workspace direcotry like idf.py create-projects, idf.py build etc...
echo alias set-idf=". Toolchain_Setup/esp/esp-idf/export.sh" >> ~/.bashrc
source ~/.bashrc

echo "Everything has been set propperly."
echo "Now you are ready to use idf in your personal workspace"
echo "To use idf resources go to the workspace you want to work in and use command: set-idf"
echo "you can explore the examples from Toolchain/esp/esp-idf/examples"
echo "Either you can use projects from examples or create from scratch"
echo "To create a project from scratch run command: idf.py create-project Name_of_Project"
