//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_SIZE_TO_SIZE_T_HPP_INCLUDED
#define FCPPT_FILESYSTEM_SIZE_TO_SIZE_T_HPP_INCLUDED

#include <fcppt/optional_size_t.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::optional_size_t
size_to_size_t(
	boost::uintmax_t
);

}
}

#endif
