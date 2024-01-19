# Workshop #1: Modules

In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;



## General Instructions

### Submission Policy

This workshop is divided into two coding parts and one non-coding part.

- **Part 1** (*LAB*): A *step-by-step* guided workshop, worth 50% of the workshop's total mark.
  Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **Part 2** (*DIY*): A *do-it-yourself* type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of "Part 2" mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions of **Part 2** that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates

The due dates depend on your section. The due date for *Part #1* is at the end of they when your lab is scheduled; the due date for *Part #2* is at the end of the day that is 5 days after the day with the lab.

Please choose the `-due` option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS -due
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]



### Late penalties

You are allowed to submit your work up to 2 days after the due date with 30% penalty for each day. After that, the submission will be closed, and the mark will be zero. If the reflection is missing when the submission closes, the mark for **Part 2** will be set to 0.



### Citation

Every file that you submit must contain (as a comment) at the top:

- **your name**,
- **your Seneca email**,
- **Seneca Student ID**,
- the **date** when you completed the work.


#### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#### For work that is done partially by you

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from**.  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

- Add the citation to the file in which you have the borrowed code (make sure to clearly mark the code that is not created by you and where did you get it from).
- In the `reflect.txt` file, add a summary of the files/portions of code that is not yours (the source files should un-ambiguously identify the portions of code that are not yours).

> ⚠️ This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.


#### If you have helped someone with your code

If you have helped someone with your code, let them know of these regulations and, in your `reflect.txt` file, write exactly which part of your code was copied and who was the recipient of this code. By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.



### Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.





## Part 1 (50%)

***Movies Report*** is a program that reads an unknown number of `Movie` records from a file and stores them in a dynamically-allocated array. Each record holds the title, budget, gross income, and rating of a movie in a comma-separated-values format (`csv` file).

The program is partially developed; you can find all the files in the repository. Your responsibility is to complete the code as stated in the comments in the source code.

Create a project and add to it the provided files. From the main menu in Visual Studio, select **`View` » `Task List`**; this will open a window with a list with all your tasks (the tasks are marked with `TODO` in the source code). You can click on each one of them and Visual Studio will take you to the place where you must insert code or make changes.


### Data File

The data in the file with movie records has the following format:

```txt
BUDGET,GROSS_INCOME,RATING,TITLE<NEWLINE>
```

Two input files with movie records have been provided.  Test your code with those files.

A text input file with tokens has also been provided to test that the `read()` functions work as described.  See the main module about how those files are used.


### The `Movie` module (Partially Provided)

The structure holding a record is designed as follows:

```cpp
/// <summary>
/// A structure that encapsulates some information about a
///   single movie.
/// 
/// The title of the movie is a dynamically-allocated array
///   of characters. It requires that the programmer manages
///   the memory (allocation and deallocation).
/// </summary>
struct Movie
{
  char* m_title;
  int m_budget;
  long m_grossIncome;
  double m_rating;
};
```

The title of the movie is held in a dynamically-allocated C-style string; an object of type `Movie` will store the address of this dynamically-allocated string.

Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and make you understand how it accomplishes the goal.  If you need clarifications, contact your professor.



### `DataHandle` Module (Partially Provided)

This module contains functions that facilitate working with files to read data. Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and make you understand how it accomplishes the goal.  If you need clarifications, contact your professor.


### `w2p1` Module (Provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.




### Submission

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`, `*.txt`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.  Using the provided tester module (`w2p1.cpp`), a correct implementation will produce the output as shown in `sample_output.txt`.

Then, run the following command from your `matrix` account:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty!





## Part 2 (50%)


Comming Soon!




