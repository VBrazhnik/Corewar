# Corewar

Corewar is a School 42 project. The purpose of this project is an implementation of the programming game **“Core War”**.

![Corewar](/wiki_resources/corewar.svg)

[corewar.en.pdf](/corewar.en.pdf) is the task file.

Task resources is placed at [the `task_resources` folder](/task_resources/).

## Wiki

This project has an 8-page guide. The guide was written **in Russian**.

You can read it [at the wiki-pages](../../wiki/).

## Project Structure

This project consists of five parts:

* Champion
* Assembler
* Disassembler (Bonus)
* Virtual Machine
* Visualizer (Bonus)

Project has three developed champions: `amedvedi.s`, `wasp.s`, `kalle.s`. They are located at [the `champions` directory](/champions/).

Assembler + Disassembler are modules of the program `asm`.

Virtual Machine + Visualizer are modules of the program `corewar`.

## How to clone?

This repository includes submodule. So if you want to clone it, you can use the following command:

```
git clone --recurse-submodules <repository url>
```

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

### `asm`

```
Usage: ./asm (champion.s|champion.cor)
    champion.s   — from assemble to bytecode
    champion.cor — from bytecode to assemble
```

### `corewar`

```
Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l <num>] [-v] [-n <num>] <champion.cor> <...>
    -a          : Print output from "aff" (Default is off)
    -dump <num> : Dump memory (32 octets per line) after <num> cycles and exit
    -d    <num> : Dump memory (64 octets per line) after <num> cycles and exit
    -show <num> : Run <num> cycles, dump memory (32 octets per line), pause and repeat
    -s    <num> : Run <num> cycles, dump memory (64 octets per line), pause and repeat
    -l    <num> : Log levels
                   1  : Show lives
                   2  : Show cycles
                   4  : Show operations
                   8  : Show deaths
                   16 : Show PC movements
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
```

## Visualizer

The best visualizer performance is with **iTerm2**.

![Visualizer](/wiki_resources/visualizer.png)
