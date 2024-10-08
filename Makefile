CXX = gcc
CXXFLAGS = -g -std=c99 -Wall -Werror -Wextra -pedantic
LEAK_TESTER = valgrind
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all
SRC_DIR = src
OBJ_DIR = objFiles
TARGET = restaurant_maneger

SRC_FILES = main.c list.c queue.c atendimento.c cardapio.c

OBJ_FILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

test: $(TARGET)
	./$(TARGET) $(TEST_ARGS)

leak: $(TARGET)
	$(LEAK_TESTER) $(LEAK_FLAGS) ./$(TARGET)