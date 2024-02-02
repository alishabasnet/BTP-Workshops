# Workshop #1: Modules

In the process of doing your first workshop, in part 1 (**LAB**) section you are to sub-divide a program into modules, compile each module separately and construct an executable from the results of each compilation.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- organize source code into modules, using header and implementation files;
- compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- describe to your instructor what you have learned in completing this workshop.



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

**SeneGraph** is a program that receives several statistical sample values and compares those values using a horizontal *Bar Chart*.


### Step 1: *Test the Program*

#### On Windows, using Visual Studio

- Open Visual Studio 2022 (VS) and create an *Empty C++ Windows Console Project*:
  ![Empty Project](images/emptyproj.png)
- copy the file `SeneGraph.cpp` (provided) into the project folder.
- in VS, open `Solution Explorer` (click on `View` » `Solution Explorer` if it's not visible already), and then add `SeneGraph.cpp` file to your project:
  - right-click on **`Source Files`**
  - select **`Add` » `Existing Item`**
  - select **`SeneGraph.cpp`** from the file browser
  - click on **`Ok`**
- now you can run the program by selecting **`Debug` » `Start Debugging`** or pressing the **`F5`** button.


#### On Linux, in your Matrix account

- connect to Seneca with [Global Protect VPN](https://students.senecapolytechnic.ca/spaces/186/it-services/wiki/view/1024/vpn)
- upload `SeneGraph.cpp` to your matrix account (ideally, to a designated directory for your workshop solutions). Then, enter the following command to compile the source file and create an executable called `ws`:

  ```bash
  g++ SeneGraph.cpp -Wall -std=c++11 -o ws
  ```

- type the following to run and test the execution:

  ```bash
  ws
  ```

The expected output of the program can be found in the file `sample_output.txt` (provided). Use the same input data as in the sample run and compare that the output is correct.



### Step 2: Create the Modules

It's time to break the program into multiple modules. In the solution explorer, add three new modules to your project:

- `w1_p1`: a module to hold the `main()` function.
- `io`: a module to hold the Input/Output related functions.
- `graph`: a module to hold the functions related to "graph" data entry, processing and creation.

The `w1_p1` module has an implementation (`.cpp`) file but no header file. The `io` and `graph` modules have both implementation (`.cpp`) and header (`.h`) files:





#### Header files

Add `io.h` and `graph.h` to the project directory (right click on project name and select *`Add` » `New Item`* and add a header file).  

Make sure you add the compilation safeguards and have all the C++ code in the last four modules in a namespace called `seneca`. **Compilation Safeguards** refers to a technique to guard against multiple inclusion of headers in *the same module*. It does so by applying macros that check against a defined name:

```cpp
#ifndef NAMESPACE_HEADERFILENAME_H // replace with relevant names, each header should have its own header guard, unique in the ENTIRE project
#define NAMESPACE_HEADERFILENAME_H

// Your header file content goes here

#endif
```

If the name isn’t yet defined, the `#ifndef` will allow the code to proceed onward to then define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.

Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).

Additionally, here is an instructional video showing how the compiler works and why you need these safeguards in all your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.

[Compilation Safeguards: https://www.youtube.com/watch?v=EGak2R7QdHo](https://www.youtube.com/watch?v=EGak2R7QdHo)


#### C++ Source Files

Add `io.cpp`, `graph.cpp`, and `w1_p1.cpp` to the project (right click on project name and select *`Add` » `New Item`* and add a C++ file). In each one of this files, include the corresponding header.




## Step 3: The `w1_p1` Module

At the top of the file, add the following:

```cpp
#include "io.h"
#include "graph.h"

using namespace std;
using namespace seneca;
```

From the provided file `SeneGraph.cpp`, add in this module the function (this function is not part of any namespace):

- `main` function


## Step 4: Organize the Rest of the Code in Modules

Separate the remaining functions from `SeneGraph.cpp` into modules. Copy the body of the functions into the cpp files and the prototypes into the header files.


### General guideline for creating modules

- ***Included Headers***
  Avoid unnecessary random includes and only include a header file in another file in which the header file functions are called or the header file identifiers are used.
- ***Global Variables***
  Global variable declarations must be in the source files (`*.cpp`).
- ***Structure Definitions***
  Structure definitions must be kept in the header file to be visible to all the modules using it.
- ***Constant Value Definitions***
  The constant value definitions are to be added to the file they are used in; if they are used in a header file, they must be added to the header file otherwise they must be added to the source file they are used in.
- ***Namespaces***
  All your code (in header files and source files) must be surrounded by the `seneca` namespace except in the module holding the `main` function. The main module should only use the `seneca` namespace (`using namespace seneca;`).
  > Important: Never use the **using namespace ...** statement in a header file.

Add to each module the following:

- ***`io` module***
  - `MAX_NO_OF_SAMPLES` constant (add in the header)
  - `GRAPH_WIDTH` constant (add in the header)
  - `drawLine` function
  - `intDigits` function
  - `printInt` function
  - `moveCursorBack` function
  - `drawLineWithLabel` function
  - `getInt` function
  - `printMsg` function
  - `printErrorMsg` function
  - `menu` function
- ***`graph` module***
  - `getSamples` function
  - `findMax` function
  - `printSampleBar` function
  - `printGraph` function





### Step 5: Testing

#### Windows

To test that you have done this correctly, you can compile each module separately, by right-clicking on `w1_p1.cpp`, `io.cpp`, and `graph.cpp` separately (in *Solution Explorer*) and select `Compile` from the menu. If the compilation is successful, most likely you have done it correctly.

Now remove `SeneGraph.cpp` from the project. You can do this by right-clicking on the filename in *Solution Explorer* and selecting `Remove` in the menu (make sure you do not delete this file but only remove it).

Compile and run the project (as you did before in Step 1) and make sure everything works.


#### Linux (in your Matrix account)

On Linux, in your matrix account, upload all the module files and compile the source code using the command below.

```bash
g++ graph.cpp –Wall -std=c++11 –c
```

This example will only compile `File.cpp` (only the first two stages of compilation) and will not create an executable; the flag `-c` ensures that.

To compile the whole project, use the command:

```bash
g++ w1_p1.cpp io.cpp graph.cpp -Wall -std=c++11 -o ws
```

Run the program like before and make sure that everything still works properly, and the output matches the expected one. The provided expected output file is generated when the user inputs the following values when prompted:

```txt
3
1
5
2
34
12
25
5
16
3
0
```


### Submission

The professor's testing module is slightly different and can be found in the file `w1_p1_prof.cpp`. During this term, the tester will check that you implemented correctly various features; as such it might contain specialized statements or use different input files. Look at the provided tester and ask your professor in class if it contains things that you don't understand.

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

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


Create a program called "Student's Mark Distribution Program" that generates a report based on student mark records saved in a file in a comma-separated format. A student record holds the student's first name, last name, and the mark.

The files with data contain multiple records about students; each record is stored in a single line. A record line has the following format:

```txt
FIRST_NAME,LAST_NAME,MARK
```

Look in the provided files `group1.csv`, `group2.csv`, and `group3.csv` for the actual files.



### Modules

This part of your workshop has the modules:

- `w1_p2`: already provided (no change necessary)
- `file`: already provided (no change necessary)
- `io`: copy if from *Part 1* (no change necessary)
- `graph`: copy it from *Part 1* (update the definition of a function; see below)
- `mark`: create this module


#### The `graph` module

Update the `printGraph()` function to add the number labels to the beginning of each *Bar Chart*.

```cpp
/// <summary>
/// Draw a graph, allowing the user to visually compare the samples.
/// </summary>
/// <param name="samples">the collection of samples to be drawn</param>
/// <param name="noOfSamples">the number of samples in the collection</param>
/// <param name="label">the name of the graph</param>
void printGraph(int samples[], int noOfSamples, const char* label)
{
   // find which sample is the biggest. This sample will be used
   //   to scale the other sample so they can be visually compared.
   int max = findMax(samples, noOfSamples);

   printMsg("\n");
   drawLineWithLabel(GRAPH_WIDTH + 4, label); // PART_2: `+4` is new in part 2 (expands the graph to accommodate the number at the beginning of line)
   for (int i = 0; i < noOfSamples; ++i)
   {
      printInt((10 - i) * 10, 4); // PART_2: New in part 2
      printSampleBar(samples[i], max);
   }
   drawLine(GRAPH_WIDTH + 4); // PART_2: `+4` is new in part 2 (expands the graph to accommodate the number at the beginning of line)
}
```

No other changes are necessary in this module.


#### The `mark` module

Create this module and add to a structure that hold information about a single mark a student has received:

```cpp
/// <summary>
/// Record of a mark received by a student.
/// </summary>
struct Mark
{
   /// <summary>
   /// The first name of the student.
   /// </summary>
   char m_firstName[20 + 1];
   /// <summary>
   /// The last name of the student.
   /// </summary>
   char m_lastName[30 + 1];
   /// <summary>
   /// The mark the student received (as a number between 0 and 100).
   /// </summary>
   int m_mark;
};
```

Also, add the function `printReport()`; implement it according to the specs from comments:

```cpp
/// <summary>
/// This file prints a statistic report of the collection of marks
///   found in a file. This function will count how many students have
///   received marks in the interval 0%-10%, 10%-20%, 20%-30%, ..., 90%-100%.
/// 
/// Using a *Bar Chart*, this function will display the report in the
///   following format:
/// 
/// +--- Students' Mark Distribution -----------------------------------+
/// 100 | ************************* 3                                   |
/// 90  | **************** 2                                            |
/// 80  | ********************************* 4                           |
/// 70  | ************************* 3                                   |
/// 60  | ********************************* 4                           |
/// 50  | ********************************* 4                           |
/// 40  | ************************************************** 6          |
/// 30  | *********************************************************** 7 |
/// 20  | ************************* 3                                   |
/// 10  | *********************************************************** 7 |
/// +-------------------------------------------------------------------+
/// 
///   and then print the sorted list of all the marks found in the file.
/// </summary>
/// <param name="filename">stores the address of an array of characters
///   representing the filename that holds the data with marks</param>
/// <returns>true if the data files is opened successfully, false otherwise.</returns>
/* TODO: define the `printReport` function
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* printReport()
*
* - use the function `seneca::openFile()` to open the file
* - if the file is successfully open:
*   - use the function `seneca::readAllMarks()` to load the content of the file
*   - create an array with how many marks are in each interval
*   - use the function `seneca::printGraph()` to print the *Bar Chart* with the
*       number of marks in each interval
*   - sort the collection of marks in descending order based on the `m_mark` field.
*       Use a **stable** sorting algorithm like BubbleSort:
*       https://intro2c.sdds.ca/F-Refinements/algorithms#bubble-sort
*
*       See here more info on stability of sorting algorithms:
*       https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
*   - print all the marks in the sorted collection using the format
*       `## : [MARK] FIRST_NAME LAST_NAME`
*       (see sample output)
*   - use the function `seneca::closeFile()` to close the file
* - return true if the file was successfully open, false otherwise
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
bool printReport(const char* filename);
```

The `printReport()` function is the only mandatory function in this module (because is used from `w1_p2` module). Consider adding to this module other functions as you see necessary to help you complete this part.



### Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- what happens if you put the function `main` in the `seneca` namespace?
- what are the benefits of putting the code into multiple modules instead of putting everything in a single file?

To avoid deductions, refer to code in your solution as examples to support your explanations.

You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the source code files to your `matrix` account:

- `w1_p2.cpp`
- `mark.h`
- `mark.cpp`
- `file.h`
- `file.cpp`
- `graph.h`
- `graph.cpp`
- `io.h`
- `io.cpp`
- `group1.csv`
- `group2.csv`
- `group3.csv`
- `reflect.txt`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. The professor's tester module has been provided in the repository. A sample run can be found in the file `output_sample.txt`.

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
