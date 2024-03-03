All the code in this repository has been written for a C++17 compiler.

# Format for preference tables and matching.

In order to use the fundamental algorithm, preference tables are needed for the men and the women. The program requires that these preference tables are stored in seperate text files. Furthermore, the program requires that all names are integers. If the names of the men and women in your example are strings, these must be converted to integers using any one-to-one mapping. Given integer names, a preference table must be represented in the text file as follows. Each line of the text file contains the name of a man/woman along with their preference list. The first name in each line is the name of a man/woman whose preferences are being represented. The preferences of the man/woman are then listed immediately after in order, seperated by spaces.

For example, suppose we have men named "1", "2" and "3"; and women named "4", "5" and "6". One example of a preference table for the men is:

| Man | 1st preference | 2nd preference | 3rd preference |
| ----| ---| --- | ---|
| 1 | 4 | 5|6|
| 2 | 5 |6|4|
| 3 | 6 |5|4|

This preference table would be represented in the text file as follows:

1 4 5 6 

2 5 6 4

3 6 5 4

An example of preference tables for the men and women respectively have been provided in the files 'men_prefs.txt' and 'women_prefs.txt'.

