#include "mergedirs.h"

bool fileCheck(char *source, char *destination) // Checks if file should be copied
{
  bool fileExists = false;
  struct stat   buffer;   
  int existenceCheck = (stat (destination, &buffer) == 0); // Checks if file already exists
	if (existenceCheck == 1)
    	{
        	fileExists = true;

		if (contents == true)  // Contents check with c switch **NOT WORKING**
		{
			printf("Checking contents\n");
			printf("Contents of 1: %s\nContents of 2: %s\n", filesummary(source), filesummary(destination));
			if (strpbrk(filesummary(source), filesummary(destination)) != NULL)
                	{
                        printf("Contents search matched\n");
                	}
			else printf("Contents search did not match\n");	
		}
                        struct stat foo;
                        time_t mtime, size;

                        if (stat(source, &foo) < 0)
                        {
                                perror(source);
                                exit(EXIT_FAILURE);
                        }
                        mtime = foo.st_mtime; //Finds file times and sizes
			size = foo.st_size;
                        struct stat foo2;
                        time_t mtime2, size2;

                        if (stat(destination, &foo2) < 0)
                        {
                                perror(destination);
                                exit(EXIT_FAILURE);
                        }
                        mtime2 = foo2.st_mtime;
			size2 = foo2.st_size;

		if (modification == true) // Modification mode
		{		
			if (mtime > mtime2) // If source is newer than destination
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (largest == true) // Largest size mode
		{
			if (size > size2) // If source is larger than destination
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		{
		return true;
		}

    	}
	else
	{
		fileExists = false;
		return true;
	}
return fileExists;	
}
