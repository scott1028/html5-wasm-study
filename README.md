# WebAssembly(WAS)

#### Usage

```
$ emcc add.c -s WASM=1 -o add.html  # (create a http-server to open it. note: $ gcc add.c -o add.out && ./add.out)
$ emcc -o custom.html custom.c -O3 -s WASM=1
```
