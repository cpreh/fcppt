//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/time/std_time.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

fcppt::optional::object<std::time_t> fcppt::time::std_time()
{
  std::time_t const ret{std::time(nullptr)};

  return fcppt::optional::make_if(ret != fcppt::literal<std::time_t>(-1), fcppt::const_(ret));
}
