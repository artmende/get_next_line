# get_next_line
get_next_line is a project for 42 cursus that allows reading from a file, 1 line at a time.
Each call to get_next_line on the same file will read the next line until the end of file is reached.

See subject pdf for details. The bonus part (multiple fd) is supported.

The main.c file provided can be used for testing. 
After cloning the repo, open the 'main' directory and type in this command (on mac or linux) : \n
gcc main.c ../get_next_line.c ../get_next_line_utils.c -D BUFFER_SIZE=23 && ./a.out

The buffer size can be set to whatever you want, any positive integer should work.
