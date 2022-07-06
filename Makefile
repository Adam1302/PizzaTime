CXX = g++
CXXFLAGS = -std=c++14 -MMD
OBJECTS = controller.o main.o pizza.o pizzaViewer.o size.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = pizzaTime

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
