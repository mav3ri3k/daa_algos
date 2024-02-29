# build log
default: build run output

# g++ main.cpp -o main
build:
	g++ main.cpp -o main

# ./main 1>out.log 2> err.log
run:
	./main 1>out.log 2>err.log

# bat out.log
output:
	bat out.log

# bat log.txt
log:
	bat err.log

list:
	@just --list --list-heading $'Recipies for DAA\n' --unsorted
