//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_ITERATOR_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/iterator/range_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Iterator
>
fcppt::iterator::range<
	Iterator
>::range(
	Iterator _begin,
	Iterator _end
)
:
	begin_{
		std::move(
			_begin
		)
	},
	end_{
		std::move(
			_end
		)
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
