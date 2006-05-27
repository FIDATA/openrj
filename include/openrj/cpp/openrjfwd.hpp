/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/openrjfwd.hpp
 *
 * Purpose: Forward declarations for the Open-RJ C++ mapping
 *
 * Created: 27th November 2004
 * Updated: 28th May 2006
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


/** \file openrj/cpp/openrjfwd.hpp
 *
 * \brief [C++ only] Forward declarations for the
 *  \link openrj::cpp Open-RJ/C++\endlink mapping.
 *
 * This file is useful for the case where you wish to implement your
 * components in terms of types of the openrj::cpp namespace, but do not
 * need to include the full definitions in order to define the
 * components.
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_HPP_OPENRJFWD
#define OPENRJ_INCL_OPENRJ_CPP_HPP_OPENRJFWD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_HPP_OPENRJFWD_MAJOR      1
# define OPENRJ_VER_OPENRJ_CPP_HPP_OPENRJFWD_MINOR      1
# define OPENRJ_VER_OPENRJ_CPP_HPP_OPENRJFWD_REVISION   1
# define OPENRJ_VER_OPENRJ_CPP_HPP_OPENRJFWD_EDIT       8
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
/// \brief The namespace of the Open-RJ/C++ mapping.
///
/// This contains the Field, Record, FileDatabase and MemoryDatabase classes,
/// along with the exception class DatabaseException
namespace cpp
{

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

class Field;
class Record;
class DatabaseBase;
class FileDatabase;
class MemoryDatabase;
class DatabaseException;

#ifndef OPENRJ_CPP_NO_OBSOLETE
typedef FileDatabase Database;
#endif /* !OPENRJ_CPP_NO_OBSOLETE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_HPP_OPENRJFWD */

/* ////////////////////////////////////////////////////////////////////////// */
