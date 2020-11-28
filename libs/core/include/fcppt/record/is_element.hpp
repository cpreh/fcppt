//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_IS_ELEMENT_HPP_INCLUDED
#define FCPPT_RECORD_IS_ELEMENT_HPP_INCLUDED

#include <fcppt/record/element_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Tests if a type is an #fcppt::record::element.

\ingroup fcpptrecord
*/
template <typename>
struct is_element : std::false_type
{
};

template <typename Type, typename Tag>
struct is_element<fcppt::record::element<Type, Tag>> : std::true_type
{
};

}
}

#endif
