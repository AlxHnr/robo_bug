P_NAME  = robo_bug
OBJECTS = main.o tile.o	calc.o	data.o	graphic.o forest.o bee.o

# flags
CFLAGS	= -Wall -O2 `sdl-config --cflags` -I.
LDFLAGS	= `sdl-config --libs` -lSDL_image -lSDL_ttf

# main application
$(P_NAME)/$(P_NAME): $(OBJECTS:%.o=obj/%.o)
	mkdir -p $(P_NAME)
	$(CC) $(OBJECTS:%.o=obj/%.o) $(LDFLAGS) -o $(P_NAME)/$(P_NAME)

# compile objects
obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $<
	mv *.o obj

# run application
run: $(P_NAME)/$(P_NAME)
	cd $(P_NAME) && ./$(P_NAME)

# additional stuff

clean:
	- rm -rf $(P_NAME)/$(P_NAME) obj
