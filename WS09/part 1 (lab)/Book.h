#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "LibraryItem.h"

namespace seneca
{

    class Book : public LibraryItem
    {
    private:
        char *m_author;

    public:
        /// <summary>
        /// Default constructor.
        /// </summary>
        Book();

        /// <summary>
        /// Parameterized constructor.
        /// </summary>
        /// <param name="title">The title of the book.</param>
        /// <param name="year">The year of publication of the book.</param>
        /// <param name="author">The author of the book.</param>
        Book(const char *title, int year, const char *author);

        /// <summary>
        /// Copy constructor.
        /// </summary>
        Book(const Book &other);

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~Book();

        /// <summary>
        /// Copy assignment operator.
        /// </summary>
        Book &operator=(const Book &other);

        /// <summary>
        /// Displays the details of the book.
        /// </summary>
        /// <param name="ostr">The output stream where the details are to be displayed.</param>
        /// <returns>A reference to the output stream.</returns>
        virtual std::ostream &display(std::ostream &ostr = std::cout) const override;

        /// <summary>
        /// Checks if the current book's author is lexicographically greater than the other book's author.
        /// </summary>
        /// <param name="other">The other book to compare with.</param>
        /// <returns>True if the current book's author is greater, false otherwise.</returns>
        bool operator>(const Book &other) const;
    };

} // namespace seneca

#endif // SENECA_BOOK_H
