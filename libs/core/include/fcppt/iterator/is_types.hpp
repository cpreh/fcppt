//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_IS_TYPES_HPP_INCLUDED
#define FCPPT_ITERATOR_IS_TYPES_HPP_INCLUDED

#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Type
>
struct is_types
:
std::false_type
{
};

template<
	typename Derived,
	typename ValueType,
	typename Reference,
	typename DifferenceType,
	typename IteratorCategory
>
struct is_types<
	fcppt::iterator::types<
		Derived,
		ValueType,
		Reference,
		DifferenceType,
		IteratorCategory
	>
>
:
std::true_type
{
};

}
}

#endif
