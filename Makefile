all: dat_ec3.dat graf_ec3(1).png graf_ec3(2).png

graf_ec3(1).png graf_ec3(2).png: dat_ec3.dat graf_ec3.py
	python3 graf_ec3.py

dat_ec3.dat: sol_ec3.x
	./sol_ec3.x

sol_ec3.x: sol_ec3.cpp
	g++ sol_ec3.cpp -o sol_ec3.x

clean:
	rm -rf *.x *.dat *.png
