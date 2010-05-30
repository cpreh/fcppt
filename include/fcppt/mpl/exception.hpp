//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_MPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace mpl
{

/// The exception thrown by some mpl operations
class exception
:
	public fcppt::exception
{
public:
	explicit exception(
		fcppt::string const &
	);
};

}
}

#include <fcppt/mpl/impl/exception.hpp>

#endif
