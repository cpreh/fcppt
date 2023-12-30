//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_OUTPUT_HPP_INCLUDED
#define FCPPT_MPL_LIST_OUTPUT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp> // IWYU pragma: keep
#include <fcppt/io/widen_string.hpp>
#include <fcppt/mpl/list/back.hpp>
#include <fcppt/mpl/list/empty.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/pop_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <typeinfo> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template <fcppt::mpl::list::object_concept List, typename Ch, typename Traits>
void print(std::basic_ostream<Ch, Traits>&)
requires fcppt::mpl::list::empty<List>::value
{
}

template <fcppt::mpl::list::object_concept List, typename Ch, typename Traits>
void print(std::basic_ostream<Ch, Traits> &_stream)
requires (!fcppt::mpl::list::empty<List>::value)
{
  auto const print_one{
    []<typename Type>(fcppt::tag<Type>, std::basic_ostream<Ch, Traits> &_inner_stream)
    {
      _inner_stream << fcppt::io::widen_string(fcppt::type_name_from_info(typeid(Type)));
    }
  };

  fcppt::algorithm::loop(
      fcppt::mpl::list::pop_back<List>{},
      [&_stream,&print_one]<typename Type>(fcppt::tag<Type> const _tag)
      {
        print_one(_tag, _stream);

        _stream << FCPPT_CHAR_LITERAL(Ch, ',');
      });

  print_one(fcppt::tag<fcppt::mpl::list::back<List>>{}, _stream);
}

}
/**
\brief Prints a list.
\ingroup fcpptmpl
Prints \a List to \a _stream. Every type in \a List will be converted to a
string using #fcppt::type_name.
*/
template <typename Ch, typename Traits, typename... Types>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::mpl::list::object<Types...> const &)
{
  _stream << FCPPT_CHAR_LITERAL(Ch, '(');

  fcppt::mpl::list::detail::print<fcppt::mpl::list::object<Types...>>(_stream);

  _stream << FCPPT_CHAR_LITERAL(Ch, ')');

  return _stream;
}
}

#endif
