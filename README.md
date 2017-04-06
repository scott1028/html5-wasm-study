# WebAssembly(WAS)

#### Usage

```
$ emcc add.c -s WASM=1 -o add.html  # (create a http-server to open it. note: $ gcc add.c -o add.out && ./add.out)
$ emcc -o custom.html custom.c -O3 -s WASM=1
$ emcc custom02.cpp -o custom02.html -s EXPORTED_FUNCTIONS="['_int_sqrt']"
$ emcc -o custom02.wasm custom02.cpp -O3 -s WASM=1 -s SIDE_MODULE=1
  (Recommend ... )
$ emcc -o custom03.wasm custom03.cpp -O3 -s WASM=1 -s SIDE_MODULE=1  # instance.exports.__Z6mytesti,  __Z6??????i
$ emcc -o custom04.wasm custom04.c -O3 -s WASM=1 -s SIDE_MODULE=1  # instance.exports._mytest, _?????
```

```
fetch('custom02.wasm').then(function(response) { return response.arrayBuffer() }).then(function(binary){ return WebAssembly.compile(binary) }).then(function(module){debugger;})
```

#### WASM Loader & Run A Sample

```
int square (int x) {
  return x * x;
}
```

```
emcc math.c -Os -s WASM=1 -s SIDE_MODULE=1 -o math.wasm
```

```
function loadWebAssembly(filename, imports = {}) {
  return fetch(filename)
    .then(response => response.arrayBuffer())
    .then(buffer => WebAssembly.compile(buffer))
    .then(module => {
      imports.env = imports.env || {}
      Object.assign(imports.env, {
        memoryBase: 0,
        tableBase: 0,
        memory: new WebAssembly.Memory({ initial: 256, maximum: 256 }),
        table: new WebAssembly.Table({ initial: 0, maximum: 0, element: 'anyfunc' })
      })
      return new WebAssembly.Instance(module, imports)
    })
}

function loadJS (url, imports = {}) {
  return fetch(url)
    .then(response => response.text())
    .then(code => new Function('imports', `return (${code})()`))
    .then(factory => ({ exports: factory(imports) }))
}
```

```
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Compile C to WebAssembly</title>
  <meta name="apple-mobile-web-app-capable" content="yes" />
  <meta name="apple-mobile-web-app-status-bar-style" content="black" />
  <meta name="apple-touch-fullscreen" content="yes" />
  <meta name="format-detection" content="telephone=no, email=no" />
  <script src="../loader.js"></script>
</head>

<body>
  <h1>Compile C to WebAssembly</h1>
  <p>The test result can be found in console.</p>

  <script>
    loadWebAssembly('math.wasm')
      .then(instance => {
        const square = instance.exports._square

        console.log('2^2 =', square(2))
        console.log('3^2 =', square(3))
        console.log('(2 + 5)^2 =', square(2 + 5))
      })
  </script>
</body>
</html>
```