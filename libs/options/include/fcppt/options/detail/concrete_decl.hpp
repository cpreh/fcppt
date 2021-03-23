//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_CONCRETE_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CONCRETE_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/base_decl.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/concrete_fwd.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
template <typename Result, typename Parser>
class concrete : public fcppt::options::base<Result>
{
  using base_type = fcppt::options::base<Result>;

public:
  FCPPT_NONMOVABLE(concrete);

  explicit concrete(Parser &&);

  ~concrete() override;

  using result_type = Result;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const override;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const override;

  [[nodiscard]] fcppt::options::option_name_set option_names() const override;

  [[nodiscard]] fcppt::string usage() const override;

private:
  Parser const parser_;
};

}
}
}

#endif
