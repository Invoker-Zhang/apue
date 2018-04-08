MKDIR = mkdir -p
CC = gcc
INCLUDES = -I $(hdrdir)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c

srcdir = src
objdir = bin
libdir = lib
hdrdir = inc
depdir = $(srcdir)/.d

sources = $(shell find $(srcdir) -name "*.c")
libs = $(shell find $(libdir) -name "*.c")
headers = $(shell find $(hdrdir) -name "*.h")
objects = $(subst .c,,\
		  	$(subst $(srcdir),$(objdir), $(sources)))
dependents = $(subst .c,.d,\
			 	$(subst $(srcdir),$(depdir), $(sources)))

all: $(objects)
	@echo $(sources)

$(objects): $(objdir)/% : $(srcdir)/%.c $(libs)
	@$(MKDIR) $(objdir)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $^ -o $@

-include $(dependents)

$(dependents) : $(depdir)/%.d : $(srcdir)/%.c
	@$(MKDIR) $(depdir); \
	$(CC) -M $(CPPFLAGS) $(INCLUDES) $< > $@.$$$$; \
	sed 's,\(.*\)\.o[ :]*,$(objdir)/\1.o $@ :,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

clean:
	rm -rf $(objdir)
	rm -rf $(depdir)

