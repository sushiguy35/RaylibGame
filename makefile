compile:
	g++ src/main.cpp -lraylib -lm -o main.exe
	make run
	
run:
	./main.exe

clean:
	rm -rf main.exe
