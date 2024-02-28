,>,                     Read first digit and store in cell 1  
,                       Read second digit

[                       Loop to add:
    >+                    Add digit in cell 2 to cell 1
    <-                    Decrement cell 2
    >-                    Decrement cell 1
    <<-                   Decrement cell 2
]

<<.                      Print cell 1 which contains sum
