srcdir = src
objdir = bin
hdrdir = inc
libdir = lib

basenames = $(basename $(shell cd $(srcdir); ls))
sources = $(addsuffix .c, $(addprefix $(srcdir)/, $(basenames)))
headers = $(shell find . -name '*.h')
libs = $(addprefix $(libdir)/, $(shell cd $(libdir); ls) )
objects = $(addsuffix .out, $(addprefix $(objdir)/, $(basenames)))

all: $(objdects)
	@ echo $(objects)

test:
	@ echo $(sources)
	@ echo $(headers)
	@ echo $(libs)
	@ echo $(objects)


$(objects) : $(objdir)/%.out : $(srcdir)/%.c $(libs) $(headers)
	gcc -o $@ $< $(libs) -I $(hdrdir)

clean:
	rm $(objdir)/*

.PHONY: all test clean
