# WebAssembly(WAS)

#### Usage

```
$ emcc add.c -s WASM=1 -o add.html  # (create a http-server to open it. note: $ gcc add.c -o add.out && ./add.out)
$ emcc -o custom.html custom.c -O3 -s WASM=1
$ emcc custom02.cpp -o custom02.html -s EXPORTED_FUNCTIONS="['_int_sqrt']"
$ emcc -o custom02.wasm custom02.cpp -O3 -s WASM=1 -s SIDE_MODULE=1
```
