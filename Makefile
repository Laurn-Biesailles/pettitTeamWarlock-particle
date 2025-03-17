a.out: main.o node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -Wall -fsanitize=address std=c++17 main.o

main.o: main.cc node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -Wall -fsanitize=address std=c++17 main.cc

clean:
	rm -f a.out core *.o
