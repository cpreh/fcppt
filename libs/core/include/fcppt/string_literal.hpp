//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRING_LITERAL_HPP_INCLUDED
#define FCPPT_STRING_LITERAL_HPP_INCLUDED

#include <fcppt/detail/make_char_literals.hpp>
#include <fcppt/detail/string_literal.hpp>
#include <fcppt/detail/string_types.hpp>
#include <fcppt/mpl/list/as_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

/**
\brief A char or wchar_t string literal depending on a type.

\ingroup fcpptvarious

If \a _type is char, then the literal will be of type <code>char const *</code>.
If \a _type is wchar_t, then the literal will be of type <code>wchar_t const *</code>.

\param _type Must be char or wchar_t.
\param _literal Must be a string literal.
*/
#define FCPPT_STRING_LITERAL(_type, _literal) \
  fcppt::detail::string_literal<_type>(FCPPT_DETAIL_MAKE_CHAR_LITERALS( \
      fcppt::mpl::list::as_tuple<fcppt::detail::string_types>, std::data, _literal))

#endif
