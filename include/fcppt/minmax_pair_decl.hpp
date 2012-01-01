//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED

#include <fcppt/homogenous_pair_decl.hpp>
#include <fcppt/minmax_pair_fwd.hpp>


namespace fcppt
{

/// A homogenous pair that asserts that its first element is always less or equal to the second
/**
 * If the invariant is violated, fcppt::invalid_min_max_pair will be thrown.
*/
template<
	typename T
>
class minmax_pair
{
public:
	typedef T value_type;

	typedef fcppt::homogenous_pair<
		T
	> pair_type;

	minmax_pair(
		T const &min,
		T const &max
	);

	T
	min() const;

	T
	max() const;

	pair_type const
	pair() const;

	void
	min(
		T const &
	);

	void
	max(
		T const &
	);

	void
	pair(
		pair_type const &
	);

	void
	swap(
		minmax_pair &
	);
private:
	void
	check();

	pair_type impl_;
};

template
<
	typename T
>
void
swap(
	minmax_pair<T> &,
	minmax_pair<T> &
);

}

#endif
