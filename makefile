OBJ = $(basename $(wildcard *.cpp))
	

%.e: %.cpp
	g++ $< -o $(basename $@)

%.cpp: 
	cp template.cpp $@

clean:
	rm -f $(OBJ)
