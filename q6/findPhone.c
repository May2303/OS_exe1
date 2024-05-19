#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

size_t my_strlen(const char *str);
void remove_newline(char *str);

#define PHONEBOOK_FILE "phonebook.txt" // Assuming phonebook.txt is in the same directory


int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) { // Check if the number of arguments is valid
       // Print usage info to stderr to realize what the mistake
        write(STDERR_FILENO, "Usage: ", 7);
        write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
        write(STDERR_FILENO, " <name> [<phonebook_file>]\n", 27);
        exit(1);
    }

    char *name = argv[1];
    char *phonebook_file;
    if (argc == 3) { // Determine phonebook file name
        phonebook_file = argv[2];
    } else {
        phonebook_file = PHONEBOOK_FILE;
 }
    // Create two pipes for inter-process communication
    int pipe1[2], pipe2[2]; // 2 for chaining commands
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }

    // First child process 
    int pid1 = fork(); 
    //-grep
    if (pid1 == -1) {
        perror("fork");
        exit(1);
    }
    // Inside the first child process
    if (pid1 == 0) {
        // Redirect grep output to pipe1
        dup2(pipe1[1], STDOUT_FILENO); 
        close(pipe1[0]);               // Close unused read end of pipe1
        close(pipe2[0]);               // Close unused read and write ends of pipe2
        close(pipe2[1]);

        // Search for the entire line containing the name in the phonebook file
        execlp("grep", "grep", "-i", name, phonebook_file, NULL);

        perror("execlp");
        exit(1);


    } else {
        // Second child process 
        //awk 
        int pid2 = fork();
        // Check if forking failed
        if (pid2 == -1) {
            perror("fork");
            exit(1);
        }
        
        // inside the second child process -awk
        if (pid2 == 0) {
            // Redirect awk input from pipe1 and output to pipe2
            dup2(pipe1[0], STDIN_FILENO);  
            dup2(pipe2[1], STDOUT_FILENO); 
            close(pipe1[1]);               // Close unused write end of pipe1
            close(pipe2[0]);               // Close unused read end of pipe2

            // Print only the phone number after splitting by comma
            execlp("awk", "awk", "-F,", "{print $2}", NULL);

            perror("execlp");
            exit(1);
             } 

        // Parent process 
        else {      
            close(pipe1[0]);      
            close(pipe1[1]);
            close(pipe2[1]);      

            int status; // Wait for both child processes to finish

            // Wait for grep -pid1 and akw- pid2
            waitpid(pid1, &status, 0); 
            waitpid(pid2, &status, 0); 

            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {  // Check if both child processes exited successfully
                write(STDOUT_FILENO, "Phone number: ", 14);

                char buffer[12]; // phone number max length is 9 digits+seperator
                ssize_t bytes_read_pipe2 = read(pipe2[0], buffer, sizeof(buffer) - 1);
               
                if (bytes_read_pipe2 == 0) { //if there is not 
                    write(STDERR_FILENO, "Name not found in phonebook\n", 28);
                } else {
                    buffer[bytes_read_pipe2] = '\0'; // convert the string to Null
                    remove_newline(buffer);    // Remove trailing newline
                    write(STDOUT_FILENO, buffer, my_strlen(buffer));
                    write(STDOUT_FILENO, "\n", 1);
                }
                // At least one of the child processes failed
            } else {
                write(STDERR_FILENO, "Name not found in phonebook\n", 28);
            }
        }
    }

    return 0;
}


// More functins: 

// Function to find the length of a string
size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to remove trailing newline character
void remove_newline(char *str) {
    size_t len = my_strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}