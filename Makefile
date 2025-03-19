a.out: main.o node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -fsanitize=address -std=c++23 main.o

main.o: main.cc node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -fsanitize=address -std=c++23 -c main.cc

clean:
	rm -f a.out core *.o
