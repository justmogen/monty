>+++++++               Set cell 0 to 8 (char code for 'S')
[
    >++++               Add 4 to cell 1 ('c' = 99) 
    <<-                Decrement cell 0
    >+                 Add 1 to cell 1 ('h' = 104)
    <-                 Decrement cell 0 
    >+++               Add 3 to cell 1 ('o' = 111)
    <<-                Decrement cell 0
    >++                Add 2 to cell 1 ('o' = 111)
    <<-                Decrement cell 0
    >+++               Add 3 to cell 1 ('l' = 108)
]
>+.                  Print 'S' (cell 0) 
<<<<<-.              Print 'chool' (cell 1)
>>.                  Print newline (char 10)
