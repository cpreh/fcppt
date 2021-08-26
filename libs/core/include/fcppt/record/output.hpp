//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_OUTPUT_HPP_INCLUDED
#define FCPPT_RECORD_OUTPUT_HPP_INCLUDED

#include <fcppt/output.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/indices.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Outputs a record to a stream

\ingroup fcpptrecord
*/
template <typename Ch, typename Traits, typename... Elements>
std::basic_ostream<Ch, Traits> &operator<<(
    std::basic_ostream<Ch, Traits> &_stream, fcppt::record::object<Elements...> const &_record)
{
  _stream << _stream.widen('{');

  using element_list = fcppt::record::element_vector<fcppt::record::object<Elements...>>;
  fcppt::algorithm::loop(
      fcppt::mpl::list::indices<element_list>{},
      [&_stream, &_record]<std::size_t Index>(fcppt::tag<fcppt::mpl::size_type<Index>>)
      {
        using label = fcppt::record::element_to_label<
            fcppt::mpl::list::at<element_list, fcppt::mpl::size_type<Index>>>;

        _stream << fcppt::io::widen_string(fcppt::record::label_name<label>())
                << fcppt::io::widen_string(" = ");
        fcppt::output(_stream, fcppt::record::get<label>(_record));
        if constexpr (Index != fcppt::mpl::list::size<element_list>::value - 1U)
        {
          _stream << fcppt::io::widen_string(", ");
        }
      });

  return _stream << _stream.widen('}');
}

}
}

#endif
