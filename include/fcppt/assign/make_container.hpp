//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED

namespace fcppt
{
namespace assign
{

/**
 * \brief Creates a container using <code>operator()</code> syntax
 * \ingroup fcpptassign
 * \details
 * Example:
 * \snippet doc/assign.cpp make_container
 */
template<
	typename Container
>
class make_container
{
public:
	typedef Container container_type;

	explicit
	make_container(
		typename container_type::const_reference
	);

	make_container &
	operator()(
		typename container_type::const_reference
	);

	operator Container() const;

	container_type const &
	container() const;
private:
	container_type container_;
};

}
}

#include <fcppt/assign/impl/make_container.hpp>

#endif
