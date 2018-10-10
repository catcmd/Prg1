#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h> /*strlen()*/

int main (int argc, char *argv[]) 
{
	char reader[256];

	//memset(reader, 0, sizeof(reader));
	//memset(destination,int Value; sizeof(array))
	//sets the content of array to whatever you want
	for (int counter = 0; counter < sizeof(reader); counter++)
	{
		reader[counter] = 0;
	}

	
	unsigned int bytes_written = 0;//globaler counter 

	if (argc > 2)/*argc = 2 because 2 dimensonal array *argv[]*/ 
	{
		for(int counter_sigma = 1; counter_sigma < argc; counter_sigma++)
			//äußere counter zählt ab array 1 dimension
		{
			for (int counter_pi = 0; counter_pi < strlen(argv[counter_sigma]); counter_pi++)
				//counter counts inner pi and compares to dimension
			{
				if (bytes_written < sizeof(reader))
					//es darf nur bis zu begrenzung von reader buffer eingelesen werden
				{
					reader[bytes_written] = argv[counter_sigma][counter_pi];
					//reader[anzahl der wörter]
					//argv[dimension]+[stelle] = character

					bytes_written++;
				}
				else
				{
					printf("Too many symbols!");
					break;
				}
			}
		}
		printf("%s\n sehr schoooeeeen eingelesen Memet!", reader);//Danke Herr Huan!
	}
	else 
	{
		printf("Give me the inputz.\n");
	}
	
	
}