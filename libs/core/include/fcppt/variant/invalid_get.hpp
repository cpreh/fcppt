//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED
#define FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/variant/exception.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Thrown by \link fcppt::variant::get_exn\endlink.

\ingroup fcpptvariant
*/
class invalid_get
:
	public fcppt::variant::exception
{
public:
	explicit
	invalid_get(
		fcppt::string const &
	);
};

}
}

#include <fcppt/variant/impl/invalid_get.hpp>

#endif
