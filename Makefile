%.cpp:
	cat template.cpp > $@

%.c: %.cpp
	g++ $< -o $(basename $@) ; ./$(basename $@)


clean:
	rm -f $(basename $(wildcard *.cpp))