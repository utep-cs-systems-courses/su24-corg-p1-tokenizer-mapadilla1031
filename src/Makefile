OBJS = ui.o tokenizer.o history.o 
#compile flags
CFLAGS=-g -O3

#Target built
all: ui 

ui: $(OBJS)
	cc -o ui $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h history.h 

#delete files created by compilation
clean:
	rm -f *.o ui *~ *#
run:ui
	./ui

