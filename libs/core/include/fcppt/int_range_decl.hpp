//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INT_RANGE_DECL_HPP_INCLUDED
#define FCPPT_INT_RANGE_DECL_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>
#include <fcppt/type_iso/undecorated_type.hpp>


namespace fcppt
{

/**
\brief A forward range over integers

\ingroup fcpptvarious
*/
template<
	typename Int
>
class int_range
{
public:
	typedef
	Int
	value_type;

	typedef
	fcppt::int_iterator<
		Int
	>
	iterator;

	typedef
	iterator
	const_iterator;

	typedef
	fcppt::type_iso::undecorated_type<
		Int
	>
	size_type;

	/**
	\brief Creates a range

	If end < begin the range will be empty.

	\param begin The first element in the range

	\param end The element one past the end
	*/
	constexpr
	int_range(
		Int begin,
		Int end
	);

	constexpr
	iterator
	begin() const;

	constexpr
	iterator
	end() const;

	constexpr
	size_type
	size() const;
private:
	Int begin_;

	Int end_;
};

}

#endif
