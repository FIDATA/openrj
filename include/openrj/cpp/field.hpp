/* /////////////////////////////////////////////////////////////////////////////
 * File:    field.hpp
 *
 * Purpose: Field class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
 * Updated: 18th February 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* \file openrj/cpp/field.hpp This is the root file of the Open-RJ C-API
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_H_FIELD
#define OPENRJ_INCL_OPENRJ_CPP_H_FIELD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_MAJOR    1
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_MINOR    2
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_REVISION 3
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_EDIT     8
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>

#include <stlsoft_shim_string.h>
#include <stlsoft_string_access.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
namespace cpp
{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief This class represents a field in a record in the database
class Field
{
/// \name Construction
/// @{
public:
    Field(ORJField const *field)
        : m_field(field)
    {}

    /// Default constructor
    Field()
        : m_field(NULL)
    {}
    /// Copy constructor
    Field(Field const &rhs)
        : m_field(rhs.m_field)
    {}

    /// Copy assignment operator
    Field &operator =(Field const &rhs)
    {
        m_field = rhs.m_field;

        return *this;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns the name of the field
    char const *GetName() const
    {
        ORJString const *name;

        ORJ_Field_GetNameA(m_field, &name);

        return name->ptr;
    }
    /// \brief Returns the value of the field
    char const *GetValue() const
    {
        ORJString const *value;

        ORJ_Field_GetValueA(m_field, &value);

        return value->ptr;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Provides access to the underlying field pointer
    ORJField const  *GetField() const
    {
        return m_field;
    }
    /// \brief Provides access to the field's record, in the form of its
    /// underlying field pointer
    ORJRecord const *GetRecord() const
    {
        openrj_assert(NULL != m_field);

        return ORJ_Field_GetRecordA(m_field);
    }
/// @}

// Members
private:
    ORJField const *m_field;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline ::stlsoft::basic_shim_string<char> c_str_ptr(Field const &f)
{
    ORJField const                      *pf =   f.GetField();
    size_t                              cch =   pf->name.len + 1 + pf->value.len;
    ::stlsoft::basic_shim_string<char>  ss(cch);

    if(cch < ss.size())
    {
        char    *s  =   ss.data();

        strncpy(s, pf->name.ptr, pf->name.len);
        s += pf->name.len;
        *s++ = '=';
        strncpy(s, pf->value.ptr, pf->value.len);
    }

    return ss;
}

template <class S>
inline S &operator <<(S &s, Field const &field)
{
    s << field.GetName() << "=" << field.GetValue();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

namespace stlsoft
{
    using ::openrj::cpp::c_str_ptr;
}

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_FIELD */

/* ////////////////////////////////////////////////////////////////////////// */
