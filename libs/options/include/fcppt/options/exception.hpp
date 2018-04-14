//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONS_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/exception_fwd.hpp>


namespace fcppt
{
namespace options
{

class exception
:
	public fcppt::exception
{
public:
	explicit
	exception(
		fcppt::string &&
	);
};

}
}

#include <fcppt/options/impl/exception.hpp>

#endif
