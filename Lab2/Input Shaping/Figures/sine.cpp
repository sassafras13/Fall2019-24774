#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main(){

	clock_t t;
	double w = 3.14159;
	int a = 1;
	double s = 0;

	while(1>0){
		t = clock();

		cout<<"Time- "<<t<<endl;

		if(a*sin(w*t) > 0){
		 s = a;
		}
	else if(a*sin(w*t) < 0){
  		s = -a;
		}
	else if(a*sin(w*t) == 0){
  		s = 0;
		}

		cout<<"Signal- "<<s<<endl;
		cout<<"\n";
	}



	return 0;
}