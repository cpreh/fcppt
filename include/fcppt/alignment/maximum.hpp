//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_MAXIMUM_HPP_INCLUDED
#define FCPPT_ALIGNMENT_MAXIMUM_HPP_INCLUDED

/// The maximum alignment supported
#ifdef _MSC_VER
#define FCPPT_ALIGNMENT_MAXIMUM 128
#elif __GNUC__
#define FCPPT_ALIGNMENT_MAXIMUM 32
#else
#error "Don't know what the maximum alignment should be!"
#endif

#endif
