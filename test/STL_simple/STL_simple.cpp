/* /////////////////////////////////////////////////////////////////////////////
 * File:        STL_simple.cpp
 *
 * Purpose:     C++ test program for the Open-RJ/STL (the STL mapping of the
 *              Open-RJ library). This program uses the memory_database class
 *              and attempts to be a smallest-possible informative example.
 *
 * Created:     24th May 2005
 * Updated:     25th May 2005
 *
 * www:         http://www.openrj.org/
 *
 * Thanks:      To Rajiv Bhagwat for pointing out that the test programs left
 *              much to be desired in terms of discoverability.
 *
 * License:     Copyright 2005, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2005
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* Open-RJ Header Files */
#include <openrj/stl/database.hpp>

/* Standard C++ Library Files */
#include <iostream>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

using std::cerr;
using std::endl;
using std::cout;

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

// Sample database
static const char   contents[] =

    "%% Sample Open-RJ database - Cats and Dogs\n"
    "%% Created:   28th September 2004\n"
    "%% Updated:   29th September 2004\n"
    "Name:      Barney\n"
    "Species:   Dog\n"
    "Breed:     Bijon \\\n"
    "           Frieze\n"
    "%%\n"
    "Name:      Elsa\n"
    "Species:   Dog\n"
    "Breed:     Mixed\n"
    "%%\n"
    "Name:      Fluffy Kitten\n"
    "Species:   Cat\n"
    "%%\n"
    "Name:      Moet\n"
    "Species:   Dog\n"
    "Breed:     Boxer\n"
    "%%\n"
    "Name:      Rebel\n"
    "Species:   Dog\n"
    "Breed:     German \\\n"
    "           Shepherd\n"
    "%%\n"
    "Name:      Pepper\n"
    "Species:   Dog\n"
    "Breed:     Border Collie\n"
    "%%\n"
    "Name:      Samson\n"
    "Species:   Dog\n"
    "Breed:     Ridgeback\n"
    "%%\n"
    "Name:      Sheltie\n"
    "Species:   Dog\n"
    "Breed:     Shetland \\\n"
    "           Sheepdog\n"
    "%%\n"
    "Name:      Sparky\n"
    "Species:   Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char * /* argv */[])
{
    try
    {
        // 1. Create a database instance on memory, so use memory_database

        unsigned                        flags   =   0;  // No special flags here.
        openrj::stl::memory_database    db(&contents[0], sizeof(contents), flags);

        // 2. Display database characteristics

        cout << endl << "2. Display database characteristics:" << endl;

        cout    << "Database has " 
                << db.num_lines() << " lines in " 
                << db.num_fields() << " fields in "
                << db.num_records() << " records"
                << endl;

        // 3. Enumerate the contents using subscript operators

        cout << endl << "3. Enumerate records and their fields using subscript operators:" << endl;

        { for(size_t iRecord = 0; iRecord < db.size(); ++iRecord)
        {
            openrj::stl::record record(db[iRecord]);

            cout    << "record-#" << iRecord
                    << " " << record.comment() << " "
                    << " (" << db.size() << " fields)"
                    << endl;

            for(size_t iField = 0; iField < record.size(); ++iField)
            {
                openrj::stl::field  field(record[iField]);
                std::string         name    =   field.name();
                std::string         value   =   field.value();

                cout << "  field-#" << iField << ": " << field << endl;
            }
        }}

        // 4. Enumerate the contents using begin()/end() methods

        cout << endl << "4. Enumerate records and their fields using begin()/end() methods:" << endl;

        openrj::stl::database_base::const_iterator   begin   =   db.begin();
        openrj::stl::database_base::const_iterator   end     =   db.end();

        { for(; begin != end; ++begin)
        {
            openrj::stl::record record(*begin);

            cout    << "record"
                    << " " << record.comment() << " "
                    << " (of " << db.size() << " fields)"
                    << endl;

            openrj::stl::record::const_iterator begin   =   record.begin();
            openrj::stl::record::const_iterator end     =   record.end();

            for(; begin != end; ++begin)
            {
                openrj::stl::field  field(*begin);
                std::string         name    =   field.name();
                std::string         value   =   field.value();

                // VC++ 6.0 and earlier don't do the insertion operator properly
#if !defined(__STLSOFT_COMPILER_IS_MSVC) || \
_MSC_VER > 1200
                cout << "  field" << " " << field << endl;
#else /* ? compiler */
                cout << "  field" << " " << stlsoft::c_str_ptr(field) << endl;
#endif /* compiler */
            }
        }}

#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS // Not all compilers support this, so ...
        // 5. Enumerate all the fields of the database en bloc

        cout << endl << "5. Enumerate all the fields of the database en bloc:" << endl;

        cout << endl << "All fields:" << endl;
        std::copy(db.fields_begin(), db.fields_end(), std::ostream_iterator<openrj::stl::field>(std::cout, "\n"));
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */

#if 0
        // 6. Carry out some name lookups
            if(record.has_field("Name"))
            {
                openrj::stl::string_t   value       =   record["Name"];

                cout << "This record has a \"Name\" field, whose value is " << value << endl;

                size_t                  numNames    =   record.count_fields("Name");

                STLSOFT_SUPPRESS_UNUSED(numNames);
            }
#endif /* 0 */


    }
    catch(std::exception &x)
    {
        cerr << "Failed to open database: " << x.what() << endl;
    }

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
