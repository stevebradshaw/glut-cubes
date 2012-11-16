CC = gcc
CFLAGS = -g -Wall -m32
ifeq ($(shell uname), Darwin)
  LIBS = -framework OpenGL -framework GLUT
else
  LIBS = -lGL -lGLU -lglut
endif

cubes: cubes.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

.o:.c
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	-rm -f *.o *~ cubes *core*

FORCE:
