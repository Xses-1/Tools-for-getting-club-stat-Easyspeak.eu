#include <bits/stdc++.h>

int main () {

	int DataLen;    //Length of the input data
	int rep;        //Number of repetitions of Biquad filter

	long double s1 = 0;
	long double s2 = 0;
	long double y  = 0;


	/***** 30 - Sample rate (Hz); 1.2 - Fc (Hz); 0.66 - Q; 0 - Gain (dB); ****/

	/*
	long double a0 =  0.013218108833849065;
	long double a1 =  0.026436217667698130;
	long double a2 =  0.013218108833849065;
	long double b1 = -1.630060578768085500;
	long double b2 =  0.682933014103481800;
	

	long double a0 =  0.015450834080293272;
	long double a1 =  0.030901668160586544;
	long double a2 =  0.015450834080293272;
	long double b1 = -1.615928550743209000;
	long double b2 =  0.677731887064382100;
	
	long double a0 =  0.014515272203912907;
	long double a1 =  0.029030544407825813;
	long double a2 =  0.014515272203912907;
	long double b1 = -1.518082626104218400;
	long double b2 =  0.576143714919870200;
	*/

	long double a0 =  0.015768438130305498;
	long double a1 =  0.031536876260610996;
	long double a2 =  0.015768438130305498;
	long double b1 = -1.649145233388259200;
	long double b2 =  0.712218985909481300;

	/*
	long double a0 =  0.03560519814260837;
	long double a1 =  0.07121039628521673;
	long double a2 =  0.03560519814260837;
	long double b1 = -1.50492807640712110;
	long double b2 =  0.64734886897755440;

	long double a0 =  0.009596104727053228;
	long double a1 =  0.019192209454106456;
	long double a2 =  0.009596104727053228;
	long double b1 = -1.718146680520927000;
	long double b2 =  0.756531099429140000;
	
	long double a0 =  0.006031090479547847;
	long double a1 =  0.012062180959095694;
	long double a2 =  0.006031090479547847;
	long double b1 = -1.337852909293157300;
	long double b2 =  0.361977271211348650;
	*/


	std::cout << "Repetitions:" << std::endl;
	std::cin >> rep;

	std::cout << "Data length:" << std::endl;
	std::cin >> DataLen;

	int32_t    in[DataLen];
        long double out[DataLen];


	for (int i = 0; i < DataLen; i++) {

		std::cin >> in[i];

	}

	/**** Biquad filter algorithm ****/
	for (int j = 0; j < rep; j++ ) {

		for (int i = 0; i < DataLen; i++) {

        		y  = a0 * in[i] + s1;
	        	s1 = a1 * in[i] - b1 * y + s2;
	       	 	s2 = a2 * in[i] - b2 * y;

        		out[i] = y;

       		 }

		if (j == (rep - 1)) {
			break;
		}

		for (int i = 0; i < DataLen; i++) {

			in[i] = out[i];

		}
	}


	std::cout << std::endl <<
	"---------------------------------------------------------------------------"
	"---------------------------------------------------------------------------"
	<< std :: endl  << std::endl;

	for (int i = 0; i < DataLen; i++) {

		std::cout << out[i] << std::endl;

	}



	return 0;

}
