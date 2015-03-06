//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_OUTPUT_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_OUTPUT_ITERATOR_HPP_INCLUDED

#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if an iterator is an output iterator

\ingroup fcppttypetraits

Checks if \a Iterator is an output iterator.

\tparam Iterator Must be an iterator type
*/
template<
	typename Iterator
>
using is_output_iterator
=
fcppt::type_traits::is_iterator_of_category<
	Iterator,
	std::output_iterator_tag
>;

}
}

#endif
