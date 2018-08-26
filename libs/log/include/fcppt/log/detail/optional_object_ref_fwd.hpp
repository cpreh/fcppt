//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

/**
\brief An optional logger object

\ingroup fcpptlog
*/
typedef
fcppt::optional::reference<
	fcppt::log::object
>
optional_object_ref;

}
}
}

#endif
