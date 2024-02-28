, >,		                            Read the 2 numbers from stdin to cell 0 and cell 1

[                                       Start loop
    < +										Add 1 to c0
    > -										Substract 1 from c1
]                                       End loop

> ++++ ++++								Add 8 to c2

[                                       Start loop
    < ++++ ++								Add 6 to c1
    > -										Substract 1 from c2
]                                       End loop

<										Move to c1

[                                       Start loop
    < -										Substract 1 from c0
    > -										Substract 1 from c1
]                                       End loop

< .                                     Move to c0 and print the result of the addition
