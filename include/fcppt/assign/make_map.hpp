//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_MAP_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_MAP_HPP_INCLUDED

#include <fcppt/assign/make_container.hpp>


namespace fcppt
{
namespace assign
{

/**
\brief Creates a map using <code>operator()</code> syntax

This class is a convenience wrapper over fcppt::assign::make_container for
maps. Instead of taking <code>Container::const_reference</code>, which must be
created with <code>std::make_pair(key, mapped)</code>, it takes the two
arguments separately.

\ingroup fcpptassign
*/
template<
	typename Container
>
class make_map
{
public:
	typedef Container container_type;

	make_map(
		typename container_type::key_type const &,
		typename container_type::mapped_type const &
	);

	make_map &
	operator()(
		typename container_type::key_type const &,
		typename container_type::mapped_type const &
	);

	operator Container() const;

	container_type const &
	container() const;
private:
	typedef fcppt::assign::make_container<
		Container
	> assign_container_type;

	assign_container_type assign_container_;
};

}
}

#include <fcppt/assign/impl/make_map.hpp>

#endif
