/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/field.hpp
 *
 * Purpose: Field class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
 * Updated: 14th July 2006
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/** \file openrj/cpp/field.hpp
 *
 * [C++ only] Definition of the openrj::cpp::Field class.
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_H_FIELD
#define OPENRJ_INCL_OPENRJ_CPP_H_FIELD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_MAJOR    1
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_MINOR    4
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_REVISION 3
# define OPENRJ_VER_OPENRJ_CPP_H_FIELD_EDIT     16
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>

#include <stlsoft/string/shim_string.hpp>
#include <stlsoft/shims/access/string.hpp>

#include <string.h>

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
/// \name Types
/// @{
public:
    typedef Field   class_type;
/// @}

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
    Field(class_type const &rhs)
        : m_field(rhs.m_field)
    {}

    /// Copy assignment operator
    class_type &operator =(class_type const &rhs)
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

/// \name Comparison
/// @{
public:
    bool IsEqual(class_type const &rhs) const
    {
        return 0 == strcmp(GetName(), rhs.GetName()) && 0 == strcmp(GetValue(), rhs.GetValue());
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
 * Operators
 */

/// \brief Evaluates to true if the two instances have identical names and values
inline bool operator ==(Field const &lhs, Field const &rhs)
{
    return lhs.IsEqual(rhs);
}

/// \brief Evaluates to true if the two instances have different names and/or values
inline bool operator !=(Field const &lhs, Field const &rhs)
{
    return !lhs.IsEqual(rhs);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// \brief String access shim providing, possibly NULL, C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline ::stlsoft::basic_shim_string<char, true> c_str_ptr_null(Field const &f)
{
    ORJField const                              *pf =   f.GetField();
    size_t                                      cch =   pf->name.len + 1 + pf->value.len;
    ::stlsoft::basic_shim_string<char, true>    ss(cch);

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

/// \brief String access shim providing C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
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

/// \brief String access shim providing (potentially non-nul-terminated) C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline ::stlsoft::basic_shim_string<char> c_str_data(Field const &f)
{
    return c_str_ptr(f);
}

/// \brief String attribute shim providing the length of the C-string form of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline size_t c_str_len(Field const &f)
{
    ORJField const  *pf =   f.GetField();

    return pf->name.len + 1 + pf->value.len;
}

/// \brief Stream insertion shim for a Field instance
///
/// \ingroup group_openrj_streaminsertionshimfunctiontemplates
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
    using ::openrj::cpp::c_str_ptr_null;
    using ::openrj::cpp::c_str_ptr;
    using ::openrj::cpp::c_str_data;
    using ::openrj::cpp::c_str_len;
}

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_FIELD */

/* ////////////////////////////////////////////////////////////////////////// */
