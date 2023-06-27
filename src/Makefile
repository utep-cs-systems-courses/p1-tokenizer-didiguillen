tokenizer: uimain.o chars.o
	cc -o tokenizer uimain.o chars.o

clean:
	rm -f *.o tokenizer

uimain.o: uimain.c tokenizer.h
chars.o: chars.c tokenizer.h

run: tokenizer
	./tokenizer
