OBJ = $(basename $(wildcard *.cpp))

base: 
	python3 base.py
	
%.e: %.cpp
	g++ $< -o $(basename $@)
	
clean:
	rm -f $(OBJ)
