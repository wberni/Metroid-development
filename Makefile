# Makefile para SFML Game

# Compilador
CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g

# Directorios
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)

# Librerías SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Encontrar todos los .cpp
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BIN_DIR)/game.exe

# Target por defecto
all: $(EXECUTABLE)

# Crear ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo "✓ Compilado: $@"

# Crear archivos objeto en build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "✓ Objeto: $@"

# Limpiar archivos compilados
clean:
	@rm -rf $(BUILD_DIR)
	@echo "✓ Limpiado"

# Ejecutar
run: $(EXECUTABLE)
	@$(EXECUTABLE)

# Recompilar todo
rebuild: clean all

.PHONY: all clean run rebuild
