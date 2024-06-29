//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/enum/array_init.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/default_stream.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/standard_level_stream.hpp>

fcppt::log::level_stream_array fcppt::log::default_level_streams()
{
  return fcppt::enum_::array_init<fcppt::log::level_stream_array>(
      [](fcppt::log::level const _level)
      {
        return fcppt::unique_ptr_to_base<fcppt::log::level_stream>(
            fcppt::make_unique_ptr<fcppt::log::standard_level_stream>(
                fcppt::log::default_stream(_level), _level));
      });
}
