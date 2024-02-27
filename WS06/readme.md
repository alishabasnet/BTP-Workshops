# Workshop #6: Classes and resources, IO operators

In this workshop, you will learn to make classes and resources, following the "[the rule of 3](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming))" for safe copying. You'll also practice simple file handling using **ifstream** and **ofstream**.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create copy constructors
- define and create a copy assignment operator
- do simple file IO using `ifstream` and `ofstream`



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

In part one of the workshop, you will create an application that loads from file a collection of emails and shows them to the user (for simplicity, we consider that an email will only contain information about the sender, the subject, and the date when it was received).  To accomplish this, you will create a custom type named `Email` that stores information about a single email, and a custom type named `Inbox` that will contain a collection of emails.

This part of the workshop has three modules:

- `email` - represents a single email (you must fully implement this module in `*.h`/`*.cpp` files)
- `inbox` - represents a collection of emails that a person has received (you must fully implement this module in `*.h`/`*.cpp` files)
- `w6_p1` - which contains the `main()` function (already provided, do not change it)

The data that will be processed by your application will be loaded from the provided files (`emails_monday.csv` and `emails_misc.csv`). The files are text files in *coma-separated-values* format; each line from the input file contains information about a single email:

  ```txt
  SENDER_EMAIL_ADDRESS,SENDER_NAME,EMAIL_SUBJECT,RECEIVED_DATE<endl>
  ```

The `RECEIVED_DATE` field has the format `YYYY-MM-DD HH:MM:SS`.


### The `email` Module

Design and implement a class named `Email` that stores information about a single email that a person has received. For simplicity, you class will store only some information about an email (the sender's name, the sender's email address, the email subject, and the date when the email was received). Also for simplicity, only the subject of the email will be stored in a **dynamically-allocated* array of characters; all other information will be stored in statically-allocated memory.  The class will not expose the data to clients and validate the parameters before storing them into the attributes.  The client will interact with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `Email` will store the following information:

- `m_fromName` - as a statically allocated array of 100 characters representing the name of the person who sent the email.
- `m_fromAddress` - as a statically allocated array of 100 characters representing the email address of the person who sent the email.
- `m_dateReceived` - as a statically allocated array of 20 characters representing the date and time when the email has been received. The date and time field will have the format `YYYY-MM-DD HH:MM:SS`.
- `m_subject` - as a pointer to a dynamically allocated array of characters that represents the subject of the email. **This is a resource that your code must manage it!**

#### Public Members

The class `Email` will provide to clients the following public functions:

- a default constructor that sets the current instance into an empty state

- a copy constructor (calls the copy assignment operator to do the copying)

- a copy-assignment operator (follow the steps as shown in the course notes)

- a destructor

- `load()` - a modifier that loads data from an input stream and stores it into the current instance. The data existing in the stream will contain the information about an email with the fields separated by comma, using the format: `FROM_ADDRESS,FROM_NAME,SUBJECT,DATE` (in this order).

    **📌Parameters**:
    - `in` - a reference to an object of type `std::istream`

    **📌Return**:
    - `true` if data was successfully loaded; `false` otherwise

    **🔍Implementation**:
    - create a local variable named `buffer` as an array of 1000 characters.
    - call the function `std::istream::getline()` four times to extract from the parameter the address, the sender's name, the email subject, and the date. Store the extracted data into `m_fromAddress`, `m_fromName`, `buffer`, and `m_dateReceived` respectively.
    - if the input stream is in a good state (check using `std::istream::good()`), then the data was successfully read -- deallocate the memory used by `m_subject`, allocate new memory sufficient to store the content of the `buffer`, and copy what subject from the `buffer`.
    - if the input stream has encountered an error during the extraction, set the current instance to an empty state.



#### Friend Helpers

- `operator<<()` - overload the insertion to insert an `Email` object into the first parameter.

  **📌Parameters**:
  - `out` - a reference to an output stream
  - `email` - an un-modifiable reference to an object of type `Email`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - if the second parameter is not in an empty state, then insert the email object into the first parameter using the following format: `SENDER_NAME(20)  SENDER_EMAIL_ADDRESS(40)  THE_RECEIVED_TIME(15)  EMAIL_SUBJECT<endl>`.
    - the numbers in the brackets represent the width of each field
    - the sender address and the time fields should be aligned to the left
    - the fields are separated by **exactly** two spaces
    - insert a new line at the end
    - note that you should not print the entire date when the email was received, but only the hours:minutes:seconds (i.e., the content of the attribute `m_dateReceived` starting from index `?` -- see the format above of the date).





### The `inbox` Module

Design and implement a class named `Inbox` that manages a collection of objects of type `Email` of undetermined size.  The class will not expose the data to clients and validate the parameters before storing them into the attributes.  The client will interact with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `Inbox` will store the following information:

- `m_emails` - the address of a dynamically allocated array of objects of type `Email`. **This is a resource that your code must manage it!**
- `m_cntEmails` - the number of objects in the array pointed by `m_emails`.


#### Public Members

The class `Inbox` will provide to clients the following public functions:

- a default constructor that sets the current instance into an empty state

- a copy constructor (calls the copy assignment operator to do the copying)

- a copy-assignment operator (follow the steps as shown in the course notes)

- a destructor

- `operator+=()` - a modifier that adds to the inbox one more email

  **📌Parameters**:
  - `email` - an un-modifiable reference to an object of type `Email` to be added to the inbox

  **📌Return**:
  - a reference to the current instance

  **🔍Implementation**:
  - resize the array whose address is stored in `m_emails` and add the parameter at the end



- `operator+()` - a query that creates a new `Inbox` object (a copy of the current instance) and adds to it the email received as a parameter

  **📌Parameters**:
  - `email` - an un-modifiable reference to an object of type `Email` to be added

  **📌Return**:
  - an object of type `Inbox`

  **🔍Implementation**:
  - create a local object of type `Inbox` using the copy constructor
  - add to this local object the email received as parameter (use `Inbox::operator+=()`)
  - return the local object



- `void load()` - a modifier that loads a collection of emails from a file and adds them to the current instance (resize the array if necessary)

  **📌Parameters**:
  - `filename` - the address of an unmodifiable array of characters with the file name containing the emails

  **📌Return**:
  - nothing

  **🔍Implementation**:
  - if the parameter is null, this function does nothing
  - open the file for reading
  - if the file is successfully open, in a loop:
    - create an object of type `Email`
    - load a single email from file, using the function `Email::load()`
    - add the loaded email to the current instance using `Inbox::operator+=`; if no email could be loaded, stop the loop
  - close the file



- `void save()` - a query that saves into the file all the emails stored in the inbox

  **📌Parameters**:
  - `filename` - the address of an unmodifiable array of characters with the file name where to save the content of the inbox

  **📌Return**:
  - nothing

  **🔍Implementation**:
  - if the parameter is null, this function does nothing
  - open the file for writing
  - if the file is successfully open, iterate over the collection of emails stored and insert each one into the file (use the insertion operator you overloaded in the `email` module)
  - close the file



#### Friend Helpers

- `operator<<()` - overload the insertion to insert an `Inbox` object into the first parameter.

  **📌Parameters**:
  - `out` - a reference to an output stream
  - `inbox` - an un-modifiable reference to an object of type `Inbox`.

  **📌Return**:
  - the first parameter

  **🔍Implementation**:
  - iterate over the collection of emails stored and insert each one into the first parameter




### The `w6_p1` Module (Provided)

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

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- explain what happens if the copy-assignment operator does not check for self-assignment (do an experiment, report your findings, and explain the result)
- the instructions above said that the copy-constructor should call the copy assignment-operator to do the actual copy. Do some research and explain why this method is preferred and why the copy-constructor should not do the copy by itself.

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