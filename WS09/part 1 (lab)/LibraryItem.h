#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H

#include <iostream>

namespace seneca {

    class LibraryItem {
    private:
        char* m_title;
        int m_year;
    public:
        /// <summary>
        /// Default constructor.
        /// </summary>
        LibraryItem();
        
        /// <summary>
        /// Parameterized constructor.
        /// </summary>
        /// <param name="title">The title of the library item.</param>
        /// <param name="year">The year of publication of the library item.</param>
        LibraryItem(const char* title, int year);
        
        /// <summary>
        /// Copy constructor.
        /// </summary>
        LibraryItem(const LibraryItem& other);
        
        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~LibraryItem(); 

        /// <summary>
        /// Copy assignment operator.
        /// </summary>
        LibraryItem& operator=(const LibraryItem& other);

        /// <summary>
        /// Displays the details of the library item.
        /// </summary>
        /// <param name="ostr">The output stream where the details are to be displayed.</param>
        /// <returns>A reference to the output stream.</returns>
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    };

} // namespace seneca


#endif // SENECA_LIBRARYITEM_H
