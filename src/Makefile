OBJS = ui.o tokenizer.o 
#compile flags
CFLAGS=-g -o3

#Target built
all: ui

ui: $(OBJS)
	cc -o ui $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h


#delete files created by compilation
clean:
	rm -f *.o ui
run:ui
	./ui
