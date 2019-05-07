Minimum requirements : 
 - You have a modern c++ compiler (gcc or clang) that can compile c++11 code.
 - You have CMake (Version 3.12 minimum) installed.
 - You have git installed.
 - (While all this is possible from a windows machine, it is much easier on a linux or a mac.)

Here are the commands to run on the terminal (steps to compile and run this from terminal)
1. `git clone git@github.com:jmcarter17/Concordances.git` (to clone the repo)
2. `cd Concordances` (to move in the directory of the newly cloned repo) 
3. `git submodule update --init` (to bring in dependencies -- for tests)
4. `mkdir build` (to create build directory)
5. `cd build` (to move in the build directory)
6. `cmake ..` (to configure compilation by running cmake) 
7. `make` (to build library, tests and executable) 
8. `./tests/ConcordancesTests` (Optional : to Run tests) 
9. `./Concordances` (to run executable)
9a. `../files/smallPoem.txt` (on prompt, to write the name of a file)
10 `cat ../files/smallPoem.txt` (to display the content of the file on the terminal)

To test with another file, create a new file in the "files" directory, and then,
when running the executable `./Concordances`, on prompt enter `../files/newFileName`.
