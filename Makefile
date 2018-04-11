# apue Makefile.
# 2018.4.7
# Author: Invoker 

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

objects = $(foreach parm, $(source_dirs) $(lib_dir),\
		  		$(patsubst $(parm)/%.c, $(object_dir)/%.o, $(wildcard $(parm)/*.c)))
lib_objects = $(patsubst $(lib_dir)/%.c, $(object_dir)/%.o, $(wildcard $(lib_dir)/*.c))

programs = $(foreach parm, $(source_dirs),\
		   		$(patsubst $(parm)/%.c, $(object_dir)/%, $(wildcard $(parm)/*.c)))

all:  $(programs)
	@echo $(objects)
	@echo $(lib_objects)
	@echo $(programs)

$(objects) : | $(object_dir)

$(object_dir):
	$(MKDIR) $@

# $(call build-rules, srcdir, objdir)
define compile-rules =
$(subst .c,.o, $(subst $1,$2, $(wildcard $1/*.c))): $2/%.o : $1/%.c
	$$(COMPILE.c) $$< $$(OUTPUT_OPTION)
endef


$(foreach parm, $(source_dirs), $(eval $(call compile-rules, $(parm), $(object_dir))))

$(eval $(call compile-rules, $(lib_dir),$(object_dir)))

define link-rules =
$(subst $1, $2, $(subst .c,, $(wildcard $1/*.c))): $2/% : $2/%.o $(lib_objects)
	$$(CC) $$^ -o $$@
endef

$(foreach parm, $(source_dirs), $(eval $(call link-rules, $(parm), $(object_dir))))

.PHONY: clean

clean:
	$(RM) $(object_dir)
