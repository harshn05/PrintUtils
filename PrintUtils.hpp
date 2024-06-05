#pragma once
#include <string>
#include <vector>
#include <array>
#include <fstream>

/**
 * @file PrintUtils.hpp
 * @brief Contains utility functions for printing vectors and matrices.
 */

namespace
{
	/**
	 * @brief Overload of the output stream operator for printing vectors.
	 * @tparam T The type of elements in the vector.
	 * @param ost The output stream.
	 * @param obj The vector to be printed.
	 * @return The output stream after printing the vector.
	 */
	template <typename T>
	std::ostream &operator<<(std::ostream &ost, const std::vector<T> obj)
	{
		// Print each element of the vector on a new line
		for (size_t i = 0; i < obj.size(); i++)
		{
			ost << obj[i] << '\n';
		}
		return ost;
	}

	/**
	 * @brief Overload of the output stream operator for printing vectors of arrays.
	 * @tparam T The type of elements in the array.
	 * @param ost The output stream.
	 * @param obj The vector of arrays to be printed.
	 * @return The output stream after printing the vector of arrays.
	 */
	template <typename T>
	std::ostream &operator<<(std::ostream &ost, const std::vector<std::array<T, 3>> obj)
	{
		int rows = obj.size();
		int columns = 3;
		for (size_t i = 0; i < rows; i++)
		{
			auto v = obj.at(i);
			for (size_t j = 0; j < columns; j++)
			{
				ost << v.at(j);
				if (j != columns - 1)
				{
					ost << ",";
				}
			}
			ost << std::endl;
		}
		return ost;
	}

	/**
	 * @brief Overload of the output stream operator for printing matrices (vectors of vectors).
	 * @tparam T The type of elements in the matrix.
	 * @param ost The output stream.
	 * @param obj The matrix (vector of vectors) to be printed.
	 * @return The output stream after printing the matrix.
	 */
	template <typename T>
	std::ostream &operator<<(std::ostream &ost, const std::vector<std::vector<T>> obj)
	{
		int rows = obj.size();
		int columns = obj.at(0).size();
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				ost << obj[i][j];
				if (j != columns - 1)
				{
					ost << ",";
				}
			}
			ost << std::endl;
		}
		return ost;
	}
}

/**
 * @namespace PrintUtils
 * @brief Contains utility functions for printing data structures.
 */
namespace PrintUtils
{
	/**
	 * @class CSV
	 * @brief Class for printing data structures as CSV files.
	 * @tparam T The type of data in the data structures.
	 */
	template <class T>
	class CSV
	{
	public:
		/**
		 * @brief Prints a two-dimensional array as a two-dimensional CSV file.
		 * @param rows The number of rows in the array.
		 * @param columns The number of columns in the array.
		 * @param M The two-dimensional array.
		 * @param Filename The name of the output CSV file.
		 */
		static void TwoDArrayAsTwoD(int rows, int columns, T **M, std::string Filename);

		/**
		 * @brief Prints a one-dimensional array as a one-dimensional CSV file.
		 * @param p The size of the array.
		 * @param M The one-dimensional array.
		 * @param Filename The name of the output CSV file.
		 */
		static void OneDArrayAsOneD(int p, T *M, std::string Filename);

		/**
		 * @brief Prints a one-dimensional vector as a one-dimensional CSV file.
		 * @param M The one-dimensional vector.
		 * @param Filename The name of the output CSV file.
		 */
		static void OneDVectorAsOneD(std::vector<T> &M, std::string Filename);

		/**
		 * @brief Prints a two-dimensional vector as a two-dimensional CSV file.
		 * @param M The two-dimensional vector.
		 * @param Filename The name of the output CSV file.
		 */
		static void TwoDVectorAsTwoDVector(std::vector<std::vector<T>> M, std::string Filename);

		/**
		 * @brief Prints two one-dimensional vectors as a two-column CSV file.
		 * @param V1 The first one-dimensional vector.
		 * @param V2 The second one-dimensional vector.
		 * @param Filename The name of the output CSV file.
		 */
		static void OneDVectorOneDVector(std::vector<T> V1, std::vector<T> V2, std::string Filename);
	};
}

// void PrintUtils::CSV<bool>::TwoDArray(int, int, bool**, std::string);

/**
 * Writes a two-dimensional array to a CSV file.
 *
 * @tparam T The type of elements in the array.
 * @param rows The number of rows in the array.
 * @param columns The number of columns in the array.
 * @param M The two-dimensional array to be written.
 * @param Filename The name of the output CSV file.
 */
template <class T>
void PrintUtils::CSV<T>::TwoDArrayAsTwoD(int rows, int columns, T **M, std::string Filename)
{
	Filename = Filename + ".csv";
	std::ofstream outdata;
	outdata.open(Filename);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns - 1; j++)
		{
			outdata << M[i][j] << ",";
		}
		outdata << M[i][columns - 1] << std::endl;
	}
}

/**
 * Writes the elements of a one-dimensional array to a CSV file.
 *
 * @tparam T The type of the elements in the array.
 * @param p The number of elements in the array.
 * @param M Pointer to the array.
 * @param Filename The name of the output CSV file.
 */
template <class T>
inline void PrintUtils::CSV<T>::OneDArrayAsOneD(int p, T *M, std::string Filename)
{
	Filename = Filename + ".csv";
	std::ofstream outdata;
	outdata.open(Filename);

	for (size_t i = 0; i < p - 1; i++)
	{
		outdata << M[i] << std::endl;
	}
	outdata << M[p - 1];
}

/**
 * Writes the elements of a one-dimensional vector to a CSV file.
 * Each element is written on a separate line in the file.
 *
 * @tparam T The type of elements in the vector.
 * @param M The one-dimensional vector to be written to the file.
 * @param Filename The name of the CSV file to be created.
 */
template <class T>
inline void PrintUtils::CSV<T>::OneDVectorAsOneD(std::vector<T> &M, std::string Filename)
{
	Filename = Filename + ".csv";
	std::ofstream outdata;
	outdata.open(Filename);
	int p = M.size();
	for (size_t i = 0; i < p - 1; i++)
	{
		outdata << M[i] << std::endl;
	}
	outdata << M[p - 1];
}

/**
 * Writes two one-dimensional vectors to a CSV file.
 *
 * @tparam T The type of elements in the vectors.
 * @param V1 The first vector.
 * @param V2 The second vector.
 * @param Filename The name of the output CSV file.
 */
template <class T>
inline void PrintUtils::CSV<T>::OneDVectorOneDVector(std::vector<T> V1, std::vector<T> V2, std::string Filename)
{
	Filename = Filename + ".csv";
	std::ofstream outdata;
	outdata.open(Filename);
	int p = V1.size();
	for (size_t i = 0; i < p - 1; i++)
	{
		outdata << V1[i] << "," << V2[i] << std::endl;
	}
	outdata << V1[p - 1] << "," << V2[p - 1];
}

/**
 * Writes a two-dimensional vector to a CSV file.
 *
 * @tparam T The type of elements in the vector.
 * @param M The two-dimensional vector to be written.
 * @param Filename The name of the output CSV file.
 */
template <class T>
inline void PrintUtils::CSV<T>::TwoDVectorAsTwoDVector(std::vector<std::vector<T>> M, std::string Filename)
{
	Filename = Filename + ".csv";
	std::ofstream outdata;
	outdata.open(Filename);
	int rows = M.size();
	int columns = M[0].size();

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns - 1; j++)
		{
			outdata << M[i][j] << ",";
		}
		outdata << M[i][columns - 1] << std::endl;
	}
}