# Projeto 5 - MC504

Repositório que contém arquivos alterados do kernel do linux para realização do projeto 5 da disciplina MC504

## Utilização

Este repositório apenas contém os arquivos alterados do kernel do linux, para que fosse possível adicionar um peso a cada usuário. A versão com a qual foi utilizada este repositório foi 4.11.3 e o modo que o ambiente foi preparado se encontra em:

```
https://www.ic.unicamp.br/~islene/1s2017-mc504/proj2/qemu.html
```

Após utilizar o mesmo ambiente descrito acima é necessário copiar todos os arquivos em seus respectivos diretórios com exceção do `ex-mycall.c`.

Com os arquivos alterados é necessário compilar o kernel:

```
make -j$(nproc)
```

Em seguida executar o kernel através do QEMU de modo que o arquivo `ex-mycall.c` esteja disponível dentro do sistema:

```
qemu-system-i386 -hda ArchLinux_mc504.cow -kernel linux-4.11.3/arch/i386/boot/bzImage -append "rw root=/dev/hda" -drive format=raw,file=ex-mycall.c
```

Por fim é necessário compilar o arquivo:

``` bash
cat /dev/hdb                    &&
gcc ex-mycall.c -o ex-mycall    &&
./ex-mycall                     &&
```
