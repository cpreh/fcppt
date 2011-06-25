//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_ASSERT_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_ASSERT_TYPE_HPP_INCLUDED

#define FCPPT_VARIANT_DETAIL_ASSERT_TYPE(\
	types,\
	other,\
	elements\
)\
BOOST_STATIC_ASSERT((\
	fcppt::variant::detail::index_of<\
		types,\
		other\
	>::value\
	< elements\
))

#endif
