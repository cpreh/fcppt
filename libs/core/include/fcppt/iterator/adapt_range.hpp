//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_ADAPT_RANGE_HPP_INCLUDED
#define FCPPT_ITERATOR_ADAPT_RANGE_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/iterator/range_impl.hpp>


namespace fcppt
{
namespace iterator
{

/**
\brief Turns a range into an \link fcppt::iterator::range\endlink.

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
			_range.begin(),
			_range.end()
		};
}

}
}

#endif
