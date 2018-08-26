//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DUPLICATE_NAMES_HPP_INCLUDED
#define FCPPT_OPTIONS_DUPLICATE_NAMES_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/duplicate_names_fwd.hpp>
#include <fcppt/options/exception.hpp>


namespace fcppt
{
namespace options
{

class duplicate_names
:
	public fcppt::options::exception
{
public:
	explicit
	duplicate_names(
		fcppt::string &&
	);
};

}
}

#include <fcppt/options/impl/duplicate_names.hpp>

#endif
