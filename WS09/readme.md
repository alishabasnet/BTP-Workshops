# Workshop 9: Derived Class with a Resource

In this workshop, you will create a LibraryItem class that represents different types of items in a library's inventory along with a Book class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Apply the rule of three and its derived class.
- Use the concept of inheritance and polymorphism to reuse functionality of parent in child classes
- Describe what you have learned in completing this workshop



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

In this workshop, you create an inheritance hierarchy that is used to manage the activity at a library.

## `LibraryItem` Module

Create a `LibraryItem` class that represents different types of items in a library's inventory. The class should have the following private data members:
* `char* m_title` - a pointer to store the address of a dynamically allocated array of characters representing the title of the item.
* `int m_year` - an integer to store the publication year of the item.

The `LibraryItem` class should include the following member functions:

* A default constructor - This constructor should set the title pointer to null and year to 0.
* A parameterized constructor - This constructor should take two parameters: title and year. It should allocate memory for the title string on the heap and make the title pointer point to the appropriate heap memory. Also, set the year to the provided year value.
* The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning LibraryItem objects.
* `virtual ostream& display(ostream& ostr = cout) const` - This method should display the title and year of the library item as follows:
  ```text
  Title: The book Title (the year)<no new line>
  ```

## `Book` Module

Create a `Book` class that inherits from the `LibraryItem` class. The `Book` class should have an additional private data member:
* `char* m_author` - a pointer to store the address of a dynamically allocated array of characters representing the name of the author of the book.

The `Book` class should include the following member functions:
* A parameterized constructor - This constructor should take three parameters: title, year, and author. It should allocate memory for the title and author strings on the heap and make the respective pointers point to the appropriate heap memory. Also, set the year to the provided year value.
* The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning Book objects.
  > Note that the copy constructor and copy assignment of the derived class must ensure that the base class subobject is also copied.
* `ostream& display(ostream& ostr = cout) const` - This method should display the title, year, and author of the book as follows:
  ```text
  Title: The book Title (the year)<new line>
  Author: The Author Name<no new line>
  ```
* `bool operator>(const Book& other)const` - This method checks for non-null author names and checks to see if the object's author name is lexicographically greater than the other object's author name (use `std::strcmp()`), it returns `true`; otherwise, it returns `false`.




### The `w9_p1` Module (provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.




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