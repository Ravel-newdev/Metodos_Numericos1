# Compilador e flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2

# Diretórios
SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin
TARGET   := trabalho1

# Lista de fontes (.cpp)
SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp") main.cpp

# Substitui o prefixo src/ por obj/src/ e adiciona .o
OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Regra principal
all: directories $(BIN_DIR)/$(TARGET).exe

# Linkagem
$(BIN_DIR)/$(TARGET).exe: $(OBJS)
	@echo [LD] Ligando objetos...
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo Compilação concluída com sucesso.

# Regra genérica para compilar cada .cpp → .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo [CC] Compilando $< ...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Garante que diretórios existam
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Limpeza
clean:
	@echo Removendo arq
