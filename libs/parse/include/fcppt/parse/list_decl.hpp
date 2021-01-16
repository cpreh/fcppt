//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LIST_DECL_HPP_INCLUDED
#define FCPPT_PARSE_LIST_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/list_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/separator_decl.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

template <typename Start, typename Inner, typename Sep, typename End>
class list : private fcppt::parse::tag
{
public:
  list(Start &&, Inner &&, Sep &&, End &&);

  static_assert(std::is_same_v<fcppt::parse::result_of<Start>, fcppt::unit>);

  static_assert(std::is_same_v<fcppt::parse::result_of<Sep>, fcppt::unit>);

  static_assert(std::is_same_v<fcppt::parse::result_of<End>, fcppt::unit>);

  using result_type = std::vector<fcppt::parse::result_of<Inner>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Start start_;

  fcppt::parse::separator<Inner, Sep> separator_;

  End end_;
};

FCPPT_PP_POP_WARNING

template <typename Start, typename Inner, typename Sep, typename End>
list(Start &&, Inner &&, Sep &&, End &&) -> list<
    fcppt::type_traits::remove_cv_ref_t<Start>,
    fcppt::type_traits::remove_cv_ref_t<Inner>,
    fcppt::type_traits::remove_cv_ref_t<Sep>,
    fcppt::type_traits::remove_cv_ref_t<End>>;

}
}

#endif
