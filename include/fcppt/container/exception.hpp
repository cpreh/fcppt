//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_EXCEPTION_HPP_INCLUDED
#define FCPPT_CONTAINER_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace container
{

class FCPPT_CLASS_SYMBOL exception : public fcppt::exception {
public:
	FCPPT_SYMBOL explicit exception(
		fcppt::string const &);
};

}
}

#endif
