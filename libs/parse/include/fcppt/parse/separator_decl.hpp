//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SEPARATOR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SEPARATOR_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/separator_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Parses a list of elements, delimited by a separator, e.g., a_1,...,a_n.
\ingroup fcpptparse

\a Inner is tried first. If this suceeds, this provides the first element r_1 of the result.
Then, \a Separator is tried, followed by \a Inner.
This is done as long as possible, giving the remaining elements r_2, ..., r_n of the result,
which are again taken from \a Inner.

Equivalent to:
\code
Inner >> *(Sep >> Inner)
\endcode

\tparam Sep A parser with result type unit.
*/
template <typename Inner, typename Sep>
class separator : private fcppt::parse::tag
{
public:
  separator(Inner &&, Sep &&);

  static_assert(std::is_same_v<fcppt::parse::result_of<Sep>, fcppt::unit>);

  using result_type = std::vector<fcppt::parse::result_of<Inner>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Inner inner_;

  Sep sep_;
};

FCPPT_PP_POP_WARNING

template <typename Inner, typename Sep>
separator(Inner &&, Sep &&) -> separator<
    std::remove_cvref_t<Inner>,
    std::remove_cvref_t<Sep>>;

}

#endif
