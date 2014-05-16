/**
 * Jail was the best option in the example so with smaller dices (bigger chance of rolling triple doubles)
 * Sequence: 10
 * 
 * There is a loop rolling between square 10 and 30 which have a chance of looping back over 10 to 30. (Jail > GO)
 * Hence the answer will likely be: 10 + ( 10 < n < 30 ) + ( 10 < n < 30 )
 * 
 * Look at chance options:
 *  Go to C1 - Possible
 *  Go to E3 - Possible
 *  Go to H2 - Not possible out of 10 < n < 30
 *  Go to R1 - Increases Goto next R chance to R2
 * 
 * Permutations from JAIL:
 * 
 * Square 11:  -
 * Square 12: (1,1)
 * Square 13: (1,2), (2,1)
 * Square 14: (2,2)
 * Square 15: (2,3), (3,2), (4,1), (1,4)
 * Square 16: (3,3), (4,2), (2,4)
 * Square 17: (4,3), (3,4)
 * Square 18: (4,4)
 * 
 * 15 has the most possibilities with Chance adding next Railway company card x2 from R1
 * Sequence is: 1015XX or 10XX15
 * 
 * C1 has 1 permutation from JAIL (reduced by Railway jump)
 * E3 needs a 6 from 18, 7 from 17 and 8 from 16 (will not get the 15 boost)
 * FP is possible because of the 5 permutation from 15 but no chance jump
 * 
 * Sequence is: 1015E3 or 1015FP
 * Sequence is: 101524 or 101520
 * 
 */