SOURCES := src/*.cpp
HEADERS := src/*.h

CXXFLAGS := -std=c++20 -I/opt/homebrew/Cellar/sfml/2.6.1/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EXE := Game 

.PHONY: Game clean

game:
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(EXE)

clean:
	rm -f $(EXE)
