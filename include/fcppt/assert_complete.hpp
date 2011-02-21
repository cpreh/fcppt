//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_COMPLETE_HPP_INCLUDED
#define FCPPT_ASSERT_COMPLETE_HPP_INCLUDED

/// Assert at compile time that a type is complete
#define FCPPT_ASSERT_COMPLETE(type)\
static_cast<void>(sizeof(type))

#endif
