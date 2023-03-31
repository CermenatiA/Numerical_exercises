exe:
	./main.x
compile: test_function.o integrators.o
	g++ test_function.o integrators.o -o main.x
test_function.o: test_function.cpp integrators.h standard_functions.h
	g++ -c test_function.cpp -o test_function.o
integrators.o: integrators.cpp integrators.h standard_functions.h
	g++ -c integrators.cpp -o integrators.o
clean:
	rm *.x *.o
delete:
	rm *.dat
