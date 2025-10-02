### Sistemas Operacionais

Aliases para salvar no `.bashrc` ou `.zshrc`:

```
comp() {
  gcc -o output.exe -Wall -Werror -pedantic -std=c18 "$@"
}

comp_t() {
  gcc -o output.exe -Wall -Werror -pedantic -std=c18 -lpthread "$@"
}

comp_omp() {
  gcc -o output.exe -Wall -Werror -pedantic -std=c18 -fopenmp "$@"
}
```

> Usar a flag `-lpthread` caso esteja incluindo a biblioteca `pthread.h`.

Exemplo de uso:

`comp file.c` gera o arquivo output.exe

https://formulae.brew.sh/formula/libomp
