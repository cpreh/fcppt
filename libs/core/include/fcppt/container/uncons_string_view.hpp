//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_UNCONS_STRING_VIEW_HPP_INCLUDED
#define FCPPT_CONTAINER_UNCONS_STRING_VIEW_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{

/**
\brief Splits a string_view into its head and tail.

\ingroup fcpptcontainer
*/
template <typename Ch, typename Traits>
fcppt::optional::object<fcppt::tuple::object<Ch, std::basic_string_view<Ch, Traits>>>
uncons_string_view(std::basic_string_view<Ch, Traits> const _view)
{
  return fcppt::optional::make_if(
      fcppt::not_(_view.empty()),
      [_view]
      {
        return fcppt::tuple::make(
            _view.front(),
            [_view]
            {
              std::basic_string_view<Ch, Traits> shrunk{_view};
              shrunk.remove_prefix(1);
              return std::move(shrunk);
            }());
      });
};
}

#endif
