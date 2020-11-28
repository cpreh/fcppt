//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IS_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_IS_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Tests if a type is an #fcppt::unique_ptr.

\ingroup fcpptsmartptr
*/
template <typename Type>
struct is_unique_ptr : std::false_type
{
};

template <typename Type, typename Deleter>
struct is_unique_ptr<fcppt::unique_ptr<Type, Deleter>> : std::true_type
{
};

}

#endif
