//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINOR_VERSION_HPP_INCLUDED
#define FCPPT_MINOR_VERSION_HPP_INCLUDED

#include <fcppt/version_int.hpp>
#include <fcppt/version.hpp>

namespace fcppt
{

version_int const minor_version(
	(FCPPT_VERSION / 1000) % 1000
);

}

#endif
