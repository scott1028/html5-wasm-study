#include <stdio.h>

int add(int x, int y){
    return x + y;
}

// emcc1: emcc add.c -s WASM=1 -o add.html (create a http-server to open it.)
// emcc2: 
// GCC: gcc add.c -o add.out && ./add.out
int main(int argc, char ** argv) {
	printf("%d\n", add(2, 3));
    printf("Hello World!!!\n");
}
