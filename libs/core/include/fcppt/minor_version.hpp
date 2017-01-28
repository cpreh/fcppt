//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINOR_VERSION_HPP_INCLUDED
#define FCPPT_MINOR_VERSION_HPP_INCLUDED

#include <fcppt/version.hpp>
#include <fcppt/version_integral_c.hpp>


namespace fcppt
{

/**
\brief fcppt's minor version
\ingroup fcpptvarious
*/
typedef fcppt::version_integral_c<
	(FCPPT_VERSION / 1000) % 1000
> minor_version;

}

#endif
