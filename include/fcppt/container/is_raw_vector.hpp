//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IS_RAW_VECTOR_HPP_INCLUDED
#define FCPPT_CONTAINER_IS_RAW_VECTOR_HPP_INCLUDED

#include <fcppt/container/raw_vector_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to test if a container is a fcppt::container::raw_vector
\ingroup fcpptcontainer
*/
template<
	typename T
>
struct is_raw_vector
:
boost::false_type
{};

// Without this, doxygen generates another raw_vector type (wtf?)
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename A
>
struct is_raw_vector<
	fcppt::container::raw_vector<
		T,
		A
	>
>
:
boost::true_type
{};
/// \endcond

FCPPT_PP_POP_WARNING

}
}

#endif
