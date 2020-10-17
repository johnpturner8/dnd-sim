#Team 8: DND-Sim Makefile
#Let's see if this works lol

compile:
	g++ Player.cpp Enemy.cpp Turn.cpp Encounter.cpp driver.cpp -o Driver.out
run:
	./Driver.out
clean:
	rm*.out
