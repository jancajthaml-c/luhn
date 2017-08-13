OUTDIR=dist
CFLAGS= -O2

.PHONY: default clean

default: test clean

$(OUTDIR):
	@mkdir -p $(OUTDIR)

test: $(OUTDIR) $(OUTDIR)/luhn.o $(OUTDIR)/main.o
	gcc $(CFLAGS) $(OUTDIR)/luhn.o $(OUTDIR)/main.o -o test
	./test

$(OUTDIR)/luhn.o: luhn.c
	gcc $(CFLAGS) -o $(OUTDIR)/luhn.o -c $^

$(OUTDIR)/main.o: main.c
	gcc $(CFLAGS) -o $(OUTDIR)/main.o -c $^ 

clean:
	@rm -f test
	@rm -rf $(OUTDIR)
