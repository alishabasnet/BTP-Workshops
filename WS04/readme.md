# Workshop #4: Constructors, Destructors, and the Current Instance

In this workshop, you will make use of constructors to initialize objects containing both static and dynamic data members as well as destructors to release those resources as the objects go out of scope. There will be use of the current object within the class to modify the state.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- The use of the default and overloaded constructors
- The use of destructors
- The use of the current object within the class's member functions
- The handling of dynamic resources via the constructor and destructor



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

In part one of the workshop, you will create a custom type named `Fridge` that will manage an array of undetermined size of `Food` objects.  A fridge has a certain maximum capacity; a client cannot add foods if they exceed the capacity of the fridge.  For simplicity, you are only required to provide functionality to add foods in the fridge, but you are encouraged to implement to the functionality to remove a food ittem as an exercise.

This part of the workshop has three modules:

- `food` - represents a single food item (already provided, do not change it)
- `fridge` - represents a fridge (you must fully implement this module in `*.h`/`*.cpp` files)
- `w4_p1` - which contains the `main()` function (already provided, do not change it)

Your task is to implement the `Fridge` module.



### The `Fridge` Module

Design and implement a class named `Fridge` that manages a collection of foods of undetermined size.  The class will not expose the data to clients, validate the parameters before storing them into the attributes.  The client will interract with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `Fridge` will store the following information about a single fridge:

- `m_capacity` - as an object of type `int`, representing the maximum capacity of the fridge, measured in kilograms.  A valid fridge will have a capacity of at least 10 kilograms, and no foods can be added to fridge if they exceed the capacity.
- `m_model` - a pointer that stores the address of a dynamically-allocated C-string containing the model of the fridge.
- `m_foods` - a pointer that stores the address of a dynamically-allocated array of `Food` objects. These are the foods that are in the fridge.
- `m_cntFoods` - as an object of type `int` that stores the number of `Food` objects that exists in the fridge.

Not mandatory, but highly encouraged:

- `getContentWeight()` - a **query** that receives no parameters and returns an `int`.

  This function iterates over the array whose address is stored in `m_foods` and calculates the total weight of all foods stored in the fridge (adds together `Food::m_weight`).  At the end, returns the calculated value.

#### Public Members

The class `Fridge` will provide to clients the following public functions:

- a default constructor
  **Implementation**:
  - set the capacity and number of foods to 0
  - set the pointer attributes to null



- a custom constructor with two parameters that initializes the current instance with the values of the parameters.
  **Parameters**:
  1. `model` - the address of an unmodifiable C-string representing the model of the fridge.
  2. `capacity` - an object of type `int` representing the capacity of the fridge

  **Implementation**:
  - create a temporary empty object of type `Fridge` using the default constructor and copy it in the current instance: `*this = Fridge()`.
  - call the `Fridge::setModel()` to set the model and capacity (the `setModel()` will store the parameters in the current instance only they contain valid data; see below)



- a custom constructor with four parameters that initializes the current instance with the values of the parameters.
  **Parameters**:
  1. `foods` - the address of an unmodifiable array of `Food` objects to be stored in the fridge.
  2. `cntFoods` - an object of type `int` representing the size of `foods` array received as parameter
  3. `model` - the address of an unmodifiable C-string representing the model of the fridge.
  4. `capacity` - an object of type `int` representing the capacity of the fridge

  **Implementation**:
  - create a temporary empty object of type `Fridge` using the default constructor and copy it in the current instance: `*this = Fridge()`.
  - call the `Fridge::setModel()` to set the model and capacity
  - if the `m_model` is not null (the `Fridge::setModel()` called before accepted the parameters)
    - in a loop, iterate over the array `foods` received as parameter, and add each food to the fridge by calling `Fridge::addFoo()`.

- a destructor that removes any resource used by the current instance
  **Implementation**:
  - deallocate the dynamic memory used by the current instance



- `addFood()` - a **modifier** that adds a new `Food` object to the fridge if there is capacity.
  **Parameters**:
  1. `aFood` - an unmodifiable reference to an object to type `Food`
  
  **Return**:
  - `true` if `aFood` was added to the fridge, `false` otherwise

  **Implementation**:
  - use `Fridge::getContentWeight()` to get the total weight of all foods from the fridge
  - if the total weight plus the weight of `aFood` is less or equal to the capacity of the fridge, then
    - resize the array of foods `m_food` and add `aFood` at the end
    - return `true`
  - else
    - return `false`



- `setModel()` - a **modifier** that sets the model and capacity of a fridge.
  **Parameters**:
  1. `model` - the address of an unmodifiable C-string representing the model of the fridge.
  2. `capacity` - an object of type `int` representing the capacity of the fridge

  **Return**:
  - nothing

  **Implementation**:
  - if the `model` is not null or empty string, and the `capacity` is at least 10kg
    - deallocate the memory used by the attribute `m_model`
    - allocate new memory, sufficient to accommodate the `model` parameter
    - copy parameter `model` into `m_model` attribute
    - copy parameter `capacity` into `m_capacity` attribute



- `isFull()` - a **query** that returns `true` if the fridge is at least at 90% capacity, `false` otherwise. This function receives no parameters.
  **Hint**: use `Fridge::getContentWeight()` to get the weight of all items from the fridge



- `hasFood()` - a **query** that returns `true` if the fridge contains the food received as parameter, `false` otherwise. If the parameter is null, this query returns `true` if the fridge is not empty.
  **Parameters**:
  1. `theFood` - the address of an unmodifiable C-string with the name of the food to be checked. *By default, this parameter is null!*

  **Return**:
  - `true` if `theFood` was found in the fridge, or the parameter is null and the fridge contains at least one `Food` item; `false` otherwise

  **Implementation**:
  - if the parameter is null and `m_cntFoods` is more than zero, return `true`
  - else, iterate over the `m_foods` array and compare the name of the food with `theFood` parameter. If a match is found, return `true`
  - if none of the foods' name match the parameter, return `false`



- `display()` - a **query** that inserts into the parameter the content of the current instance
  **Parameters**:
  1. `out` - a reference to an object of type `std::ostream`. *By default, this parameter is `std::cout`!*

  **Return**:
  - a reference to the object received as parameter

  **Implementation**:
  - if the `m_model` is null (the object is in an empty state), insert into `out` the message "The fridge object is in an empty state.\n".
  - else, insert into `out` the content of the object as shown in the sample output. To calculate the fill percentage, use the formula: $$100 \times \frac{TOTAL\_WEIGHT\_OF\_FOODS}{FRIDGE\_CAPACITY}$$





### The `w4_p1` Module (Provided)

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


COMING SOON