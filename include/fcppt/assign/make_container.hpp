//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED

namespace fcppt
{
namespace assign
{

/// Creates a container using operator() syntax
template<
	typename Container
>
class make_container
{
public:
	typedef Container container_type;

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
	container_type c_;
};

}
}

#include <fcppt/assign/detail/make_container_impl.hpp>

#endif
