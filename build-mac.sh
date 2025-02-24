chown -R $USER .
cd app
qmake6 la-calc.pro
make
make clean
sudo chmod a=rwx la-calc.app
rm ~/Desktop/LA-calculator
ln la-calc.app/Contents/MacOS/la-calc ~/Desktop/LA-calculator
