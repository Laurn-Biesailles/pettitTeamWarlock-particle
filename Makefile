a.out: main.o node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -fsanitize=address main.o

main.o: main.cc node.h particle.h particleSys.h ParticleGraphics.h
	g++ -g -fsanitize=address -c main.cc

clean:
	rm -f a.out core *.o
