//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/enum/array_map.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/default_level_streams_impl.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/standard_level_stream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::log::level_stream_array fcppt::log::default_level_streams()
{
  return fcppt::enum_::array_map(
      fcppt::log::default_level_streams_impl(),
      [](fcppt::unique_ptr<fcppt::log::standard_level_stream> &&_elem)
          -> fcppt::unique_ptr<fcppt::log::level_stream>
      { return fcppt::unique_ptr_to_base<fcppt::log::level_stream>(std::move(_elem)); });
}
