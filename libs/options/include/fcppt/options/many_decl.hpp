//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/many_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A parser for zero or more elements.

\ingroup fcpptoptions

Wraps a parser such that it may apply zero or more times. The result type is a
record that adds one layer of <code>std::vector</code> to the elements of the
result type of \a Parser.

\see fcppt::options::make_many
*/
template <typename Parser>
class many
{
public:
  explicit many(Parser &&);

  using result_type = fcppt::record::map_elements<
      fcppt::options::result_of<Parser>,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<std::vector>,
          fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_type>, fcppt::mpl::arg<1>>>>;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::options::usage usage() const;

private:
  Parser parser_;
};

FCPPT_PP_POP_WARNING

}

#endif
