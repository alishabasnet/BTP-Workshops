///

// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "file.h"

using namespace std;

namespace seneca
{

    /// <summary>
    /// The file descriptor; will be set when a file is open with
    ///   `openFile`, and reset when the file is closed with `closeFile`.
    /// </summary>
    FILE *g_fptr;

    bool openFile(const char filename[])
    {
        bool allGood = false;
        if (g_fptr == nullptr)
        {
            g_fptr = fopen(filename, "r");
            allGood = g_fptr != nullptr;
        }
        return allGood;
    }

    void closeFile()
    {
        if (g_fptr)
        {
            fclose(g_fptr);
            g_fptr = nullptr;
        }
    }

    int getRecordsCount()
    {
        // if no file is opened,return -1
        if (g_fptr == nullptr)
            return -1;

        int numRecords = 0;
        // else start counting lines
        if (g_fptr != nullptr)
        {
            // Get current position in the file
            auto currentPosition = ftell(g_fptr);

            // Go to the beginning of the file
            fseek(g_fptr, 0, SEEK_SET);

            // Read line by line and count the lines
            char line[256];
            while (fgets(line, sizeof(line), g_fptr) != nullptr)
                ++numRecords;

            // Reposition the cursor to the original location
            fseek(g_fptr, currentPosition, SEEK_SET);
        }

        return numRecords;
    }

    char *read(char delim)
    {
        long position = ftell(g_fptr);
        int counter = 0;
        char ch;

        // Count the number of characters until the delimiter or end of file
        while (fscanf(g_fptr, "%c", &ch) == 1 && ch != delim)
        {
            ++counter;
        }

        // Reposition the cursor to the beginning of the token
        fseek(g_fptr, position, SEEK_SET);

        // Allocate memory for the token
        char *token = new char[counter + 1];

        // Read the token into the allocated memory
        for (int i = 0; i < counter; ++i)
        {
            fscanf(g_fptr, "%c", &token[i]);
        }

        // Null-terminate the string
        token[counter] = '\0';

        // Move the file cursor past the delimiter
        if (ch == delim)
        {
            fscanf(g_fptr, "%*c");
        }

        return token;
    }

    bool read(int &val, char delim)
    {
        char *token = read(delim);

        if (token != nullptr)
        {
            // Convert the array of characters to an integer
            val = atoi(token);

            // Deallocate the memory used by the array
            delete[] token;

            return true;
        }

        return false;
    }

} // namespace seneca