exe:
	./main.x
compile_explicit: explicit.o grid.o solver.o
	g++ explicit.o grid.o solver.o -o main.x
explicit.o: Test_explicit_CN.cpp PDE_solver.h Spatial_grids.h standard_functions.h
	g++ -c Test_explicit_CN.cpp -o explicit.o
compile_implicit: implicit.o grid.o solver.o
	g++ implicit.o grid.o solver.o -o main.x
implicit.o: Test_implicit_CN.cpp PDE_solver.h Spatial_grids.h standard_functions.h
	g++ -c Test_implicit_CN.cpp -o implicit.o
grid.o: Spatial_grids.cpp Spatial_grids.h standard_functions.h
	g++ -c Spatial_grids.cpp -o grid.o
solver.o: PDE_solver.cpp PDE_solver.h Spatial_grids.h standard_functions.h
	g++ -c PDE_solver.cpp -o solver.o
clean:
	rm *.x *.o
delete_expl:
	rm results_expl/*.dat
delete_impl:
	rm results_impl/*.dat