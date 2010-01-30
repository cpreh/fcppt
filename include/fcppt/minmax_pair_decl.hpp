//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED

#include <fcppt/minmax_pair_fwd.hpp>

namespace fcppt
{

template<
	typename T
>
class minmax_pair
{
public:
	minmax_pair(
		T const &min,
		T const &max
	);

	T min() const;

	T max() const;

	void
	min(
		T const &
	);

	void
	max(
		T const &
	);
private:
	void check();

	T
		min_,
		max_;
};

}

#endif
