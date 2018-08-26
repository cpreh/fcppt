//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_ITERATOR_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/iterator/range_decl.hpp>


template<
	typename Iterator
>
fcppt::iterator::range<
	Iterator
>::range(
	Iterator const _begin,
	Iterator const _end
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
	typename Iterator
>
Iterator
fcppt::iterator::range<
	Iterator
>::begin() const
{
	return
		begin_;
}

template<
	typename Iterator
>
Iterator
fcppt::iterator::range<
	Iterator
>::end() const
{
	return
		end_;
}

#endif
