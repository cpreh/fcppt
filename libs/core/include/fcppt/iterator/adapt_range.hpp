//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_ADAPT_RANGE_HPP_INCLUDED
#define FCPPT_ITERATOR_ADAPT_RANGE_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/iterator/range_impl.hpp>
#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>


namespace fcppt
{
namespace iterator
{

/**
\brief Turns a range into an #fcppt::iterator::range.

\ingroup fcpptiterator
*/
template<
	typename Range
>
inline
fcppt::iterator::range<
	fcppt::container::to_iterator_type<
		Range
	>
>
adapt_range(
	Range &_range
)
{
	return
		fcppt::iterator::range<
			fcppt::container::to_iterator_type<
				Range
			>
		>{
			fcppt::range::begin(
				_range
			),
			fcppt::range::end(
				_range
			)
		};
}

}
}

#endif
