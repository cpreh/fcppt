//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CHAR_LITERAL_HPP_INCLUDED
#define FCPPT_CHAR_LITERAL_HPP_INCLUDED

#include <fcppt/identity.hpp> // IWYU pragma: keep
#include <fcppt/detail/char_literal.hpp> // IWYU pragma: keep
#include <fcppt/detail/char_types.hpp> // IWYU pragma: keep
#include <fcppt/detail/make_char_literals.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/as_tuple.hpp> // IWYU pragma: keep

/**
\brief A char or wchar_t literal depending on a type.

\ingroup fcpptvarious

If \a _type is char, then the literal will be of type <code>char</code>.
If \a _type is wchar_t, then the literal will be of type <code>wchar_t</code>.

\param _type Must be char or wchar_t.
\param _literal Must be a char literal.
*/
#define FCPPT_CHAR_LITERAL(_type, _literal) \
  fcppt::detail::char_literal<_type>(FCPPT_DETAIL_MAKE_CHAR_LITERALS( \
      fcppt::mpl::list::as_tuple<fcppt::detail::char_types>, fcppt::identity{}, _literal))

#endif
