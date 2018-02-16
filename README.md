User Manual

The following is a list of commands and capabilities compatible with the given shell:

When running an external program such as a batch file with the appropriate commands, enter in the format "myshell programname". The shell will read through the content of the given file until end-of-file is reached, and display the results.  

This shell supports input/output redirection in the form programname arg1 arg2 < inputfile > outputfile. This will run the programname with the 2 arguments. The input file in this command is replaced by inputfile, and the output file. 

Commands:

cd - Taking a single input argument, changes the current default directory to the given argument. To move back a directory, use the argument ".." as in "cd ..".
If no argument is given, gives the current directory. 

clr - Clears the screen.  

dir - Prints the currently working directory. 

environ - List all the environment strings.

echo - To be followed by input which the user wants to display. Displays the input on the terminal followed by a new line (multiple spaces/tabs may be reduced to a single space).

help - Display the user manual, with description of shell commands. 

pause - Pause operation of the shell until 'Enter' is pressed.

quit - Quit the shell.
