OBJS = ui.o tokenizer.o tester.o
#compile flags
CFLAGS=-g -O3

#Target built
all: ui tester

ui: $(OBJS)
	cc -o ui $(CFLAGS) $(OBJS)

tester: $(OBJS)
	cc -o tester $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h
tester.o:tester.c history.h

#delete files created by compilation
clean:
	rm -f *.o ui tester
run:ui
	./ui
test: tester
	./tester
