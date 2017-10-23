/*
* Conversion Table:-
* C to F
* (C * 1.8) + 32
* F to C
* (F - 32) / 1.8
* 
* C to K
* C + 273.15
* K to C
* K - 273.15
* 
* K to F
* (K - 273.15) * 1.8 + 32
* F to K
* (F - 32) / 1.8 + 273.15
*/

#include <stdio.h>
#include <stdlib.h>

static void ConvertT(double value, char unit);

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 3) 	{
		printf("Incorrect Input;\nUsage ex: [Value] [Unit of Messurment]\n");
	}
	else if	(argc == 3)	{
		ConvertT(atof(argv[1]), *argv[2]);
	}
	else	{
		ConvertT(atof(argv[1]), 'C');
		ConvertT(atof(argv[1]), 'F');
		ConvertT(atof(argv[1]), 'K');
	}
	
	return 0;
}

void ConvertT(double value, char unit)
{
	if (unit == 'C' || unit == 'c')	{
		if(value <= -273.15)	{
			printf("Celsius: <= Absolute Zero\n\n");
  		}
  		else	{
			printf("%.2f C:\n", value);
			printf("%.2f F\n", (value * 1.8) + 32);
			printf("%.2f K\n\n", value + 273.15);
  		}
	}

	else if (unit == 'F'|| unit == 'f')	{
		if(value <= -459.67)	{
			printf("Fahrenheit: <= Absolute Zero\n\n");
  		}
  		else	{
			printf("%.2f F:\n", value);
			printf("%.2f K\n", (value - 32) / 1.8 + 273.15);
			printf("%.2f C\n\n", (value - 32) / 1.8);
  		}
	}

	else if (unit == 'K'|| unit == 'k')	{
		if(value <= 0)	{
			printf("Kelvin: <= Absolute Zero\n\n");
  		}
  		else	{
			printf("%.2f K:\n", value);
			printf("%.2f F\n", (value - 273.15) * 1.8 + 32);
			printf("%.2f C\n\n", value - 273.15);
  		}
	}

	else	{
			printf("Incorrect Unit;\nUnit must be C, F or K (c, f or k)\n");
	}
}