# 1. Variables de configuración
CXX      = g++
CXXFLAGS = -Wall -Werror -std=c++17 -I./include
TARGET   = programa

# 2. Directorios
SRC_DIR = ./src

# 3. Archivos fuentes y objetos
# Ahora busca absolutamente todos los .cpp dentro de ./src (incluyendo main.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Convierte la lista de .cpp en archivos de objeto .o
OBJS = $(SRCS:.cpp=.o)

# 4. Regla principal (se ejecuta con 'make')
all: $(TARGET)

# Vinculación del ejecutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar los archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 5. Limpieza de archivos generados
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

.PHONY: all clean