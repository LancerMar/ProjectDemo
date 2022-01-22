#include <cstdlib>
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

	in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);
	out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);

	for(int i=0;i<N;i++)
	{
		in[i][0]=sin(i)+sin(10*i)+sin(100*i);
		in[i][1]=0;
	}
	
	p = fftw_plan_dft_1d(N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);

	fftw_execute(p);

	for(int i=0;i<N;i++)
	{
		ofin<<in[i][0]<<std::endl;
		ofout<<out[i][0]<<std::endl;
	}

	fftw_destroy_plan(p);
	fftw_free(in);
	fftw_free(out);

	return 0;
}
