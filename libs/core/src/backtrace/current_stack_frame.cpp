//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/backtrace/current_stack_frame.hpp>
#include <fcppt/backtrace/stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/impl/private_config.hpp>
#if defined(FCPPT_HAVE_BACKTRACE)
#include <fcppt/c_deleter.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <execinfo.h>
#include <fcppt/config/external_end.hpp>
#endif

fcppt::backtrace::stack_frame
fcppt::backtrace::current_stack_frame(fcppt::backtrace::stack_limit const &
#if defined(FCPPT_HAVE_BACKTRACE)
                                          max
#endif
)
{
#if defined(FCPPT_HAVE_BACKTRACE)
  using element_type = void *;

  using symbol_sequence = fcppt::container::buffer::object<element_type>;

  symbol_sequence const symbols{fcppt::container::buffer::read_from<symbol_sequence>(
      fcppt::cast::size<symbol_sequence::size_type>(max.get()),
      [](symbol_sequence::pointer const _data, symbol_sequence::size_type const _size) {
        return fcppt::cast::to_unsigned(
            ::backtrace(_data, fcppt::cast::size<int>(fcppt::cast::to_signed(_size))));
      })};

  fcppt::unique_ptr<char *, fcppt::c_deleter> const raw_symbols{::backtrace_symbols(
      symbols.read_data(), fcppt::cast::size<int>(fcppt::cast::to_signed(symbols.read_size())))};

  return fcppt::algorithm::map<fcppt::backtrace::stack_frame>(
      fcppt::iterator::make_range(
          raw_symbols.get_pointer(), raw_symbols.get_pointer() + symbols.read_size()),
      [](char const *const _symbol) { return fcppt::from_std_string(_symbol); });
#else
  return fcppt::backtrace::stack_frame();
#endif
}
