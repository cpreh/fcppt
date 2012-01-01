//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_DECL_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_DECL_HPP_INCLUDED

#include <fcppt/homogenous_pair_fwd.hpp>

namespace fcppt
{

/// Like <code>%std::pair</code>, but both elements are of the same type
template
<
	typename T
>
class homogenous_pair
{
public:
	typedef T value_type;

	typedef T first_type;

	typedef T second_type;

	value_type first;
	value_type second;

	explicit
	homogenous_pair();

	explicit
	homogenous_pair(
		value_type const &_first,
		value_type const &_second
	);

	void
	swap(
		homogenous_pair &
	);
};

template
<
	typename T
>
bool
operator<(
	homogenous_pair<T> const &,
	homogenous_pair<T> const &
);

template
<
	typename T
>
bool
operator==(
	homogenous_pair<T> const &,
	homogenous_pair<T> const &
);

template
<
	typename T
>
bool
operator!=(
	homogenous_pair<T> const &,
	homogenous_pair<T> const &
);

template
<
	typename T
>
void
swap(
	homogenous_pair<T> &,
	homogenous_pair<T> &
);

}

#endif
