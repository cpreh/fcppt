//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_STREAM_DECL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_STREAM_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/parse/basic_stream_decl.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/parse/detail/stream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch>
class stream : public fcppt::parse::basic_stream<Ch>
{
  FCPPT_NONMOVABLE(stream);

public:
  using impl_ref = fcppt::reference<std::basic_istream<Ch>>;

  explicit stream(impl_ref);

  ~stream() override;

  [[nodiscard]] fcppt::optional::object<Ch> get_char() override;

  [[nodiscard]] fcppt::parse::position<Ch> get_position() const override;

  void set_position(fcppt::parse::position<Ch> const &) override;

private:
  impl_ref const impl_;

  fcppt::parse::location location_;
};

}

#endif
