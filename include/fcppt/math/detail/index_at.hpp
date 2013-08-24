//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Iterator,
	typename SizeType
>
typename std::iterator_traits<
	Iterator
>::reference
index_at(
	Iterator const _iterator,
	SizeType const _size
)
{
	return
		*(
			_iterator
			+
			fcppt::cast::size<
				typename std::iterator_traits<
					Iterator
				>::difference_type
			>(
				fcppt::cast::to_signed(
					_size
				)
			)
		);
}

}
}
}

#endif
