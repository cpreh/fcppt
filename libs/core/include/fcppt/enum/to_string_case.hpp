//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STRING_CASE_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_CASE_HPP_INCLUDED

/**
\brief Generates a case for the implementation of #fcppt::enum_::to_string_impl.
\ingroup fcpptenum
*/
#define FCPPT_ENUM_TO_STRING_CASE(type,name) case type::name: return #name

#endif
