OBJ = $(basename $(wildcard *.cpp))
	
%.e: %.cpp
	g++ $< -o $(basename $@)
	
clean:
	rm -f $(OBJ)