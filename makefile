# Compiler 
CXX = g++

# Flags for compiling and linking
CXXFLAGS = -Isrc -Iheader
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = main.cpp src/window.cpp src/vehicle.cpp src/goal.cpp src/shape.cpp src/init.cpp

# Executable name
TARGET = main

# Build rule
$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	-rm $(TARGET)