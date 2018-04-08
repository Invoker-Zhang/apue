# apue Makefile.
# 2018.4.7
# Author: Invoker Zhang

MKDIR = mkdir -p
RM = rm -rf

CC = gcc
INCLUDES = -I $(header_dir)
CFLAGS = 
CPPFLAGS = 
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c
OUTPUT_OPTION = -o $@

source_dirs = examples exercises diys
lib_dir = lib
object_dir = bin
header_dir = inc

VPATH = $(source_dirs)

headers := $(wildcard $(header_dir)/*.h)
lib_sources := $(wildcard $(lib_dir)/*.c)
lib_objects := $(patsubst $(lib_dir)/%.c, $(object_dir)/%.o, $(lib_sources))
indivd_sources := $(shell find $(source_dirs) -name "*.c")
indivd_objects := $(addprefix $(object_dir)/, $(subst .c,.o, $(notdir $(indivd_sources))))
indivd_progs := $(addprefix $(object_dir)/, $(subst .c,, $(notdir $(indivd_sources))))
indivd_phonys := $(subst .c,, $(notdir $(indivd_sources)))

all: $(indivd_phonys)
	@echo $(headers)
	@echo $(lib_sources)
	@echo $(lib_objects)
	@echo $(indivd_sources)
	@echo $(indivd_objects)
	@echo -------------
	@echo $(indivd_phonys)
	@echo $(indivd_progs)

$(lib_objects): $(object_dir)/%.o : $(lib_dir)/%.c
	@$(MKDIR) $(object_dir)
	$(COMPILE.c) $< $(OUTPUT_OPTION)

$(indivd_objects): $(object_dir)/%.o : %.c
	@$(MKDIR) $(object_dir)
	$(COMPILE.c) $< $(OUTPUT_OPTION)

$(indivd_phonys) : % : $(object_dir)/%
	@echo $<

$(indivd_progs) : $(object_dir)/% : $(object_dir)/%.o  $(lib_objects)
	$(CC) $^ -o $@ 
