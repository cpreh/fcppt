//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_OPTIONAL_SIZE_FWD_HPP_INCLUDED
#define FCPPT_FILESYSTEM_OPTIONAL_SIZE_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

typedef
fcppt::optional::object<
	std::uintmax_t
>
optional_size;

}
}

#endif
