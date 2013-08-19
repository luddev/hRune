SHELL := /bin/bash
CC := gcc
CXX := g++

CFLAGS := -Wall -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2`
CXXFLAGS := -Wall -std=c++11 -pedantic -ggdb `pkg-config --cflags sdl2`
LFLAGS := `pkg-config --libs sdl2` -lSDL2_image

OBJ := obj/linux/
BIN := bin/linux/

TARGET := $(BIN)hRune

SRCDIRS := src src/* src/*/* src/*/*/*
SOURCES := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c)) $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.cpp))
OBJECTS = $(patsubst %.c, $(OBJ)%.o, $(patsubst %.cpp, $(OBJ)%.o, $(SOURCES)))

BEG = 	echo -e -n "  \033[32m$(1)$(2)...\033[0m" ; echo -n > /tmp/.`whoami`-build-errors
END = 	if [[ -s /tmp/.`whoami`-build-errors ]] ; then \
		echo -e -n "\r\033[1;33m$(1)$(2)\033[0m\n"; \
		cat /tmp/.`whoami`-build-errors; \
	else \
		echo -e -n "\r  \033[1;32m$(1)$(2)\033[0m\033[K\n"; \
	fi

INFO = echo -e -n "\r  \033[1;34m$(1)$(2)\033[0m\n"

ERRORFUNC = echo -e " \033[1;31m! Fatal error encountered.\033[0m"; \
	cat /tmp/.`whoami`-build-errors; \
	exit 1;

ERRORS = 2>>/tmp/.`whoami`-build-errors || { $(call ERRORFUNC) }

ERRORSS = >>/tmp/.`whoami`-build-errors || { $(call ERRORFUNC) }

BEGRM = echo -e -n "  \033[31m$(1)$(2)...\033[0m" && echo -n > /tmp/.`whoami`-build-errors
ENDRM = echo -e -n "\r  \033[1;31m$(1)$(2)\033[0m\033[K\n"

.PHONY: all clean init

all: init $(TARGET)
	@$(call INFO, "--", "Building hRune...Done!");
	cp -r res/* $(BIN)

init:
	@$(call INFO, "--", "Building hRune...");

$(OBJ)%.o: %.c
	@$(call BEG, "CC", "$<")
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS) $(ERRORS)
	@$(call END, "CC", "$<")

$(OBJ)%.o: %.cpp
	@$(call BEG, "CXX", "$<")
	@mkdir -p $(dir $@)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(ERRORS)
	@$(call END, "CXX", "$<")

$(TARGET): $(OBJECTS)
	@$(call BEG, "LD", "$<")
	@mkdir -p $(dir $@)
	@$(CXX) $(OBJECTS) -o $(TARGET) $(LFLAGS) $(ERRORS)
	@$(call END, "LD", "$<")

clean:
	@$(call BEGRM, "RM", "$(BIN) $(OBJ)")
	@$(RM) -rf $(BIN) $(OBJ)
	@$(call ENDRM, "RM", "$(BIN) $(OBJ)")
