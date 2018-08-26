//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_OPTIONAL_BUFFER_FWD_HPP_INCLUDED
#define FCPPT_IO_OPTIONAL_BUFFER_FWD_HPP_INCLUDED

#include <fcppt/io/buffer_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{
namespace io
{

typedef
fcppt::optional::object<
	fcppt::io::buffer
>
optional_buffer;

}
}

#endif
