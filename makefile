CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2

SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin
TARGET   := trabalho1

# encontra recursivamente todos os .cpp
SRCS := $(shell find $(SRC_DIR) -name "*.cpp") main.cpp

# gera caminho equivalente em obj/
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)

all: directories $(BIN_DIR)/$(TARGET)

# regra de linkagem
$(BIN_DIR)/$(TARGET): $(OBJS)
	@echo "[LD] Ligando objetos..."
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Compilação concluída com sucesso."

# regra genérica: compila qualquer .cpp dentro de src/
$(OBJ_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "[CC] Compilando $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# regra especial para main.cpp
$(OBJ_DIR)/main.cpp.o: main.cpp
	@mkdir -p $(dir $@)
	@echo "[CC] Compilando main.cpp ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
	@echo "Removendo arquivos objeto e executável..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpeza concluída."

rebuild: clean all