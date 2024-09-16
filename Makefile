all: ./bin/decoder.exe

./bin/decoder.exe: ./obj/quadtree.o ./obj/image.o ./obj/bits.o ./obj/main.o 
	gcc ./obj/*.o -o ./bin/decoder.exe
./obj/image.o: ./src/image.c
	gcc -o ./obj/image.o -c ./src/image.c
./obj/quadtree.o: ./src/quadtree.c
	gcc -o ./obj/quadtree.o -c ./src/quadtree.c
./obj/bits.o: ./src/bits.c
	gcc -o ./obj/bits.o -c ./src/bits.c
./obj/main.o: ./src/main.c
	gcc -o ./obj/main.o -c ./src/main.c

clean:
	rm ./obj/*.o ./bin/decoder.exe