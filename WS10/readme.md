# Workshop #10: Function Templates

In this workshop, you are to code a `standard-layout` class template (previously called `P`lain `O`ld `D`ata) and two function templates. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- code a very simple `struct` as template
- code function templates
- code calls to function template
- describe what you have learned while completing this workshop



## General Instructions

### Submission Policy

This workshop is divided into one coding part and one non-coding part.

- **Part 1** (*LAB*): A *step-by-step* guided workshop, worth 50% of the workshop's total mark.
  Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of "Part 1" mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions of **Part 1** that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates

The due dates depend on your section. The due date for *Part #1* is at the end of the day when your lab is scheduled.

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





## Part 1 (100%)

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `seneca` namespace.

This part of the workshop has four modules:

- `Book`: contains logic representing a single book (fully provided, do not change)
- `Student`: contains logic representing a single book (fully provided, do not change)
- `MatchPair`: contains templates to manipulate collections of unknown objects (you have to implement this module). This module has only the header file.
- `w10_p1`: the driver module (partially provided)


### `MatchPair` module

Create a header file called `MatchPair.h`. Do not create an implementation file for this module, since it is a **template** module.

In the `MatchPair` module, create a templated custom type (`struct`) called `Pair`. This custom type has **two** different type-parameters `T` and `U` (in this order):
- a public member called `first` of type `T`
- a public member called `second` of type `U`

Add the following function template to the `MatchPair` module.  This function template is used to add a `Pair` element to a dynamically-allocated array of `Pair` objects.

```cpp
template<typename T, typename U>
void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size)
{
	Pair<T, U>* temp = new Pair<T, U>[size + 1];

	for (int k = 0; pArray && k < size; k++)
		temp[k] = pArray[k];

	temp[size].first = first;
	temp[size].second = second;

	releaseMem(pArray);
	pArray = temp;
	size++;
}
```

> The function `addDynamicPairElement`is designed to add a new element (a `Pair<>`) to a dynamic array of `Pair<>` objects (`pArray`). It takes three parameters: the array itself (`pArray`), the **first** element of the `Pair<>`, the **second** element of the `Pair<>`, and a reference to an integer **size** which represents the current size of the array.
>
> The function dynamically allocates memory for a new temporary array (`temp`) with a size one greater than the current size. It then copies the elements from the original array into the temporary array using a loop. After that, it assigns the provided first and second values to the newly added element in the temporary array.
>
> Next, it deallocates the memory occupied by the original array. Finally, it updates the pointer `pArray` to point to the newly created array and increments the `size` by one.



#### `matches` templated function

Finds pairs of element matches in two arrays, where the two arrays may carry elements of different types.

Create a function template called `matches` that has **two** template parameters (`T` and `U`), and **five** function parameters. The function parameters are:
- `arr1` - the address of an array of unmodifiable objects of type `T`
- `arr2` - the address of an array of unmodifiable objects of type `U`
- `size1` - the number of elements in `arr1`
- `size2` - the number of elements in `arr2`
- `size3` - a reference to an integer. This is the number of matches found in the two arrays.

Implement this function as following:
- create a pointer called `pt` for storing the address of an array of objects of type `Pair<>` (use `T` and `U` as the template parameters); initialize this pointer to null.

- initialize the parameter `size3` to zero. This parameter is to keep track of the number of elements in the array whose address is stored in `pt`.

- in a loop, iterates through all the elements of the first array `arr1`, and in each of these iterations it runs a nested loop to iterate, or sub-iterate, through all the elements of the second array `arr2`.

  Each sub-iteration is to compare the current element of `arr1` with the current element of `arr2` for equality (using `==` operator).

  If the compared elements are equal, it calls `addDynamicPairElement` function to add the matched  `Pair<>` as a new elemet to the `pt` dynamic array. 

- return the address of the first element of the new dynamic array; remember that its size is returned through the fifth function parameter. **NOTE:** The return type of `matches` is to be set to the type of the returned data.  



#### `releaseMem` templated function
This function is for releasing the dynamic memory allocated by `matches` function. 

Create a function template called `releaseMem`, which  
 that has **one** template parameter (`T`), and **one** function parameter. The function parameter is:
- `arr` - the address of an array of objects of type `T`;

This function releases the dynamic memory at the address received as parameter.


### The `w10_p1` Module (partially provided)

In this workshop you will be making some changes in the main module. Make sure you add to the comment at the top of the main module including your information.




### Submission

Upload the header files (`*.h`), and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and test that everything works properly.  Using the provided tester module, a correct implementation will produce the output as shown in `sample_output.txt`.

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







### Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and **the project milestones** and mention any issues that caused you difficulty and how you solved them.

To avoid deductions, refer to code in your solution as examples to support your explanations.

You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`), and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and test that everything works properly.  Using the provided tester module, a correct implementation will produce the output as shown in `sample_output.txt`.

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



<!--🔜 COMING SOON-->