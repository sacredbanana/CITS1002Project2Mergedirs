#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <string.h>
#include <sys/time.h>
#include <utime.h>

// DECLARE GLOBAL PREPROCESSOR CONSTANTS
#define OPTLIST			"lmvi:c"
// DECLARE GLOBAL FUNCTIONS
extern void readDirectory(char*);
extern void copyFile(char*, char*);
extern bool fileCheck(char*, char*);
extern char* filesummary(char*);
//DECLARE GLOBAL VARIABLES
extern bool patternCheck;
extern bool largest;
extern bool modification;
extern bool verbose;
extern bool contents;
extern char outputDirectory[MAXPATHLEN];
extern char pattern[100];
