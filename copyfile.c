#include "mergedirs.h"

void copyFile(char in_filename[], char destination[])
{
    FILE        *fp_in  = fopen(in_filename, "r");
    FILE        *fp_out = fopen(destination, "w");

//  ENSURE THAT OPENING BOTH FILES HAS BEEN SUCCESSFUL
    if(fp_in != NULL && fp_out != NULL) {

        char    buffer[BUFSIZ];
        size_t  got, wrote;

if ( modification == true)
{
        while( (got = fread(buffer, 1, sizeof buffer, fp_in)) > 0) {  
            wrote = fwrite(buffer, 1, got, fp_out);
            if(wrote != got) {
                printf("error copying files\n");
                exit(EXIT_FAILURE);
            }
        }

	if (verbose == true)
		printf("%s copied to %s\n", in_filename, destination); 
}
//  ENSURE THAT WE ONLY CLOSE FILES THAT ARE OPEN
    if(fp_in != NULL)
        fclose(fp_in);
    if(fp_out != NULL)
        fclose(fp_out);

  struct stat foo;
  time_t mtime;
  struct utimbuf new_times;

  if (stat(in_filename, &foo) < 0) {
    perror(in_filename);
    exit(EXIT_FAILURE);
  }
  mtime = foo.st_mtime;
  new_times.modtime = foo.st_mtime;    // set mtime to mtime of original file
  if (utime(destination, &new_times) < 0) {
    perror(destination);
    exit(EXIT_FAILURE);
  }

    }


}
