//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/container/buffer/read_from_opt.hpp>
#include <fcppt/container/buffer/to_raw_vector.hpp>
#include <fcppt/io/buffer.hpp>
#include <fcppt/io/optional_buffer.hpp>
#include <fcppt/io/read_chars.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <ios>
#include <istream>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::io::optional_buffer fcppt::io::read_chars(std::istream &_stream, std::size_t const _count)
{
  return fcppt::optional::map(
      fcppt::container::buffer::read_from_opt<
          fcppt::container::buffer::object<fcppt::io::buffer::value_type>>(
          _count,
          [&_stream](
              fcppt::io::buffer::pointer const _data, fcppt::io::buffer::size_type const _size) {
            return fcppt::optional::make_if(
                _stream
                    .read(_data, fcppt::cast::size<std::streamsize>(fcppt::cast::to_signed(_size)))
                    .good(),
                [&_stream] {
                  return fcppt::cast::size<fcppt::io::buffer::size_type>(
                      fcppt::cast::to_unsigned(_stream.gcount()));
                });
          }),
      [](fcppt::container::buffer::object<fcppt::io::buffer::value_type> &&_buffer) {
        return fcppt::container::buffer::to_raw_vector(std::move(_buffer));
      });
}
