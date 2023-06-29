tokenizer: uimain.o chars.o history.o
	cc -o tokenizer uimain.o chars.o history.o

clean:
	rm -f *.o tokenizer

uimain.o: uimain.c tokenizer.h history.h
chars.o: chars.c tokenizer.h
history.o: history.c history.h tokenizer.h

run: tokenizer
	./tokenizer
