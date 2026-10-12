CC = gcc
CFLAGS = -Wall -Iinc $(shell mysql_config --cflags)
LDFLAGS = $(shell mysql_config --libs)

ifeq ($(DEBUG), 1)
    CFLAGS += -g -O0 -DDEBUG
else
    CFLAGS += -O2
endif

SRC_DIR  = src
DATA_DIR = data
LIB_DIR  = lib
OBJ_DIR  = obj
BIN_DIR  = bin

SRCS      = $(wildcard $(SRC_DIR)/*.c)
DATA_SRCS = $(wildcard $(DATA_DIR)/*.c)
LIB_SRCS  = $(wildcard $(LIB_DIR)/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c,  $(OBJ_DIR)/%.o, $(SRCS)) \
       $(patsubst $(DATA_DIR)/%.c, $(OBJ_DIR)/%.o, $(DATA_SRCS))

LIB_OBJS = $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))
LIB_A    = $(LIB_DIR)/libutils.a

PROJECT = $(notdir $(CURDIR))
OUT     = $(BIN_DIR)/$(PROJECT)

.PHONY: all clean

all: $(OUT)

$(OUT): $(OBJS) $(LIB_A)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -L $(LIB_DIR) -lutils $(LDFLAGS) -o $@
	@echo ">>> 编译成功: $@"

$(LIB_A): $(LIB_OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB_OBJS) $(OUT) $(LIB_A)
	@echo ">>> 清理完成"
