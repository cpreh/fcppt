//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYSTEM_OPTIONAL_ERROR_CODE_FWD_HPP_INCLUDED
#define FCPPT_SYSTEM_OPTIONAL_ERROR_CODE_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace system
{

/**
\brief An optional error code

\ingroup fcpptsystem
*/
typedef
fcppt::optional::object<
	boost::system::error_code
>
optional_error_code;

}
}

#endif
