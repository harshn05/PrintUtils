
# PrintUtils

This C++ header-only class provides a utility for printing various data structures, including vectors, arrays, and matrices, to the console or to a CSV file. It includes a namespace PrintUtils with a class CSV that contains static methods for writing one-dimensional and two-dimensional arrays, vectors, and pairs of vectors to CSV files.

The operator<< overloads allow for easy printing of vectors, vectors of arrays, and matrices (vectors of vectors) to the console. Each method in the CSV class opens a file with the provided filename, writes the data structure to it in CSV format, and then closes the file. The methods are templated, allowing for use with any data type that can be written to a std::ostream.

[Click here for the detailed documentation.](https://harshn05.github.io/PrintUtils/)

Harsh Kumar Narula
<harsh.narula@iitbombay.org>
