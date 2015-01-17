//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_MAP_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_MAP_HPP_INCLUDED


namespace fcppt
{
namespace assign
{

/**
\brief Creates a map using <code>operator()</code> syntax.

This class is meant for convenient initialization of maps. Instead of taking
<code>Container::const_reference</code>, which must be created with
<code>std::make_pair(key, mapped)</code>, it takes the two arguments
separately.

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
		typename container_type::key_type &&,
		typename container_type::mapped_type &&
	);

	make_map(
		typename container_type::key_type const &,
		typename container_type::mapped_type const &
	);

	make_map &
	operator()(
		typename container_type::key_type &&,
		typename container_type::mapped_type &&
	);

	make_map &
	operator()(
		typename container_type::key_type const &,
		typename container_type::mapped_type const &
	);

	operator Container &&();

	container_type &&
	move_container();
private:
	Container container_;
};

}
}

#include <fcppt/assign/impl/make_map.hpp>

#endif
