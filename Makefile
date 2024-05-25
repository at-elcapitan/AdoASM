# Compiler
COM 		:= gcc
CFLAGS 		:= -O3 -pipe

# Files
SRC_DIR  	:= src/
OUT_DIR		:= out/
BLD_DIR 	:= build/
OUTPUT 		:= dasm

SOURCES   := $(wildcard ${SRC_DIR}*.c)
OBJECTS	  := $(patsubst $(SRC_DIR)%.c, $(BLD_DIR)%.o, $(SOURCES))

.PHONY : all
all : dirs main
	@echo "Done!"

.PHONT : dirs
dirs :
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(BLD_DIR)

.PHONY : main
main : $(OBJECTS)
	$(COM) $(CFLAGS) -o $(OUT_DIR)$(OUTPUT) $(OBJECTS) $(LFLAGS)

$(BLD_DIR)%.o: $(SRC_DIR)%.c
	$(COM) $(CFLAGS) -c $<  -o $@

.PHONY : run
run : all
	@echo "-------"
	@./out/dasm