# PKBrainfuck
PKBrainfuck is my own brainfuck interpreter created fully in cpp. Currently it's work in progress.

## Basic features
 1. Interpreting and executing code written in brainfuck

## Installation
To install this interpreter on your own computer, you have to:
 1. Clone this repository `$ git clone https://github.com/pkwasniok/PKBrainfuck/`
 2. Compile code on your machine `$ make` (gcc is needed)
 3. Run interpreter `$ ./pkbrainfuck hello_world.bf`

## Usage
To run your program you have to start interpreter with you file name as first parameter. Command should look liek this `$ pkbrainfuck {your-file-name}`. After this your code should be executed properly.

## Plans
 1. Add posibility of changing size of file buffor
 2. Add posibility of changing size of bf script buffor
 3. Add rest of the operetors (for now it only handles following operators: `>`, `<`, `+`, `-`, `.`)