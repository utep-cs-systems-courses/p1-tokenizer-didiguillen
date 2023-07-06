Project 1: Tokenizer
====================
# How it works:
- This tokenizer takes in a string, separates words via spaces, and records
those words as tokens.
- You also have the option to view a history of strings you've tokenized and
re-tokenize them.

# How to run:
- In command-line, use the command "make" to compile all necessary files. Once
compiled, use the command "make run" to start the program. You may also use
"./tokenizer".

# What to know:
- The tokenizer takes a maximum of 100 chars. When given more than 100, it
takes the remaining chars and tokenizes them separately from the first 100
chars. In history, the same string of length 101+ will be stored in 2 or more
nodes and displayed/re-tokenized separately.
