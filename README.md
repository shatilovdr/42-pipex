# Pipex

## Table of Contents
- [Mandatory](#mandatory)
- [Examples](#examples)
- [Requirements](#requirements)
- [Bonus](#bonus)
- [Usage](#usage)
- [Results](#results)

## Mandatory

This project is about handling pipes.

The program will be executed as follows:
./pipex file1 cmd1 cmd2 file2

It must take 4 arguments:

• file1 and file2 are file names.

• cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:

```
$> < file1 cmd1 | cmd2 > file2
```

## Examples

```
$> ./pipex infile "ls -l" "wc -l" outfile
```
Should behave like: < infile ls -l | wc -l > outfile

```
$> ./pipex infile "grep a1" "wc -w" outfile
```
Should behave like: < infile grep a1 | wc -w > outfile

## Requirements

Your project must comply with the following rules:

• You have to turn in a Makefile which will compile your source files. It must not relink.

• You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).

• Your program mustn’t have memory leaks.

• If you have any doubt, handle the errors like the shell command:

```< file1 cmd1 | cmd2 > file2```

## Bonus

You will get extra points if you:

• Handle multiple pipes.

This:
```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Should behave like:
```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

• Support « and » when the first parameter is "here_doc".

This:
```
$> ./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like:
```
cmd << LIMITER | cmd1 >> file
```

## Usage

1) To compile mandatory part executable run
```
make
```
Than run executable according to the description above.

2) To compile bonus part executable run
```
make bonus
```
Than run executable according to the description above.

## How to use 

1) Clone:	
	```sh
		git clone git@github.com:shatilovdr/42-pipex.git
	```
2) cd into the directory.
	```sh
		cd 42-pipex
	```
3) Compile project
	```sh
		make
	```
	or 
	```sh
		make bonus
	```
	to support bonus part

