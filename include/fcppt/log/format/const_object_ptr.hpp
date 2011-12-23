//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CONST_OBJECT_PTR_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CONST_OBJECT_PTR_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/log/format/object_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

typedef fcppt::shared_ptr<
	fcppt::log::format::object const
> const_object_ptr;

}
}
}

#endif
