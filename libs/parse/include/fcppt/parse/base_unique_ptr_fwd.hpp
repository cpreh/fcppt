//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED
#define FCPPT_PARSE_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/parse/base_fwd.hpp>

namespace fcppt
{
namespace parse
{
template <typename Result, typename Ch, typename Skipper>
using base_unique_ptr = fcppt::unique_ptr<fcppt::parse::base<Result, Ch, Skipper>>;

}
}

#endif
