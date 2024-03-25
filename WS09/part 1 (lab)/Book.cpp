#include "Book.h"
#include <cstring>

namespace seneca
{

    Book::Book(const char *title, int year, const char *author) : LibraryItem(title, year)
    {
        if (author != nullptr)
        {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
        else
        {
            m_author = nullptr;
        }
    }

    Book::Book(const Book &other) : LibraryItem(other)
    {
        if (other.m_author != nullptr)
        {
            m_author = new char[strlen(other.m_author) + 1];
            strcpy(m_author, other.m_author);
        }
        else
        {
            m_author = nullptr;
        }
    }

    Book::~Book()
    {
        delete[] m_author;
        m_author = nullptr;
    }

    Book &Book::operator=(const Book &other)
    {
        if (this != &other)
        {
            LibraryItem::operator=(other);
            delete[] m_author;
            if (other.m_author != nullptr)
            {
                m_author = new char[strlen(other.m_author) + 1];
                strcpy(m_author, other.m_author);
            }
            else
            {
                m_author = nullptr;
            }
        }
        return *this;
    }

    std::ostream &Book::display(std::ostream &ostr) const
    {
        LibraryItem::display(ostr);
        ostr << std::endl;
        if (m_author != nullptr)
        {
            ostr << "Author: " << m_author;
        }
        else
        {
            ostr << "Author: [Unknown]";
        }
        return ostr;
    }

    bool Book::operator>(const Book &other) const
    {
        if (m_author != nullptr && other.m_author != nullptr)
        {
            return strcmp(m_author, other.m_author) > 0;
        }
        return false;
    }

} // namespace seneca
