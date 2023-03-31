exe:
	./main.x
compile: test_equation.o ODE_solver.o
	g++ test_equation.o ODE_solver.o -o ./main.x
test_equation.o: test_equation.cpp ODE_solver.h standard_functions.h
	g++ -c test_equation.cpp -o test_equation.o
ODE_solver.o: ODE_solver.cpp ODE_solver.h standard_functions.h
	g++ -c ODE_solver.cpp -o ODE_solver.o
clean:
	rm *.o *.x
delete:
	rm *.dat