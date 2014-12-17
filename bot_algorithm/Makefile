CC = g++
CFLAGS  := -std=c++11 -Wall -Wfatal-errors -c -ggdb
BIN = Bot_Show
OBJ = bot_algorithm.o node_bot.o 

all: .depend $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ $(LDFLAGS)  -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.depend: *.hpp *.cpp
	@echo -n > .depend
	@$(foreach obj,$(OBJ), g++ $(CFLGAS) -MM $(subst .o,.cpp,$(obj)) >> .depend;)

-include .depend

clean::
	rm -f *~ $(OBJ) $(BIN) .depend
