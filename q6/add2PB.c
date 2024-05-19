#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    /* Open the file "phonebook.txt" in append mode ("a")
     If the file does not exist, it will be created */
    FILE *filePointer = fopen("phonebook.txt", "a"); 

    int i;

  // Check if the file was opened successfully
    if (filePointer == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the first command-line argument to the file
    fprintf(filePointer, "%s", argv[1]);

    for (i = 2; i < argc - 1; i++){
        // Loop through the remaining command-line arguments, except the last one
        fprintf(filePointer, " %s", argv[i]);
    }
    /* Write the last command-line argument to the file, 
    preceded by a comma and followed by a newlin */
    fprintf(filePointer, ",%s\n", argv[i]);

    fclose(filePointer);//close the file
    return 0;
}