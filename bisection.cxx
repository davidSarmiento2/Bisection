#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#define epsilon0 10e-8
#define epsilon1 10e-4
#define epsilon2 10e-2

const double EulerConstant = std::exp(1.0);
const double pi = M_PI;


double function (double x);
double bisection (double a, double b, double epsilon);

int main(int argc, char* argv[])
{
	double ans = bisection(0,10, 10e-8);
	if (ans > 0)
	{
		std::cout << "La cantidad de iteraciones necesarias para hallar la raiz, fueron; " << ans << std::endl;
	}
	return 0;
}

double function (double x)
{
	return (x * (pow(EulerConstant,x))) - pi;
}

double bisection (double a, double b, double epsilon)
{
	double midPoint = 0;
	double iteration = 0;

	while (function(midPoint) != 0 || fabs(function(midPoint)) > epsilon)
	{
		++iteration;
		if(function(a) * function (b) < 0)
		{	
			midPoint = (a+b)/2;
			if(fabs(function(midPoint)) < epsilon)
			{
				break;
			}
			if( (function(a))*function(midPoint) > 0 )
			{
				a = midPoint;
			}
			else
			{
				b = midPoint;
			}
		}
		else
		{
			std::cout << "Dados los intervalos, no hay raiz" << std::endl;
			return 0;
		}
	}
	std::cout << "La raiz es: " << midPoint << std::endl; 
	return iteration;
}
