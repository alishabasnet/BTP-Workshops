#include "LibraryItem.h"
#include <cstring>

namespace seneca
{

    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char *title, int year) : m_year(year)
    {
        if (title != nullptr)
        {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        else
        {
            m_title = nullptr;
        }
    }

    LibraryItem::LibraryItem(const LibraryItem &other) : m_year(other.m_year)
    {
        if (other.m_title != nullptr)
        {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        else
        {
            m_title = nullptr;
        }
    }

    LibraryItem::~LibraryItem()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    LibraryItem &LibraryItem::operator=(const LibraryItem &other)
    {
        if (this != &other)
        {
            delete[] m_title;
            if (other.m_title != nullptr)
            {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else
            {
                m_title = nullptr;
            }
            m_year = other.m_year;
        }
        return *this;
    }

    std::ostream &LibraryItem::display(std::ostream &ostr) const
    {
        if (m_title != nullptr)
        {
            ostr << "Title: " << m_title << " (" << m_year << ")";
        }
        else
        {
            ostr << "Title: [Unknown] (" << m_year << ")";
        }
        return ostr;
    }

} // namespace seneca
