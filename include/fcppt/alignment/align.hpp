//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_ALIGN_HPP_INCLUDED
#define FCPPT_ALIGNMENT_ALIGN_HPP_INCLUDED

/// Forces the specified alignment on a declaration in byes
#ifdef _MSC_VER
#define FCPPT_ALIGNMENT_ALIGN(x) __declspec(align(x))
#elif __GNUC__
#define FCPPT_ALIGNMENT_ALIGN(x) __attribute__((__aligned__(x)))
#else
#error "Don't know how to align types!"
#endif

#endif
