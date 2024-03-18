#include <iostream>
#include <fstream>
#include <cstring>
#include "hotel.h"
#include "file.h"

using namespace std;

namespace seneca
{

    /// <summary>
    /// Sets the first name and last name of a guest.
    /// </summary>
    /// <param name="theGuest">the guest whose name must be set.</param>
    /// <param name="fName">the first name of the guest</param>
    /// <param name="lName">the last name of the guest</param>
    void setGuest(Guest &theGuest, const char *fName, const char *lName)
    {
        strcpy(theGuest.m_firstName, fName);
        strcpy(theGuest.m_lastName, lName);
    }

    void loadData(const char *fileName, Hotel &theHotel)
    {

        // 1. Open the file using file helper
        if (!seneca::openFile(fileName))
            return;

        // 2. Get number of rooms available for this hotel
        // and dynamically allocate it
        int numRooms = seneca::getRecordsCount();
        theHotel.m_rooms = new Room[numRooms];
        theHotel.m_cntRooms = numRooms;

        // 3. Looping each rooms to get detail
        for (int i = 0; i < numRooms; ++i)
            seneca::loadData(theHotel.m_rooms[i]);

        // 4. Closing file, so no memory losses
        seneca::closeFile();
    }

    /// <summary>
    /// Load from a file the information about a single room.
    /// </summary>
    /// <param name="theRoom">the object where to put data loaded from the file</param>
    void loadData(Room &theRoom)
    {
        // 1. Read room number
        theRoom.m_roomNumber = seneca::read(',');

        // 2. Read content till it found `\n`
        seneca::read(theRoom.m_maxCntGuests, '\n');

        // 3. Initializing rest as default values ( 0 and null pointer )
        theRoom.m_cntGuests = 0;
        theRoom.m_guests = nullptr;
    }

    /// <summary>
    /// Print to screen the details of the hotel.
    /// </summary>
    /// <param name="theHotel">the hotel whose details are to be printed.</param>
    void display(const Hotel &theHotel)
    {
        int standardRooms = 1, familyRooms = 1, suites = 1;

        // 1. Display standard rooms
        cout << "Standard Rooms:" << endl;
        for (int i = 0; i < theHotel.m_cntRooms; ++i)
        {
            if (theHotel.m_rooms[i].m_roomNumber[0] == 'A')
            {
                cout << standardRooms << ". ";
                display(theHotel.m_rooms[i]);
                standardRooms++;
                cout << endl;
            }
        }

        // 2. Display Family Rooms
        cout << "Family Rooms:" << endl;
        for (int i = 0; i < theHotel.m_cntRooms; ++i)
        {
            if (theHotel.m_rooms[i].m_roomNumber[0] == 'B')
            {
                cout << familyRooms << ". ";
                display(theHotel.m_rooms[i]);
                familyRooms++;
                cout << endl;
            }
        }

        // 3. Display Suites
        cout << "Suites:" << endl;
        for (int i = 0; i < theHotel.m_cntRooms; ++i)
        {
            if (theHotel.m_rooms[i].m_roomNumber[0] == 'C')
            {
                cout << suites << ". ";
                display(theHotel.m_rooms[i]);
                cout << endl;
                suites++;
            }
        }
    }

    /// <summary>
    /// Print to screen the details of a single room.
    /// </summary>
    /// <param name="theRoom">the room whose details are to be printed.</param>
    void display(const Room &theRoom)
    {
        // 1. show the data in format [ roomNumber ( guests / maxGuest ) ]
        cout << theRoom.m_roomNumber << " ("
             << theRoom.m_cntGuests << "/" << theRoom.m_maxCntGuests << ")";

        // 2. Show the comma separated guest if available
        if (theRoom.m_cntGuests > 0)
        {
            // this adds `: ` just before above data
            // i.e [ roomNumber ( guests / maxGuest ): guest1, guest2 ... ]
            cout << ": ";
            for (int i = 0; i < theRoom.m_cntGuests; ++i)
            {
                cout << theRoom.m_guests[i].m_firstName << " " << theRoom.m_guests[i].m_lastName;
                // don't includ comma after last guest
                if (i < theRoom.m_cntGuests - 1)
                    cout << ", ";
            }
        }
    }

    Room *findRoom(const Hotel &theHotel, const char *roomNumber)
    {

        // 1. Loop through all rooms in the hotel
        for (int i = 0; i < theHotel.m_cntRooms; ++i)
        {
            // 1.1. Compare the hotel's room number and provied room number
            if (strcmp(theHotel.m_rooms[i].m_roomNumber, roomNumber) == 0)
            {
                return &theHotel.m_rooms[i];
            }
        }

        // 2. Return null pointr if no result found
        return nullptr;
    }

    /// <summary>
    /// Add a guest to the room ONLY if the room capacity has not been reached.
    ///   If the room is already at capacity, this function does nothing.
    /// </summary>
    /// <param name="theRoom">the room where guests will be staying</param>
    /// <param name="theGuest">the gust that wants to stay in the room</param>
    void addGuest(Room &theRoom, const Guest &theGuest)
    {
        // 1. Check if total guest available is lesser than maximum guest
        if (theRoom.m_cntGuests < theRoom.m_maxCntGuests)
        {
            // 1.1 Dynamically generate new array of guests
            Guest *newGuests = new Guest[theRoom.m_cntGuests + 1];

            // 1.2 Memory to memory copy ( fastest and better )
            // Reference: https://en.cppreference.com/w/cpp/string/byte/memcpy
            // void* memcpy( void* dest, const void* src, std::size_t count );
            memcpy(newGuests, theRoom.m_guests, sizeof(Guest) * theRoom.m_cntGuests);

            // 1.3 insert the guest to the last of guest list
            newGuests[theRoom.m_cntGuests++] = theGuest;

            // 1.4 Delete the previosly allocated guests list
            delete[] theRoom.m_guests;

            // 1.5 Assign new lists as it sets the location
            theRoom.m_guests = newGuests;
        }
    }

    /// <summary>
    /// Deallocates all dynamic memory used by a `Hotel` object.
    /// </summary>
    /// <param name="theHotel">the object whose memory must be deallocated.</param>

    void deallocate(Hotel &theHotel)
    {
        // deallocate dynamic memory memory allocated, to prevent memory lossu
        for (int i = 0; i < theHotel.m_cntRooms; ++i)
        {
            delete[] theHotel.m_rooms[i].m_roomNumber;
            delete[] theHotel.m_rooms[i].m_guests;
        }
        delete[] theHotel.m_rooms;
    }

} // namespace seneca