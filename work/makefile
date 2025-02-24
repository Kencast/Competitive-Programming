OBJ = $(basename $(wildcard *.cpp))

%.e: %.cpp
	g++ -lm -O2 -std=c++20 -pipe -fsanitize=address -DLOCAL $< -o $(basename $@)

%.cpp: 
	cp ../template.cpp $@
	
clean:
	rm -f $(OBJ)
