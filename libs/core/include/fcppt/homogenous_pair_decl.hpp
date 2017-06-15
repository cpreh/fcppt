//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_DECL_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_DECL_HPP_INCLUDED

#include <fcppt/homogenous_pair_fwd.hpp>


namespace fcppt
{

/**
\brief A pair like <code>%std::pair</code> with both elements of the same type

\ingroup fcpptvarious

A homogenous pair of type <code>T</code> is like an
<code>%std::pair<T,T></code>. A short example:
\snippet homogenous_pair.cpp homogenous_pair

\tparam T Can be any type
*/
template<
	typename T
>
class homogenous_pair
{
public:
	/**
	\brief The value type
	*/
	typedef T value_type;

	typedef T first_type;

	typedef T second_type;

	/**
	\brief The first element
	*/
	value_type first;

	/**
	\brief The second element
	*/
	value_type second;

	/**
	\brief Initializes a pair

	Initializes the pair with the values provided by \a first and \a
	second.

	\param first The value for the first member

	\param second The value for the second member
	*/
	homogenous_pair(
		value_type const &first,
		value_type const &second
	);

	/**
	\brief Initializes a pair by moving
	*/
	homogenous_pair(
		value_type &&first,
		value_type &&second
	);

	/**
	\brief Swaps two pairs

	Swaps this pair with \a other. Swaps <code>this->first</code> with
	<code>other.first</code> and <code>this->second</code> with
	<code>other.second</code>.

	\param other The pair to swap with
	*/
	void
	swap(
		homogenous_pair &other
	);
};

/**
\brief Free function for swapping pairs

Calls <code>left.swap(right)</code>

\param left The first pair to swap

\param right The second pair to swap
*/
template<
	typename T
>
void
swap(
	fcppt::homogenous_pair<
		T
	> &left,
	fcppt::homogenous_pair<
		T
	> &right
);

}

#endif
