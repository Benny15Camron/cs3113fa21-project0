all: project0

project0: project0.c
        cc project0.c -o project0 -Wall -pedantic 

clean:
        rm -f project0
