#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return exp(x);
}

double fp(double x)
{
	return exp(x);
}

int main() {
	double xT[4]={-1.0,0.5,1.5,2.0};
	double x, p, l_jn, l_jnP, h_jn, hBar_jn;
	int NbStep,n;
	
	x=-5.0;
	n=4;
	NbStep=int (10.000001/0.1);
	

	cout<<"Lagrange p(x):"<<endl;
	for(int step=0;step<=NbStep;step++) 
	{
		p=0.0;
		for(int j=0;j<n;j++)
		{
			l_jn=1.0;
			for(int i=0;i<n;i++)
			{
				if(i!=j) l_jn=l_jn*((x-xT[i])/(xT[j]-xT[i])); //calculate l_jn
			}
			p=p+l_jn*f(xT[j]);
		}
		cout<<"x= "<<x<<" p(x)= "<<p<<endl;
		x=x+0.1;
	}
		
	cout<<endl<<"Hermite p(x):"<<endl;
	x=-5.0;
	for(int step=0;step<=NbStep;step++)
	{
		p=0.0;
		for(int j=0;j<n;j++) 
		{
			l_jn=1.0;
			l_jnP=0.0;
			for(int i=0;i<n;i++)
			{
				if(i!=j)
				{
					l_jn=l_jn*((x-xT[i])/(xT[j]-xT[i])); 
					l_jnP=l_jnP+(1.0/(xT[j]-xT[i])); 
				}
			}
			h_jn=(1.0-2.0*(x-xT[j])*l_jnP)*l_jn*l_jn;
			hBar_jn=(x-xT[j])*l_jn*l_jn;
			p=p+h_jn*f(xT[j])+hBar_jn*fp(xT[j]);
		}
		cout<<"x= "<<x<<" p(x)= "<<p<<endl;
		x=x+0.1;
	}
		
	return 0;
}
