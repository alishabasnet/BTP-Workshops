# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that form a hierarchical structure. The base class is a `BankAccount` that holds common attributes of a bank account.  The child class is a `SavingsAccount` that is derived from the `BankAccount` class.  In each class, you will define private, protected, and public members as well as custom input/output operators.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- inherit a derived class from a base class
- shadow a base class member function with a derived class member function
- access a shadowed member function that is defined in a base class
- utilize custom input/output operators with these classes
- describe to your instructor what you have learned in completing this workshop



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

This part of the workshop has three modules:

- `BankAccount` - represents a generic bank account email (you must fully implement this module in `*.h`/`*.cpp` files)
- `SavingsAccount` - represents a savings account that earns interest every month (you must fully implement this module in `*.h`/`*.cpp` files)
- `DepositUtility` - it contains a `Date` and `DepositInfo` classes that you can use when implementing your solution (already provided, do not change it)
- `w7_p1` - which contains the `main()` function (already provided, do not change it)



### The `BankAccount` Module

Design and code a class named `BankAccount` that holds information about a bank account. Place your class definition in a header file named `BankAccount.h` and your function definitions in an implementation file named `BankAccount.cpp`.  In your implementation, assume that all the data read from a stream or received from the client is good and doesn't require validation.  The client will interact with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `BankAccount` will store the following information:

- `m_name` - as a statically allocated array of 100 characters representing the name of the person who owns the account.
- `m_openDate` - an object of type `seneca::Date` (see provided code) that holds the date when this account has been opened.
- `m_depInfo` - an object of type `seneca::DepositInfo` (see provided code) that holds some information about the account (i.e., institution name, bank transit code, and account number).
- `m_balance` - as a floating-point number in double precision representing amount of money available in the account.

#### Protected Members

The class should allow the derived class to interact with a `BankAccount` using the following members:

- `getBalance()` - a query that returns the balance of the account.

- `setBalance()` - a modifier that updates the balance to the value of the parameter
  **📌Parameters**:
  - the new balance as a floating-point number in double precision

- `writeCurrency()` - a query method that inserts into the stream received as a first parameter a formatted dollar amount received as a second parameter.
  **📌Parameters**:
  - `out` - a reference to an object of type `std::ostream`
  - `amount` - a floating-point number in double precision

  **🔍Implementation**:
  Insert into the first parameter the amount written with a leading `$` sign and a precision of 2.  For example, if `amount` is `1.2`, `$1.20` is inserted to `out`. Your function should not have side-effects.

#### Public Members

The class `BankAccount` will provide to clients the following public functions:

- a custom constructor
  **📌Parameters**:
  - `name` - the address of a C-style array of characters representing the name of the account holder
  - `openDate` - an object of type `seneca::Date` representing when the account was open
  - `depInfo` - an object of type `seneca::DepositInfo` containing some extra info about the account
  - `balance` - the amount of money that exists in the account

  **🔍Implementation**:
  Copy all parameters into their corresponding attributes. Assume all data is valid.

- `write()` - a query that inserts into the stream received as parameter the content of the current instance
  **📌Parameters**:
  - `out` - an unmodifiable reference to an object of type `std::ostream`.

  **📌Return**:
  - the parameter

  **🔍Implementation**:
  Insert the information in the following format:
  ```txt
  >> NAME | BALANCE | DATE_OPENED | DEPOSIT_INFO
  ```
  - use `writeCurrency` to print the balance
  - use the insertion operators overloaded for `seneca::Date` and `seneca::DepositInfo` to print the attributes of custom types.

- `read()` - a mutator that reads data from the stream received as the first parameter and stores it in the current instance.
  **📌Parameters**:
  - `in` - an un-modifiable reference to an object of type `std::istream`

  **📌Return**:
  - the parameter

  **🔍Implementation**:
  Ask the user to type info and then read from the stream and store it in the attributes of the current instance.
  ```txt
  Name: [USER TYPES HERE]
  Opening Balance: [USER TYPES HERE]
  Date Opened (year month day): [USER TYPES HERE]
  Transit #: [USER TYPES HERE]
  Institution #: [USER TYPES HERE]
  Account #: [USER TYPES HERE]
  ```
  Assume all data the user types is valid.  Use `istream::getline()` to read the user name (delimiter is `\n`), and the extraction operator for the other fields. Note that the extraction operator is already provided for `seneca::Date` and `seneca::DepositInfo`; use it!


#### Free Helpers

- `operator>>()` - overload the extraction to read from a stream some data that is stored in a `BankAccount` object.
  **📌Parameters**:
  - `in` - a reference to an object of type `std::istream`
  - `account` - a reference to an object of type `BankAccount`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - call the function `BankAccount::read()`


- `operator<<()` - overload the insertion to insert an `BankAccount` object into the first parameter.

  **📌Parameters**:
  - `out` - a reference to an object of type `std::ostream`.
  - `account` - an un-modifiable reference to an object of type `BankAccount`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - call the function `BankAccount::write()`





### The `SavingsAccount` Module

Design and code a class named `SavingsAccount` that holds information about a savings account.  Place your class definition in a header file named `SavingsAccount.h` and your function definitions in an implementation file named `SavingsAccount.cpp`.  In your implementation, assume that all the data read from a stream or received from the client is good and doesn't require validation.  The client will interact with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `SavingsAccount` will store the following information:

- `m_interest` - as a floating-point number in double precision representing the interest rate that must be paid on the balance. This is a number between 0 and 1 (this is the percentage the account gains in interest every month).
- `m_interestDate` - an object of type `seneca::Date` that represents the date when the interest was last applied to the account.
- `writeInterest()` - a query method that inserts into the stream received as a first parameter the interest rate stored in the current instance.
  **📌Parameters**:
  - `out` - a reference to an object of type `std::ostream`

  **🔍Implementation**:
  Insert into the parameter the `m_interest` with a precision of 3 and followed by the symbol `%`.  For example, if `m_interest` is 0.12, `0.120%` is written to `out`. Your function should not have side-effects.


#### Public Members

The class `SavingsAccount` will provide to clients the following public functions:

- a custom constructor
  **📌Parameters**:
  - `name` - the address of a C-style array of characters representing the name of the account holder
  - `openDate` - an object of type `seneca::Date` representing when the account was open
  - `depInfo` - an object of type `seneca::DepositInfo` containing some extra info about the account
  - `balance` - the amount of money that exists in the account
  - `interest` - the interest for this account as a floating-point number in double precision
  - `interestDate` - an object of type `seneca::Date` representing when the date when the interest was last applied to the account.

  **🔍Implementation**:
  Copy all parameters into their corresponding attributes. Assume all data is valid.

- `applyInterest()` - a mutator that increases the account balance by adding the interest
  **📌Parameters**:
  - `today` - an unmodifiable reference to an object of type `seneca::Date`.

  **🔍Implementation**:
  - get the balance of the account (`BankAccount::getBalance()`)
  - calculate how much interest this account has earned
  - calculate the new balance as the sum of the old balance and interest amount
  - update the balance of the account (`BankAccount::setBalance()`)
  - print to screen detailed information about how the account's balance has been changed, using the format:
  `   [Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date]`
    - use `writeCurrency()` and `writeInterest()` functions to help with the formatting
  - update the date when the interest has been added to `today`

- `write()` - a query that inserts into the stream received as parameter the content of the current instance
  **📌Parameters**:
  - `out` - an unmodifiable reference to an object of type `std::ostream`.

  **📌Return**:
  - the parameter

  **🔍Implementation**:
  - use `BankAccount::write()` to insert the inherited attributes
  - insert the remaining two attributes
  - the complete record should look like this:

    ```txt
    >> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date]
    ```

- `read()` - a mutator that reads data from the stream received as the first parameter and stores it in the current instance.
  **📌Parameters**:
  - `in` - an un-modifiable reference to an object of type `std::istream`

  **📌Return**:
  - the parameter

  **🔍Implementation**:
  - use `BankAccount::write()` to read the inherited attributes
  - use the extraction operator to read the remaining two attributes
  - the complete format should look like this:
    ```txt
    Name: [USER TYPES HERE]
    Opening Balance: [USER TYPES HERE]
    Date Opened (year month day): [USER TYPES HERE]
    Transit #: [USER TYPES HERE]
    Institution #: [USER TYPES HERE]
    Account #: [USER TYPES HERE]
    Interest Date (year month day): [USER TYPES HERE]
    Interest Rate: [USER TYPES HERE]
    ```
    Assume all data the user types is valid.


#### Free Helpers

- `operator>>()` - overload the extraction to read from a stream some data that is stored in a `SavingsAccount` object.
  **📌Parameters**:
  - `in` - a reference to an object of type `std::istream`
  - `account` - a reference to an object of type `SavingsAccount`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - call the function `SavingsAccount::read()`


- `operator<<()` - overload the insertion to insert an `SavingsAccount` object into the first parameter.

  **📌Parameters**:
  - `out` - a reference to an object of type `std::ostream`.
  - `account` - an un-modifiable reference to an object of type `SavingsAccount`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - call the function `SavingsAccount::write()`




### The `w7_p1` Module (Provided)

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

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and **the project milestones** and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- you were instructed to overload the insertion operator twice (for both classes `BankAccount` and `SavingsAccount`). Since the implementation was identical, why couldn't we just inherit it in the derived class? What would happen if we don't overload it for `SavingsAccount`? Would the program still work? Do an experiment and report your findings.
- in the derived class you needed to access the balance of the account in order to apply interest, but the balance attribute was private in the base class (hence, inaccessible in the derived class). How were you able to get access to the balance?  If you would make the attribute to be not private, the code would simplify a lot; do some research and explain why is bad practice to have non-private attributes.

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