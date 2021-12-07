# A dumb attempt to brute force Advent of Code 2021 day 6 using a 4-bit integer.

If you use the sample input, part 2 should fit within 16 GB of RAM if 4-bit integers are used.

According to the example, the input '3,4,3,1,2' should result in a total of 26984457539 lanternfish after 256 days. When simulating each fish, they have 9 possible states. This fits within 4 bits, so the fish can be represented as a 4-bit integer.

26984457539 * 0.5 = 13492228769.5 bytes. Lets round that to 13492228770 bytes. This is equal to 13.5 GB. This fits in the memory of a decent computer with 16 GB of RAM.