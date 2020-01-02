//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MOVE_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_MOVE_RANGE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/move_range_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief A range that moves its elements

\ingroup fcpptcontainer

\tparam Container A container type.
*/
template<
	typename Container
>
class move_range
{
	FCPPT_NONCOPYABLE(
		move_range
	);
public:
	explicit
	move_range(
		Container &&
	);

	move_range(
		move_range &&
	);

	move_range &
	operator=(
		move_range &&
	);

	~move_range();

	typedef
	std::move_iterator<
		typename
		Container::iterator
	>
	iterator;

	typedef
	typename
	Container::const_iterator
	const_iterator;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;
private:
	Container container_;
};

}
}

#endif
