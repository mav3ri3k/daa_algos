# daa_algos
All algorithms done in uni course daa

## Structure
All algorithms are divided into modules based on `syllabus.pdf`
Each algorithm has its own folder with justfile

If you have `casey/just` and `sharkdp/bat` installed, building-running-logging can be done with just recipies

*Default Config*
```justfile
# build run output
default: build run output

# g++ main.cpp -o main
build:
	g++ main.cpp -o main

# ./main 1> out.log 2> err.log
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
```

If using `just`:
- All stdout piped to `out.log`
- All stderr piped to `err.log` 

