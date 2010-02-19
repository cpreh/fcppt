//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED

/// Pragma macro, the same as #pragma
/** This can be used to wrap pragma inside other macros
*/
#if defined(_MSC_VER)
#define FCPPT_PP_PRAGMA(x) __pragma(x)
#elif defined(__GNUC__)
#define FCPPT_PP_PRAGMA(x) _Pragma(#x)
#endif

#endif
