# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is a lung disease also known as silicosis. It is the longest word
in the English language in the dictionary provided.

## According to its man page, what does `getrusage` do?

Literally - get resource usage,
returning resource usage measures for who, which can be RUSAGE_SELF,
RUSAGE_CHILDREN, or RUSAGE_THREAD

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members in a variable of type struct rusage.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Because passing large structs by value is slow and memory intensive.
If returning or passing structs by value, stack overflow may occur.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

In summary:
If a character is in alphabetic character or an apostrophe that is not at the start
the character is appended to the word array. If the character is numerical
it is ignored. If the loop sees any punctuation or a space then \0 is appended to complete the word array.
c = fgetc(fp) is the primary function call that is used to iterate through the file
until the end of the file is reached, each character is processed in the summarization above.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

To avoid overwrite of important data in memory or cause segmentation fault.
Since some of the words in txt end in punctuation the process of
'reading' through text becomes compounded in difficulty when using
fscanf alone.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

To prevent changing the data pointed to. To avoid changes to a read word & dictionary.
