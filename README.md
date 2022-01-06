## Advent of Code 2015

Started  10 Dec 2020  
Finished 04 Jan 2021

The second Advent of Code I have completed in its entirety. Realistically, I finished day 2 on the 27th of December and the whole thing took a bit longer than a week (with a lot of free time!). Finishing advent of Code 2020 helped massively with speeding up my coding.

### Testing:  
CMake is configured for testing each day against my input solutions. To use, create a build directory and run `cmake [source_directory]`, followed by `make` to compile the source code. `CTest` can be used to run the test suite.

Openssl is included as a submodule for day 4, which required an md5 hash.