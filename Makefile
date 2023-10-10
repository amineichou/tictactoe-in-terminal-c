FLAGS = -Wall -Wextra -Werror

all: play

play:
	@gcc $(FLAGS) game.c -o game
	@./game

test:
	@gcc $(FLAGS) test.c -o test
	@./test
	@rm test

clean:
	@rm game
	@rm test