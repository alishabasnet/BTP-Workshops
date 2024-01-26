// TODO: add header guard and include any file that is necessary in this module.

// TODO: put all entities you create in `seneca` namespace.  Create and add the member functions
//           as described in the comments below.

	const char* const INVALID_REASON__PLATE = "Received bad value for license plate.";
	const char* const INVALID_REASON__MODEL = "Received bad value for car model.";
	const char* const INVALID_REASON__DESC = "Received bad value for problem description.";
	const char* const INVALID_REASON__EMPTY = "Object not initialized.";
	const char* const VALID_OBJECT = "The object contains valid data and can be used.";

	/// <summary>
	/// A class that represents a `Car` object that requires service from
	///     an AutoService.
	/// </summary>
	class Car
	{
		/// <summary>
		/// A statically-allocated C-style array of characters containing
		///     the license plate number of the car.
		/// </summary>
		char m_licencePlate[9];
		/// <summary>
		/// A dynamically-allocated C-style array of characters containing
		///     the make/model of the car.
		/// </summary>
		char* m_makeModel;
		/// <summary>
		/// A dynamically-allocated C-style array of characters containing
		///     a description of the problem as reported by the customer.
		/// </summary>
		char* m_problemDesc;
		/// <summary>
		/// An estimation of the cost to repair the problem reported by a customer.
		/// </summary>
		double m_cost;

		/// <summary>
		/// A C-style string with a descriptive text if the object contains
		///     good data and can be used, or the reason why data was not accepted.
		/// 
		/// This attribute will contain the value of one of the global variables:
		/// INVALID_REASON__PLATE
		/// INVALID_REASON__MODEL
		/// INVALID_REASON__DESC 
		/// INVALID_REASON__EMPTY
		/// VALID_OBJECT
		/// 
		/// This is not a dynamically-allocated string and doesn't require deallocation.
		/// </summary>
		const char* m_objectStatus;
	public:
		/// <summary>
		/// Check if the `Car` object contains valid data and can be used.
		/// </summary>
		/// <returns>`true` if the object contains valid data; `false` otherwise.</returns>
		/* TODO: add the prototype of the `isEmpty` QUERY that receives no parameters
		*         and returns a Boolean value. Implement it in the cpp file as described below.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* isEmpty()
		* - return `true` if the attribute `m_makeModel` is null; `false` otherwise.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/






		/// <summary>
		/// Sets the object into an empty state.  The object is not valid anymore and should
		///     not be used until it receives valid data.
		/// </summary>
		/* TODO: add the prototype of the `setEmpty` MODIFIER that receives no parameters
		*         and returns nothing. Implement it in the cpp file as described below.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* setEmpty()
		* - set the plate number (`m_licencePlate`) to empty string
		* - set the model/make of the car (`m_makeModel`) and the description of the
		*       problem (`m_problemDesc`) to null
		* - set the repair cost (`m_cost`) to zero
		* - set object status (`m_objectStatus`) to `INVALID_REASON__EMPTY`
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/






		/// <summary>
		/// Copies the values of the parameters into the attributes.  If at least one of the
		///     parameters is not valid, this function sets the object into an empty state
		///     and records the reason why the object could not accept the values received.
		/// 
		/// This function will validate the parameters before accepting them: the strings
		///     are considered valid if they have at least one character (they are not null
		///     and not empty).
		/// </summary>
		/// <param name="plateNo">an array of characters with the plate number of the car</param>
		/// <param name="model">an array of characters with the make/model of the car</param>
		/// <param name="desc">an array of characters with the description of the problem
		///     the car has</param>
		/// <param name="serviceCost">an estimation of the repair cost of the problem reported
		///     by a customer.</param>
		/* TODO: add the prototype of the `set` MODIFIER that receives as parameters:
		*        - the address to an un-modifiable C-string representing the plate number
		*        - the address to an un-modifiable C-string representing the model/make of the car
		*        - the address to an un-modifiable C-string representing a description of the
		*              problem as reported by the customer.
		*        - a floating point number in double precision representing the estimated cost
		*              of repairs/fixes.
		*        This function return nothing. Implement it in the cpp file as described below.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* set()
		* - call `Car::deallocateMemory()` to release any dynamic memory in use by this object.
		* - validate the parameters (the order is important to set appropriate status message):
		*       - if the plate number parameter is null or contains the address of an empty
		*             string, set `m_objectStatus` to `INVALID_REASON__PLATE`
		*       - else if the model/make parameter is null or contains the address of an empty
		*             string, set `m_objectStatus` to `INVALID_REASON__MODEL`
		*       - else if the problem description parameter is null or contains the address
		*             of an empty string, set `m_objectStatus` to `INVALID_REASON__DESC`
		*       - if all parameters are good, then:
		*             - copy with `std::strncpy()` the plate number into `m_licencePlate`.
		*                   See that `m_licencePlate` can accept at most 8+1 characters
		*                   so we must ensure that we do not copy more than that and the null
		*                   is set appropriately at the end.
		*             - allocate dynamic memory for C-string able to store the make/model
		*                   received as parameter; copy with `std::strcpy()` the parameter into
		*                   this dynamic array; store the address of this array in `m_makeModel`
		*             - allocate dynamic memory for C-string able to store the problem description
		*                   received as parameter; copy with `std::strcpy()` the parameter into
		*                   this dynamic array; store the address of this array in `m_problemDesc`
		*             - copy the cost parameter into `m_cost`
		*             - set `m_objectStatus` to `VALID_OBJECT`
		*
		* Documentation to read:
		* - `std::strcpy`    - https://en.cppreference.com/w/c/string/byte/strcpy
		* - `std::strncpy`   - https://en.cppreference.com/w/c/string/byte/strncpy
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/






		/// <summary>
		/// Prints to screen the content of the object.
		/// 
		/// If the object is valid, prints the data in the format:
		/// `| PLATE(8) | MODEL(20) | PROBLEM_DESCRIPTION(40) | COST(8) |`
		/// 
		/// If the object is not valid, prints to screen:
		/// `| REASON_WHY_INVALID(85) |`
		/// 
		/// The numbers in brackets represent the size of the field for printed value.
		/// 
		/// This function has no side-effects: the function will restore any changes to
		///     formatting options to their original values (as they were before the
		///     function is called).
		/// </summary>
		/* TODO: add the prototype of the `display` QUERY that receives no parameters
		*         and returns nothing. Implement it in the cpp file as described below.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* display()
		* - store in a local variable the current filling character and the precision
		* - if the object is valid, then
		*       - print the `m_licencePlate`, `m_makeModel`, `m_problemDesc`, and `m_cost`.
		* 
		*         See the sample output for hints on alignment, filling character,
		*             and precision. The field width for each attribute is specified in
		*             the description above.
		* 
		*         When you change a formatting option with `ostream::setf(...)`, you must
		*             remove it with `ostream::unsetf(...)` when you are done.
		* - if the object is not valid, then
		*       - print the `m_objectStatus`.
		* - restore the filling character and precision to the original values.
		* 
		* Documentation to read (also in the course notes):
		* - `std::ostream::fill()`       - https://en.cppreference.com/w/cpp/io/basic_ios/fill
		* - `std::ostream::width()`      - https://en.cppreference.com/w/cpp/io/ios_base/width
		* - `std::ostream::precision()`  - https://en.cppreference.com/w/cpp/io/ios_base/precision
		* - `std::ostream::setf()`       - https://en.cppreference.com/w/cpp/io/ios_base/setf
		* - `std::ostream::unsetf()`     - https://en.cppreference.com/w/cpp/io/ios_base/unsetf
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/






		/// <summary>
		/// Deallocates all the dynamic memory used by the object, and set the object
		///   to an empty state.
		/// </summary>
		/* TODO: add the prototype of the `deallocateMemory` MODIFIER that receives no parameters
		*         and returns nothing. Implement it in the cpp file as described below.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* deallocateMemory()
		* - deallocate the memory used by make/model array (`m_makeModel`) and the problem
		*       description array (`m_problemDesc`)
		* - call the `Car::setEmpty()` function to set the object in an empty state.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		
	};
