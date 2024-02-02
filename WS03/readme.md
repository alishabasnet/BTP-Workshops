# Workshop #3: Member Functions and Privacy

In this workshop, you will create custom types, create member functions to access and modify data store in an object, and print to screen the information in a way that is easy to read.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define class types
- privatize data within the class type
- use member functions to query the state of an object
- use member functions to change the state of an object
- format your output on the console
- describe to your instructor what you have learned in completing this workshop



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

***Auto Service*** is a program manages the activity in an auto repair shop. The customers will bring their cars in and report a problem with the car that they want fixed. The program will record the information about the cars in objects of type `Car`.  When a client wants to store data into a `Car` object, the data will be validated before is accepted; if the data is not valid, the program will put the object in a *safe empty state* and record which data was invalid -- the object cannot be used until valid data is stored.

The program is partially developed; you can find all the files in the repository. Your responsibility is to complete the code as stated in the comments in the source code.

Create a project and add to it the provided files. From the main menu in Visual Studio, select **`View` » `Task List`**; this will open a window with a list with all your tasks (the tasks are marked with `TODO` in the source code). You can click on each one of them and Visual Studio will take you to the place where you must insert code or make changes.


### The `car` Module (Partially Provided)

The *Auto Service* will record the following information about each car:
- the license plate number, as a statically-allocated C-string
- the make/model of the car that require service, as a dynamically-allocated C-string of undetermined size
- the problem description that the customer provides, as a dynamically-allocated C-string of undetermined size
- the estimated cost of repairs.
- the status of an object, as a statically-allocated C-string. When the customer doesn't provide sufficient information about a car, the *Auto Service* will make some notes about what data is missing. A car that contains missing data cannot be serviced.

Look in the provided files and read the comments; proceed with the implementation when you understand the responsibilities of each function.  Read the provided code and understand how it accomplishes the goal.  If you need clarifications, contact your professor.  If you start writing code before you know what you try to accomplish, you will write wrong code and will be difficult to recover.

Use the provided sample output to infer the printing options like: alignment, precision, filling characters.



### `w3_p1` Module (Provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.




### Submission

Upload the header files (`*.h`), and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and test that everything works properly.  Using the provided tester module (`w3_p1.cpp`), a correct implementation will produce the output as shown in `sample_output.txt`.

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


In *Part #2* of the workshop you are to create an application that manages the activity of an ice cream vendor. The vendor can handle one customer at a time; will receive orders from customer with an *undetermined* number ice creams flavors, and will print the order receipt to the screen.

Your task is to implement the modules `IceCream` and `Vendor`. A sample output of the application has been provided in the file `sample_output.txt` (generated using the client provided in module `w3_p2`).

This program consists of the following modules:
- `w3_p2` (already provided, do not change it)
- `IceCream` -- contains the definition of a class named `IceCream` that manages information about a **single** ice cream a customer has ordered (i.e., the flavour, the number of scoops, if it should use a vanilla waffer). There is no mandatory function from this module that the client requires; add all the functionality as you see fit for your solution.

    **Hint**: for simplicity, the `IceCream` class is not required to use dynamic memory.
- `Vendor` -- contains a class that manages a dynamically-allocated array of `IceCream` objects representing the customer order. The array must be resized at runtime as the customer adds more flavours to the order.  See below for public functions that the `Vendor` class must have.

Your program must follow the rules:
- do not add global variables/functions, unless specifically instructed to do so.  Global constants are acceptable.
- all attributes in a class must be **private**, unless specifically instructed otherwise.
- add as many **private** members as your design requires.
- the client manipulates the data through **public** functions.
- all member functions should be queries, unless the needs of the project require otherwise.
- all member functions should be private, unless the needs of the project require otherwise.
- all public functions must validate their parameters before working with them (don't trust that clients provide good values).
- all parameters passed by-address or by-reference should be constants, unless the needs of the code require otherwise.
- all entities you create must be in the `seneca` namespace.

***You may freely use/copy any logic or code needed from the PART 1!***  You must use *custom types*, *public*/*private members*, and *dynamic memory allocation*.


### The `Vendor` Module

The class `Vendor` must use dynamic memory to manage the ice cream flavours the customer adds to the order. The class must have the following public functions:

- `startNewOrder()` -- Deallocates any dynamic memory used by the object and sets it to an empty state.
- `addToOrder()` -- Creates a new `IceCream` object and adds it to the collection of ice cream that the customer ordered **only** if the collection doesn't already contain that flavour and all the parameters are valid.

    If any of the parameters is not valid or the customer already ordered an ice cream with this flavour, this function does nothing.
    
    ***Note***: this function must work with dynamic memory and resize the array of ice creams to accommodate the new flavour the customer ordered.
    
    Paramaters:
    - `flavour` -- the address of a C-string containing the flavour of the ice cream the customer ordered. **Valid Value**: any string with at least one character.
    - `cntScoops` -- an integer with the number of scoops for this ice cream. **Valid Value**: only the value 1, 2, and 3.
    - `hasVanillaWafer` -- `true` if the ice cream should be in a vanilla wafer; `false` if a plastic cup should be used instead.
- `displayOrderReceipt` -- Print to screen the receipt for the customer's order, containing the ice creams in the order, the details for each ice cream, and a breakdown of prices.

    At the end print the total amount the customer must pay, including a 13% tax.

    This function should have no side effects (any formatting changes you make to `cout`, should be removed when the function finishes, and the original formatting options restored).
- `openShop()` -- Initializes the object to a default state (initializes all the attributes to some default value or empty state).
- `closeShop()` -- Deallocates any dynamic memory used by the object and sets it to an empty state.





### Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- what are the benefits of preventing clients from directly accessing the data members in a class.

To avoid deductions, refer to code in your solution as examples to support your explanations.

You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the source code files to your `matrix` account:

- `w2_p2.cpp`
- `hotel.h`
- `hotel.cpp`
- `file.h`
- `file.cpp`
- `hotel.csv`
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
