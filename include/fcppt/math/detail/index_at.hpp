//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/container/to_reference_type.hpp>
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
	typename Storage,
	typename SizeType
>
inline
fcppt::container::to_reference_type<
	Storage
>
index_at(
	Storage &_storage,
	SizeType const _size
)
{
	return
		*(
			_storage.begin()
			+
			fcppt::cast::size<
				typename
				std::iterator_traits<
					fcppt::container::to_iterator_type<
						Storage
					>
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
