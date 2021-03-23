//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_MAKE_CHAR_LITERALS_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_CHAR_LITERALS_HPP_INCLUDED


#define FCPPT_DETAIL_MAKE_CHAR_LITERALS(tuple_type,func,_literal) \
  tuple_type{func(_literal), func(L##_literal), func(u##_literal), func(U##_literal)}

#endif
