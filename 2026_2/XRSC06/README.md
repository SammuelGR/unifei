### AUDITORIA E SEGURANÇA DE SI

Aliases para salvar no `.bashrc` ou `.zshrc`:

```
comp() {
  gcc -o output.exe -Wall -Werror -pedantic -std=c18 "$@"
}
```

Exemplo de uso:

`comp file.c` gera o arquivo output.exe
