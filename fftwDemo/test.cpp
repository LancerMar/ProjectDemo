#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <complex>
#include <fftw3.h>

int main()
{
	std::ofstream ofout("out.dat");

	ofout.precision(8);
    
    fftw_complex *in;
    fftw_complex *out;
    fftw_plan p;

    const int N=1000;
    in = (fftw_complex*)fftw_malloc(sizeof(double)*N);
    out = (fftw_complex*)fftw_malloc(sizeof(double)*N);
    std::ifstream file("testdata.dat",std::ios::in | std::ios::binary);

    char val[4*N];
    char* val_tmp;
    val_tmp=val;
    for (int i=0;i<N*4;i=i+4)
    {

        file.read(val_tmp,4);
        //in[i/4][0] =*(int32_t*)(val_tmp);
        in[i/4][0] = 0;
        in[i/4][1] = 0;
        val_tmp=val_tmp+4;
    }

    p = fftw_plan_dft_1d(N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);

    fftw_execute(p);

    for(int i=0;i<N;i++)
	{
		ofout<<out[i][0]<<std::endl;
	}

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

}