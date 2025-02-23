chown -R $USER .
cd app
qmake6 la-calc.pro
make
make clean
chmod a=rwx la-calc.app
rm ~/Desktop/LA-calculator
ln -s la-calc.app ~/Desktop/LA-calculator

