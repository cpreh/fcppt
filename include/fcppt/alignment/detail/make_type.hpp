//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_DETAIL_MAKE_TYPE_HPP_INCLUDED
#define FCPPT_ALIGNMENT_DETAIL_MAKE_TYPE_HPP_INCLUDED

#include <fcppt/alignment/align.hpp>
#include <fcppt/alignment/size_type.hpp>
#include <fcppt/config.hpp>
#if !defined(FCPPT_ALIGN_TEMPLATE_PARAMETERS)
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/repetition/for.hpp>
#include <fcppt/config/external_end.hpp>
#endif

namespace fcppt
{
namespace alignment
{
namespace detail
{

/// \cond FCPPT_DOXYGEN_DEBUG
#if !defined(FCPPT_ALIGN_TEMPLATE_PARAMETERS)
/// \endcond
template<
	typename T,
	size_type Alignment
>
struct make_type;

/// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_ALIGNMENT_DETAIL_GENERATE(r, state)\
template<\
	typename T\
>\
struct make_type<\
	T,\
	state\
>\
{\
	typedef FCPPT_ALIGNMENT_ALIGN(state) T type;\
};

#define FCPPT_ALIGNMENT_DETAIL_MAXIMUM 128

#define FCPPT_ALIGNMENT_DETAIL_GENERATE_END(r, state)\
	BOOST_PP_LESS_EQUAL(\
		state,\
		FCPPT_ALIGNMENT_DETAIL_MAXIMUM\
	)

#define FCPPT_ALIGNMENT_DETAIL_GENERATE_ADD(r, state)\
	BOOST_PP_MUL(state, 2)

BOOST_PP_FOR(
	1,
	FCPPT_ALIGNMENT_DETAIL_GENERATE_END,
	FCPPT_ALIGNMENT_DETAIL_GENERATE_ADD,
	FCPPT_ALIGNMENT_DETAIL_GENERATE
)

#undef FCPPT_ALIGNMENT_DETAIL_GENERATE_ADD
#undef FCPPT_ALIGNMENT_DETAIL_GENERATE_END
#undef FCPPT_ALIGNMENT_DETAIL_MAXIMUM
#undef FCPPT_ALIGNMENT_DETAIL_GENERATE
#else
template<
	typename T,
	size_type Alignment
>
struct make_type
{
	typedef T FCPPT_ALIGNMENT_ALIGN(Alignment) type;
};
#endif
/// \endcond

}
}
}

#endif
