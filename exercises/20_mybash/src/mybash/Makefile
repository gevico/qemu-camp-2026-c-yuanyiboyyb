# src/mybash/Makefile

CC = gcc
CFLAGS = -Wall -I../../include

# 可执行文件名
TARGET := mybash
# 最终输出到 BINDIR（比如 ./bin/）
BINDIR ?= ./bin
# 中间文件目录（比如 ./obj/src/mybash/）
OBJDIR ?= ./obj
OBJROOT := $(abspath $(OBJDIR)/..)
LINKLIBS ?= -L$(OBJROOT)/mysed -L$(OBJROOT)/mywc -L$(OBJROOT)/mytrans -L$(OBJROOT)/myfile

# 源文件
SRCS := main.c
OBJS := $(SRCS:.c=.o)
OBJS := $(patsubst %.o,$(OBJDIR)/%.o,$(OBJS))

# 最终二进制路径
TARGET_PATH := $(BINDIR)/$(TARGET)

all: $(TARGET_PATH)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET_PATH): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LINKLIBS) -lmysed -lmywc -lmytrans -lmyfile

clean:
	@rm -rf $(OBJDIR)/*.o $(TARGET_PATH)
