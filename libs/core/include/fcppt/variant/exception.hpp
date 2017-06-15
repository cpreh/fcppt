//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_EXCEPTION_HPP_INCLUDED
#define FCPPT_VARIANT_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/exception.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief The base exception class for variant exceptions

\ingroup fcpptvariant
*/
class exception
:
	public fcppt::exception
{
public:
	explicit
	exception(
		fcppt::string const &
	);
};

}
}

#include <fcppt/variant/impl/exception.hpp>

#endif
