CC = g++
CFLAGS  := -std=c++11 -Wall -Wfatal-errors -c -ggdb
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BIN = powersamurai
OBJ = powersamurai.o main.o animation.o entity.o bot.o player.o	

all: .depend $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.depend: *.hpp *.cpp
	@echo -n > .depend
	@$(foreach obj,$(OBJ), g++ $(CFLGAS) -MM $(subst .o,.cpp,$(obj)) >> .depend;)

-include .depend

clean::
	rm -f *~ $(OBJ) $(BIN) .depend
