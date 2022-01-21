#include<iostream>
#include<cmath>
#include<complex>
#include<fstream>
#include<fftw3.h>

const int N=1000;

int main()
{
	//std::ofstream of1("ECGdataIn.dat");
	//std::ofstream of2("ECGdataOut.dat");
	std::ofstream ofin("in.txt");
	std::ofstream ofout("out.txt");

	ofin.precision(6);
	ofout.precision(6);

	fftw_complex *in, *out;
	fftw_plan p;
	


	return 0;
}
