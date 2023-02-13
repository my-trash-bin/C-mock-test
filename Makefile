test: test.exe
	./$<

test.exe: main.o
	$(CC) -ldl -o $@ $^
