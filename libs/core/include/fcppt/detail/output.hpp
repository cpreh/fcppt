//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_OUTPUT_HPP_INCLUDED
#define FCPPT_DETAIL_OUTPUT_HPP_INCLUDED

#include <fcppt/output_impl.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::detail
{
template <typename Type>
class output
{
public:
  explicit output(fcppt::reference<Type const> const _value) : value_{_value} {}

  [[nodiscard]] Type const &value() const { return this->value_.get(); }
private:
  fcppt::reference<Type const> value_;
};

template <typename Type, typename Ch, typename Traits>
inline std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::detail::output<Type> const &_output)
{
  fcppt::output_impl<Type>::execute(_stream, _output.value());

  return _stream;
}
}

#endif
