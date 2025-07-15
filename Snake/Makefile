
SRCS = $(shell find . -name "*.cpp")




main: $(SRCS)
	@echo Compiling cpp files to executable...
	@g++ $(SRCS) -o snake
	@echo
	@echo Done.
	@echo Enter ./snake to run program
	@echo 

clean:
	rm snake