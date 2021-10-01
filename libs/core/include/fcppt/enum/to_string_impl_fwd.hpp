//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STRING_IMPL_FWD_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_IMPL_FWD_HPP_INCLUDED

namespace fcppt::enum_
{
/**
\brief Customization point for #fcppt::enum_::to_string.
\ingroup fcpptenum

A specialization of this class should contain a static member function
<code>std::string_view get(Enum)</code>.
*/
template <typename Enum, typename Enable = void>
struct to_string_impl;

}

#endif
