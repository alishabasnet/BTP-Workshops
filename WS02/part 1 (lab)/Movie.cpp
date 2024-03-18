#include <iostream>
#include <cstring>
#include "Movie.h"
#include "DataHandle.h"

using namespace std;

namespace seneca
{
	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	Movie *g_colMovies = nullptr;

	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	int g_cntMovies = 0;

	/// <summary>
	/// load the data from the file name provided
	/// </summary>
	bool loadData(const char fileName[])
	{
		if (g_colMovies != nullptr)
			deallocateMemory();

		if (!seneca::openFile(fileName))
			return false;

		int numMovies = seneca::getRecordsCount();

		g_colMovies = new Movie[numMovies];

		for (int i = 0; i < numMovies; ++i)
		{
			if (!seneca::loadData(g_colMovies[i]))
			{
				deallocateMemory();
				return false;
			}
		}

		seneca::closeFile();

		g_cntMovies = numMovies;

		return true;
	}

	/// <summary>
	///	load the movies data as `Movie` struct
	/// </summary>
	bool loadData(Movie &aMovie)
	{
		// 1. Read the budget from the file and store it in the movie object
		if (!seneca::read(aMovie.m_budget, ','))
		{
			return false;
		}

		// 2. Read the gross income from the file and store it in the movie object
		if (!seneca::read(aMovie.m_grossIncome, ','))
		{
			return false;
		}

		// 3. Read the rating from the file and store it in the movie object
		if (!seneca::read(aMovie.m_rating, ','))
		{
			return false;
		}

		// 4. Read the title from the file and store it in the movie object
		aMovie.m_title = seneca::read('\n');

		// Check if the title was successfully loaded
		if (aMovie.m_title == nullptr)
		{
			return false;
		}

		// If successful, return true
		return true;
	}

	/// <summary>
	/// Implementation for display that receives an index
	/// </summary>
	void display(int idx)
	{
		if (idx >= 0 && idx < g_cntMovies)
		{
			// Access the movie at the given index
			Movie &movie = g_colMovies[idx];

			// Display the movie information with the desired format
			cout << movie.m_title << ", " << movie.m_budget << ", $" << movie.m_grossIncome << ", " << movie.m_rating << endl;
		}
		else
		{
			cout << "Index out of bounds.\n";
		}
	}

	/// <summary>
	// Implementation for display that receives a label, startIdx, and endIdx
	/// </summary>
	void display(const char label[], int startIdx, int endIdx)
	{
		// Print the label
		printf("******** %s ****************\n", label);

		// Loop through movies in the specified range
		for (int i = startIdx; i < g_cntMovies && i <= endIdx; ++i)
		{
			// Print movie information
			printf(">> ");
			display(i);
		}
	}

	/// <summary>
	// Implementation for deallocateMemory
	/// </summary>
	void deallocateMemory()
	{
		// Iterate over the collection of movies and deallocate memory
		for (int i = 0; i < g_cntMovies; ++i)
		{
			delete[] g_colMovies[i].m_title;
		}

		// Deallocate memory used by the array of movies
		delete[] g_colMovies;

		// Reset global variables
		g_colMovies = nullptr;
		g_cntMovies = 0;
	}

} // namespace seneca