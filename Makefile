
all: condvar create_directory mutex1 mutex_tutoring open_test semiphore sprintf_example ulimit_test

condvar: condvar.o
	gcc -o condvar condvar.o -l pthread

condvar.o: condvar.c
	gcc -c condvar.c

create_directory: create_directory.o
	gcc -o create_directory create_directory.o

create_directory.o: create_directory.c
	gcc -c create_directory.c

mutex1: mutex1.o
	gcc -o mutex1 mutex1.o -l pthread

mutex1.o: mutex1.c
	gcc -c mutex1.c

mutex_tutoring: mutex_tutoring.o
	gcc -o mutex_tutoring mutex_tutoring.o -l pthread

mutex_tutoring.o: mutex_tutoring.c
	gcc -c mutex_tutoring.c

open_test: open_test.o
	gcc -o open_test open_test.o

open_test.o: open_test.c
	gcc -c open_test.c
#producerConsumer: producerConsumer.o
#	gcc -o producerConsumer producerConsumer.o -l pthread

#producerConsumer.o: producerConsumer.c
#	gcc -c producerConsumer.c

semiphore: semiphore.o
	gcc -o semiphore semiphore.o -l pthread

semiphore.o: semiphore.c
	gcc -c semiphore.c

sprintf_example: sprintf_example.o
	gcc -o sprintf_example sprintf_example.o

ulimit_test.o: ulimit_test.c
	gcc -c ulimit_test.c

clean: 
	rm -f *.o condvar create_directory mutex1 mutex_tutoring ulimit_test semiphore open_test sprintf_example

