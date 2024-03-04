This repository contains code which can find a stable matching in the stable marriage problem, and code which can check if any proposed matching is stable. All the code in this repository has been written for a C++17 compiler. It is recommended that the entire repository is downloaded before compiling and running any of the code.

If using Linux, open the command line and change the directory to that in which the code has been downloaded. If using Windows, see 'windows.md'.

# Format for preference tables and matching
## Preference tables

In order to use the fundamental algorithm, preference tables are needed for the men and the women. The relevant program requires that these preference tables are stored in seperate text files. Furthermore, the program requires that all names are integers. If the names of the men and women in your example are strings, these must be converted to integers using any one-to-one mapping. Given integer names, a preference table must be represented in the text file as follows. Each line of the text file contains the name of a man/woman along with their preference list. The first name in each line is the name of a man/woman whose preferences are being represented. The preferences of the man/woman are then listed immediately after in order, separated by spaces.

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

## Matching

In order to check if a matching is stable given a pair of preference tables, a matching is of course required. The relevant program requires that this is given in a text file in a similar manner to the preference tables. Each line in the text file represents a matching. Each line contains two names, separated by a space. The first name in each line is the name of a man, and the second name is the name of his partner. Using the same example as above, suppose we propose the following matching:

|Man|Woman|
|---|---|
|1|4|
|2|5|
|3|6|

This matching would be represented in the text file as follows:

1 4

2 5

3 6

An example of a matching has been provided in the file 'match.txt'.

# Fundamental Algorithm
## Output
The code provides the matching given by the fundamental algorithm and says whether or not the matching is stable.
## Compilation 

The C++ to produce this output uses functions contained in three different files. The first file is 'fund_alg_funs.cpp'; this contains the code which performs the fundamental algorithm. To compile this code, enter the following command into the Linux command line:

g++ --std=c++17 -c fund_alg.cpp

The second file is 'is_stable_funs.cpp'; this contains the code which checks if a matching is stable. To compile this code, enter the following command into the Linux command line:

g++ --std=c++17 -c is_stable_funs.cpp

The third file is 'file_to_pref.cpp'; this contains the code which turns the contents of a text document into a preference table. To compile this code, enter the following command into the Linux command line:

g++ --std=c++17 -c file_to_pref.cpp

The C++ code which produces the output is contained in the 'fund_alg.cpp' file. In order to compile the code into an executable program, enter the following command into the Linux command line:

g++ --std=c++17 fund_alg.cpp fund_alg_funs.o is_stable_funs.o file_to_pref.o -o fund_alg.o

This will create the executable file 'fund_alg.o'.

## Running the code
In order to run the code, first create two files containing the preference tables in the required format. Assuming these are files are named 'men_prefs.txt' and 'women_prefs.txt' (these can be renamed), the fundamental algorithm can be run by entering the following command into the Linux command line:

./fund_alg.o men_prefs.txt women_prefs.txt

Here, the mens' preference table is provided first and the womens' preference table second.

# Checking if a matching is stable
## Output
Given a matching and a pair of preference tables, the code will say whether or not the matching is stable.

## Compilation
The C++ code to produce this output uses functions contained in two different files; 'is_stable_funs.cpp' and 'file_to_pref.cpp'. See above on how to compile these.

The C++ code which produces the output is contained in the 'is_stable.cpp' file. In order to compile the code into an executable program, enter the following command into the Linux command line:

g++ --std=c++17 is_stable.cpp is_stable_funs.o file_to_pref.o -o is_stable.o

This will create the exectuable file 'is_stable.o'.

## Running the code

In order to run the code, first create three files, two containing the preference tables and one containing the matching, all in the required format. Assuming these files are named 'men_prefs.txt', 'women_prefs.txt' and 'match.txt' (these can be renamed), the check of stability can be performed by entering the following command into the Linux command line:

./is_stable.o men_prefs.txt women_prefs.txt match.txt

Here, the mens' preference table is provided first, the womens' preference table second and the matching third.
