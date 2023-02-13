test: test.exe
	./$<

test.exe: exit.o main.o
	$(CC) -ldl -o $@ $^

main.o: main.c exit.h
exit.o: exit.c exit.h
