CXX = g++
FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline  \
		-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum      \
		-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual    \
		-Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2          \
		-Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor\
		-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192                \
		-Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla  \
		-D_DEBUG -D_EJUDGE_CLIENT_SIDE
all: main

main: quadratic.o quadratic_helpers.o quadratic_logic.o quadratic_unitest.o quadratic_flags.o
	$(CXX) $(FLAGS) quadratic.o quadratic_helpers.o quadratic_logic.o \
					quadratic_unitest.o quadratic_flags.o			  \
					-o main

quadratic.o: quadratic.cpp
	$(CXX) -c quadratic.cpp $(FLAGS)

quadratic_helpers.o: quadratic_helpers.cpp
	$(CXX) -c quadratic_helpers.cpp $(FLAGS)

quadratic_logic.o: quadratic_logic.cpp
	$(CXX) -c quadratic_logic.cpp $(FLAGS)

quadratic_unitest.o: quadratic_unitest.cpp
	$(CXX) -c quadratic_unitest.cpp $(FLAGS)

quadratic_flags.o: quadratic_flags.cpp
	$(CXX) -c quadratic_flags.cpp $(FLAGS)

clean:
	del -rf *.o main
