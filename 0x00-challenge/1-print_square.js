#!/usr/bin/node
/*
    Print a square with the character #

    The size of the square must be the first argument
    of the program.
*/

// Check if the size argument is missing
if (process.argv.length <= 2) {
    process.stderr.write("Missing argument\n");
    process.stderr.write("Usage: ./1-print_square.js <size>\n");
    process.stderr.write("Example: ./1-print_square.js 8\n");
    process.exit(1);
}

// Parse the size argument from the command line and convert it to an integer
const size = parseInt(process.argv[2]); // The radix should be removed to parse the size as a base-10 integer

for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
        // Print the character '#' for each position
        process.stdout.write("#");
    }
    // Move to the next line after printing a row
    process.stdout.write("\n");
}

