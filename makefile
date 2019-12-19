all: isort txtfind

isort: sort.c sort.h
	gcc -Wall sort.c -o isort
# 	gcc -Wall -c sort.c -o isort
# 	gcc -Wall -o isort sort.c

txtfind: string.c string.h
	gcc -Wall string.c -o txtfind
# 	gcc -Wall -c string.c
# 	gcc -Wall -o txtfind string.c

.PHONY: clean all 

clean:
	rm -f *.o all isort txtfind *.out