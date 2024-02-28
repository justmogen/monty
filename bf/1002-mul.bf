Read in the 2 numbers and store in cell 1 and cell 2
>, >, <<

Convert from ASCII to actual numbers
+++++ +
[
    Decrement cell 1 to convert from ASCII to the actual number
    >----- ---
    Decrement cell 2 to convert from ASCII to the actual number
    >----- ---
    <<-
]

Multiply the numbers
>[
    Move to cell 1
    >[>+>+<<-]
    Move to cell 2
    >[<+>-]
    Move back to cell 1
    <<-
]

Separate the numbers for printing
>[-]>+> >+++++ +++++<
[
    Decrement cell 1 and move the pointer to the right
    - >- [>>>]+++++ +++++<<+
    Move the pointer back to the left
    [<<<]>>>>
]
Move the pointer to the left
<-
Increment the pointer to cell 3
<+++++ +++++>>>[-<<<->>>]<<<

Convert the result back to ASCII
<+++++ +
[
    Increment the pointer to cell 3 and store the value in cell 4
    >+++++ +++>
    Loop while cell 3 is not zero
    [+++++ +++>]
    Move the pointer to cell 4 and decrement it
    <[<]>-
]

Print the product
>>[.<<]<[<<]>>.
