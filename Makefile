OUTDIR=.

CFLAGS= -O2
MODULES= $(OUTDIR)/luhn.o

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/luhn.o: luhn.c
	gcc $(CFLAGS) -o $(OUTDIR)/luhn.o $^

$(OUTDIR)/benchmark.o: benchmark.c
	gcc $(CFLAGS) -o $(OUTDIR)/benchmark.o $^

.PHONY: test
test:
	chmod +x luhn.o
	./luhn.o
