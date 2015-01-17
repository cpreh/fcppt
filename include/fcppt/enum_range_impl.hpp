//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/enum_iterator_impl.hpp>
#include <fcppt/enum_range_decl.hpp>


template<
	typename Enum
>
fcppt::enum_range<
	Enum
>::enum_range(
	size_type const _begin,
	size_type const _end
)
:
	begin_{
		_begin
	},
	end_{
		_end
	}
{
}

template<
	typename Enum
>
typename
fcppt::enum_range<
	Enum
>::iterator
fcppt::enum_range<
	Enum
>::begin() const
{
	return
		iterator(
			begin_
		);
}

template<
	typename Enum
>
typename
fcppt::enum_range<
	Enum
>::iterator
fcppt::enum_range<
	Enum
>::end() const
{
	return
		iterator(
			end_
		);
}

#endif
