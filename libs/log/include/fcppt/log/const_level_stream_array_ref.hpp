//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONST_LEVEL_STREAM_ARRAY_REF_HPP_INCLUDED
#define FCPPT_LOG_CONST_LEVEL_STREAM_ARRAY_REF_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/log/level_stream_array_fwd.hpp>


namespace fcppt
{
namespace log
{

typedef
fcppt::reference<
	fcppt::log::level_stream_array const
>
const_level_stream_array_ref;

}
}

#endif
