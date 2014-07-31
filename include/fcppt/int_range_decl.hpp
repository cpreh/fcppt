//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INT_RANGE_DECL_HPP_INCLUDED
#define FCPPT_INT_RANGE_DECL_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>


namespace fcppt
{

template<
	typename Int
>
class int_range
{
public:
	typedef
	fcppt::int_iterator<
		Int
	>
	iterator;

	typedef
	iterator
	const_iterator;

	int_range(
		Int begin,
		Int end
	);

	iterator
	begin() const;

	iterator
	end() const;
private:
	Int begin_;

	Int end_;
};

}

#endif
