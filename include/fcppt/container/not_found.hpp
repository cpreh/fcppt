//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_NOT_FOUND_HPP_INCLUDED
#define FCPPT_CONTAINER_NOT_FOUND_HPP_INCLUDED

#include <fcppt/container/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>

namespace fcppt
{
namespace container
{

class FCPPT_CLASS_SYMBOL not_found
:
	public exception
{
public:
	FCPPT_SYMBOL explicit not_found(
		fcppt::string const &
	);
};

}
}

#endif
