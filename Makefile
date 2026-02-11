# The default rule: compiles main.c into the 'main' executable
final:
	gcc main.c -o main

# Deletes the compiled executable
clean:
	rm -f main