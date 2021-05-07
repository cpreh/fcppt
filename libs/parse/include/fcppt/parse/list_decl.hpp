//          Copyright Carl Philipp Reh 2009 - 2021.
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

/**
\brief Parses lists, e.g., [a_1,...,a_n].
\ingroup fcpptparse

A list parser consists of a start parser \a Start, an end parser \a End,
a separator parser \a Sep and an inner parser \a Inner.
The purpose of this parser is to parse lists like [a_1,...,a_n],
where Start recognizes '[', End recognizes ']', Sep recognizes ',' and Inner recognizes the a_i,
producing the results r_1, ..., r_n. The result of the list parser is then vector{r_1,...,r_n}.

This is implemented as follows:
The start parser is tried first and parses the beginning of the list.
Then, the end parser is tried, which parses the end of the list.
If this succeeds, the list is empty and the result is the empty vector.
Otherwise, the list is nonempty and the inner parser is tried.
If this succeeds, this provides the first element r_1 of the result.
Then, the separator parser is tried, followed by the inner parser.
This is done as long as possible, giving the remaining elements r_2, ..., r_n of the result,
which are again taken from the inner parser.
Lastly, the end parser is tried and if it succeeds, the result is <code>vector{r_1,...,r_n}</code>.

Equivalent to:
\code
Start >> (End | (fcppt::parse::separator{Inner,Sep} >> End))
\endcode

\tparam Start A parser with result type unit.
\tparam End A parser with result type unit.
\tparam Sep A parser with result type unit.
*/
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
    std::remove_cvref_t<Start>,
    std::remove_cvref_t<Inner>,
    std::remove_cvref_t<Sep>,
    std::remove_cvref_t<End>>;

}
}

#endif
