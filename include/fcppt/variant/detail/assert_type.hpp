//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_ASSERT_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_ASSERT_TYPE_HPP_INCLUDED

#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


#define FCPPT_VARIANT_DETAIL_ASSERT_TYPE(\
	types,\
	other,\
	elements\
)\
static_assert((\
	::fcppt::variant::detail::index_of<\
		types,\
		typename std::remove_reference<\
			other\
		>::type\
	>::value\
	< elements\
	),\
	"Invalid type given to a variant"\
)

#endif
