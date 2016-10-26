#include "mergedirs.h"

static void readSubdirectory(char *subDirName, char *mainDirName) // Reads a subdirectory
{
	DIR *subdirp;
	struct dirent *sdp;
	char fullname[MAXPATHLEN];
	subdirp = opendir(subDirName);
	char newDirectory[MAXPATHLEN];
	if (subdirp == NULL)
	{
		perror(" mergedirs" );
		exit(EXIT_FAILURE);
	}
	
	while((sdp = readdir(subdirp)) != NULL) // Reading
	{
		struct stat stat_buffer;
		sprintf(fullname, "%s/%s", subDirName, sdp->d_name );
		if (stat(fullname, &stat_buffer) != 0)
		{
			perror( "mergedirs" );
			exit(EXIT_FAILURE);
		}
		else if (( S_ISDIR( stat_buffer.st_mode ) && strcmp(sdp->d_name, "..") != 0) && strcmp(sdp->d_name, ".") != 0) // Created needed directory
		{
			strcpy(newDirectory, outputDirectory);
			strcat(newDirectory, mainDirName);
			strcat(newDirectory, "/");
			strcat(newDirectory, sdp->d_name);
			mkdir(newDirectory, 0777);
			if (verbose == true)
				printf("Creating directory %s", newDirectory);
		}
        else if( S_ISREG( stat_buffer.st_mode )) { // Reading file
		strcpy(newDirectory, outputDirectory);
		strcat(newDirectory, mainDirName);
                strcat(newDirectory, "/");
                strcat(newDirectory, sdp->d_name);
                if (fileCheck(fullname, newDirectory)) // Checks if can copy file
		{
			copyFile(fullname, newDirectory);
			if (verbose == true)
				printf("Copying file %s to: %s\n", fullname, newDirectory);
		}
        }
        }
        closedir(subdirp);
}

void readDirectory(char *dirName) // Reads directory
{
	DIR *dirp;
	struct dirent *dp;
	char fullname[MAXPATHLEN];
	char newDirectory[MAXPATHLEN];
	dirp = opendir(dirName); 
	if (dirp == NULL)
	{
		perror( "mergedirs" );
        	exit(EXIT_FAILURE);
   	}		

	while((dp = readdir(dirp)) != NULL)
	{  
	struct stat  stat_buffer;

        sprintf(fullname, "%s/%s", dirName, dp->d_name );    

        if(stat(fullname, &stat_buffer) != 0) {
        	perror( "mergedirs" );
		exit(EXIT_FAILURE);
        }
        else if(( S_ISDIR( stat_buffer.st_mode ) && strcmp(dp->d_name, "..") != 0) && strcmp(dp->d_name, ".") != 0) { // Creates needed directories
		strcpy(newDirectory, outputDirectory);
		strcat(newDirectory, "/");
		strcat(newDirectory, dp->d_name);
		if ((strpbrk(newDirectory, pattern) != NULL) && (patternCheck == true)) // Pattern check, if enabled
        	{
                	printf("Search matched. Bypassing directory.\n");
             
        	}
		else {
			if (verbose == true)
                		printf("Creating directory %s", newDirectory);
			mkdir(newDirectory, 0777);
			readSubdirectory(fullname, dp->d_name);
		}        
}
        else if( S_ISREG( stat_buffer.st_mode )) { // Read file
		strcpy(newDirectory, outputDirectory);
		strcat(newDirectory, dp->d_name);
		if (fileCheck(fullname, newDirectory)) // Checks if file needs copying
		{
			if (verbose == true)
				printf("Copying file %s to %s\n", fullname, newDirectory);
			copyFile(fullname, newDirectory);
		}
        }
        else {
        }
	}
    	closedir(dirp);
} 
