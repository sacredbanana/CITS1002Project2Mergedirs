/*
   CITS Project 2 2012
   Name: Cameron Armstrong
   Student number: 21194619
   Date: 2/11/2012
*/

#include "mergedirs.h"

int main( int argc, char *argv[])
{
int opt;
int optionCount = 0;
opterr = 0;
while((opt = getopt(argc, argv, OPTLIST)) != -1) // Check for switches
{
	if (opt == 'l') // Check for largest switch
 	{		
		optionCount++;
		largest = true;
		printf("Largest is true\n");
	} 
	else if (opt == 'm') // Check for modification time switch
		{
		optionCount++;
		modification = true;
		printf("Modification is true\n");
		}
	else if (opt == 'v') // Check for verbose switch
		{
		optionCount++;
		verbose = true;
		printf("Verbose is true\n");
		}
	else if (opt == 'i') // Check for pattern switch
		{
		optionCount = optionCount + 2;
		patternCheck = true;
		strcpy(pattern, optarg);
		printf("Pattern check on\n");
		}
	else if (opt == 'c') // Check for contents comparison switch
		{
		optionCount++;
		contents = true;
		printf("Contents check mode activated\n");
		}
	else
		{
		fprintf(stderr, "No switches.Turning on modification time mode.\n"); // If no switches
		modification = true;
		}
}
if ((modification == false) && (largest == false) && (contents == false)) // If no valid mode is selected, select modification
{
	fprintf(stderr, "No mode activated. Enabling modification time mode.\n");
	modification = true;
}

int noOfInputs = 0;
char inputDirectory[10][100];
for (int i = 1; i <= (argc - 2); i++) // Check for the input directories
{
	if ((argv[i][0] != '-')&&(argv[i][0] != pattern[0]) && (argv[i][1] != pattern[1]))
	{
		noOfInputs++;
		strcpy(inputDirectory[noOfInputs - 1], argv[i]);
	}
}
strcpy(outputDirectory, argv[argc - 1]);
printf("The output directory is %s\n", outputDirectory); // Gets output directory
if (verbose == true)
	printf("Creating directory %s\n", outputDirectory);
mkdir(outputDirectory, 0777); // Creates main output directory
strcat(outputDirectory, "/");
for (int i = 0; i <= (noOfInputs - 1); i++)
{
	readDirectory(inputDirectory[i]); // Starts reading directories
}
return 0;
}

