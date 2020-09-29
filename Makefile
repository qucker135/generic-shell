CC = g++
EXE = main

$(EXE): main.cpp
	$(CC) -lncurses main.cpp -o $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	rm $(EXE)
